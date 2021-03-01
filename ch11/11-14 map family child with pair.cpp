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
    map<string, vector<string>> mp = {
        {"Zhao",{"Yi","Er","San","Si"}},
        {"Qian",{"Bo","Zhong","Shu","Ji"}},
        {"Sun", {"A","B","C","D"}}
    };
    vector<pair<string,string>> v = {
        {"Yi","0101"},{"Er","0102"},{"San","0103"},{"Si","0104"},
        {"Bo","0201"},{"Zhong","0202"},{"Shu","0203"},{"Ji","0204"},
        {"A","0301"},{"B","0302"},{"C","0303"},{"D","0304"}
    };

    for (auto const & k : mp) {
        cout << k.first << ": \t";
        for (auto const & name : k.second) {
            cout << name << ", ";
        }
        cout << endl;
    }
    cout << endl;

    for (auto const & i : v) {
        cout << i.first << " at " << i.second << endl;
    }
    cout << endl;

    return 0;
}