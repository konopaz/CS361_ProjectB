#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {
    public:
        std::string name;
        string telephone;
        string streetAddress;
        string city;
        string state;
        string zip;
        unsigned int distance(Location*);
        string to_string(void);
};

#endif
