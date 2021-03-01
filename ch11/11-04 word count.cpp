#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // transform, remove_if
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <cctype> // ispunct, tolower

using namespace std;

// c++ - How to convert std::string to lower case? - Stack Overflow 
//   https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
void lower_word(string & word) {
    transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {return tolower(c);});
}

// * C++ Remove punctuation from String - Stack Overflow 
//     * https://stackoverflow.com/questions/19138983/c-remove-punctuation-from-string
void remove_punct(string & word) {
    word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
}

int main() {
    map<string, int> word_cnt;
    string word;
    ifstream ifs("11-03 input.txt");
    while (ifs >> word) {

        lower_word(word);
        remove_punct(word);

        ++word_cnt[word];
    }


    for (const auto & ele : word_cnt) {
        cout << ele.first << ": " << ele.second << endl;
    }

    return 0;
}