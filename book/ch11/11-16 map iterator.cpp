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
    map<string,int> m;
    m["you"] = 1;
    auto itr = m.begin();
    cout << itr->first << ": " << itr->second << endl;
    itr->second = 2;
    cout << itr->first << ": " << itr->second << endl;

    return 0;
}