#include<iostream>
#include<stack>
#include<queue>
#include<cstdlib>
#include<ctime>
using namespace std;

/***********************************************************
*
*普通的树(多叉) 腾讯面试题-求最远的两个叶子节点间的距离
*
************************************************************/
typedef struct node
{
	int data;
	int child_num;
	node** childs;
}*tree;
int maxDiameter = 0;
int Diameter(tree t)
{
	if (t->child_num == 0)
		return 1;

	tree ptr = NULL;
	int max1 = 0, max2 = 0, tmp = 0;
	for (int i = 0; i < t->child_num; i++)
	{
		ptr = t->childs[i];

		if (ptr != NULL)
		{
			tmp = Diameter(ptr);

			if (max1 > max2 && tmp > max2)
				max2 = tmp;
			else if (max2 >= max1 && tmp > max1)
				max1 = tmp;

		}
	}
	if (max1 + max2 > maxDiameter)
	{
		maxDiameter = max1 + max2;
	}

	return (max1 > max2 ? max1 + 1 : max2 + 1);
}
//创建多叉树
void createTNode(tree* tnode)
{
	int tmp = 0;
	cin >> tmp;

	if (tmp > 0)
	{
		(*tnode) = (tree)malloc(sizeof(**tnode));

		(*tnode)->data = tmp;
		cout << tmp << "'s count of son\n";
		int icnt = 0;
		cin >> icnt;

		(*tnode)->child_num = icnt;
		(*tnode)->childs = (tree*)malloc(icnt * sizeof(tree));

		for (int i = 0; i < icnt; i++)
		{
			cout << tmp << "'s " << i << "st son\n";
			createTNode(&((*tnode)->childs[i]));
		}

	}
	else *tnode = NULL;

}
void DFSTraverse(tree node)
{
	cout << "\n----------Depth First Traverse--------------\n";

	stack<tree> stk;
	if (node)
		stk.push(node);
	else
		return;
	while (!stk.empty())
	{
		node = stk.top();
		stk.pop();
		cout << node->data << "\t";

		for (int i = node->child_num - 1; i >= 0; i--)
		{
			stk.push(node->childs[i]);
		}
	}
}
void BFSTraverse(tree node)
{
	cout << "\n----------Broad First Traverse--------------\n";

	queue<tree> que;
	if (node)
		que.push(node);
	else
		return;

	while (!que.empty())
	{
		node = que.front();
		que.pop();
		cout << node->data << "\t";

		for (int i = 0; i < node->child_num; i++)
		{
			que.push(node->childs[i]);
		}
	}

}


/***********************************************************
*
*二叉树 淘宝和网易的面试题
*
************************************************************/
typedef struct tnode
{
	int data;
	struct tnode* left;
	struct tnode* right;
} TreeNode;
int getLongestDist(TreeNode* node, int& maxDist)
{
	if (node->left == NULL && node->right == NULL)
		return 1;

	int leftlen = 0, rightlen = 0;

	if (node->left != NULL)
	{
		leftlen = getLongestDist(node->left, maxDist);
		cout << node->data << "'s leftlen =" << leftlen << " maxDist=" << maxDist << endl;
	}

	if (node->right != NULL)
	{
		rightlen = getLongestDist(node->right, maxDist);
		cout << node->data << "'s rightlen =" << rightlen << " maxDist=" << maxDist << endl;
	}

	if (leftlen + rightlen > maxDist)
	{
		maxDist = leftlen + rightlen;
		cout << "maxdist=" << maxDist << endl;
	}

	return (leftlen > rightlen ? leftlen + 1 : rightlen + 1);
}
//创建二叉树
void createBiTNode(TreeNode** tnode)
{
	//srand(clock());
	int tmp = 0;
	cin >> tmp;

	if (tmp > 0)
	{
		*tnode = new TreeNode;
		//(*tnode)->data=rand();
		//cin>>(*tnode)->data;
		//cout<<"n="<<n<<endl;
		(*tnode)->data = tmp;
		cout << tmp << "'s left\n";
		createBiTNode(&((*tnode)->left));
		cout << tmp << "'s right\n";
		createBiTNode(&((*tnode)->right));
	}
	else *tnode = NULL;

}
void preTraverse(TreeNode* tnode)
{
	cout << "\n----------Pre Order Traverse--------------\n";

	stack<TreeNode*> stk;

	while (tnode || !stk.empty())
	{
		if (tnode)
		{
			cout << tnode->data << "\t";
			stk.push(tnode);
			tnode = tnode->left;
		}
		else
		{
			tnode = stk.top();
			stk.pop();
			tnode = tnode->right;
		}

	}
	cout << "\n";
}
void midTraverse(TreeNode* tnode)
{
	cout << "\n----------In Order Traverse--------------\n";
	stack<TreeNode*> stk;
	while (tnode || !stk.empty())
	{
		if (tnode)
		{
			stk.push(tnode);
			tnode = tnode->left;
		}
		else
		{
			tnode = stk.top();
			cout << tnode->data << "\t";

			tnode = tnode->right;
			stk.pop();
		}
	}
	cout << "\n";
}

#ifdef main
int main(int argc, char** argv)
{
	//普通树
	{
		tree root = NULL;
		createTNode(&root);

		DFSTraverse(root);

		BFSTraverse(root);

		Diameter(root);

		cout << "\nmaxDiameter=" << maxDiameter << endl;

	}

	//二叉树
	{
		TreeNode* root = NULL;
		createBiTNode(&root);

		preTraverse(root);

		midTraverse(root);

		int maxdist = 0;
		getLongestDist(root, maxdist);

		cout << "\nmaxdist=" << maxdist << endl;
	}

	system("pause");
	return 0;
}
#endif