#include <iostream>
#include <algorithm>
using namespace std;
//using std::cout;
//using std::endl;
//using std::cin;
//using std::max;
#pragma once

#ifdef Knowledge Points
https ://www.cnblogs.com/zhangbaochong/p/5164994.html 平衡二叉树详解
https://zhuanlan.zhihu.com/p/102040188 指针讲解：*&p和&*p
#endif

//平衡二叉树结点
template <typename T>
struct AvlNode
{
	T data;
	int height; //结点所在高度
	AvlNode<T>* left;
	AvlNode<T>* right;
	AvlNode<T>(const T theData) : data(theData), left(NULL), right(NULL), height(0) {}
};

//AvlTree
template <typename T>
class AvlTree
{
public:
	AvlTree<T>() {}
	~AvlTree<T>() {}
	AvlTree<T>* root;
	//插入结点
	void Insert(AvlNode<T>*& t, T x);
	//删除结点
	bool Delete(AvlNode<T>*& t, T x);
	//查找是否存在给定值的结点
	bool Contains(AvlNode<T>* t, const T x) const;
	//中序遍历
	void InorderTraversal(AvlNode<T>* t);
	//前序遍历
	void PreorderTraversal(AvlNode<T>* t);
	//最小值结点
	AvlNode<T>* FindMin(AvlNode<T>* t) const;
	//最大值结点
	AvlNode<T>* FindMax(AvlNode<T>* t) const;

private:
	//求树的高度
	int GetHeight(AvlNode<T>* t);
	//单旋转 左
	AvlNode<T>* LL(AvlNode<T>* t);
	//单旋转 右
	AvlNode<T>* RR(AvlNode<T>* t);
	//双旋转 右左
	AvlNode<T>* LR(AvlNode<T>* t);
	//双旋转 左右
	AvlNode<T>* RL(AvlNode<T>* t);
};

template <typename T>
AvlNode<T>* AvlTree<T>::FindMax(AvlNode<T>* t)const
{
	if (t == NULL)
		return NULL;
	else if (t->right == NULL)
		return t;
	else
		return FindMax(t->right);
}

template <typename T>
AvlNode<T>* AvlTree<T>::FindMin(AvlNode<T>* t) const
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return FindMin(t->left);
}

template <typename T>
int AvlTree<T>::GetHeight(AvlNode<T>* t)
{
	if (t == NULL)
	{
		return -1;
	}
	else
	{
		return t->height;
	}
}

//单旋转
//左左插入导致的不平衡
template <typename T>
AvlNode<T>* AvlTree<T>::LL(AvlNode<T>* t)
{
	AvlNode<T>* q = t->left; //q 为 t 的左子树
	t->left = q->right;
	q->right = t;
	t = q;
	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
	q->height = max(GetHeight(q->left), GetHeight(q->right)) + 1;

	return q;
}

//单旋转
//右右插入导致的不平衡
template <typename T>
AvlNode<T>* AvlTree<T>::RR(AvlNode<T>* t)
{
	AvlNode<T>* q = t->right; //q 为 t 的右子树
	t->right = q->left;
	q->left = t;
	t = q;
	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
	q->height = max(GetHeight(q->left), GetHeight(q->right)) + 1;
	
	return q;
}

//双旋转
//插入点位于t的左儿子的右子树
template <typename T>
AvlNode<T>* AvlTree<T>::LR(AvlNode<T>* t)
{
	//双旋转可以通过两次单旋转实现
	//对t的左结点进行RR旋转，再对根节点进行LL旋转
	RR(t->left);
	return LL(t);
}

//双旋转
//插入点位于t的右儿子的左子树
template <typename T>
AvlNode<T>* AvlTree<T>::RL(AvlNode<T>* t)
{
	//对t的右结点进行LL旋转，再对根节点进行RR旋转
	LL(t->right);
	return RR(t);
}

template <typename T>
void AvlTree<T>::Insert(AvlNode<T>*& t, T x)
{
	if (t == NULL)
		t = new AvlNode<T>(x);
	else if (x < t->data)
	{
		Insert(t->left, x);
		//判断平衡情况
		if (GetHeight(t->left) - GetHeight(t->right) > 1)
		{
			//存在两种情况，左左或左右
			if (x < t->left->data)
			{
				t = LL(t);
			}
			else
			{
				t = LR(t);
			}
		}
	}
	else if (x > t->data)
	{
		Insert(t->right, x);
		if (GetHeight(t->right) - GetHeight(t->left) > 1)
		{
			//存在两种情况，右右或右左
			if (x > t->right->data)
			{
				t = RR(t);
			}
			else
			{
				t = RL(t);
			}
		}
	}
	else
	{
		;//数据重复
	}

	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
}

