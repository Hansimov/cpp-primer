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
    auto sp = make_shared<int>();
    auto p = sp.get();

    delete p;
    // 释放 p 也即 sp 的动态内存

    return 0;
} // 第二次释放 sp 的动态内存