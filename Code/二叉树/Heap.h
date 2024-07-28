#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}HP;


/*��ʼ��*/
void HeapInit(HP* php);
/*���ٶ�*/
void HeapDestroy(HP* php);
/*��������*/
void HeapPush(HP* php, HPDataType x);
/*����Ѵ�С*/
void HeapCreate(HP* php);
/*��������(���ϵ���)������˫�׽����ӽڵ㣬���õ���������*/
void Adjustment_up(HPDataType* a, int child);
/*��������(���µ���)������˫�׽����ӽڵ㣬���õ���������*/
void Adjustment_down(HPDataType* a, int n, int parents);
/*�������������ڽ���˫�׽����ӽڵ�*/
void swap(HPDataType* child, HPDataType* parents);
/*��ӡ��*/
void HeapPrint(HP* php);
/*ɾ��������С(���)���*/
void HeapPop(HP* php);
/*ȡͷ�ڵ�*/
HPDataType HeapTop(HP* php);
/*�ж϶��Ƿ�Ϊ��*/
bool HeapEmpty(HP* php);
/*������*/
void HeapSort(HPDataType* a, int num);
/*TopK����*/
void PrintTopK(const char* filename, int k);