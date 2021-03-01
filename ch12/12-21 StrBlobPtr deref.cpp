// 第一种写法：
    string& deref() const {
        auto p = check(curr, "deref() error: exceeds end!");
        return (*p)[curr];
    }

// 第二种写法：
    string& deref() const {
        return (*check(curr, "deref() error: exceeds end!"))[curr];
    }

明显第一种写法更好，因为可读性更高。