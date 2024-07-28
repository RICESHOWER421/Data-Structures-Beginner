#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include "Queue.h"

void Test01()
{
	ST x;
	StackInit(&x);
	StackPush(&x, 1);
	StackPush(&x, 2);
	printf("%d", StackTop(&x));
	StackPop(&x);
	printf("%d", StackTop(&x));
	StackPop(&x);
	StackPush(&x, 3);
	StackPush(&x, 4);
	

	while (!StackEmpty(&x))
	{
		printf("%d", StackTop(&x));
		StackPop(&x);
	}
}

void Test02()
{
	 Queue x;
	 QueueInit(&x);
	 QueuePush(&x, 1);
	 QueuePush(&x, 2);
	 QueuePush(&x, 3);
	 QueuePush(&x, 4);
	 QueuePush(&x, 5);
	 printf("%d\n", QueueFront(&x));
	 printf("%d\n", QueueSize(&x));
	 while (!QueueEmpty(&x))
	 {
		 QDataType front = QueueFront(&x);
		 printf("%d ", front);
		 QueuePop(&x);
	 }
	 printf("\n");
	 QueueEmpty(&x);
}

void Test03()
{
	ST s;
	StackInit(&s);
	char* arr = (char*)malloc(sizeof(char) * 20);
	if (arr == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	scanf("%s", arr);

	int len = strlen(arr);
	int i = 0;
	while (i < len / 2)
	{
		StackPush(&s, arr[i++]);
	}

	if (len % 2 == 1)
	{
		i++;
	}

	int index = 0;
	while (arr[i] != '\0')
	{
		char temp = StackTop(&s);
		if (temp != arr[i])
		{
			index = 1;
			break;
		}
		++i;
		StackPop(&s);
	}

	if (index == 0)
	{
		printf("是回文数\n");
	}
	else
	{
		printf("不是回文数\n");
	}
}

int main()
{
	Test03();
	return 0;
}