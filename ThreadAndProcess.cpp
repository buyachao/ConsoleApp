#include "stdio.h"
#include "stdlib.h"  
#include <iostream>  
#include <string>  
#include <stack>  
#include <windows.h>  
#include <process.h>  
using namespace std;
#include <stdio.h>

#ifdef Knowledge Points
���̱߳������ԣ�https ://blog.csdn.net/wolenski/article/details/7969908
C / C++֮���̣߳�https ://blog.csdn.net/u010236550/article/details/12372319?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-5.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-5.control
//https://blog.csdn.net/bao_qibiao/article/details/4516196 (�ٽ��������������ź������¼�������)

//��һ�⣺�̵߳Ļ�������̵߳Ļ���״̬��״̬֮��Ĺ�ϵ��
�̣߳���ʱ��Ϊ���������̣���CPUʹ�õĻ�����Ԫ�������߳�ID��������������Ĵ������ϺͶ�ջ��ɡ���������ͬһ���̵������̹߳��������Ρ����ݶκ���������ϵͳ��Դ������ļ����źţ���
�߳�������״̬������״̬��������״̬��������״̬������״̬��

//�ڶ��⣺�߳�����̵�����
1���߳��ǽ��̵�һ���֣������߳��е�ʱ�򱻳�Ϊ����Ȩ���̻������������̡�
2��һ��û���̵߳Ľ����ǿ��Ա��������̵߳ģ����һ��������ӵ�ж���̣߳����̵�ִ�й��̲���һ���ߣ��̣߳��ģ����Ƕ����ߣ��̣߳���ͬ��ɵġ�
3��ϵͳ�����е�ʱ���Ϊÿ�����̷��䲻ͬ���ڴ����򣬵��ǲ���Ϊ�̷߳����ڴ棨�߳���ʹ�õ���Դ���������Ľ��̵���Դ�����߳���ֻ�ܹ�����Դ���Ǿ���˵������CPU֮�⣨�߳������е�ʱ��Ҫռ��CPU��Դ����������ڲ�����Ӳ����Դ�ķ������߳��޹أ��߳�ֻ�ܹ������������̵���Դ��
4������̵Ŀ��Ʊ�PCB���ƣ��߳�Ҳ���Լ��Ŀ��Ʊ�TCB������TCB����������߳�״̬��PCB�����ٶ��ˡ�
5��������ϵͳ������Դ����ʱ���һ��������λ��ӵ��һ������������ռ��ַ�����������̶߳��������ڡ�

//�����⣺���߳��м���ʵ�ַ���������ʲô��
1. �̳� Thread ��
2. ʵ�� Runnable �ӿ��� new Thread(YourRunnableOjbect)

//�����⣺���߳�ͬ���ͻ����м���ʵ�ַ���������ʲô��
�̼߳��ͬ����������ɷ�Ϊ���ࣺ�û�ģʽ���ں�ģʽ������˼�壬�ں�ģʽ����ָ����ϵͳ�ں˶���ĵ�һ��������ͬ����ʹ��ʱ��Ҫ�л��ں�̬���û�̬�����û�ģʽ���ǲ���Ҫ�л����ں�̬��ֻ���û�̬��ɲ�����
�û�ģʽ�µķ����У�ԭ�Ӳ���������һ����һ��ȫ�ֱ��������ٽ������ں�ģʽ�µķ����У��¼����ź�������������

//�����⣺���߳�ͬ���ͻ����к���ͬ����ʲô����·ֱ�ʹ�����ǣ�����˵����
�߳�ͬ����ָ�߳�֮�������е�һ����Լ��ϵ��һ���̵߳�ִ��������һ���̵߳���Ϣ������û�еõ���һ���̵߳���ϢʱӦ�ȴ���ֱ����Ϣ����ʱ�ű����ѡ�
�̻߳�����ָ���ڹ���Ľ���ϵͳ��Դ���ڸ������̷߳���ʱ�������ԡ��������ɸ��̶߳�Ҫʹ��ĳһ������Դʱ���κ�ʱ�����ֻ����һ���߳�ȥʹ�ã�����Ҫʹ�ø���Դ���̱߳���ȴ���ֱ��ռ����Դ���ͷŸ���Դ���̻߳�����Կ�����һ��������߳�ͬ��������ͳ��Ϊͬ������

