#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include "../ch07/7-26 sales_data.h"
#include <set>

using namespace std;

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    using compareType = bool (*)(const Sales_data& lhs, const Sales_data& rhs);
    // typedef bool(*compareType)(const Sales_data &lhs, const Sales_data &rhs);
    std::multiset<Sales_data, compareType> bookstore(compareIsbn);
}