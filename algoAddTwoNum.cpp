#include <iostream>
using namespace std;

#ifdef Knowledge Points
//哑节点（dummy Node）是一个被人为创建的节点，虽然其内容为NULL，但是它在堆中有占有一定的空间。哑节点的使用可以避免边界问题的处理，达到简化代码与减少代码出错可能性的目的。
#endif

//定义结构体
struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {};
};

template<class T>
int length(T& arr)
{
	return sizeof(arr) / sizeof(arr[0]);
	//return end(arr) - begin(arr);
}

//两数相加
class Solution {
public:
	void printList(ListNode* pHead)
	{
		ListNode* pTraverse = pHead;

		//判断首个节点
		if (!pTraverse)
		{
			return;
		}
		else
		{
			cout << pTraverse->val;
		}

		//其他节点
		while (pTraverse->next != NULL)
		{
			cout << "->";
			pTraverse = pTraverse->next;
			cout << pTraverse->val;
		}
		cout << endl;
	}

	ListNode* creatList()
	{
		ListNode* pNode = new ListNode(0);
		pNode->next = NULL;
		ListNode* pHead = pNode;
		for (int i = 1; i < 5; i++)
		{
			ListNode* pTemp = new ListNode(i);
			pNode->next = pTemp;
			pNode = pTemp;
		}
		return pHead;
	}

	ListNode* createList_array(int* arr, int arrlen) {
		ListNode* root = new ListNode();
		ListNode* pnode = root;//链表赋值

		for (int i = 0; i < arrlen - 1; ++i) {
			root->val = arr[i];//当前节点
			root->next = NULL;

			ListNode* p = new ListNode();//下一个结点
			p->val = arr[i + 1];
			p->next = NULL;

			root->next = p;// 连接 当前节点 与 下一个结点
			root = root->next;
		}
		//root->next = NULL;//这一句 最重要！！
		return pnode;//返回链表
	}

	ListNode* cloneList(ListNode* pHead)
	{
		ListNode* pNode = pHead;                   //获取待克隆链表头
		ListNode* pCloneHead = NULL, * pCloneNode = NULL;
		if (pNode)                                 //条件：待克隆链表非空
		{
			pCloneNode = new ListNode(pNode->val); //获取首个节点值
			pCloneNode->next = NULL;
			pCloneHead = pCloneNode;               //克隆链表头
			pNode = pNode->next;                   //待克隆链表第二个节点
		}
		while (pNode)							   //条件：待克隆链表后续节点非空
		{
			ListNode* pTemp = new ListNode(pNode->val); //临时节点值(首次循环获取的是第二个节点值)
			pCloneNode->next = pTemp;			        //克隆链表的每个节点赋值
			pCloneNode = pTemp;                         //更新克隆链表指针
			pCloneNode->next = NULL;                    //初始化下一个节点为空
			pNode = pNode->next;                        //指向下一个节点
		}
		return pCloneHead;
	}

	/*
	时间复杂度：O(max(m,n))，其中 m,n 为两个链表的长度。我们要遍历两个链表的全部位置，而处理每个位置只需要 O(1) 的时间。
	空间复杂度：O(max(m,n))，答案链表的长度最多为较长链表的长度 +1。
	*/
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int nodeSum = 0;        //临时节点值(num1 + num2 + carry)
		int nodeDigit = 0;      //最终节点值
		int nodeCarryDigit = 0; //进位数
		ListNode* pTemp = new ListNode(0); //创建临时链表，只有一个节点(哑节点)且值为"0"
		ListNode* pNewListNode = pTemp;    //创建新的头节点，相当于哑节点的头一个节点

		while (l1 || l2 || nodeCarryDigit)
		{
			nodeSum = 0;
			if (l1)                   //条件：l1非空
			{
				nodeSum += l1->val;
				l1 = l1->next;		  //获取l1的下一个节点值
			}
			if (l2)					  //条件：l2非空
			{
				nodeSum += l2->val;
				l2 = l2->next;        //获取l2的下一个节点值
			}
			nodeSum += nodeCarryDigit;
			nodeDigit = nodeSum % 10;
			nodeCarryDigit = nodeSum / 10;

			ListNode* tempNode = new ListNode(nodeDigit); //获取每个最终节点值
			pNewListNode->next = tempNode;                //赋值(此处从第二个节点处开始赋值)
			pNewListNode = pNewListNode->next;            //指向下一个节点
		}

		pNewListNode = pTemp->next; //指向哑节点的后一个节点
		delete pTemp;               //删除哑节点
		return pNewListNode;        //返回新的头节点，即结果链表
	}
};


#ifndef main
int main(int argc, char* argv[])
{
	Solution s;
	int arr0[] = { 2, 4, 3, 1 };
	int arr1[] = { 5, 6, 6 };

	//加数1
	ListNode* p1 = s.createList_array(arr0, length(arr0));
	s.printList(p1);

	//加数2
	ListNode* p2 = s.createList_array(arr1, length(arr1));
	s.printList(p2);

	//结果
	ListNode* p3 = s.addTwoNumbers(p1, p2);
	s.printList(p3);

	system("pause");
	return 0;
}
#endif
