#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <numeric>
#include "../ch01/Sales_item.h"

using namespace std;

int main() {
    ifstream ifs("10-32 input.txt");
    istream_iterator <Sales_item> in_itr(ifs), in_eof;
    vector<Sales_item> v;

    while (in_itr != in_eof) {
        v.push_back(*in_itr++);
    }

    sort(v.begin(), v.end(), 
        [](Sales_item const & left, Sales_item const & right) {
            return left.isbn() < right.isbn();
        });

    for (auto beg=v.cbegin(), end=beg; beg!=v.cend(); beg=end) {
        end = find_if(beg, v.cend(), 
            [beg](const Sales_item & item) {
                return item.isbn() != beg->isbn();
            });
        // In "Sales_item.h":
        // std::ostream& operator<<(std::ostream& out, const Sales_item& s) {
        //     out << s.isbn() << " " << s.units_sold << " "
        //         << s.revenue << " " << s.avg_price();
        //     return out;
        // }
        cout << accumulate(beg, end, Sales_item(beg->isbn())) << endl;
    }

    return 0;
}