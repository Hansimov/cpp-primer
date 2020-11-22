#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

void print_vector(const vector<string> v) {
    for (auto const &e : v) {
        cout << e << " ";
    }
    cout << endl << v.size() << endl;
}

int main() {
    string s = "0 1 2 3 5 6 8 3 2 4 4 0 9 7 6";
    stringstream ss(s);
    string word;
    vector<string> v;
    while (ss >> word) {
        v.push_back(word);
    }
    print_vector(v);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    print_vector(v);


    return 0;
}