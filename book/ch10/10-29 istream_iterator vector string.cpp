// 编写程序，使用流迭代器读取一个文本文件，存入一个 vector 中的 string 里。

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ifstream ifs("./10-29 input.txt");
    istream_iterator<string> in_itr(ifs), eof;
    vector<string> v;
    // input
    copy(in_itr, eof, back_inserter(v));
    // output
    copy(v.cbegin(), v.cend(), ostream_iterator<string>(cout, "\n"));

    return 0;
}