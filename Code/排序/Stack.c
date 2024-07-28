#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

ST* StackCreate(ST* ps)
{
	int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	ST* temp = (ST*)realloc(ps->a, sizeof(ST) * newcapacity);
	if (temp == NULL)
	{
		printf("realloc fail\n");
		exit(-1);
	}
	ps->a = temp;
	ps->capacity = newcapacity;
	return ps;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		ps = StackCreate(ps);
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top <= 0;
}