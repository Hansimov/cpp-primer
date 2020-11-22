for (auto pos = authors.equal_range(search_item);
    pos.first != pos.second; ++pos.first)
cout << pos.first->second << endl;
// pos is pair of iterators (lower_bound and upper_bound)
// pos.first is the lower_bound iterator of a <key-val> pair in the map
// pos.first->second is the value of the <key-val> pair