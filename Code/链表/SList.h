#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType date;
	struct SListNode* next;
}SLT;

/*打印*/
void SListPrint(SLT* phead);
/*尾插*/
void SListPushBack(SLT** pphead, SLTDataType x);
/*头插*/
void SListPushFront(SLT** pphead, SLTDataType x);
/*创建新链表*/
SLT* CreateSListNode(SLTDataType x);
/*尾删*/
void SListPopBack(SLT** pphead);
/*头删*/
void SListPopFront(SLT** pphead);
/*查找*/
SLT* SListFind(SLT* phead, SLTDataType x);
/*在pos之前插入一个节点*/
void SListInsert(SLT** pphead, SLT* pos, SLTDataType x);
/*在pos之后插入一个节点*/
void SListInsertAfter(SLT* pos, SLTDataType x);
/*在指定节点删除数据*/
void SListErase(SLT** pphead, SLT* pos);
/*在指定节点后删除数据*/
void SListEraseAfter(SLT** pphead, SLT* pos);
/*销毁链表*/
void SListDestory(SLT** pphead);
/*找一个单链表长度为n中值最大的结点*/
SLT* SListValMAX(SLT* pphead);
/*合并两个有序链表*/
SLT* SListCombine(SLT* pphead_1, SLT* pphead_2);
