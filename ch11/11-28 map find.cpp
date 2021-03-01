#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <utility>
#include <typeinfo>

using namespace std;

// void print(pair<string,vector<int>>::iterator p, map<string, vector<int>> &m) {
void print(const auto & p, const auto & m) {
    // Must use &, or the m.end() will be error!
    if (p!=m.end()) {
        for (auto const & e : p->second)
            cout << e << " ";
    } else {
        cout << "Nothing Found!";
    }
    cout << endl;
}
int main() {
    map<string,vector<int>> m = {
        {"a",{1,2,3}},
        {"b",{4,5,6}},
        {"c",{7,8,9}}
    };
    auto it1 = m.find("a");
    print(it1,m);
    auto it2 = m.find("d");
    print(it2,m);
    // cout << typeid(it).name();
    // cout << endl;
    // int i=1;
    // cout << typeid(i).name() << endl;



    return 0;
}