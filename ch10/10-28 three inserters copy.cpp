#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template <typename Sequence> void print(Sequence const&seq) {
    for (const auto& i : seq)
        cout << i << " ";
    cout << endl;
}

/*
* copy - C++ Reference 
    * http://cplusplus.com/reference/algorithm/copy/
*/

int main() {
    vector<int> v{1,2,3,4,5,6,7,8,9};

    // inserter
    list<int> lst_ins;
    copy(v.cbegin(), v.cend(), inserter(lst_ins, lst_ins.begin()));
    print(lst_ins);
    // 1 2 3 4 5 6 7 8 9 

    // back_inserter
    list<int> lst_back;
    copy(v.cbegin(), v.cend(), back_inserter(lst_back));
    print(lst_back);
    // 1 2 3 4 5 6 7 8 9 

    // front_inserter
    list<int> lst_front;
    copy(v.cbegin(), v.cend(), front_inserter(lst_front));
    print(lst_front);
    // 9 8 7 6 5 4 3 2 1 

    return 0;
}