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
    
    map<vector<int>::iterator, int> mv;
    vector<int> vv{1,2};
    mv.insert(pair<vector<int>::iterator,int>(vv.begin(), 0));

    map<list<int>::iterator, int> ml;
    list<int> vl{1,2};
    // ml.insert(pair<list<int>::iterator,int>(vl.begin(), 0));
    // Error: no match for 'operator<' (operand types are 'const std::_List_iterator<int>' and 'const std::_List_iterator<int>')

    return 0;
}