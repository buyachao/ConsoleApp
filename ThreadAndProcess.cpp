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
多线程笔试面试：https ://blog.csdn.net/wolenski/article/details/7969908
C / C++之多线程：https ://blog.csdn.net/u010236550/article/details/12372319?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-5.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-5.control
//https://blog.csdn.net/bao_qibiao/article/details/4516196 (临界区，互斥量，信号量，事件的区别)

//第一题：线程的基本概念、线程的基本状态及状态之间的关系？
线程，有时称为轻量级进程，是CPU使用的基本单元；它由线程ID、程序计数器、寄存器集合和堆栈组成。它与属于同一进程的其他线程共享其代码段、数据段和其他操作系统资源（如打开文件和信号）。
线程有四种状态：新生状态、可运行状态、被阻塞状态、死亡状态。

//第二题：线程与进程的区别？
1、线程是进程的一部分，所以线程有的时候被称为是轻权进程或者轻量级进程。
2、一个没有线程的进程是可以被看作单线程的，如果一个进程内拥有多个线程，进程的执行过程不是一条线（线程）的，而是多条线（线程）共同完成的。
3、系统在运行的时候会为每个进程分配不同的内存区域，但是不会为线程分配内存（线程所使用的资源是它所属的进程的资源），线程组只能共享资源。那就是说，出了CPU之外（线程在运行的时候要占用CPU资源），计算机内部的软硬件资源的分配与线程无关，线程只能共享它所属进程的资源。
4、与进程的控制表PCB相似，线程也有自己的控制表TCB，但是TCB中所保存的线程状态比PCB表中少多了。
5、进程是系统所有资源分配时候的一个基本单位，拥有一个完整的虚拟空间地址，并不依赖线程而独立存在。

//第三题：多线程有几种实现方法，都是什么？
1. 继承 Thread 类
2. 实现 Runnable 接口再 new Thread(YourRunnableOjbect)

//第四题：多线程同步和互斥有几种实现方法，都是什么？
线程间的同步方法大体可分为两类：用户模式和内核模式。顾名思义，内核模式就是指利用系统内核对象的单一性来进行同步，使用时需要切换内核态与用户态，而用户模式就是不需要切换到内核态，只在用户态完成操作。
用户模式下的方法有：原子操作（例如一个单一的全局变量），临界区。内核模式下的方法有：事件，信号量，互斥量。

//第五题：多线程同步和互斥有何异同，在什么情况下分别使用他们？举例说明。
线程同步是指线程之间所具有的一种制约关系，一个线程的执行依赖另一个线程的消息，当它没有得到另一个线程的消息时应等待，直到消息到达时才被唤醒。
线程互斥是指对于共享的进程系统资源，在各单个线程访问时的排它性。当有若干个线程都要使用某一共享资源时，任何时刻最多只允许一个线程去使用，其它要使用该资源的线程必须等待，直到占用资源者释放该资源。线程互斥可以看成是一种特殊的线程同步（下文统称为同步）。

