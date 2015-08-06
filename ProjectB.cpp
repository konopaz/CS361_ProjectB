#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "functions.h"

using namespace std;

int main() {
    int choice;
    vector<Location> database = createDatabase();
    cout << "Welcome to Oil Disposal Finder!" << endl;

    Location *home = prompt_user_for_location();

    do {
        // Prompt for menu command
        cout << "Please choose a command: " << endl;
        cout << "1: Find nearby oil disposal locations" << endl;
        cout << "2: Go directly to the nearest oil disposal location" << endl;
        //cout << "3: View Oil Disposal Checklist" << endl;
        cout << "4: Exit Application" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                unsigned int search_radius; 
                cout << "Search Radius: "; 
                getline(cin, search_radius); 
                vector<Location> matching = find_nearby(home, database, search_radius);
                print_results(home, matching);
                break;
            }
            case 2:
                turnturn(0,0);
                break;
            case 3:
                // Checklist function
                break;
        }

    } while (choice != 4);

    return 0;
}
