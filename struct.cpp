/*
  �� struct �� typedef struct
  C ��
*/
/*c
typedef struct Student 
{
	int age;
}S;
//�ȼ���
struct Student
{
	int age;
};
typedef struct Student S;
//��ʱ S �ȼ��� struct Student����������ʶ�����ƿռ䲻��ͬ
//���⻹���Զ����� struct Student����ͻ��void Student(){}��
*/



/*
  �� struct �� typedef struct
  C++�У����ڱ�������λ���ŵĹ����������򣩸ı䣬���²�ͬ��C����
*/
//1����������ʶ���ռ䶨���� struct Student{...}; ʹ��Student me; ʱ��������������ȫ�ֱ�ʶ����Studentδ�ҵ����������ʶ����������
//   ������Ϊ����ʹ��StudentҲ����ʹ��struct Student�����£�
struct Student
{
	int age;
};
void f(Student me); //��ȷ��"struct" �ؼ��ֿ���ʡ��

//2������������Student ͬ������֮����Studentֻ��������������ṹ�壬���£�
typedef struct Student
{

}S;
void Student() {}	   //��ȷ�������"Student"��ֻ����˺�����

//void S(){};		   //���󣬷��� "S" �Ѿ�����Ϊһ�� "struct Student" �ı�����

int main() 
{
	Student();
	struct Student me; //���� "S me"��
	return 0;
}