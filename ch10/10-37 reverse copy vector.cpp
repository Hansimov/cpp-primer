#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int main() {
    int left=3,right=7;
    vector<int> v{0,1,2,3,4,5,6,7,8,9};
    list<int> lst(right-left+1);
    reverse_copy(v.cbegin()+left, v.cbegin()+right+1, lst.begin());

    for (auto &i: lst) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}