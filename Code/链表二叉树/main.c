#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListBinaryTree
{
	int val;
	struct ListBinaryTree* left;
	struct ListBinaryTree* right;
}LBT;

#include "Queue.h"

LBT* InitTree(int num)
{
	LBT* temp = (LBT*)malloc(sizeof(LBT));
	temp->val = num;
	temp->left = temp->right = NULL;
}

/*前序遍历*/
void PrevOrder(LBT* tree)
{
	if (tree == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%d ",tree->val);
	PrevOrder(tree->left);
	PrevOrder(tree->right);
}

/*中序遍历*/
void MidOrder(LBT* tree)
{

	if (tree == NULL)
	{
		printf("NULL ");
		return;
	}

	MidOrder(tree->left);
	printf("%d ", tree->val);
	MidOrder(tree->right);
}

/*层序遍历（使用队列写）*/
void LevelOrder(LBT* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		LBT* front = QueueFront(&q);
		printf("%d", front->val);
		
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
		QueuePop(&q);
	}

	QueueDestroy(&q);
}

/*判断是否为完全二叉树*/
bool IsTreeComplete(LBT* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		LBT* front = QueueFront(&q);
		if (front == NULL)
			break;

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		QueuePop(&q);
	}

	while (!QueueEmpty(&q))
	{
		LBT* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
		{
			/*QueueDestroy(&q);*/
			return false;
		}
	}

	/*QueueDestroy(&q);*/
	return true;

}
/*计算二叉树的结点个数（开辟全局变量法，在多线程中具有一定缺陷）*/
//int size = 0;
//int TreeSize(LBT* tree)
//{
//	if (tree == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		++size;
//	}
//
//	TreeSize(tree->left);
//	TreeSize(tree->right);
//	return size;
//}

/*计算二叉树结点个数（最优解）*/
int TreeSize(LBT* tree)
{
	return tree == NULL ? 0 : TreeSize(tree->left) + TreeSize(tree->right) + 1; //加1是加上本层函数调用自己的结点
}

/*计算二叉树叶子结点个数*/
int TreeLeafSize(LBT* tree)
{
	/*如果这个结点为空，那么就返回0，如果这个结点的左结点和右结点都是0，那么这个结点就是叶子结点，返回1，如果不是的话则直接返回此时左结点的值加上右结点的值，继承下面结点的所含叶子结点的个数*/
	return tree == NULL ? 0 : (TreeLeafSize(tree->left) + TreeLeafSize(tree->right) == 0 ? 1 : TreeLeafSize(tree->left) + TreeLeafSize(tree->right));
}

/*计算二叉树所有结点包括空结点的个数*/
int TreeNullSize(LBT* tree)
{
	return tree == NULL ? 1 : TreeNullSize(tree->left) + TreeNullSize(tree->right) + 1;
}

/*计算二叉树第k层结点的个数*/
int TreeKLevel(LBT* tree, int k)
{
	assert(k > 0);

	if (tree == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return TreeKLevel(tree->left, k - 1) + TreeKLevel(tree->right, k - 1);
}


/*销毁二叉树*/
void TreeDestroy(LBT* tree)
{
	if (tree == NULL)
	{
		return;
	}

	TreeDestroy(tree->left);
	TreeDestroy(tree->right);
	free(tree);
}

/*查找二叉树中的某个值的结点*/
LBT* TreeFind(LBT* tree, int x)
{
	if (tree == NULL)
	{
		return NULL;
	}
	if (tree->val == x)
	{
		return tree;
	}

	LBT* temp = NULL;
	temp = TreeFind(tree->left, x);
	if (temp != NULL)
	{
		return temp;
	}
	temp = TreeFind(tree->right, x);
	if (temp != NULL)
	{
		return temp;
	}

	return NULL;
}

void Test01()
{
	LBT* tree_1 = InitTree(1);
	LBT* tree_2 = InitTree(2);
	LBT* tree_3 = InitTree(2);
	LBT* tree_4 = InitTree(3);
	LBT* tree_5 = InitTree(3);
	LBT* tree_6 = InitTree(4);
	LBT* tree_7 = InitTree(4);

	tree_1->left = tree_2;
	tree_1->right = tree_3;
	tree_2->left = tree_4;
	tree_2->right = tree_5;
	tree_3->left = tree_6;
	tree_3->right = tree_7;
	/*LBT* temp = TreeFind(tree_1, 7);
	printf("%d\n", temp->val);*/
}

int main()
{
	Test01();
	return 0;
}