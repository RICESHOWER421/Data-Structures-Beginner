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

/*��ʼ��*/
void QueueInit(Queue* pq);
/*����*/
void QueueDestroy(Queue* pq);
/*�����*/
void QueuePush(Queue* pq, QDataType x);
/*������*/
void QueuePop(Queue* pq);
/*ȡ����ͷ����*/
QDataType QueueFront(Queue* pq);
/*ȡ����β����*/
QDataType QueueBack(Queue* pq);
/*������д�С*/
int QueueSize(Queue* pq);
/*�ж϶����Ƿ�Ϊ��*/
bool QueueEmpty(Queue* pq);
