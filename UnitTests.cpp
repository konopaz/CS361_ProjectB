#include <iostream>
#include "Location.h"

using namespace::std;

bool testLocationToString();
bool testLocationDistance();

int main() {

  bool success = true;

  cout << endl << "Running unit tests..." << endl;
  cout << "----------------------------" << endl;

  success = testLocationToString() && success;
  success = testLocationDistance() && success;

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
