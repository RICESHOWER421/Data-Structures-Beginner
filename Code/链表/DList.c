#include "DList.h"

DLT* ListInit()
{
	DLT* phead = (DLT*)malloc(sizeof(DLT));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListPushBack(DLT* phead, DLTDataType x)
{
	assert(phead);
	/*传统方法*/
	/*DLT* newnode = (DLT*)malloc(sizeof(DLT));
	DLT* tail = phead->prev;

	newnode->date = x;
	newnode->prev = tail;
	newnode->next = phead;
	tail->next = newnode;
	phead->prev = newnode;*/
	ListInsert(phead, x);
}

void ListPrint(DLT* phead)
{
	assert(phead);

	DLT* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	cur = cur->next;
	if (cur == phead)
	{
		printf("fhead");
	}
	else
	{
		printf("%d\n", cur->date);
	}
}

void ListPushFront(DLT* phead)
{
	assert(phead);
	assert(phead->next != phead);

	DLT* tail = phead->prev;
	DLT* tailPrev = tail->prev;
	
	phead->prev = tailPrev;
	tailPrev->next = phead;

	free(tail);
}

void ListPopBack(DLT* phead, DLTDataType x)
{
	assert(phead);
	/*传统方法*/
	/*DLT* newnode = (DLT*)malloc(sizeof(DLT));
	newnode->date = x;
	DLT* next = phead->next;

	newnode->next = next;
	next->prev = newnode;

	newnode->prev = phead;
	phead->next = newnode;*/
	ListInsert(phead->next, x);
}

void ListPopFront(DLT* phead)
{
	assert(phead);
	assert(phead->next != phead);

	DLT* temp = phead->next;
	DLT* tempNext = temp->next;

	phead->next = tempNext;
	tempNext->prev = phead;

	free(temp);
}

DLT* ListFind(DLT* phead, DLTDataType x)
{
	DLT* cur = phead->next;
	while (cur != phead)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListErase(DLT* pos)
{
	DLT* PosPrev = pos->prev;
	DLT* PosNext = pos->next;

	PosPrev->next = PosNext;
	PosNext->prev = PosPrev;
	free(pos);
	pos = NULL;
}

void ListInsert(DLT* pos, DLTDataType x)
{
	DLT* posPrev = pos->prev;
	DLT* newnode = (DLT*)malloc(sizeof(DLT));
	newnode->date = x;

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

DLT* ListDestory(DLT* phead)
{
	assert(phead);

	DLT* cur = phead->next;
	while (cur != phead)
	{
		DLT* next = cur->next;
		free(cur);
		cur = cur->next;
	}

	/*这样做并没有实际效果，但为了保持一致性仍使用一级指针，可以在main函数实际调用时手动释放*/
	free(phead);
	phead = NULL;
}