//���ֽ��̻��߳�ͬ������Ŀ��Ʒ�����
�ٽ�����ͨ���Զ��̵߳Ĵ��л���������Դ��һ�δ��룬�ٶȿ죬�ʺϿ������ݷ��ʡ�
��������ΪЭ����ͬ��һ��������Դ�ķ��ʶ���Ƶġ�
�ź�����Ϊ����һ���������������û���Դ����ơ�
��  ��������֪ͨ�߳���һЩ�¼��ѷ������Ӷ������������Ŀ�ʼ��
1.���������ٽ��������÷ǳ����ƣ����������ǿ��������ģ�Ҳ����˵�����Կ�Խ����ʹ�á����Դ�����������Ҫ����Դ���࣬�������ֻΪ���ڽ����ڲ����õĻ�ʹ���ٽ���������ٶ��ϵ����Ʋ��ܹ�������Դռ���� ����Ϊ�������ǿ���̵Ļ�����һ�����������Ϳ���ͨ�����ִ�����
2.��������Mutex�����źŵƣ�Semaphore�����¼���Event�������Ա���Խ����ʹ��������ͬ�����ݲ������������Ķ���������ͬ�������޹أ������ڽ��̺��߳�������������̺��߳�������״̬��Ϊ���ź�״̬�����˳���Ϊ���ź�״̬�����Կ���ʹ��WaitForSingleObject���ȴ����̺� �߳��˳���
3.ͨ������������ָ����Դ����ռ�ķ�ʽʹ�ã������������һ�����ͨ�����������޷�������������һλ�û�������һ����������������ɵ����ݿ�ϵͳ�����Ը����û�����ķ�����������������ж��ٸ��߳� / ������ͬʱ�������ݿ��������ʱ��������û�������û�а취������Ҫ���źŵƶ������˵��һ����Դ��������
4.�ź���������̵߳�ͬ����ʽ��ǰ�漸�ַ�����ͬ���ź��������߳�ͬʱʹ�ù�����Դ ���������ϵͳ�е�PV������ͬ����ָ����ͬʱ���ʹ��� ��Դ���߳� �����Ŀ�����������߳���ͬһʱ�̷���ͬһ��Դ��������Ҫ������ͬһʱ�̷��ʴ���Դ������߳���Ŀ������CreateSemaphore���������ź��� ʱ��Ҫͬʱָ������������Դ�����͵�ǰ������Դ������һ���ǽ���ǰ������Դ��������Ϊ�����Դ������ÿ����һ���̶߳Թ�����Դ�ķ��ʣ���ǰ������Դ���� �ͻ��1��ֻҪ��ǰ������Դ�����Ǵ���0�ģ��Ϳ��Է����ź����źš����ǵ�ǰ���ü�����С��0ʱ��˵����ǰռ����Դ���߳����Ѿ��ﵽ��������������Ŀ�� ���������������̵߳Ľ��룬��ʱ���ź����źŽ��޷��������߳��ڴ����깲����Դ��Ӧ���뿪��ͬʱͨ��ReleaseSemaphore������������ǰ�� ����Դ������1�����κ�ʱ��ǰ������Դ�����������ܴ��������Դ������
5.PV�������ź����ĸ�����ɺ�����ѧ��E.W.Dijkstra����ġ��ź���S��һ��������S���ڵ�����ʱ����ɹ���������ʹ�õ���Դʵ��������SС����ʱ���ʾ���ڵȴ�ʹ�ù�����Դ�Ľ�������
	P���� ������Դ��
		��1��S��1��
		��2����S��1���Դ��ڵ����㣬����̼���ִ�У�
		��3����S��1��С���㣬��ý��̱��������������ź����Ӧ�Ķ����У�Ȼ��ת����̵��ȡ�
	V���� �ͷ���Դ��
		��1��S��1��
		��2������ӽ�������㣬����̼���ִ�У�
		��3������ӽ��С�ڵ����㣬��Ӹ��źŵĵȴ������л���һ���ȴ����̣�Ȼ���ٷ���ԭ���̼���ִ�л�ת����̵��ȡ�
