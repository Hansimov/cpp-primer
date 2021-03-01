// shared_ptr 为什么没有 release 成员？
因为其他指向相同对象的 shared_ptr 同样可以删除该对象，也即同样拥有“操作权限”。
因此没有必要提供该成员。

// * c++ - How to release pointer from boost::shared_ptr? - Stack Overflow 
//   * https://stackoverflow.com/questions/1525764/how-to-release-pointer-from-boostshared-ptr
