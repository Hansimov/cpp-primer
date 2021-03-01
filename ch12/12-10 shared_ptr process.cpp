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
    // 下面的代码调用了第 413 页中定义的 process 函数。
    // 解释此调用是否正确。如果不正确，应如何修改？
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p));
    // 该调用是正确的，且会将其引用计数+1，为 2
    cout << "p.use_count(): " << p.use_count() << endl;
    cout << endl;

    shared_ptr<int> q(new int(100));
    cout << "q.use_count(): " << q.use_count() << endl;
    cout << endl;

    q = p;
    cout << "p.use_count(): "    << p.use_count()
         << " | q.use_count(): " << q.use_count() << endl;
    cout << "p points to: " << *p
         << " | q points to: " << *q << endl;
    cout << endl;
    // p 的引用计数+1，为 2
    // q 原来指向的对象引用计数-1，为 0，故 int 100 动态内存被释放
    // p 的引用计数赋给 q，故二者的引用计数现在都为 2
    shared_ptr<int> r(new int(20));
    q = r;
    cout << "r.use_count(): "    << r.use_count()
         << " | q.use_count(): " << q.use_count() << endl;
    cout << "r points to: " << *r
         << " | q points to: " << *q << endl;
    return 0;
}
