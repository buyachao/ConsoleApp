/*
  ● struct 和 typedef struct
  C 中
*/
/*c
typedef struct Student 
{
	int age;
}S;
//等价于
struct Student
{
	int age;
};
typedef struct Student S;
//此时 S 等价于 struct Student，但两个标识符名称空间不相同
//另外还可以定义与 struct Student不冲突的void Student(){}。
*/



/*
  ● struct 和 typedef struct
  C++中，由于编译器定位符号的规则（搜索规则）改变，导致不同于C语言
*/
//1、如果在类标识符空间定义了 struct Student{...}; 使用Student me; 时，编译器将搜索全局标识符表，Student未找到，则在类标识符内搜索。
//   即表现为可以使用Student也可以使用struct Student，如下：
struct Student
{
	int age;
};
void f(Student me); //正确，"struct" 关键字可以省略

//2、若定义了与Student 同名函数之后，则Student只代表函数，不代表结构体，如下：
typedef struct Student
{

}S;
void Student() {}	   //正确，定义后"Student"，只代表此函数；

//void S(){};		   //错误，符号 "S" 已经定义为一个 "struct Student" 的别名；

int main() 
{
	Student();
	struct Student me; //或者 "S me"；
	return 0;
}