6.�ź��������ļ�������ԭ�
	CreateSemaphore()������һ���ź���
	OpenSemaphore()����һ���ź���
	ReleaseSemaphore()���ͷ��ź���
	WaitForSingleObject()���ȴ��ź���
#endif

#ifdef �ź������߳�֮�以��

const int THREAD_NUM = 10;
HANDLE            ga, gb, gc;

unsigned int __stdcall FunA(void* pPM)
{
	Sleep(50);//some work should to do
	printf("A\n");
	ReleaseSemaphore(gb, 1, NULL);//�ͷ��ź����������ź���B����Դ��	

	return 0;
}

unsigned int __stdcall FunB(void* pPM)
{
	Sleep(50);//some work should to do
	printf("B\n");
	ReleaseSemaphore(gc, 1, NULL);//�ͷ��ź����������ź���C����Դ��	

	return 0;
}

unsigned int __stdcall FunC(void* pPM)
{
	Sleep(50);//some work should to do
	printf("C\n");
	ReleaseSemaphore(ga, 1, NULL);//�ͷ��ź����������ź���A����Դ��	

	return 0;
}

int main()
{
	//��ʼ���ź���
	ga = CreateSemaphore(NULL, 1, 1, NULL);//��ǰ1����Դ���������1��ͬʱ����
	gb = CreateSemaphore(NULL, 0, 1, NULL);//��ǰ0����Դ���������1��ͬʱ����
	gc = CreateSemaphore(NULL, 0, 1, NULL);//��ǰ0����Դ���������1��ͬʱ����

	HANDLE  handle[THREAD_NUM];
	int i = 0;
	while (i < THREAD_NUM)
	{
		WaitForSingleObject(ga, INFINITE);  //�ȴ��ź���A>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunA, &i, 0, NULL);
		WaitForSingleObject(gb, INFINITE);  //�ȴ��ź���B>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunB, &i, 0, NULL);
		WaitForSingleObject(gc, INFINITE);  //�ȴ��ź���C>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunC, &i, 0, NULL);

		++i;
	}
	WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);//�ȴ�����������

	//�����ź���
	CloseHandle(ga);
	CloseHandle(gb);
	CloseHandle(gc);
	for (i = 0; i < THREAD_NUM; i++)
		CloseHandle(handle[i]);
	return 0;
}
#endif

#ifdef ��������������
//1������ 2������ 4������  

//���ÿ���̨�����ɫ  
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}

const int END_PRODUCE_NUMBER = 8;   //������Ʒ����  
const int BUFFER_SIZE = 4;          //����������  
int g_Buffer[BUFFER_SIZE];          //�����  
int g_i, g_j;
CRITICAL_SECTION g_cs;              //�ź�����ؼ���  
HANDLE g_hSemaphoreBufferEmpty, g_hSemaphoreBufferFull;

//�������̺߳���  
unsigned int __stdcall ProducerThreadFun(PVOID pM)
{
	for (int i = 1; i <= END_PRODUCE_NUMBER; i++)
	{
		//�ȴ��пյĻ��������֣�WaitForSingleObject�����������hHandle�¼����ź�״̬����ĳһ�߳��е��øú���ʱ���߳���ʱ��������ڹ����dwMilliseconds�����ڣ��߳����ȴ��Ķ����Ϊ���ź�״̬����ú����������أ������ʱʱ���Ѿ�����dwMilliseconds���룬��hHandle��ָ��Ķ���û�б�����ź�״̬�������������ء�����dwMilliseconds�������������������ֵ��0��INFINITE����Ϊ0����ú����������أ���ΪINFINITE�����߳�һֱ������ֱ��hHandle��ָ��Ķ����Ϊ���ź�״̬ʱΪֹ��  
		WaitForSingleObject(g_hSemaphoreBufferEmpty, INFINITE);

		//����ķ��ʻ�����  
		EnterCriticalSection(&g_cs);
		g_Buffer[g_i] = i;
		printf("�������ڻ���ص�%d����������Ͷ������%d\n", g_i, g_Buffer[g_i]);
		g_i = (g_i + 1) % BUFFER_SIZE;
		LeaveCriticalSection(&g_cs);

		//�ͷ��ź�����֪ͨ����������������  
		ReleaseSemaphore(g_hSemaphoreBufferFull, 1, NULL);
	}
	printf("��������������߳̽�������\n");
	return 0;
}

