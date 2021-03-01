#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <utility>
#include <initializer_list>
#include <stdexcept> // out_of_range
#include <memory>    // shared_ptr

using namespace std;

class StrBlob {
public:
    typedef vector<string>::size_type size_type ;

    StrBlob():
        data(make_shared<vector<string>>()) { }

    StrBlob(initializer_list<string> il):
        data(make_shared<vector<string>>(il)) { }

    size_type size() const {
        return data->size();
    }

    bool empty() const {
        return data->empty();
    }

    string & front() {
        check(0, "front() error: empty StrBlob");
        return data->front();
    }
    string & back() {
        check(0, "back() error: empty StrBlob");
        return data->back();
    }

    const string & front() const {
        check(0, "front() error: empty StrBlob");
        return data->front();
    }
    const string & back() const {
        check(0, "back() error: empty StrBlob");
        return data->back();
    }

    void push_back(const string &t) {
        data->push_back(t);
    }
    void pop_back() {
        check(0, "pop_back() error: empty StrBlob");
        data->pop_back();
    }
    void print() {
        for (const auto & e : *data)
            cout << e << " ";
        cout << endl;
    }

private:
    shared_ptr<vector<string>> data;

    void check(size_type sz, const string &msg) const {
        if (sz >= data->size())
            throw out_of_range(msg);
    }
};