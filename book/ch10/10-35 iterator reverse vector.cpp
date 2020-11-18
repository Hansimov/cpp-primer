#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int main() {
    vector<int> v{1,2,3,4,5};
    for (auto itr=v.cend(); itr!=v.cbegin(); ) {
        cout << *--itr << " ";
    }
    cout << endl;

    return 0;
}