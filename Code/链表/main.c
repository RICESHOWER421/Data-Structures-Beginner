#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
#include "DList.h"

void Test01()
{
	SLT* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SLT* temp = SListValMAX(plist);
	printf("%d", temp->date);

}

void Test02()
{
	SLT* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 2);
	SLT* pos = SListFind(plist, 1);
	SListInsert(&plist, pos, 30);
	SListPrint(plist);
	SListErase(&plist, pos);
	SListPrint(plist);
	/*int i = 1;
	while (pos)
	{
		printf("第%d个：%p->%d\n",i++,pos,pos->date);
		pos = SListFind(pos->next, 2);
	}*/
}

void Test03()
{
	SLT* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListDestory(&plist);
	SListPrint(plist);

}
//int main()
//{
//	Test03();
//	return 0;
//}
 
//void Test01()
//{
//	DLT* plist = ListInit();
//	ListPushBack(plist, 4);
//	ListPushBack(plist, 3);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 1);
//	ListPrint(plist);
//	ListPushFront(plist);
//	ListPrint(plist);
//	ListPushFront(plist);
//	ListPrint(plist);
//	ListPushFront(plist);
//	ListPrint(plist);
//}
//
//void Test02()
//{
//	DLT* plist = ListInit();
//	ListPopBack(plist, 4);
//	ListPopBack(plist, 3);
//	ListPopBack(plist, 2);
//	ListPopBack(plist, 1);
//	ListPrint(plist);
//}
//
//void Test03()
//{
//	DLT* plist = ListInit();
//	ListPopBack(plist, 4);
//	ListPopBack(plist, 3);
//	ListPopBack(plist, 2);
//	DLT* cur = ListFind(plist, 3);
//	if (cur != NULL)
//	{
//		printf("找到了，节点地址为%p\n", cur);
//	}
//	else
//	{
//		printf("没找到\n");
//	}
//}
//
//void Test04()
//{
//	DLT* plist = ListInit();
//	ListPopBack(plist, 4);
//	ListPopBack(plist, 3);
//	ListPopBack(plist, 2);
//	DLT* cur = ListFind(plist, 3);
//	ListErase(cur);
//	ListPrint(plist);
//}
//
//void Test05()
//{
//	DLT* plist = ListInit();
//	ListPopBack(plist, 4);
//	ListPopBack(plist, 3);
//	ListPopBack(plist, 2);
//	DLT* cur = ListFind(plist, 3);
//	ListInsert(cur, 1);
//	ListPrint(plist);
//}
//
//void Test06()
//{ 
//	DLT* plist = ListInit();
//	ListPopBack(plist, 4);
//	ListPopBack(plist, 3);
//	ListPopBack(plist, 2);
//	ListPrint(plist);
//	ListDestory(plist);
//	ListPrint(plist);
//}

void Test04()
{
	SLT* plist_1 = NULL;
	SListPushBack(&plist_1, 1);
	SListPushBack(&plist_1, 3);
	SListPushBack(&plist_1, 5);
	SListPushBack(&plist_1, 7);
	SListPrint(plist_1);
	SLT* plist_2 = NULL;
	SListPushBack(&plist_2, 1);
	SListPushBack(&plist_2, 4);
	SListPushBack(&plist_2, 6);
	SListPrint(plist_2);
	SLT* temp = SListCombine(plist_1, plist_2);
	SListPrint(temp);
}

int main()
{
	Test04();
	return 0;
}

