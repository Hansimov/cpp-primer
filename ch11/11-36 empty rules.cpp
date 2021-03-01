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
#include <cctype> // isspace

using namespace std;

static inline void ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch){
        return !isspace(ch);
    }));
}

static inline void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch){
        return !isspace(ch);
    }).base(),s.end());
}

static inline void trim(string &s) {
    ltrim(s);
    rtrim(s);
}

map<string,string> build_map(ifstream & rules) {
    map<string,string> m;
    string original_text;
    string replaced_text;
    while (rules >> original_text) {
        getline(rules, replaced_text);
        trim(replaced_text);
        // Use `if` statement,
        //  to avoid empty ruttles replace word with whitespace
        if (replaced_text.size()>1) {
            m[original_text] = replaced_text;
        }
    }
    return m;
}

const string & transform(const string &s, const map<string,string> &m) {
    auto itr = m.find(s);
    if (itr != m.end())
        return itr->second;
    else
        return s;
}

void word_transform(ifstream & rules, ifstream & input, ofstream & output) {
    auto m = build_map(rules);
    for (string text; getline(input, text); ) {
        istringstream iss(text);
        for (string word; iss>>word; ) {
            output << transform(word,m) << " ";
        }
        output << endl;
    }
}

int main() {    
    ifstream rules("./11-36 rules.txt");
    ifstream input("./11-33 input.txt");
    ofstream output("./11-36 output.txt");

    word_transform(rules, input, output);

    return 0;
}