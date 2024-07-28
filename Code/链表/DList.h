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

/*��ʼ��*/
DLT* ListInit();
/*β��*/
void ListPushBack(DLT* phead, DLTDataType x);
/*βɾ*/
void ListPushFront(DLT* phead);
/*ͷ��*/
void ListPopBack(DLT* phead, DLTDataType x);
/*β��*/
void ListPopFront(DLT* phead);
/*��ӡ*/
void ListPrint(DLT* phead);
/*����*/
DLT* ListFind(DLT* phead, DLTDataType x);
/*ɾ��pos�ڵ�*/
void ListErase(DLT* pos);
/*��posǰ����xֵ*/
void ListInsert(DLT* pos, DLTDataType x);
/*��������*/
DLT* ListDestory(DLT* phead);
