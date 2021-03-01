std::map<std::string, size_t> word_count;

// 原文：
// auto map_it = word_count.cbegin();

// 将 auto 修改成 std::map<std::string, size_t>::const_iterator
// 注意 iterator 是 const 的，因为是 cbegin
std::map<std::string, size_t>::const_iterator map_it = word_count.cbegin();