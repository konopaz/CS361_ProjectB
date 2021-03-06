#include <vector>
#include <string>
#include "Location.h"

using namespace std;

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
    const size_t len1 = s1.size(), len2 = s2.size();
    vector< vector<unsigned int> > d(len1 + 1, vector<unsigned int>(len2 + 1));

    d[0][0] = 0;
    for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
    for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

    for(unsigned int i = 1; i <= len1; ++i)
        for(unsigned int j = 1; j <= len2; ++j)
            d[i][j] = min(min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1));

    return d[len1][len2];
}

