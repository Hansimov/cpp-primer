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
    multimap <string,string> m = {
        {"A","hello"},
        {"A","world"},
        {"B","apple"},
        {"B","pear"},
        {"C","dog"},
        {"C","cat"}
    };

    string author_to_erase = "A";
    auto res = m.find(author_to_erase); // return first found element
    cout << res->second << endl;
    // m.erase(author_to_erase);    // erase all works
    m.erase(res);   // only erase the found element

    for (auto & e : m) {
        cout << e.first << ": " << e.second << endl;
    }


    return 0;
}