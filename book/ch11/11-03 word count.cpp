#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <utility> // pair

using namespace std;
/*
* c++ - How can I sort a std::map first by value, then by key? - Stack Overflow 
    * https://stackoverflow.com/questions/19842035/how-can-i-sort-a-stdmap-first-by-value-then-by-key
* How to sort a map by value in C++ 
    * https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp

*/

// auto cmp = [](const pair<string,int> & a, const pair<string,int> & b) {
//     return a.first == b.first ? a.second < b.second : a.first < b.first;
// };

int main() {
    map<string, int> word_cnt;
    string word;
    ifstream ifs("11-03 input.txt");
    while (ifs >> word) {
        ++word_cnt[word];
    }


    for (const auto & ele : word_cnt) {
        cout << ele.first << ": " << ele.second << endl;
    }

    return 0;
}