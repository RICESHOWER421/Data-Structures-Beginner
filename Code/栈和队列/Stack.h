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

/*初始化*/
void StackInit(ST* ps);
/*销毁*/
void StackDestory(ST* ps);
/*创建空间*/
ST* StackCreate(ST* ps);
/*插入*/
void StackPush(ST* ps, STDataType x);
/*删除*/
void StackPop(ST* ps);
/*取top值*/
STDataType StackTop(ST* ps);
/*计算栈的大小*/
int StackSize(ST* ps);
/*判断栈是否为空*/
bool StackEmpty(ST* ps);

