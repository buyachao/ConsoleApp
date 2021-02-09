#include <iostream>
using namespace std;

#ifdef Knowledge Points
//�ƽڵ㣨dummy Node����һ������Ϊ�����Ľڵ㣬��Ȼ������ΪNULL���������ڶ�����ռ��һ���Ŀռ䡣�ƽڵ��ʹ�ÿ��Ա���߽�����Ĵ����ﵽ�򻯴�������ٴ����������Ե�Ŀ�ġ�
#endif

//����ṹ��
struct ListNode {
	int val;
	ListNode* next;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {};
};

//�������
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int digit = 0;
        int carryDigit = 0;
        ListNode* res = new ListNode(0);
        ListNode* tmpRes = res;

        //carryDigitΪ��λ��
        while (l1 || l2 || carryDigit)
        {
            int tmpSum = 0;
            if (l1)
            {
                tmpSum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                tmpSum += l2->val;
                l2 = l2->next;
            }
            tmpSum += carryDigit;
            digit = tmpSum % 10;      //����
            carryDigit = tmpSum / 10; //��λ

            ListNode* newLocation = new ListNode(digit);
            tmpRes->next = newLocation;
            tmpRes = tmpRes->next;
        }

        //ɾ���ƽڵ�
        tmpRes = res->next;
        delete res;
        return tmpRes;
    }
};


#ifndef main
int main(int argc, char* argv[])
{
	
	system("pause");
	return 0;
}
#endif
