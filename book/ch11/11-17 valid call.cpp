假定 c 是一个 string 的 multiset，v 是一个 string 的 vector，解释下面的调用。指出每个调用是否合法：

copy(v.begin(), v.end(), inserter(c, c.end()));
// 合法

copy(v.begin(), v.end(), back_inserter(c));
// 不合法，set 中没有 push_back

copy(c.begin(), c.end(), inserter(v, v.end()));
// 合法

copy(c.begin(), c.end(), back_inserter(v));
// 合法