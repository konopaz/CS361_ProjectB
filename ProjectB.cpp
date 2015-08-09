#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "functions.h"

using namespace std;

int main() {
    int choice;
    vector<Location> database = createDatabase();
	vector<Location> database2 = createDatabase2();
    cout << "Welcome to Oil Disposal Finder!" << endl;

    Location *home = prompt_user_for_location();

    do {
        // Prompt for menu command
        cout << "Please choose a command: " << endl;
        cout << "1: Find nearby oil disposal locations" << endl;
        cout << "2: Go directly to the nearest oil disposal location" << endl;
        cout << "3: View Oil Disposal Checklist" << endl;
        cout << "4: View current location" << endl; 
        cout << "5: View EPA/Environmental Authorities" << endl;
	cout << "6: Exit Application" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cout << endl; 

        switch (choice) {
            case 1:{
                unsigned int search_radius; 
                cout << "Search Radius: "; 
                cin >> search_radius;  
                vector<Location> matching = find_nearby(home, database, search_radius);
                print_results(home, matching);
                break;
            }
            case 2:
                turnturn(0,0);
                break;
            case 3:
                checklist(); 
                break;
            case 4: 
                cout << home->to_string()<< endl;
                break; 
	case 5:
		unsigned int search_radius; 
                cout << "Search Radius: "; 
                cin >> search_radius;  
                vector<Location> matching = find_nearby(home, database2, search_radius);
                print_results(home, matching);
                break;
        }

    } while (choice != 6);

    return 0;
}
