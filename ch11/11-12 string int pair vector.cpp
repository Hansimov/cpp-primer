#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <utility>

using namespace std;

int main() {
    ifstream ifs("11-12 input.txt");
    string s;
    int n;
    vector<pair<string,int>> v;
    while (ifs >> s >> n) {
        v.push_back(pair<string,int>{s,n});
    }

    for (auto const & e : v) {
        cout << e.first << " " << e.second << endl;
    }
    

    return 0;
}