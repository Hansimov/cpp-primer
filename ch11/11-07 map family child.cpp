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
    map<string, vector<string>> mp = {
        {"Zhao",{"Yi","Er","San","Si"}},
        {"Qian",{"Bo","Zhong","Shu","Ji"}},
        {"Sun", {"A","B","C","D"}}
    };

    for (auto const & k : mp) {
        cout << k.first << ": \t";
        for (auto const & name : k.second) {
            cout << name << ", ";
        }
        cout << endl;
    }


    return 0;
}