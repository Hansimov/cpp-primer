#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int file_processing(string in_fname, string out_fname_odd, string out_fname_even) {
    ifstream ifs(in_fname);
    ofstream ofs_odd(out_fname_odd), ofs_even(out_fname_even);

    istream_iterator <int> in_itr(ifs), in_eof;
    ostream_iterator <int> out_itr_odd(ofs_odd, " "), out_itr_even(ofs_even, " ");

    for_each(in_itr, in_eof, [&out_itr_odd, &out_itr_even](const int i){
        *(i & 1 ? out_itr_odd : out_itr_even)++ = i;
    });

    return 0;
}

int main() {
    file_processing("10-33 input.txt",
                    "10-33 out_odd.txt",
                    "10-33 out_even.txt");

    return 0;
}