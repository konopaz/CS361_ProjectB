#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "Location.h"

vector<Location> createDatabase();
void print_results(Location*, vector<Location>);
vector<Location> find_nearby(Location*, vector<Location>);
void print_location(Location);
Location* prompt_user_for_location();
void turnturn(int locationnumber,int distance);

#endif // FUNCTIONS_H