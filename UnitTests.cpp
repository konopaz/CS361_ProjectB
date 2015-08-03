#include <iostream>
#include "Location.h"
#include "functions.h"

using namespace::std;

bool testLocationToString();
bool testLocationDistance();
bool testFindNearby();

int main() {

  bool success = true;

  cout << endl << "Running unit tests..." << endl;
  cout << "----------------------------" << endl;

  success = testLocationToString() && success;
  success = testLocationDistance() && success;
  success = testFindNearby() && success;

  cout << endl;
  if (success) {
    cout << "Success!" << endl;
    return 0;
  } else {
    cout << "so test, big fail :(" << endl;
    return 1;
  }
}

bool testLocationDistance() {

  bool success = true;

  cout << "Testing Location::distance... ";

  Location *loc1 = new Location();
  loc1->name = "1";
  loc1->telephone = "2";
  loc1->streetAddress = "3";
  loc1->city = "4";
  loc1->state = "5";
  loc1->zip = "6";

  Location *loc2 = new Location();
  loc1->name = "7";
  loc1->telephone = "8";
  loc1->streetAddress = "9";
  loc1->city = "10";
  loc1->state = "11";
  loc1->zip = "12";

  //cout << loc1->distance(loc2) << endl;
  if (loc1->distance(loc2) != 10) {
    success = false;
    cout << endl << "Failed the first distance test.";
  }

  if (success) {
    cout << "good to go.";
  }

  cout << endl;

  return success;
}

bool testLocationToString() {

  bool success = true;

  cout << "Testing Location::to_string... ";

  Location *loc = new Location();
  loc->name = "Test Name";
  loc->telephone = "(555) 555-5555";
  loc->streetAddress = "1234 Some St";
  loc->city = "Acme Falls";
  loc->state = "CA";
  loc->zip = "123456";

  if (!loc->to_string().compare("Test Name\n(555) 555-5555\n1234 Some St\nAcme Falls CA 123456\n") == 0) {
    success = false;
    cout << endl << "Failed the first to_string test.";
  }

  loc = new Location();
  loc->name = "Test Name";
  loc->streetAddress = "1234 Some St";
  loc->city = "Acme Falls";
  loc->state = "CA";
  loc->zip = "123456";

  if (!loc->to_string().compare("Test Name\n1234 Some St\nAcme Falls CA 123456\n") == 0) {
    success = false;
    cout << endl << "Failed the second to_string test.";
  }

  if (success) {
    cout << "good to go.";
  }

  cout << endl;

  return success;
}

bool testFindNearby(){

    bool success = true;

    cout << "Testing find_nearby()... ";

    Location * loc = new Location();
    loc->name = "Test Name";
    loc->streetAddress = "1234 Some St";
    loc->city = "Acme Falls";
    loc->state = "CA";
    loc->zip = "123456";

    vector<Location> database = createDatabase();
    vector<Location> matching = find_nearby(loc, database);

    if(matching[0].streetAddress != "3332 Lancaster Dr NE"){
        success = false;
        cout << endl << "Element 1 of 5 does not match";
    }
    if(matching[1].streetAddress != "315 Lancaster Dr SE"){
        success = false;
        cout << endl << "Element 2 of 5 does not match";
    }
    if(matching[2].streetAddress != "2970 Commercial St SE"){
        success = false;
        cout << endl << "Element 3 of 5 does not match";
    }
    if(matching[3].streetAddress != "4080 River Road N"){
        success = false;
        cout << endl << "Element 4 of 5 does not match";
    }
    if(matching[4].streetAddress != "2108 NW 9th Street"){
        success = false;
        cout << endl << "Element 5 of 5 does not match";
    }

    if(success){
        cout << "good to go.";
    }

    return success;
}
