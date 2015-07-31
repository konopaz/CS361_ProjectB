#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Location {
    public:
        string name;
        string telephone;
        string streetAddress;
        string city;
        string state;
        string zip;
        unsigned int distance(Location*);
        string to_string(void);
};

string Location::to_string() {
    string result = name + "\n";
    if (telephone.size() > 0) {
        result += telephone + "\n";
    }
    result += streetAddress + "\n";
    result += city + " " + state + " " + zip + "\n";

    return result;
}

unsigned int Location::distance(Location* there) {

    string s1 = this->to_string(), s2 = there->to_string();
    const std::size_t len1 = s1.size(), len2 = s2.size();
    std::vector< std::vector<unsigned int> > d(len1 + 1, std::vector<unsigned int>(len2 + 1));

    d[0][0] = 0;
    for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
    for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

    for(unsigned int i = 1; i <= len1; ++i)
        for(unsigned int j = 1; j <= len2; ++j)
            d[i][j] = std::min(std::min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1));

    return d[len1][len2];
}

vector<Location> createDatabase();
void print_results(Location*, vector<Location>);
void find_nearby(Location*, vector<Location>);
void print_location(Location);
Location* prompt_user_for_location();

int main() {
    int choice;
    vector<Location> database = createDatabase();
    cout << "Welcome to Oil Disposal Finder!" << endl;

    Location *home = prompt_user_for_location();

    do {
        // Prompt for menu command
        cout << "Please choose a command: " << endl;
        cout << "1: Find nearby oil disposal locations" << endl;
        //cout << "2: Go directly to the nearest oil disposal location" << endl;
        //cout << "3: View Oil Disposal Checklist" << endl;
        cout << "4: Exit Application" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                find_nearby(home, database);
                break;
            case 2:
                // Turn by turn function?
                break;
            case 3:
                // Checklist function
                break;
        }

    } while (choice != 4);

    return 0;
}

Location* prompt_user_for_location() {

    Location *loc = new Location;
    cout << "What is the name of your current location: ";
    getline(cin, loc->name);
    cout << "What is the street address: ";
    getline(cin, loc->streetAddress);
    cout << "What is the city: ";
    getline(cin, loc->city);
    cout << "What is the state: ";
    getline(cin, loc->state);
    cout << "What is the zipcode: ";
    getline(cin, loc->zip);

    return loc;
}

void find_nearby(Location* from, vector<Location> database) {
    //Location matching[100];
    //int size = 0;
    // ask for location
    // store location

    // search and sort within database
    /* for (int i = 0; i < database size; i++) {
        if (database[i].distance >= search_radius) {
            matching[size] = database[i];
            size++;
        }
    }
    // selection sort algorithm
        int min, temp;
        for (int i = 0; i < n-1; i++) {
            min = i;

            for (int j= i + 1; j < n; j++) {
                if(matching[j].distance < matching[min].distance)
                    min = j;
            }

            if(min != i) {
                temp = matching[i];
                matching[i] = matching[min];
                matching[min] = temp;
            }

        }
    */


    // print out results
    print_results(from, database);
}

void print_results(Location* from, vector<Location> matches) {

    for(unsigned int i = 0; i < matches.size(); i++) {
        cout << "Distance: ";
        cout << matches[i].distance(from) << endl;
        cout << matches[i].to_string();
    }
}