//�������̺߳���  
unsigned int __stdcall ConsumerThreadFun(PVOID pM)
{
	while (true)
	{
		//�ȴ��ǿյĻ���������  
		WaitForSingleObject(g_hSemaphoreBufferFull, INFINITE);

		//����ķ��ʻ�����  
		EnterCriticalSection(&g_cs);//�����ٽ���

		//��ӡ�����߼�¼
		SetConsoleColor(FOREGROUND_GREEN);
		printf("  ���Ϊ [%d] �������ߴӻ�����е�%d��������ȡ������%d\n", GetCurrentThreadId(), g_j, g_Buffer[g_j]);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		//�ж��Ƿ����
		if (g_Buffer[g_j] == END_PRODUCE_NUMBER)
		{
			LeaveCriticalSection(&g_cs);//�뿪�ٽ���
			ReleaseSemaphore(g_hSemaphoreBufferFull, 1, NULL);//�ͷ��ź�����֪ͨ��������������������(������־)              
			break;
		}
		g_j = (g_j + 1) % BUFFER_SIZE;

		//�뿪�ٽ�����Ȼ���ͷ��ź���
		LeaveCriticalSection(&g_cs);//�뿪�ٽ���
		Sleep(50); //some other work to do  
		ReleaseSemaphore(g_hSemaphoreBufferEmpty, 1, NULL);//�ͷ��ź���
	}
	SetConsoleColor(FOREGROUND_GREEN);
	printf("  ���Ϊ [%d] ���������յ�֪ͨ���߳̽�������\n", GetCurrentThreadId());
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return 0;
}

int main()
{
	InitializeCriticalSection(&g_cs);
	//��ʼ���ź���,һ����¼�в�Ʒ�Ļ���������,��һ����¼�ջ���������.  
	g_hSemaphoreBufferEmpty = CreateSemaphore(NULL, 4, 4, NULL);
	g_hSemaphoreBufferFull = CreateSemaphore(NULL, 0, 4, NULL);
	g_i = 0;
	g_j = 0;
	memset(g_Buffer, 0, sizeof(g_Buffer));

	const int THREADNUM = 3;
	HANDLE hThread[THREADNUM];
	//�������߳�  
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, ProducerThreadFun, NULL, 0, NULL);
	//�������߳�  
	hThread[1] = (HANDLE)_beginthreadex(NULL, 0, ConsumerThreadFun, NULL, 0, NULL);
	hThread[2] = (HANDLE)_beginthreadex(NULL, 0, ConsumerThreadFun, NULL, 0, NULL);
	WaitForMultipleObjects(THREADNUM, hThread, TRUE, INFINITE);

	//�ر��߳̾��
	for (int i = 0; i < THREADNUM; i++)
	{
		CloseHandle(hThread[i]);
	}

	//�����ź����͹ؼ���  
	CloseHandle(g_hSemaphoreBufferEmpty);
	CloseHandle(g_hSemaphoreBufferFull);
	DeleteCriticalSection(&g_cs);
	return 0;
}
#endif

