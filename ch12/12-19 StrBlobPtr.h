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

class StrBlobPtr; // Do not forget to declare here before StrBlob
                  // or there will be error: 'StrBlobPtr' does not name a type

class StrBlob {
public:
    typedef vector<string>::size_type size_type;

    friend class StrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();

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

class StrBlobPtr {
public:
    StrBlobPtr():
        curr(0) {}

    StrBlobPtr(StrBlob &a, size_t sz=0):
        wptr(a.data), curr(sz) {}

    bool operator!=(const StrBlobPtr &p) {
        return p.curr != curr;
    }

    string& deref() const {
        auto p = check(curr, "deref() error: exceeds end!");
        return (*p)[curr];
    }

    StrBlobPtr & incr() {
        check(curr, "incr() error: exceeds limit!");
        ++curr;
        return *this;
    }

private:
    shared_ptr<vector<string>> check(size_t sz, const string & msg) const {
        auto ret = wptr.lock();
        if (!ret)
            throw runtime_error("unbound StrBlobPtr");
        if (sz>=ret->size())
            throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}