template <typename T>
bool AvlTree<T>::Delete(AvlNode<T>*& t, T x)
{
	//t为空，未找到要删除的结点
	if (t == NULL)
	{
		return false;
	}
	else if (t->data == x) //找到了要删除的结点
	{
		//左右子树都非空
		if (t->left != NULL && t->right != NULL)
		{//在高度更高的那个子树上删除

			//左子树高度大，删除左子树中值最大的结点，将其赋给根结点
			if (GetHeight(t->left) > GetHeight(t->right))
			{
				t->data = FindMax(t->left)->data;
				Delete(t->left, t->data);
			}
			else //右子树高度大，删除右子树中值最小的结点，将其赋给根结点
			{
				t->data = FindMin(t->right)->data;
				Delete(t->right, t->data);
			}
		}
		else
		{//左右子树有一个非空，直接用需要删除的结点的子结点替换即可
			AvlNode<T>* old = t;
			t = t->left ? t->left : t->right;
			delete old;
		}
	}
	else if (x < t->data) //要删除的结点在左子树上
	{
		//递归删除左子树上的结点
		Delete(t->left, x);
		//判断是否人仍然满足平衡条件
		if (GetHeight(t->right) - GetHeight(t->left) > 1)
		{
			if (GetHeight(t->right->left) > GetHeight(t->right->right))
			{
				//RL双旋转
				t = RL(t);
			}
			else
			{
				//RR单旋转
				t = RR(t);
			}
		}
		else //满足平衡条件，调整高度
		{
			t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
		}
	}
	else //要删除的结点在右子树上
	{
		//递归删除右子树结点
		Delete(t->right, x);
		//判断平衡情况
		if (GetHeight(t->left) - GetHeight(t->right) > 1)
		{
			if (GetHeight(t->left->right) > GetHeight(t->left->left))
			{
				//LR双旋转
				t = LR(t);
			}
			else
			{
				//LL单旋转
				t = LL(t);
			}
		}
		else //满足平衡条件，调整高度
		{
			t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
		}
	}

	return true;
}

//查找结点
template <typename T>
bool AvlTree<T>::Contains(AvlNode<T>* t, const T x) const
{
	if (t == NULL)
	{
		return false;
	}

	if (x < t->data)
	{
		return Contains(t->left, x);
	}
	else if (x > t->data)
	{
		return Contains(t->right, x);
	}
	else
	{
		return true;
	}
}

//中序遍历
template <typename T>
void AvlTree<T>::InorderTraversal(AvlNode<T>* t)
{
	if (t)
	{
		InorderTraversal(t->left);
		cout << t->data << " ";
		InorderTraversal(t->right);
	}
}

//前序遍历
template <typename T>
void AvlTree<T>::PreorderTraversal(AvlNode<T>* t)
{
	if (t)
	{
		cout << t->data << " ";
		PreorderTraversal(t->left);
		PreorderTraversal(t->right);
	}
}


#ifndef main
int main(int argc, char* argv[])
{
	AvlTree<int> tree;
	int value = 0;
	int tmp = 0;
	cout << "请输入整数建立二叉树(-1结束)：" << endl;
	while (cin >> value)
	{
		if (value == -1)
		{
			break; 
		}
		else
		{
			tree.Insert((AvlNode<int>*&)tree.root, value);
		}
	}
	cout << "\n中序遍历：";
	tree.InorderTraversal((AvlNode<int>*&)tree.root);
	
	cout << "\n前序遍历：";
	tree.PreorderTraversal((AvlNode<int>*&)tree.root);
	
	cout << "\n请输入要查找的结点：";
	cin >> tmp;
	if (tree.Contains((AvlNode<int>*&)tree.root, tmp))
	{
		cout << "值为" << tmp << "已查找到" << endl;
	}
	else
	{
		cout << "值为" << tmp << "的结点不存在" << endl;
	}
	
	/*
	cout << "请输入要删除的结点：";
	cin >> tmp;
	tree.Delete((AvlNode<int>*&)tree.root, tmp);
	*/

	cout << "\n删除后的中序遍历：";
	tree.InorderTraversal((AvlNode<int>*&)tree.root);
	
	cout << "\n删除后的前序遍历：";
	tree.PreorderTraversal((AvlNode<int>*&)tree.root);
	
	system("pause");
	return 0;
}
#endif