#ifdef ��д��
//���ÿ���̨�����ɫ  
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}
const int READER_NUM = 5;  //���߸���  
//�ؼ��κ��¼�  
CRITICAL_SECTION g_cs, g_cs_writer_count;
HANDLE g_hEventWriter, g_hEventNoReader;
int g_nReaderCount;
//�����߳��������(��κ�����ʵ��)  
void ReaderPrintf(const char* pszFormat, ...)
{
	va_list   pArgList;

	va_start(pArgList, pszFormat);
	EnterCriticalSection(&g_cs);
	vfprintf(stdout, pszFormat, pArgList);
	LeaveCriticalSection(&g_cs);
	va_end(pArgList);
}
//�����̺߳���  
unsigned int __stdcall ReaderThreadFun(PVOID pM)
{
	ReaderPrintf("     ���Ϊ%d�Ķ��߽���ȴ���...\n", GetCurrentThreadId());
	//�ȴ�д�����  
	WaitForSingleObject(g_hEventWriter, INFINITE);

	//���߸�������  
	EnterCriticalSection(&g_cs_writer_count);
	g_nReaderCount++;
	if (g_nReaderCount == 1)
		ResetEvent(g_hEventNoReader);
	LeaveCriticalSection(&g_cs_writer_count);

	//��ȡ�ļ�  
	ReaderPrintf("���Ϊ%d�Ķ��߿�ʼ��ȡ�ļ�...\n", GetCurrentThreadId());

	Sleep(rand() % 100);

	//�����Ķ�,���߸�����С,��λ����  
	ReaderPrintf(" ���Ϊ%d�Ķ��߽�����ȡ�ļ�\n", GetCurrentThreadId());

	//���߸�������  
	EnterCriticalSection(&g_cs_writer_count);
	g_nReaderCount--;
	if (g_nReaderCount == 0)
		SetEvent(g_hEventNoReader);
	LeaveCriticalSection(&g_cs_writer_count);

	return 0;
}
//д���߳��������  
void WriterPrintf(const char* pszStr)
{
	EnterCriticalSection(&g_cs);
	SetConsoleColor(FOREGROUND_GREEN);
	printf("     %s\n", pszStr);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	LeaveCriticalSection(&g_cs);
}
//д���̺߳���  
unsigned int __stdcall WriterThreadFun(PVOID pM)
{
	WriterPrintf("д���߳̽���ȴ���...");
	//�ȴ����ļ��Ķ���Ϊ��  
	WaitForSingleObject(g_hEventNoReader, INFINITE);
	//���д������д�ļ�  
	ResetEvent(g_hEventWriter);

	//д�ļ�  
	WriterPrintf("  д�߿�ʼд�ļ�.....");
	Sleep(rand() % 100);
	WriterPrintf("  д�߽���д�ļ�");

	//���д�߽���д�ļ�  
	SetEvent(g_hEventWriter);
	return 0;
}

int main()
{
	//printf("  ����д������\n");
	//printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

	//��ʼ���¼����ź���  
	InitializeCriticalSection(&g_cs);
	InitializeCriticalSection(&g_cs_writer_count);

	//�ֶ���λ,��ʼ�Ѵ���  
	g_hEventWriter = CreateEvent(NULL, TRUE, TRUE, NULL);
	g_hEventNoReader = CreateEvent(NULL, FALSE, TRUE, NULL);
	g_nReaderCount = 0;

	int i;
	HANDLE hThread[READER_NUM + 1];
	//���������������߳�  
	for (i = 1; i <= 2; i++)
	{
		hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	}

	//����д���߳�  
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, WriterThreadFun, NULL, 0, NULL);
	Sleep(50);

	//��������������߽��  
	for (; i <= READER_NUM; i++)
	{
		hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	}

	WaitForMultipleObjects(READER_NUM + 1, hThread, TRUE, INFINITE);
	for (i = 0; i < READER_NUM + 1; i++)
	{
		CloseHandle(hThread[i]);
	}

	//�����¼����ź���  
	CloseHandle(g_hEventWriter);
	CloseHandle(g_hEventNoReader);
	DeleteCriticalSection(&g_cs);
	DeleteCriticalSection(&g_cs_writer_count);

	getchar();
	return 0;
}
#endif
