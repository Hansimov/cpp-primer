#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <utility>
#include <memory>

using namespace std;

int main() {
    unique_ptr<string> p1(new string("hello"));

    // unique_ptr<string> p2(p1);
    // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]'

    // auto p3 = p1;
    // same with above

    cout << *p1 << endl;
    p1.reset(nullptr);

    return 0;
}