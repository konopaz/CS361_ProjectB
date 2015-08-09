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
    cout << "Our goal is to reduce water pollution and foster cleaner waters" << endl;
    cout << "by giving you the tools you need to properly disposal of your motor oil." << endl;

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

        //Loop for error checking input
        choice = "";
        while(choice.length() != 1 || (choice[0] < '1' || choice[0] > '6')){
            getline(cin, choice);
            if(choice.length() != 1 || (choice[0] < '1' || choice[0] > '6')){
                cout << "Please enter 1 through 6" << endl;
            }
        }

        cout << endl;

        switch (choice[0]) {
            case '1':{
                unsigned int search_radius;
                string search_radius_input;
                bool input_accepted;

                //While loop making sure input is numeric
                do{
                    input_accepted = true;      //Reset to true each time
                    cout << "Search Radius: ";
                    getline(cin, search_radius_input);
                    //Make sure input is less than 10 digits
                    if(search_radius_input.length() > 9){
                        cout << "Please enter an integer from 0 to 999999999" << endl;
                        input_accepted = false;
                        continue;
                    }
                    //Scan for any non-numeric characters
                    for(unsigned int i = 0; i < search_radius_input.length(); i++){
                        if(search_radius_input[i] < '0' || search_radius_input[i] > '9'){
                            cout << "Please enter an integer from 0 to 999999999" << endl;
                            input_accepted = false;
                            break;
                        }
                    }
                }while(search_radius_input.length() < 1 || input_accepted == false);
                search_radius = atoi(search_radius_input.c_str());
                vector<Location> matching = find_nearby(home, database, search_radius);
                print_results(home, matching);
                break;
            }
            case '2':
                turnturn(0,0);
                break;
            case '3':
                checklist();
                break;
            case '4':
                cout << home->to_string()<< endl;
                break;
            case '5':
                unsigned int search_radius;
                string search_radius_input;
                bool input_accepted;

                //While loop making sure input is numeric
                do{
                    input_accepted = true;      //Reset to true each time
                    cout << "Search Radius: ";
                    getline(cin, search_radius_input);
                    //Make sure input is less than 10 digits
                    if(search_radius_input.length() > 9){
                        cout << "Please enter an integer from 0 to 999999999" << endl;
                        input_accepted = false;
                        continue;
                    }
                    //Scan for any non-numeric characters
                    for(unsigned int i = 0; i < search_radius_input.length(); i++){
                        if(search_radius_input[i] < '0' || search_radius_input[i] > '9'){
                            cout << "Please enter an integer from 0 to 999999999" << endl;
                            input_accepted = false;
                            break;
                        }
                    }
                }while(search_radius_input.length() < 1 || input_accepted == false);
                search_radius = atoi(search_radius_input.c_str());
                vector<Location> matching = find_nearby(home, database2, search_radius);
                print_results(home, matching);
                break;
        }

    } while (choice[0] != '6');

    return 0;
}
