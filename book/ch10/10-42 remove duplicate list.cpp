#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

void remove_duplicate(list<int> & lst) {
    lst.sort();
    lst.unique();
}

int main() {
    list<int> lst{1,3,5,6,2,7,9,3,7};
    remove_duplicate(lst);
    for (const auto & ele : lst)
        cout << ele << " ";
    cout << endl;

    return 0;
}