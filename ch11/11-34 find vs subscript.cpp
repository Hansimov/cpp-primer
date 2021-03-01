const string & transform(const string &s, const map<string,string> &m) {
    // auto itr = m.find(s);
    auto replaced_text = m[s];
    ...
}

若使用下标，会报错。
因为函数定义中传入的函数是 const 类型的 map 引用。而 map 的运算符不是 const 类型。
我们知道使用下标运算索引关键词，若不存在，则默认会插入一个该关键词对应的 pair。