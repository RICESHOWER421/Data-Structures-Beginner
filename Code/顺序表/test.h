#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef double SLDataType;

/*静态顺序表*/
//静态特点：如果满了就不让插入 缺点：不好确定给的数量
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int x;  //表示数组中存储了多少个数据
//	int capacity;  //数组实际存数据的空间容量是多大
//}SL;   

/*动态顺序表*/
typedef struct SeqList
{
	SLDataType* a;
	int size;     //表示数组中存储了多少数据
	int capacity;   //数组实际存数据的空间容量是多大
}SL;

//接口函数 
/*初始化顺序表*/
void SeqListInit(SL* ps);
/*尾删顺序表*/
void SeqListPopBack(SL* ps);
/*尾插顺序表*/
void SeqListPushBack(SL* ps, SLDataType x);
/*头插顺序表*/
void SeqListPushFront(SL* ps, SLDataType x);
/*头删顺序表*/
void SeqListPopFront(SL* ps);
/*打印顺序表*/
void SeqListPrint(SL* ps);
/*销毁顺序表*/
void SeqListDestory(SL* ps);
/*检查顺序表的容器大小是否已满*/
void SeqListCheckCapacity(SL* ps);
/*找到了返回x位置的下标，没有返回-1*/
int SeqListFind(SL* ps, SLDataType x);
/*指定pos下标位置插入*/
void SeqListInsert(SL* ps, int pos, SLDataType x);
/*删除pos位置的数据*/
void SeqListErase(SL* ps, int pos);
/*清空屏幕设置*/
void cls_screen();
/*输入数据判断*/
int data_judgement();
