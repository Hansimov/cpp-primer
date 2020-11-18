#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int main() {
    ifstream ifs("10-30 input.txt");
    istream_iterator <int> in_iter(ifs), eof;
    vector <int> v;
    copy(in_iter, eof, back_inserter(v));
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    return 0;
}