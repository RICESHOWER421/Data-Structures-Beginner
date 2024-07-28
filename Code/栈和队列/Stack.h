#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef char STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

/*��ʼ��*/
void StackInit(ST* ps);
/*����*/
void StackDestory(ST* ps);
/*�����ռ�*/
ST* StackCreate(ST* ps);
/*����*/
void StackPush(ST* ps, STDataType x);
/*ɾ��*/
void StackPop(ST* ps);
/*ȡtopֵ*/
STDataType StackTop(ST* ps);
/*����ջ�Ĵ�С*/
int StackSize(ST* ps);
/*�ж�ջ�Ƿ�Ϊ��*/
bool StackEmpty(ST* ps);