//四种进程或线程同步互斥的控制方法互
临界区：通过对多线程的串行化来访问资源或一段代码，速度快，适合控制数据访问。
互斥量：为协调共同对一个共享资源的访问而设计的。
信号量：为控制一个具有有限数量用户资源而设计。
事  件：用来通知线程有一些事件已发生，从而启动后继任务的开始。
1.互斥量与临界区的作用非常相似，但互斥量是可以命名的，也就是说它可以跨越进程使用。所以创建互斥量需要的资源更多，所以如果只为了在进程内部是用的话使用临界区会带来速度上的优势并能够减少资源占用量 。因为互斥量是跨进程的互斥量一旦被创建，就可以通过名字打开它。
2.互斥量（Mutex），信号灯（Semaphore），事件（Event）都可以被跨越进程使用来进行同步数据操作，而其他的对象与数据同步操作无关，但对于进程和线程来讲，如果进程和线程在运行状态则为无信号状态，在退出后为有信号状态。所以可以使用WaitForSingleObject来等待进程和 线程退出。
3.通过互斥量可以指定资源被独占的方式使用，但如果有下面一种情况通过互斥量就无法处理，比如现在一位用户购买了一份三个并发访问许可的数据库系统，可以根据用户购买的访问许可数量来决定有多少个线程 / 进程能同时进行数据库操作，这时候如果利用互斥量就没有办法完成这个要求，信号灯对象可以说是一种资源计数器。
4.信号量对象对线程的同步方式与前面几种方法不同，信号允许多个线程同时使用共享资源 ，这与操作系统中的PV操作相同。它指出了同时访问共享 资源的线程 最大数目。它允许多个线程在同一时刻访问同一资源，但是需要限制在同一时刻访问此资源的最大线程数目。在用CreateSemaphore（）创建信号量 时即要同时指出允许的最大资源计数和当前可用资源计数。一般是将当前可用资源计数设置为最大资源计数，每增加一个线程对共享资源的访问，当前可用资源计数 就会减1，只要当前可用资源计数是大于0的，就可以发出信号量信号。但是当前可用计数减小到0时则说明当前占用资源的线程数已经达到了所允许的最大数目， 不能在允许其他线程的进入，此时的信号量信号将无法发出。线程在处理完共享资源后，应在离开的同时通过ReleaseSemaphore（）函数将当前可 用资源计数加1。在任何时候当前可用资源计数决不可能大于最大资源计数。
5.PV操作及信号量的概念都是由荷兰科学家E.W.Dijkstra提出的。信号量S是一个整数，S大于等于零时代表可供并发进程使用的资源实体数，但S小于零时则表示正在等待使用共享资源的进程数。
	P操作 申请资源：
		（1）S减1；
		（2）若S减1后仍大于等于零，则进程继续执行；
		（3）若S减1后小于零，则该进程被阻塞后进入与该信号相对应的队列中，然后转入进程调度。
	V操作 释放资源：
		（1）S加1；
		（2）若相加结果大于零，则进程继续执行；
		（3）若相加结果小于等于零，则从该信号的等待队列中唤醒一个等待进程，然后再返回原进程继续执行或转入进程调度。
6.信号量包含的几个操作原语：
	CreateSemaphore()，创建一个信号量
	OpenSemaphore()，打开一个信号量
	ReleaseSemaphore()，释放信号量
	WaitForSingleObject()，等待信号量
#endif

#ifdef 信号量与线程之间互斥

const int THREAD_NUM = 10;
HANDLE            ga, gb, gc;

unsigned int __stdcall FunA(void* pPM)
{
	Sleep(50);//some work should to do
	printf("A\n");
	ReleaseSemaphore(gb, 1, NULL);//释放信号量，递增信号量B的资源数	

	return 0;
}

unsigned int __stdcall FunB(void* pPM)
{
	Sleep(50);//some work should to do
	printf("B\n");
	ReleaseSemaphore(gc, 1, NULL);//释放信号量，递增信号量C的资源数	

	return 0;
}

unsigned int __stdcall FunC(void* pPM)
{
	Sleep(50);//some work should to do
	printf("C\n");
	ReleaseSemaphore(ga, 1, NULL);//释放信号量，递增信号量A的资源数	

	return 0;
}

int main()
{
	//初始化信号量
	ga = CreateSemaphore(NULL, 1, 1, NULL);//当前1个资源，最大允许1个同时访问
	gb = CreateSemaphore(NULL, 0, 1, NULL);//当前0个资源，最大允许1个同时访问
	gc = CreateSemaphore(NULL, 0, 1, NULL);//当前0个资源，最大允许1个同时访问

	HANDLE  handle[THREAD_NUM];
	int i = 0;
	while (i < THREAD_NUM)
	{
		WaitForSingleObject(ga, INFINITE);  //等待信号量A>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunA, &i, 0, NULL);
		WaitForSingleObject(gb, INFINITE);  //等待信号量B>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunB, &i, 0, NULL);
		WaitForSingleObject(gc, INFINITE);  //等待信号量C>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunC, &i, 0, NULL);

		++i;
	}
	WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);//等待互斥量对象

	//销毁信号量
	CloseHandle(ga);
	CloseHandle(gb);
	CloseHandle(gc);
	for (i = 0; i < THREAD_NUM; i++)
		CloseHandle(handle[i]);
	return 0;
}
#endif

#ifdef 生产者与消费者
//1生产者 2消费者 4缓冲区  

//设置控制台输出颜色  
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}

