/*
�麯��(virtual)��������������(inline)��
  �� �麯�����������������������ǿ��������麯���ģ����ǵ��麯�����ֶ�̬�Ե�ʱ����������
  �� �������ڱ�����������������������麯���Ķ�̬���������ڣ��������޷�֪�������ڵ����ĸ����룬����麯������Ϊ��̬��ʱ�������ڣ�������������
  �� inline virtualΨһ����������ʱ���ǣ�������֪�������õĶ������ĸ��ࣨ��Base::who()����ֻ���ڱ���������ʵ�ʶ�������Ƕ����ָ�������ʱ�Żᷢ������
*/

/*
�麯������ʹ��
*/

#include <iostream>
using namespace std;
class Base 
{
public:
	inline virtual void who() 
	{
		cout << "I am Base\n";
	}
	virtual ~Base() {}
	
};

class Derived :public Base
{
public:
	inline void who() 
	{
		cout << "I am Derived\n";//��дinlineʱ��ʽ����
	}
};

/*int main() 
{
	//�˴����麯�� who()����ͨ���ࣨBase���ľ������b�������õģ������ڼ����ȷ���ˣ������������������ģ��������Ƿ�����ȡ���ڱ�������
	Base b;
	b.who();

	//�˴����麯����ͨ��ָ����õģ����ֶ�̬�ԣ���Ҫ������ʱ�ڼ����ȷ�������Բ���Ϊ������
	Base* ptr = new Derived();
	ptr->who();

	//��ΪBase��������������Virtual ~Base(){}��������deleteʱ�����ȵ��������ࣨDerived�������������ٵ��û��ࣨBase��������������ֹ�ڴ�й¶��
	delete ptr;
	ptr = nullptr;

	system("pause");
	return 0;
}*/