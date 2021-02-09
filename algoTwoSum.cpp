#include <iostream>
#include <unordered_map>
#include <random>
using namespace std;

#ifdef Knowledge Points
//unorder_map 和 map 内部实现机理不同
map：内部实现了一个红黑树（红黑树是非严格平衡二叉搜索树，而AVL是严格平衡二叉搜索树），红黑树具有自动排序的功能，因此map内部的所有元素都是有序的，红黑树的每一个节点都代表着map的一个元素。因此，对于map进行的查找，删除，添加等一系列的操作都相当于是对红黑树进行的操作。map中的元素是按照二叉搜索树（又名二叉查找树、二叉排序树，特点就是左子树上所有节点的键值都小于根节点的键值，右子树所有节点的键值都大于根节点的键值）存储的，使用“中序遍历”可将键值按照从小到大遍历出来。
unordered_map：内部实现了一个哈希表（也叫散列表，通过把关键码值映射到Hash表中一个位置来访问记录，查找的时间复杂度可达到O(1)，其在海量数据处理中有着广泛应用）。因此，其元素的排列顺序是无序的。哈希表详细介绍

//map优缺点：
map优点：1、有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作；2、红黑树，内部实现一个红黑书使得map的很多操作在lgn的时间复杂度下就可以实现，因此效率非常的高。
map缺点：空间占用率高，因为map内部实现了红黑树，虽然提高了运行效率，但是因为每一个节点都需要额外保存父节点、孩子节点和红 / 黑性质，使得每一个节点都占用大量的空间。
适用处：对于那些有顺序要求的问题，用map会更高效一些。

//unordered_map优缺点：
unordered_map优点：因为内部实现了哈希表，因此其查找速度非常的快
unordered_map缺点：哈希表的建立比较耗费时间
适用处 : 对于查找问题，unordered_map会更加高效一些，因此遇到查找问题，常会考虑一下用unordered_map

//总结:
1、内存占有率的问题就转化成红黑树 VS hash表, 还是unorder_map占用的内存要高；但是unordered_map执行效率要比map高很多。
2、对于unordered_map或unordered_set容器，其遍历顺序与创建该容器时输入的顺序不一定相同，因为遍历是按照哈希表从前往后依次遍历的
3、map和unordered_map的使用，unordered_map的用法和map是一样的，提供了 insert，size，count等操作，并且里面的元素也是以pair类型来存贮的。其底层实现是完全不同的，上方已经解释了，但是就外部使用来说却是一致的。
#endif

//两数之和
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int iCount = nums.size();

		/*1、暴力枚举法
		时间复杂度：O(N^2)，其中 N 是数组中的元素数量。最坏情况下数组中任意两个数都要被匹配一次。
		空间复杂度：O(1)。
		✔新全最容易想到的方法是枚举数组中的每一个数 x，寻找数组中是否存在 target - x。
		✔当我们使用遍历整个数组的方式寻找 target - x 时，需要注意到每一个位于 x 之前的元素都已经和 x 匹配过，因此不需要再进行匹配。而每一个元素不能被使用两次，所以我们只需要在 x 后面的元素中寻找 target - x。
		*/
		for (int i = 0; i < iCount; i++)          //前指针，循环次数=容器容量
		{
			for (int j = (i + 1); j < iCount; j++)//后指针，循环次数=容器容量-1
			{
				if (nums[i] + nums[j] == target)  //判断两数之和是否==目标值
				{
					return { i, j };
				}
			}
		}
		return {};

		/*2、哈希表法
		时间复杂度：O(N)，其中 N 是数组中的元素数量。对于每一个元素 x，我们可以 O(1) 地寻找 target - x。
		空间复杂度：O(N)，其中 N 是数组中的元素数量。主要为哈希表的开销。
		✔注意到方法一的时间复杂度较高的原因是寻找 target - x 的时间复杂度过高。因此，我们需要一种更优秀的方法，能够快速寻找数组中是否存在目标元素。如果存在，我们需要找出它的索引。
		✔使用哈希表，可以将寻找 target - x 的时间复杂度降低到从 O(N) 降低到 O(1)。
		✔对于每一个 x，我们首先查询哈希表中是否存在 target - x，然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配。
		*/
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); i++)
		{
			int iNum = nums[i];
			auto it = hashtable.find(target - iNum); //自动类型推断，此处为迭代器类型；查找是否包含另一个元素(加数)。
			if (it != hashtable.end())               //判断迭代器是否指向，unordered_map容器中容器中最后一个元素之后的位置。
			{
				return { it->second, i };
			}
			hashtable[iNum] = i; //没有匹配到元素，则加入hash表中
		}
		return {};

		//3、平衡二叉树
	}
};

#ifdef main
int main(int argc, char* argv[])
{
	Solution s;
	vector<int> nums = { 2, 15, 13, 5, 23, 10, 6, 7 };
	vector<int> vResult;

	vResult = s.twoSum(nums, 16);
	if (vResult.size() == 0 || vResult.empty() == true)
	{
		cout << "没有找到元素" << endl;
	}
	else
	{
		cout << "[" << vResult[0] << ", " << vResult[1] << "]" << endl;
	}

	system("pause");
	return 0;
}
#endif