const int END_PRODUCE_NUMBER = 8;   //生产产品个数  
const int BUFFER_SIZE = 4;          //缓冲区个数  
int g_Buffer[BUFFER_SIZE];          //缓冲池  
int g_i, g_j;
CRITICAL_SECTION g_cs;              //信号量与关键段  
HANDLE g_hSemaphoreBufferEmpty, g_hSemaphoreBufferFull;

//生产者线程函数  
unsigned int __stdcall ProducerThreadFun(PVOID pM)
{
	for (int i = 1; i <= END_PRODUCE_NUMBER; i++)
	{
		//等待有空的缓冲区出现，WaitForSingleObject函数用来检测hHandle事件的信号状态，在某一线程中调用该函数时，线程暂时挂起，如果在挂起的dwMilliseconds毫秒内，线程所等待的对象变为有信号状态，则该函数立即返回；如果超时时间已经到达dwMilliseconds毫秒，但hHandle所指向的对象还没有变成有信号状态，函数照样返回。参数dwMilliseconds有两个具有特殊意义的值：0和INFINITE。若为0，则该函数立即返回；若为INFINITE，则线程一直被挂起，直到hHandle所指向的对象变为有信号状态时为止。  
		WaitForSingleObject(g_hSemaphoreBufferEmpty, INFINITE);

		//互斥的访问缓冲区  
		EnterCriticalSection(&g_cs);
		g_Buffer[g_i] = i;
		printf("生产者在缓冲池第%d个缓冲区中投放数据%d\n", g_i, g_Buffer[g_i]);
		g_i = (g_i + 1) % BUFFER_SIZE;
		LeaveCriticalSection(&g_cs);

		//释放信号量，通知消费者有新数据了  
		ReleaseSemaphore(g_hSemaphoreBufferFull, 1, NULL);
	}
	printf("生产者完成任务，线程结束运行\n");
	return 0;
}

//消费者线程函数  
unsigned int __stdcall ConsumerThreadFun(PVOID pM)
{
	while (true)
	{
		//等待非空的缓冲区出现  
		WaitForSingleObject(g_hSemaphoreBufferFull, INFINITE);

		//互斥的访问缓冲区  
		EnterCriticalSection(&g_cs);//进入临界区

		//打印消费者记录
		SetConsoleColor(FOREGROUND_GREEN);
		printf("  编号为 [%d] 的消费者从缓冲池中第%d个缓冲区取出数据%d\n", GetCurrentThreadId(), g_j, g_Buffer[g_j]);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		//判断是否结束
		if (g_Buffer[g_j] == END_PRODUCE_NUMBER)
		{
			LeaveCriticalSection(&g_cs);//离开临界区
			ReleaseSemaphore(g_hSemaphoreBufferFull, 1, NULL);//释放信号量，通知其它消费者有新数据了(结束标志)              
			break;
		}
		g_j = (g_j + 1) % BUFFER_SIZE;

		//离开临界区，然后释放信号量
		LeaveCriticalSection(&g_cs);//离开临界区
		Sleep(50); //some other work to do  
		ReleaseSemaphore(g_hSemaphoreBufferEmpty, 1, NULL);//释放信号量
	}
	SetConsoleColor(FOREGROUND_GREEN);
	printf("  编号为 [%d] 的消费者收到通知，线程结束运行\n", GetCurrentThreadId());
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return 0;
}

int main()
{
	InitializeCriticalSection(&g_cs);
	//初始化信号量,一个记录有产品的缓冲区个数,另一个记录空缓冲区个数.  
	g_hSemaphoreBufferEmpty = CreateSemaphore(NULL, 4, 4, NULL);
	g_hSemaphoreBufferFull = CreateSemaphore(NULL, 0, 4, NULL);
	g_i = 0;
	g_j = 0;
	memset(g_Buffer, 0, sizeof(g_Buffer));

	const int THREADNUM = 3;
	HANDLE hThread[THREADNUM];
	//生产者线程  
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, ProducerThreadFun, NULL, 0, NULL);
	//消费者线程  
	hThread[1] = (HANDLE)_beginthreadex(NULL, 0, ConsumerThreadFun, NULL, 0, NULL);
	hThread[2] = (HANDLE)_beginthreadex(NULL, 0, ConsumerThreadFun, NULL, 0, NULL);
	WaitForMultipleObjects(THREADNUM, hThread, TRUE, INFINITE);

	//关闭线程句柄
	for (int i = 0; i < THREADNUM; i++)
	{
		CloseHandle(hThread[i]);
	}

	//销毁信号量和关键段  
	CloseHandle(g_hSemaphoreBufferEmpty);
	CloseHandle(g_hSemaphoreBufferFull);
	DeleteCriticalSection(&g_cs);
	return 0;
}
#endif

