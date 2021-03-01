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

void process(shared_ptr<int> ptr) {
    cout << "process use_count(): " << ptr.use_count() << endl;
}


int main() {
    auto p = new int();
    auto sp = make_shared<int>();

    process(sp);
    // 合法：引用计数为 2

    // process(new int());
    // error: could not convert '(operator new(4u), (<statement>, ((int*)<anonymous>)))' from 'int*' to 'std::shared_ptr<int>'

    // process(p);
    // error: could not convert 'p' from 'int*' to 'std::shared_ptr<int>'

    process(shared_ptr<int>(p));
    // 合法：引用计数为 1，但是会导致第二次动态内存释放（退出 main 函数时）

    return 0;
}


