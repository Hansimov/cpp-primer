#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>

using namespace std;


int main() {
    // 11-24
    map<int,int> m;
    m[0] = 1;
    for (const auto &e:m) {
        cout << e.first << ": " << e.second << endl;
    }

    // 11-25
    vector<int> v;
    v[0] = 1;
    for (const auto &e:v) {
        cout << e << " " << endl;
    }
    // nothing output

    return 0;
}