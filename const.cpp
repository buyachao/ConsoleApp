#include <stdlib.h>
#include <iostream>
using namespace std;
class A
{
public:
	A(); //���캯��
	A(int x) : a(x) { };  //��ʼ���б�

	//const �����ڶ����غ���������
	int getValue();		  //��ͨ��Ա����
	int getValue() const; //����Ա�����������޸����е��κ����ݳ�Աֵ

private:
	const int a; //�������Ա��ֻ���ڳ�ʼ���б�ֵ
};

/*void function()
{
	//����
	A b;				  //��ͨ���󣬿��Ե���ȫ����Ա����
	const A a;			  //������ֻ�ܵ��ó���Ա���������³���Ա����
	const A *p = &a;      //��ָ��
	const A &q = a;       //������

	//ָ��
	char greeting[] = "Hello";
	char* p1 = greeting;			 //ָ�������ָ���ַ��������
	const char* p2 = greeting;		 //ָ�������ָ���ַ����鳣��
	char* const p3 = greeting;		 //��ָ�룬ָ���ַ��������
	const char* const p4 = greeting; //��ָ�룬ָ���ַ����鳣��
}*/

//����
void function1(const int Var);       //���ݹ����Ĳ����ں����ڲ����ɱ�
void function2(const char* Var);     //����ָ����ָ����Ϊ����
void function3(char* const Var);     //����ָ��Ϊ��ָ��
void function4(const int& Var);      //���ò����ں����ڲ�Ϊ����

//����ֵ
const int function5();               //����һ������
const int* function6();				 //����һ��ָ������ָ�������ʹ�ã�const int *p = function6();
int* const function7();              //����һ��ָ������ĳ�ָ�룬ʹ�ã�int* const p = function7();

/*int main()
{
	char str[17] = { 0 };
	char* p = str;
	cout << "ָ����ռ�ռ��С��" << dec << sizeof(p) << endl;
	cout << "������ռ�ռ��С��" << dec << sizeof(str) << endl;

	system("pause");
	return 0;
}*/