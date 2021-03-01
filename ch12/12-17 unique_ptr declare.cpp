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
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;

    // IntP p0(ix);
    // error: no matching function for call to 'std::unique_ptr<int>::unique_ptr(int&)'

    IntP p1(pi);
    // 能编译通过，但是运行时可能错误。
    // 在当前作用域外，pi 将被 delete，而 pi 并非由 new 分配空间，因此会报错。


    IntP p2(pi2);
    // 能编译通过，但是可能会造成空悬指针。
    // 在当前作用域外，pi2 将被 delete，变成空悬指针。

    IntP p3(&ix);
    // 同 pi。能编译通过，但是运行时可能错误。
    // 在当前作用域外， &ix 也即 pi 将被 delete，而 pi 并非由 new 分配空间，因此会报错。

    IntP p4(new int(2048));
    // 正确。推荐用法。

    IntP p5(p2.get());
    // 能编译通过，但是会错误。
    // p2 指针会被释放两次。

    return 0;
}