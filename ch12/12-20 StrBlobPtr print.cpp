#include "12-19 StrBlobPtr.h"

int main() {
    ifstream ifs("12-20 input.txt");

    StrBlob blob;

    for (string s; getline(ifs,s); ) {
        blob.push_back(s);
    }

    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg!=pend; pbeg.incr())
        cout << pbeg.deref() << endl;

    return 0;
}