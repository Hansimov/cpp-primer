// 使用 unique_copy 将一个 vector 中不重复的元素拷贝到一个初始为空的 list 中

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    vector<int> v{1,3,1,4,2,7,9,11};
    list<int> lst;
    sort(v.begin(), v.end()); // Must sort!
    unique_copy(v.begin(), v.end(), back_inserter(lst));

    for (auto i: lst) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}