vector<Location> createDatabase() {
    vector<Location> database;

    Location loc1;
    loc1.name = "Firestone Complete Auto Care";
    loc1.telephone = "(503) 689-8250";
    loc1.streetAddress = "295 Commercial St NE";
    loc1.city = "Salem";
    loc1.state = "OR";
    loc1.zip = "97301";
    //loc1.distance = 0;
    database.push_back(loc1);

    Location loc2;
    loc2.name = "Firestone Complete Auto Care";
    loc2.telephone = "(503) 798-9966";
    loc2.streetAddress = "844 Lancaster Dr";
    loc2.city = "Salem";
    loc2.state = "OR";
    loc2.zip = "97301";
    //loc2.distance = 0;
    database.push_back(loc2);

    /*
    Location loc3;
    loc3.name = "O’Reilly Auto Parts";
    loc3.telephone = "(503) 399-9969";
    loc3.streetAddress = "3863 Commercial St SE";
    loc3.city = "Salem";
    loc3.state = "OR";
    loc3.zip = "97302";
    loc3.distance = 0;
    database.push_back(loc3);

    Location loc4;
    loc4.name = "AutoZone";
    loc4.telephone = "(503) 763-7171";
    loc4.streetAddress = "2970 Commercial St SE";
    loc4.city = "Salem";
    loc4.state = "OR";
    loc4.zip = "97302";
    loc4.distance = 0;
    database.push_back(loc4);

    Location loc5;
    loc5.name = "Walmart Tire and Lube Express";
    loc5.telephone = "(503) 391-0754";
    loc5.streetAddress = "1940 Turner Rd SE";
    loc5.city = "Salem";
    loc5.state = "OR";
    loc5.zip = "97302";
    loc5.distance = 0;
    database.push_back(loc5);

    Location loc6;
    loc6.name = "AutoZone";
    loc6.telephone = "(503) 390-5622";
    loc6.streetAddress = "4080 River Road N";
    loc6.city = "Keizer";
    loc6.state = "OR";
    loc6.zip = "97303";
    loc6.distance = 0;
    database.push_back(loc6);

    Location loc7;
    loc7.name = "O’Reilly Auto Parts";
    loc7.telephone = "(503) 390-7029";
    loc7.streetAddress = "4297 River Road N";
    loc7.city = "Keizer";
    loc7.state = "OR";
    loc7.zip = "97303";
    loc7.distance = 0;
    database.push_back(loc7);

    Location loc8;
    loc8.name = "Valley Recycling and Disposal";
    loc8.telephone = "(503) 585-4300";
    loc8.streetAddress = "2515 Salem-Dallas Hwy NW";
    loc8.city = "Salem";
    loc8.state = "OR";
    loc8.zip = "97304";
    loc8.distance = 0;
    database.push_back(loc8);

    Location loc9;
    loc9.name = "O’Reilly Auto Parts";
    loc9.telephone = "(503) 362-7477";
    loc9.streetAddress = "2727 Lancaster Dr NE";
    loc9.city = "Salem";
    loc9.state = "OR";
    loc9.zip = "97305";
    loc9.distance = 0;
    database.push_back(loc9);

    Location loc10;
    loc10.name = "AutoZone";
    loc10.telephone = "(503) 589-4896";
    loc10.streetAddress = "3332 Lancaster Dr NE";
    loc10.city = "Salem";
    loc10.state = "OR";
    loc10.zip = "97305";
    loc10.distance = 0;
    database.push_back(loc10);

    Location loc11;
    loc11.name = "Salem-Keizer Recycling and Transfer";
    loc11.telephone = "(503) 588-5169";
    loc11.streetAddress = "3250 Deer Park Dr SE";
    loc11.city = "Salem";
    loc11.state = "OR";
    loc11.zip = "97310";
    loc11.distance = 0;
    database.push_back(loc11);

    Location loc12;
    loc12.name = "AutoZone";
    loc12.telephone = "(503) 371-7500";
    loc12.streetAddress = "315 Lancaster Dr SE";
    loc12.city = "Salem";
    loc12.state = "OR";
    loc12.zip = "97317";
    loc12.distance = 0;
    database.push_back(loc12);

    Location loc13;
    loc13.name = "Republic Services";
    loc13.telephone = "(541) 928-2551";
    loc13.streetAddress = "1214 SE Montgomery St";
    loc13.city = "Albany";
    loc13.state = "OR";
    loc13.zip = "97321";
    loc13.distance = 0;
    database.push_back(loc13);

    Location loc14;
    loc14.name = "O’Reilly Auto Parts";
    loc14.telephone = "(541) 967-7700";
    loc14.streetAddress = "2105 Santiam Hwy SE";
    loc14.city = "Albany";
    loc14.state = "OR";
    loc14.zip = "97322";
    loc14.distance = 0;
    database.push_back(loc14);

    Location loc15;
    loc15.name = "AutoZone";
    loc15.telephone = "(541) 752-9050";
    loc15.streetAddress = "2108 NW 9th Street";
    loc15.city = "Corvallis";
    loc15.state = "OR";
    loc15.zip = "97330";
    loc15.distance = 0;
    database.push_back(loc15);

    Location loc16;
    loc16.name = "Republic Services";
    loc16.telephone = "(541) 754-0444";
    loc16.streetAddress = "110 NE Walnut Blvd";
    loc16.city = "Corvallis";
    loc16.state = "OR";
    loc16.zip = "97330";
    loc16.distance = 0;
    database.push_back(loc16);

    Location loc17;
    loc17.name = "Coffin Butte Landfill Recycling Center";
    loc17.telephone = "(541) 745-5792";
    loc17.streetAddress = "28972 Coffin Butte Rd";
    loc17.city = "Corvallis";
    loc17.state = "OR";
    loc17.zip = "97330";
    loc17.distance = 0;
    database.push_back(loc17);

    Location loc18;
    loc18.name = "Firestone Complete Auto Care";
    loc18.telephone = "(541) 230-5111";
    loc18.streetAddress = "385 S Third St";
    loc18.city = "Corvallis";
    loc18.state = "OR";
    loc18.zip = "97333";
    loc18.distance = 0;
    database.push_back(loc18);

    Location loc19;
    loc19.name = "O’Reilly Auto Parts";
    loc19.telephone = "(503) 831-1279";
    loc19.streetAddress = "111 E Ellendale Ave";
    loc19.city = "Dallas";
    loc19.state = "OR";
    loc19.zip = "97338";
    loc19.distance = 0;
    database.push_back(loc19);

    Location loc20;
    loc20.name = "Walmart Tire and Lube Express";
    loc20.telephone = "(503) 623-4751";
    loc20.streetAddress = "321 NE Kings Valley Hwy";
    loc20.city = "Dallas";
    loc20.state = "OR";
    loc20.zip = "97338";
    loc20.distance = 0;
    database.push_back(loc20);

    Location loc21;
    loc21.name = "AutoZone";
    loc21.telephone = "(541) 259-5275";
    loc21.streetAddress = "2063 S Santiam Hwy";
    loc21.city = "Lebanon";
    loc21.state = "OR";
    loc21.zip = "97355";
    loc21.distance = 0;
    database.push_back(loc21);

    Location loc22;
    loc22.name = "O’Reilly Auto Parts";
    loc22.telephone = "(541) 258-1694";
    loc22.streetAddress = "2195 S Santiam Hwy";
    loc22.city = "Lebanon";
    loc22.state = "OR";
    loc22.zip = "97355";
    loc22.distance = 0;
    database.push_back(loc22);

    Location loc23;
    loc23.name = "Walmart Tire and Lube Express";
    loc23.telephone = "(541) 258-7400";
    loc23.streetAddress = "3290 S Santiam Hwy";
    loc23.city = "Lebanon";
    loc23.state = "OR";
    loc23.zip = "97355";
    loc23.distance = 0;
    database.push_back(loc23);

    Location loc24;
    loc24.name = "O’Reilly Auto Parts";
    loc24.telephone = "(541) 258-7400";
    loc24.streetAddress = "903 N 1st St";
    loc24.city = "Stayton";
    loc24.state = "OR";
    loc24.zip = "97383";
    loc24.distance = 0;
    database.push_back(loc24);

    Location loc25;
    loc25.name = "O’Reilly Auto Parts";
    loc25.telephone = "(541) 367-2115";
    loc25.streetAddress = "1118 Main St";
    loc25.city = "Sweet Home";
    loc25.state = "OR";
    loc25.zip = "97386";
    loc25.distance = 0;
    database.push_back(loc25);
    */

    return database;
}
