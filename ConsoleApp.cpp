#include <iostream>
using namespace std;

#ifdef Knowledge Points
//指针对象：https://blog.csdn.net/qq_26501341/article/details/58192662
//对象和声明的区别：https://blog.csdn.net/qq78442761/article/details/100651081
//C++运行时多态：https://blog.csdn.net/Rage_/article/details/81041167
//类指针与类实例对象：https://blog.csdn.net/baidu_39486224/article/details/81301900?utm_source=blogxgwz4

//--初始化 - 基类的构造函数先调用，派生类的构造函数后调用
//--指针 - 对于一个类型T，T*就是指向T的指针类型，也即一个T*类型的变量能够保存一个T对象的地址，而类型T是可以加一些限定词的，如const、volatile等等。所示指针的含义
char c = 'a';
char* p = &c; //p里面存放的是c的地址
//--引用 - 引用是一个对象的别名，主要用于函数参数和返回值类型，符号T&表示T类型的引用。所示引用的含义：
int i = 1;
int& r = i;   //此时i=r=1；

//******多态性(c++的多态性用一句话概括就是：在基类的函数前加上virtual关键字，在派生类中重写该函数，运行时将会根据对象的实际类型来调用相应的函数，如果对象类型是派生类，就调用派生类的函数，如果对象类型是基类，就调用基类的函数)
1、每一个类都有虚表。
2、虚表可以继承，如果子类没有重写虚函数，那么子类虚表中仍然会有该函数的地址，只不过这个地址指向的是基类的虚函数实现，如果基类有3个虚函数，那么基类的虚表中就有三项(虚函数地址)，派生类也会虚表，至少有三项，如果重写了相应的虚函数，那么虚表中的地址就会改变，指向自身的虚函数实现，如果派生类有自己的虚函数，那么虚表中就会添加该项。
3、派生类的虚表中虚地址的排列顺序和基类的虚表中虚函数地址排列顺序相同。这就是c++中的多态性，当c++编译器在编译的时候，发现Father类的Say()函数是虚函数，这个时候c++就会采用晚绑定技术，也就是编译时并不确定具体调用的函数，而是在运行时，依据对象的类型来确认调用的是哪一个函数，这种能力就叫做c++的多态性，我们没有在Say()函数前加virtual关键字时，c++编译器就确定了哪个函数被调用，这叫做早期绑定。
4、c++的多态性就是通过晚绑定技术来实现的。
/*
虚函数是在基类中定义的，目的是不确定它的派生类的具体行为，例如 :
	定义一个基类:class Animal //动物，它的函数为breathe()
	再定义一个类class Fish //鱼。它的函数也为breathe()
	再定义一个类class Sheep //羊，它的函数也为breathe()
*/
5、将Fish，Sheep定义成Animal的派生类，然而Fish与Sheep的breathe不一样，一个是在水中通过水来呼吸，一个是直接呼吸，所以基类不能确定该如何定义breathe，所以在基类中只定义了一个virtual breathe，它是一个空的虚函数，具体的函数在子类中分别定义，程序一般运行时，找到类，如果它有基类，再找到它的基类，最后运行的是基类中的函数，这时，它在基类中找到的是virtual标识的函数，它就会再回到子类中找同名函数，派生类也叫子类，基类也叫父类，这就是虚函数的产生，和类的多态性的体现。
6、这里的多态性是指类的多态性。
7、函数的多态性是指一个函数被定义成多个不同参数的函数。当你调用这个函数时，就会调用不同的同名函数。
8、一般情况下(不涉及虚函数)，当我们用一个指针 / 引用调用一个函数的时候，被调用的函数是取决于这个指针 / 引用的类型。
9、当设计到多态性的时候，采用了虚函数和动态绑定，此时的调用就不会在编译时候确定而是在运行时确定。不在单独考虑指针 / 引用的类型而是看指针 / 引用的对象的类型来判断函数的调用，根据对象中虚指针指向的虚表中的函数的地址来确定调用哪个函数。
#endif

class A
{
public:
	A() { p(); }//基类构造函数
	virtual void p() { printf("A"); }
	virtual ~A() { p(); }//基类虚析构函数
};
class B : public A
{
public:
	B() { p(); }//派生类构造函数
	virtual void p() { printf("B"); }
	~B() { p(); }//派生类虚析构函数
};
class CA
{
public:
	void f() //成员函数f()
	{
		cout << "CA f()" << endl;
	}
	virtual void ff() //虚函数ff()
	{
		cout << "CA ff()" << endl;
		f();
	}
};
class CB : public CA
{
public:
	virtual void f()
	{
		cout << "CB f()" << endl;
	}
	void ff()
	{
		cout << "CB ff()" << endl;
		f();
		CA::ff();
	}
};
class CC : public CB
{
public:
	virtual void f()
	{
		cout << "C f()" << endl;
	}
};


int func(unsigned int v)
{
	unsigned int temp = 0;

	temp = v >> 16;
	cout << temp << " ";
	v ^= temp;
	cout << v << "+ \t";

	temp = v >> 8;
	cout << temp << " ";
	v ^= temp;
	cout << v << "- \t";

	temp = v >> 4;
	cout << temp << " ";
	v ^= temp;
	cout << v << "* \t";

	v = v & 0xf;
	cout << v << "/ \t";

	temp = (0x6996 >> v) & 1;
	cout << temp << endl;

	return temp;
}

int funb(int n)
{
	unsigned int t = 1 << n;
	int val = 0;
	for (int i = 0; i < t; i++)
	{
		val += func(i);
	}
	return val;
}

#ifndef main
int main(int argc, char* argv[])
{
	int iNum = funb(10);

	cout << iNum << endl;

	/*
	//--------------------------------构造与析构
	A* a = new B();
	delete a;
	cout << endl << endl;

	//--------------------------------引用和指针
	CB cb;       //创建CB类型对象
	CA* ap = &cb;//CA类型指针，指向CB类型对象
	CC c;        //创建CC类型对象
	CB& br = c;  //声明CB类型引用(兼容)，CC类型对象的别名
	CB* bp = &c; //CB类型指针，指向CC类型对象

	ap->f();     //CA f() CA为基类型指针, 调用自身类 f()
	cout << endl;

	cb.f();		 //CB f() CB类型对象, 调用自身类 f()
	cout << endl;

	br.f();		 //C f() CB类型引用(兼容CC类型), CC类对象的的别名
	cout << endl;

	bp->f();	 //C f() CB类型指针, 因CB类型的 f()函数为虚函数，运行时将会根据对象的实际类型来调用相应的函数，实际对象类型是CC类型。
	cout << endl;

	ap->ff();	 //
	cout << endl;

	bp->ff();	 //C f() CB类型指针, 因CB类型的 f()函数为虚函数，运行时将会根据对象的实际类型来调用相应的函数，实际对象类型是CC类型。
	cout << endl;
	*/

	system("pause");
	return 0;
}
#endif