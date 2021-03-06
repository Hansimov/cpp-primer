#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "8-6 sales_data.h"

using namespace std;

int main(int argc, char **argv) {
    // ifstream ifs(argv[1]);
    ifstream ifs("./8-6 input.txt");
    // ofstream ofs(argv[2]);
    // ofstream ofs("./8-7 output.txt", ofstream::trunc);
    ofstream ofs("./8-7 output.txt", ofstream::app);
    Sales_data sd;

    if (read(ifs,sd)) {
        Sales_data trans;
        while (read(ifs, trans)) {
            if (sd.isbn() == trans.isbn()) {
                sd.combine(trans);
            } else {
                // print(cout, sd) << endl;
                print(ofs, sd) << endl;
                sd = trans;
            }
        }
        // print(cout, sd) << endl;
        print(ofs, sd) << endl;
    } else {
        cerr << "No data" << endl;
    }

    return 0;
}