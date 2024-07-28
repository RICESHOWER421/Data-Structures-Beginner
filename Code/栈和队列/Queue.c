#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL; 
	pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->x = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = pq->tail->next;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QNode* next = pq->head->next;
	if (pq->head == pq->tail)
	{
		pq->tail = next;
	}
	free(pq->head);
	pq->head = next;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
    return pq->head == NULL;
}	

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->x;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);

	return pq->tail->x;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int len = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return len;
}