/*
extern "C"
  ● 被extern限定的函数或变量是extern类型的
  ● 被extern "C"修饰的变量和函数是按照C语言方式编译和连接的，extern "C" 的作用是让C++编译器将 extern "C"声明的代码当作C语言代码处理，可以避免C++因符号修饰导致代码不能和C语言库中的符号进行链接的问题。
*/

/*
extern "C" 使用
*/

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	void* memset(void*, int, size_t);

#ifdef __cplusplus
}
#endif // __cplusplus
