#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <utility>
#include <memory> // shared_ptr, make_shared

using namespace std;

shared_ptr<vector<int>> create_dynamic_vector() {
    auto ptr = make_shared<vector<int>>();
    return ptr;
}

void read_vector(shared_ptr<vector<int>> &ptr, stringstream & ss) {
    int i;
    while (ss >> i) {
        ptr->push_back(i);
    }
}

void print_vector(const shared_ptr<vector<int>> &ptr) {
    for (const auto & e : *ptr)
        cout << e << " ";
    cout << endl;
}

int main() {
    stringstream ss("1 2 3 4 5 6");
    auto ptr = create_dynamic_vector();
    read_vector(ptr, ss);
    print_vector(ptr);


    return 0;
}