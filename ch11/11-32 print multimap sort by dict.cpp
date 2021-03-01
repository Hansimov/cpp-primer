#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main() {
    multimap <string,string> m = {
        {"A","world"},
        {"A","hello"},
        {"B","apple"},
        {"C","dog"},
        {"B","pear"},
        {"C","cat"}
    };

    for (auto & e : m) {
        cout << e.first << ": " << e.second << endl;
    }

    cout << "\n----------\n\n";

    map<string,multiset<string>> m2;
    for (auto & e : m) {
        m2[e.first].insert(e.second);
    }

    for (auto & e : m2) {
        cout << e.first << ": ";
        for (auto & i : e.second)
            cout << i << " ";
        cout << endl;
    }


    return 0;
}