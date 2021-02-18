#include <iostream>
using namespace std;

#ifdef Knowledge Points
//�ƽڵ㣨dummy Node����һ������Ϊ�����Ľڵ㣬��Ȼ������ΪNULL���������ڶ�����ռ��һ���Ŀռ䡣�ƽڵ��ʹ�ÿ��Ա���߽�����Ĵ����ﵽ�򻯴�������ٴ����������Ե�Ŀ�ġ�
#endif

//����ṹ��
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

//�������
class Solution {
public:
	void printList(ListNode* pHead)
	{
		ListNode* pTraverse = pHead;

		//�ж��׸��ڵ�
		if (!pTraverse)
		{
			return;
		}
		else
		{
			cout << pTraverse->val;
		}

		//�����ڵ�
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
		ListNode* pnode = root;//����ֵ

		for (int i = 0; i < arrlen - 1; ++i) {
			root->val = arr[i];//��ǰ�ڵ�
			root->next = NULL;

			ListNode* p = new ListNode();//��һ�����
			p->val = arr[i + 1];
			p->next = NULL;

			root->next = p;// ���� ��ǰ�ڵ� �� ��һ�����
			root = root->next;
		}
		//root->next = NULL;//��һ�� ����Ҫ����
		return pnode;//��������
	}

	ListNode* cloneList(ListNode* pHead)
	{
		ListNode* pNode = pHead;                   //��ȡ����¡����ͷ
		ListNode* pCloneHead = NULL, * pCloneNode = NULL;
		if (pNode)                                 //����������¡����ǿ�
		{
			pCloneNode = new ListNode(pNode->val); //��ȡ�׸��ڵ�ֵ
			pCloneNode->next = NULL;
			pCloneHead = pCloneNode;               //��¡����ͷ
			pNode = pNode->next;                   //����¡����ڶ����ڵ�
		}
		while (pNode)							   //����������¡��������ڵ�ǿ�
		{
			ListNode* pTemp = new ListNode(pNode->val); //��ʱ�ڵ�ֵ(�״�ѭ����ȡ���ǵڶ����ڵ�ֵ)
			pCloneNode->next = pTemp;			        //��¡�����ÿ���ڵ㸳ֵ
			pCloneNode = pTemp;                         //���¿�¡����ָ��
			pCloneNode->next = NULL;                    //��ʼ����һ���ڵ�Ϊ��
			pNode = pNode->next;                        //ָ����һ���ڵ�
		}
		return pCloneHead;
	}

	/*
	ʱ�临�Ӷȣ�O(max(m,n))������ m,n Ϊ��������ĳ��ȡ�����Ҫ�������������ȫ��λ�ã�������ÿ��λ��ֻ��Ҫ O(1) ��ʱ�䡣
	�ռ临�Ӷȣ�O(max(m,n))��������ĳ������Ϊ�ϳ�����ĳ��� +1��
	*/
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int nodeSum = 0;        //��ʱ�ڵ�ֵ(num1 + num2 + carry)
		int nodeDigit = 0;      //���սڵ�ֵ
		int nodeCarryDigit = 0; //��λ��
		ListNode* pTemp = new ListNode(0); //������ʱ����ֻ��һ���ڵ�(�ƽڵ�)��ֵΪ"0"
		ListNode* pNewListNode = pTemp;    //�����µ�ͷ�ڵ㣬�൱���ƽڵ��ͷһ���ڵ�

		while (l1 || l2 || nodeCarryDigit)
		{
			nodeSum = 0;
			if (l1)                   //������l1�ǿ�
			{
				nodeSum += l1->val;
				l1 = l1->next;		  //��ȡl1����һ���ڵ�ֵ
			}
			if (l2)					  //������l2�ǿ�
			{
				nodeSum += l2->val;
				l2 = l2->next;        //��ȡl2����һ���ڵ�ֵ
			}
			nodeSum += nodeCarryDigit;
			nodeDigit = nodeSum % 10;
			nodeCarryDigit = nodeSum / 10;

			ListNode* tempNode = new ListNode(nodeDigit); //��ȡÿ�����սڵ�ֵ
			pNewListNode->next = tempNode;                //��ֵ(�˴��ӵڶ����ڵ㴦��ʼ��ֵ)
			pNewListNode = pNewListNode->next;            //ָ����һ���ڵ�
		}

		pNewListNode = pTemp->next; //ָ���ƽڵ�ĺ�һ���ڵ�
		delete pTemp;               //ɾ���ƽڵ�
		return pNewListNode;        //�����µ�ͷ�ڵ㣬���������
	}
};


#ifndef main
int main(int argc, char* argv[])
{
	Solution s;
	int arr0[] = { 2, 4, 3, 1 };
	int arr1[] = { 5, 6, 6 };

	//����1
	ListNode* p1 = s.createList_array(arr0, length(arr0));
	s.printList(p1);

	//����2
	ListNode* p2 = s.createList_array(arr1, length(arr1));
	s.printList(p2);

	//���
	ListNode* p3 = s.addTwoNumbers(p1, p2);
	s.printList(p3);

	system("pause");
	return 0;
}
#endif
