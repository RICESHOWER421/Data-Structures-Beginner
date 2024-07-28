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

/*��ӡ*/
void SListPrint(SLT* phead);
/*β��*/
void SListPushBack(SLT** pphead, SLTDataType x);
/*ͷ��*/
void SListPushFront(SLT** pphead, SLTDataType x);
/*����������*/
SLT* CreateSListNode(SLTDataType x);
/*βɾ*/
void SListPopBack(SLT** pphead);
/*ͷɾ*/
void SListPopFront(SLT** pphead);
/*����*/
SLT* SListFind(SLT* phead, SLTDataType x);
/*��pos֮ǰ����һ���ڵ�*/
void SListInsert(SLT** pphead, SLT* pos, SLTDataType x);
/*��pos֮�����һ���ڵ�*/
void SListInsertAfter(SLT* pos, SLTDataType x);
/*��ָ���ڵ�ɾ������*/
void SListErase(SLT** pphead, SLT* pos);
/*��ָ���ڵ��ɾ������*/
void SListEraseAfter(SLT** pphead, SLT* pos);
/*��������*/
void SListDestory(SLT** pphead);
/*��һ����������Ϊn��ֵ���Ľ��*/
SLT* SListValMAX(SLT* pphead);
/*�ϲ�������������*/
SLT* SListCombine(SLT* pphead_1, SLT* pphead_2);
