#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <utility>

using namespace std;

int main() {
    map<int,int> m = {
        {1,11},
        {2,22},
        {3,33}
    };

    auto it1 = m.lower_bound(4);
    auto it2 = m.upper_bound(4);
    auto it3 = m.equal_range(4);
    cout << (it1 == m.end()) << " "
         << (it2 == m.end()) << " "
         << (it3.first == m.end()) << " "
         << (it3.second == m.end()) << " "
         << endl;

    return 0;
}