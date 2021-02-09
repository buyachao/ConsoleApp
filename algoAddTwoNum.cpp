#include <iostream>
using namespace std;

#ifdef Knowledge Points
//哑节点（dummy Node）是一个被人为创建的节点，虽然其内容为NULL，但是它在堆中有占有一定的空间。哑节点的使用可以避免边界问题的处理，达到简化代码与减少代码出错可能性的目的。
#endif

//定义结构体
struct ListNode {
	int val;
	ListNode* next;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {};
};

//两数相加
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int digit = 0;
        int carryDigit = 0;
        ListNode* res = new ListNode(0);
        ListNode* tmpRes = res;

        //carryDigit为进位数
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
            digit = tmpSum % 10;      //数字
            carryDigit = tmpSum / 10; //进位

            ListNode* newLocation = new ListNode(digit);
            tmpRes->next = newLocation;
            tmpRes = tmpRes->next;
        }

        //删除哑节点
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
