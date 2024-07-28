#include "SList.h"

SLT* CreateSListNode(SLTDataType x)
{
	SLT* newnode = (SLT*)malloc(sizeof(SLT));
	if (newnode == NULL)
	{
		printf("内存开辟失败\n");
		exit(-1);
	}
	newnode->date = x;
	newnode->next = NULL;

	return newnode;
}

void SListPrint(SLT* phead)
{
	SLT* cur = phead;
	while (cur != NULL)
	{
		printf("%d->",cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}


void SListPushBack(SLT** pphead, SLTDataType x)
{
	SLT* newnode = CreateSListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLT* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
	
		tail->next = newnode;
	}
}

void SListPushFront(SLT** pphead, SLTDataType x)
{
	SLT* newnode = CreateSListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLT** pphead)
{
	/*第一种：链表为空的情况*/
	if(*pphead == NULL)
	{
		printf("链表为空！\n");
		exit(-1);
	}
	/*assert(*pphead);*/

	/*第二种：链表只有一个元素的情况*/
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	/*第三种：链表中存在多个元素*/
	else
	{
		SLT* tail = *pphead;
		SLT* temp = NULL;
		while(tail->next != NULL)
		{
			temp = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		temp->next = NULL;
	}
}

/*错误示范:情况考虑不周*/
//void SListPopBack(SLT** pphead)
//{
//	SLT* tail = *pphead;
//	SLT* temp = NULL;
//	while (tail->next != NULL)
//	{
//		temp = tail;
//		tail = tail->next;
//	}
//	if (tail != *pphead)
//	{
//		temp->next = NULL;
//	}
//	free(tail);
//	tail = NULL;
//}

void SListPopFront(SLT** pphead)
{
	/*第一种：链表为空的情况*/
	assert(*pphead);
	/*第二种：链表有一个或多个元素的时候*/
	SLT* temp = *pphead;
	*pphead = (*pphead)->next;
	free(temp);
	temp = NULL;
	/*SLT* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;*/
}

SLT* SListFind(SLT* phead, SLTDataType x)
{
	SLT* temp = phead;
	while (temp)
	{
		if (temp->date == x)
		{
			return temp;
		}
		else
		{
			temp = temp->next;
		}
	}
	return NULL;
}

void SListInsert(SLT** pphead, SLT* pos, SLTDataType x)
{
	SLT* newnode = CreateSListNode(x);
	if (*pphead == pos)
	{
		*pphead = newnode;
		(*pphead)->next = pos;
	}
	else
	{
		SLT* temp = *pphead;
		while (temp->next != pos)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = pos;
	}
}

void SListErase(SLT** pphead, SLT* pos)
{
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		SLT* temp = *pphead;
		while (temp->next != pos)
		{
			temp = temp->next;
		}
		temp->next = pos->next;
		free(pos);
	}
}

void SListDestory(SLT** pphead)
{
	SLT* temp = &pphead;
	while (temp)
	{
		SLT* next = temp->next;
		free(temp);
		temp = next;
	}
	*pphead = NULL;
}

void SListInsertAfter(SLT* pos, SLTDataType x)
{
	SLT* newnode = CreateSListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SLT** pphead, SLT* pos)
{
	SLT* temp = pos->next;
	pos->next = temp->next;
	free(temp);
	temp = NULL;
}

SLT* SListValMAX(SLT* pphead)
{
	assert(pphead);

	SLT* temp = (SLT*)malloc(sizeof(SLT));
	temp->date = -1;
	temp->next = NULL;

	SLT* cur = pphead;
	while (cur)
	{
		if (cur->date > temp->date)
		{
			temp = cur;
		}
		cur = cur->next;
	}

	return temp;
}

SLT* SListCombine(SLT* pphead_1, SLT* pphead_2)
{
	assert(pphead_1 && pphead_2);

	SLT* cur_1 = pphead_1;
	SLT* cur_2 = pphead_2;
	while (cur_1 && cur_2)
	{
		//1 3 5 7 
		//1 4 6
		if ((cur_1->date < cur_2->date) && (cur_2->date != cur_1->date))
		{
			SLT* temp_1 = cur_1->next;
			SLT* temp_2 = cur_2;
			cur_2 = cur_2->next;
			cur_1->next = temp_2;
			temp_2->next = temp_1;
			cur_1 = temp_2->next;
		}
		else if (cur_1->date == cur_2->date)
		{
			cur_1 = cur_1->next;
			cur_2 = cur_2->next;
		}
		else
		{
			cur_1 = cur_1->next;
		}
	}

	if (cur_1 == NULL && cur_2 != NULL)
	{
		cur_1 = cur_2;
	}

	return pphead_1;
}