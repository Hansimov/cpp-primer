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
    // 如果我们像下面这样调用 process, 会发生什么？
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p.get()));
    // shared_ptr<int>(p.get()) 会创建一个临时的 shared_ptr 并拷贝给实参
    // 但该拷贝并不是 p 本身，故 process 中输出的 use_count 为 1 而非 2
    // process() 运行结束后，use_count -1，为 0，将释放 p 指向的 int 42 的动态内存

    cout << "p.use_count(): " << p.use_count() << endl;
    // p 的引用计数仍为 1
    cout << "p points to: " << *p << endl;
    // 由于上面指向 int 42 的动态内存已被释放，因此得到的将是一个随机的值
    return 0;
} // 退出 main 函数时，将会第二次释放 p 指向的动态内存


