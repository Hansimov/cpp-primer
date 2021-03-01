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
    map<string, int> m = {
        {"a",1}, {"b",2}, {"c",3}
    };
    for (const auto & e : m)
        cout << e.first << ": " << e.second << endl;

    map<string,int>::key_type key = "a";
    map<string,int>::mapped_type ret = m[key];
    cout << ret << endl;

    return 0;
}