#ifdef 读写者
//设置控制台输出颜色  
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(hConsole, wAttributes);
}
const int READER_NUM = 5;  //读者个数  
//关键段和事件  
CRITICAL_SECTION g_cs, g_cs_writer_count;
HANDLE g_hEventWriter, g_hEventNoReader;
int g_nReaderCount;
//读者线程输出函数(变参函数的实现)  
void ReaderPrintf(const char* pszFormat, ...)
{
	va_list   pArgList;

	va_start(pArgList, pszFormat);
	EnterCriticalSection(&g_cs);
	vfprintf(stdout, pszFormat, pArgList);
	LeaveCriticalSection(&g_cs);
	va_end(pArgList);
}
//读者线程函数  
unsigned int __stdcall ReaderThreadFun(PVOID pM)
{
	ReaderPrintf("     编号为%d的读者进入等待中...\n", GetCurrentThreadId());
	//等待写者完成  
	WaitForSingleObject(g_hEventWriter, INFINITE);

	//读者个数增加  
	EnterCriticalSection(&g_cs_writer_count);
	g_nReaderCount++;
	if (g_nReaderCount == 1)
		ResetEvent(g_hEventNoReader);
	LeaveCriticalSection(&g_cs_writer_count);

	//读取文件  
	ReaderPrintf("编号为%d的读者开始读取文件...\n", GetCurrentThreadId());

	Sleep(rand() % 100);

	//结束阅读,读者个数减小,空位增加  
	ReaderPrintf(" 编号为%d的读者结束读取文件\n", GetCurrentThreadId());

	//读者个数减少  
	EnterCriticalSection(&g_cs_writer_count);
	g_nReaderCount--;
	if (g_nReaderCount == 0)
		SetEvent(g_hEventNoReader);
	LeaveCriticalSection(&g_cs_writer_count);

	return 0;
}
//写者线程输出函数  
void WriterPrintf(const char* pszStr)
{
	EnterCriticalSection(&g_cs);
	SetConsoleColor(FOREGROUND_GREEN);
	printf("     %s\n", pszStr);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	LeaveCriticalSection(&g_cs);
}
//写者线程函数  
unsigned int __stdcall WriterThreadFun(PVOID pM)
{
	WriterPrintf("写者线程进入等待中...");
	//等待读文件的读者为零  
	WaitForSingleObject(g_hEventNoReader, INFINITE);
	//标记写者正在写文件  
	ResetEvent(g_hEventWriter);

	//写文件  
	WriterPrintf("  写者开始写文件.....");
	Sleep(rand() % 100);
	WriterPrintf("  写者结束写文件");

	//标记写者结束写文件  
	SetEvent(g_hEventWriter);
	return 0;
}

int main()
{
	//printf("  读者写者问题\n");
	//printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

	//初始化事件和信号量  
	InitializeCriticalSection(&g_cs);
	InitializeCriticalSection(&g_cs_writer_count);

	//手动置位,初始已触发  
	g_hEventWriter = CreateEvent(NULL, TRUE, TRUE, NULL);
	g_hEventNoReader = CreateEvent(NULL, FALSE, TRUE, NULL);
	g_nReaderCount = 0;

	int i;
	HANDLE hThread[READER_NUM + 1];
	//先启动二个读者线程  
	for (i = 1; i <= 2; i++)
	{
		hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	}

	//启动写者线程  
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, WriterThreadFun, NULL, 0, NULL);
	Sleep(50);

	//最后启动其它读者结程  
	for (; i <= READER_NUM; i++)
	{
		hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	}

	WaitForMultipleObjects(READER_NUM + 1, hThread, TRUE, INFINITE);
	for (i = 0; i < READER_NUM + 1; i++)
	{
		CloseHandle(hThread[i]);
	}

	//销毁事件和信号量  
	CloseHandle(g_hEventWriter);
	CloseHandle(g_hEventNoReader);
	DeleteCriticalSection(&g_cs);
	DeleteCriticalSection(&g_cs_writer_count);

	getchar();
	return 0;
}
#endif
