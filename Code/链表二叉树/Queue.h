#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct ListBinaryTree* QDataType;

typedef struct QueueNode 
{
	QDataType x;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

/*初始化*/
void QueueInit(Queue* pq);
/*销毁*/
void QueueDestroy(Queue* pq);
/*入队列*/
void QueuePush(Queue* pq, QDataType x);
/*出队列*/
void QueuePop(Queue* pq);
/*取队列头数据*/
QDataType QueueFront(Queue* pq);
/*取队列尾数据*/
QDataType QueueBack(Queue* pq);
/*计算队列大小*/
int QueueSize(Queue* pq);
/*判断队列是否为空*/
bool QueueEmpty(Queue* pq);
