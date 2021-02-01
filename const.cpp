#include <stdlib.h>
#include <iostream>
using namespace std;
class A
{
public:
	A(); //构造函数
	A(int x) : a(x) { };  //初始化列表

	//const 可用于对重载函数的区分
	int getValue();		  //普通成员函数
	int getValue() const; //常成员函数，不得修改类中的任何数据成员值

private:
	const int a; //常对象成员，只能在初始化列表赋值
};

/*void function()
{
	//对象
	A b;				  //普通对象，可以调用全部成员函数
	const A a;			  //常对象，只能调用常成员函数、更新常成员变量
	const A *p = &a;      //常指针
	const A &q = a;       //常引用

	//指针
	char greeting[] = "Hello";
	char* p1 = greeting;			 //指针变量，指向字符数组变量
	const char* p2 = greeting;		 //指针变量，指向字符数组常量
	char* const p3 = greeting;		 //常指针，指向字符数组变量
	const char* const p4 = greeting; //常指针，指向字符数组常量
}*/

//函数
void function1(const int Var);       //传递过来的参数在函数内部不可变
void function2(const char* Var);     //参数指针所指内容为常量
void function3(char* const Var);     //参数指针为常指针
void function4(const int& Var);      //引用参数在函数内部为常量

//返回值
const int function5();               //返回一个常数
const int* function6();				 //返回一个指向常量的指针变量，使用：const int *p = function6();
int* const function7();              //返回一个指向变量的常指针，使用：int* const p = function7();

/*int main()
{
	char str[17] = { 0 };
	char* p = str;
	cout << "指针所占空间大小：" << dec << sizeof(p) << endl;
	cout << "数组所占空间大小：" << dec << sizeof(str) << endl;

	system("pause");
	return 0;
}*/