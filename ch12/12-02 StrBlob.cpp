#include "12-02 StrBlob.h"
#include <iostream>

int main() {
    const StrBlob csb{"hello", "world", "apple"};
    StrBlob sb{"hello", "world", "dog"};

    sb.print();
    sb.pop_back();
    sb.print();
    sb.push_back("pear");
    sb.print();
    cout << sb.front() << " " << sb.back() << endl;
}