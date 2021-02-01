#include <iostream>
#include <unordered_map>
#include<Windows.h>
#include <random>
using namespace std;

//两数之和
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		DWORD start_time, end_time;
		int iCount = nums.size();

		//1、暴力枚举法
		/*
		1、最容易想到的方法是枚举数组中的每一个数 x，寻找数组中是否存在 target - x。
		2、当我们使用遍历整个数组的方式寻找 target - x 时，需要注意到每一个位于 x 之前的元素都已经和 x 匹配过，因此不需要再进行匹配。而每一个元素不能被使用两次，所以我们只需要在 x 后面的元素中寻找 target - x。
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

		//2、哈希表法
		/*
		1、注意到方法一的时间复杂度较高的原因是寻找 target - x 的时间复杂度过高。因此，我们需要一种更优秀的方法，能够快速寻找数组中是否存在目标元素。如果存在，我们需要找出它的索引。
		2、使用哈希表，可以将寻找 target - x 的时间复杂度降低到从 O(N)O(N) 降低到 O(1)O(1)。
		3、对于每一个 x，我们首先查询哈希表中是否存在 target - x，然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配。
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

		//3、平衡二叉树
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
		cout << "没有找到元素" << endl;
	}
	else
	{
		cout << "[" << vResult[0] << ", " << vResult[1] << "]" << endl;
	}

	return 0;
}

#ifdef unorder_map
//内部实现机理不同
map： map内部实现了一个红黑树（红黑树是非严格平衡二叉搜索树，而AVL是严格平衡二叉搜索树），红黑树具有自动排序的功能，因此map内部的所有元素都是有序的，红黑树的每一个节点都代表着map的一个元素。因此，对于map进行的查找，删除，添加等一系列的操作都相当于是对红黑树进行的操作。map中的元素是按照二叉搜索树（又名二叉查找树、二叉排序树，特点就是左子树上所有节点的键值都小于根节点的键值，右子树所有节点的键值都大于根节点的键值）存储的，使用中序遍历可将键值按照从小到大遍历出来。
unordered_map : unordered_map内部实现了一个哈希表（也叫散列表，通过把关键码值映射到Hash表中一个位置来访问记录，查找的时间复杂度可达到O(1)，其在海量数据处理中有着广泛应用）。因此，其元素的排列顺序是无序的。哈希表详细介绍

//优缺点以及适用处
map优点：
1、有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作；
2、红黑树，内部实现一个红黑书使得map的很多操作在lgn的时间复杂度下就可以实现，因此效率非常的高。
map缺点：
1、空间占用率高，因为map内部实现了红黑树，虽然提高了运行效率，但是因为每一个节点都需要额外保存父节点、孩子节点和红 / 黑性质，使得每一个节点都占用大量的空间。
适用处：对于那些有顺序要求的问题，用map会更高效一些。


unordered_map优点：
1、因为内部实现了哈希表，因此其查找速度非常的快
unordered_map缺点：
1、哈希表的建立比较耗费时间
适用处：对于查找问题，unordered_map会更加高效一些，因此遇到查找问题，常会考虑一下用unordered_map


总结：
1、内存占有率的问题就转化成红黑树 VS hash表, 还是unorder_map占用的内存要高；但是unordered_map执行效率要比map高很多。
2、对于unordered_map或unordered_set容器，其遍历顺序与创建该容器时输入的顺序不一定相同，因为遍历是按照哈希表从前往后依次遍历的
3、map和unordered_map的使用，unordered_map的用法和map是一样的，提供了 insert，size，count等操作，并且里面的元素也是以pair类型来存贮的。其底层实现是完全不同的，上方已经解释了，但是就外部使用来说却是一致的。
#endif