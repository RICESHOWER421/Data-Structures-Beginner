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

/*ǰ�����*/
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

/*�������*/
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

/*���������ʹ�ö���д��*/
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

/*�ж��Ƿ�Ϊ��ȫ������*/
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
/*����������Ľ�����������ȫ�ֱ��������ڶ��߳��о���һ��ȱ�ݣ�*/
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

/*��������������������Ž⣩*/
int TreeSize(LBT* tree)
{
	return tree == NULL ? 0 : TreeSize(tree->left) + TreeSize(tree->right) + 1; //��1�Ǽ��ϱ��㺯�������Լ��Ľ��
}

/*���������Ҷ�ӽ�����*/
int TreeLeafSize(LBT* tree)
{
	/*���������Ϊ�գ���ô�ͷ���0������������������ҽ�㶼��0����ô���������Ҷ�ӽ�㣬����1��������ǵĻ���ֱ�ӷ��ش�ʱ�����ֵ�����ҽ���ֵ���̳������������Ҷ�ӽ��ĸ���*/
	return tree == NULL ? 0 : (TreeLeafSize(tree->left) + TreeLeafSize(tree->right) == 0 ? 1 : TreeLeafSize(tree->left) + TreeLeafSize(tree->right));
}

/*������������н������ս��ĸ���*/
int TreeNullSize(LBT* tree)
{
	return tree == NULL ? 1 : TreeNullSize(tree->left) + TreeNullSize(tree->right) + 1;
}

/*�����������k����ĸ���*/
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


/*���ٶ�����*/
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

/*���Ҷ������е�ĳ��ֵ�Ľ��*/
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