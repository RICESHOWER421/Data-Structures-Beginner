#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DLTDataType;

typedef struct SDListNode
{
	DLTDataType date;
	struct DListNode* next;
	struct DListNode* prev;
}DLT;

/*初始化*/
DLT* ListInit();
/*尾插*/
void ListPushBack(DLT* phead, DLTDataType x);
/*尾删*/
void ListPushFront(DLT* phead);
/*头插*/
void ListPopBack(DLT* phead, DLTDataType x);
/*尾插*/
void ListPopFront(DLT* phead);
/*打印*/
void ListPrint(DLT* phead);
/*查找*/
DLT* ListFind(DLT* phead, DLTDataType x);
/*删除pos节点*/
void ListErase(DLT* pos);
/*在pos前插入x值*/
void ListInsert(DLT* pos, DLTDataType x);
/*销毁链表*/
DLT* ListDestory(DLT* phead);
