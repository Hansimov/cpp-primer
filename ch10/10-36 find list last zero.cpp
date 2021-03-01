#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int main() {
    list<int> lst{1,2,3,4,5,0,1,0,2};
    auto idx = find(lst.crbegin(), lst.crend(), 0);
    cout << *idx << " before " << *idx.base() << endl;

    return 0;
}