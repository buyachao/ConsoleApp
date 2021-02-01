#include <iostream>
#include <unordered_map>
#include<Windows.h>
#include <random>
using namespace std;

//����֮��
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		DWORD start_time, end_time;
		int iCount = nums.size();

		//1������ö�ٷ�
		/*
		1���������뵽�ķ�����ö�������е�ÿһ���� x��Ѱ���������Ƿ���� target - x��
		2��������ʹ�ñ�����������ķ�ʽѰ�� target - x ʱ����Ҫע�⵽ÿһ��λ�� x ֮ǰ��Ԫ�ض��Ѿ��� x ƥ�������˲���Ҫ�ٽ���ƥ�䡣��ÿһ��Ԫ�ز��ܱ�ʹ�����Σ���������ֻ��Ҫ�� x �����Ԫ����Ѱ�� target - x��
		*/
		start_time = GetTickCount();
		for (int i = 1; i < iCount; i++)
		{
			for (int j = (i + 1); j < iCount; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					end_time = GetTickCount();
					cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;
					return { i, j };
				}
			}
		}
		return {};

		//2����ϣ��
		/*
		1��ע�⵽����һ��ʱ�临�ӶȽϸߵ�ԭ����Ѱ�� target - x ��ʱ�临�Ӷȹ��ߡ���ˣ�������Ҫһ�ָ�����ķ������ܹ�����Ѱ���������Ƿ����Ŀ��Ԫ�ء�������ڣ�������Ҫ�ҳ�����������
		2��ʹ�ù�ϣ�����Խ�Ѱ�� target - x ��ʱ�临�ӶȽ��͵��� O(N)O(N) ���͵� O(1)O(1)��
		3������ÿһ�� x���������Ȳ�ѯ��ϣ�����Ƿ���� target - x��Ȼ�� x ���뵽��ϣ���У����ɱ�֤������ x ���Լ�ƥ�䡣
		*/
		unordered_map<int, int> hashtable;
		start_time = GetTickCount();
		for (int i = 0; i < nums.size(); i++)
		{
			int iNum = nums[i];
			auto it = hashtable.find(target - iNum);
			if (it != hashtable.end())
			{
				end_time = GetTickCount();
				cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;
				return { it->second, i };
				cout << "[" << nums[i] << ", " << nums[it->second] <<"]"<< endl;
			}
			hashtable[iNum] = i;
		}
		return {};

		//3��ƽ�������
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	vector<int> nums; //= { 2, 15, 11, 7 }
	vector<int> vResult;
	for (int i = 0; i < 65536; i++)
	{
		nums.push_back(i);
	}

	vResult = s.twoSum(nums, 55362);
	if (vResult.size() == 0 || vResult.empty() == true)
	{
		cout << "û���ҵ�Ԫ��" << endl;
	}
	else
	{
		cout << "[" << vResult[0] << ", " << vResult[1] << "]" << endl;
	}

	return 0;
}

#ifdef unorder_map
//�ڲ�ʵ�ֻ���ͬ
map�� map�ڲ�ʵ����һ���������������Ƿ��ϸ�ƽ���������������AVL���ϸ�ƽ�������������������������Զ�����Ĺ��ܣ����map�ڲ�������Ԫ�ض�������ģ��������ÿһ���ڵ㶼������map��һ��Ԫ�ء���ˣ�����map���еĲ��ң�ɾ������ӵ�һϵ�еĲ������൱���ǶԺ�������еĲ�����map�е�Ԫ���ǰ��ն���������������������������������������ص���������������нڵ�ļ�ֵ��С�ڸ��ڵ�ļ�ֵ�����������нڵ�ļ�ֵ�����ڸ��ڵ�ļ�ֵ���洢�ģ�ʹ����������ɽ���ֵ���մ�С�������������
unordered_map : unordered_map�ڲ�ʵ����һ����ϣ��Ҳ��ɢ�б�ͨ���ѹؼ���ֵӳ�䵽Hash����һ��λ�������ʼ�¼�����ҵ�ʱ�临�ӶȿɴﵽO(1)�����ں������ݴ��������Ź㷺Ӧ�ã�����ˣ���Ԫ�ص�����˳��������ġ���ϣ����ϸ����

//��ȱ���Լ����ô�
map�ŵ㣺
1�������ԣ�����map�ṹ�����ŵ㣬��Ԫ�ص��������ںܶ�Ӧ���ж���򻯺ܶ�Ĳ�����
2����������ڲ�ʵ��һ�������ʹ��map�ĺܶ������lgn��ʱ�临�Ӷ��¾Ϳ���ʵ�֣����Ч�ʷǳ��ĸߡ�
mapȱ�㣺
1���ռ�ռ���ʸߣ���Ϊmap�ڲ�ʵ���˺��������Ȼ���������Ч�ʣ�������Ϊÿһ���ڵ㶼��Ҫ���Ᵽ�游�ڵ㡢���ӽڵ�ͺ� / �����ʣ�ʹ��ÿһ���ڵ㶼ռ�ô����Ŀռ䡣
���ô���������Щ��˳��Ҫ������⣬��map�����ЧһЩ��


unordered_map�ŵ㣺
1����Ϊ�ڲ�ʵ���˹�ϣ�����������ٶȷǳ��Ŀ�
unordered_mapȱ�㣺
1����ϣ��Ľ����ȽϺķ�ʱ��
���ô������ڲ������⣬unordered_map����Ӹ�ЧһЩ����������������⣬���ῼ��һ����unordered_map


�ܽ᣺
1���ڴ�ռ���ʵ������ת���ɺ���� VS hash��, ����unorder_mapռ�õ��ڴ�Ҫ�ߣ�����unordered_mapִ��Ч��Ҫ��map�ߺܶࡣ
2������unordered_map��unordered_set�����������˳���봴��������ʱ�����˳��һ����ͬ����Ϊ�����ǰ��չ�ϣ���ǰ�������α�����
3��map��unordered_map��ʹ�ã�unordered_map���÷���map��һ���ģ��ṩ�� insert��size��count�Ȳ��������������Ԫ��Ҳ����pair�����������ġ���ײ�ʵ������ȫ��ͬ�ģ��Ϸ��Ѿ������ˣ����Ǿ��ⲿʹ����˵ȴ��һ�µġ�
#endif