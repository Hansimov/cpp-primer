// word_count: map<string,size_t>
while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
// if word in word_count, increment count by 1
// if not, insert word and set count to 1