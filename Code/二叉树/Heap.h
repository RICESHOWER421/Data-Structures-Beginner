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


/*初始化*/
void HeapInit(HP* php);
/*销毁堆*/
void HeapDestroy(HP* php);
/*插入数据*/
void HeapPush(HP* php, HPDataType x);
/*扩大堆大小*/
void HeapCreate(HP* php);
/*调整函数(向上调整)，调整双亲结点和子节点，会用到交换函数*/
void Adjustment_up(HPDataType* a, int child);
/*调整函数(向下调整)，调整双亲结点和子节点，会用到交换函数*/
void Adjustment_down(HPDataType* a, int n, int parents);
/*交换函数，用于交换双亲结点和子节点*/
void swap(HPDataType* child, HPDataType* parents);
/*打印堆*/
void HeapPrint(HP* php);
/*删除堆中最小(最大)结点*/
void HeapPop(HP* php);
/*取头节点*/
HPDataType HeapTop(HP* php);
/*判断堆是否为空*/
bool HeapEmpty(HP* php);
/*堆排序*/
void HeapSort(HPDataType* a, int num);
/*TopK问题*/
void PrintTopK(const char* filename, int k);