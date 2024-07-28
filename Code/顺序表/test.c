#include "test.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	/*如果数组空间不足或者未进行开辟空间，则拓宽空间或者开辟空间*/
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;

		SLDataType* temp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->a = temp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPrint(SL* ps)
{
	int i = 0;
	if (sizeof(SLDataType) == 4)
	{
		for (i = 0; i < ps->size; i++)
		{
			printf("%d\t", ps->a[i]);
		}
	}
	else if (sizeof(SLDataType) == 1)
	{
		for (i = 0; i < ps->size; i++)
		{
			printf("%c\t", ps->a[i]);
		}
	}
	else
	{
		int time = 0;
		printf("请问是单精度浮点型还是双精度浮点型？(单精度选1，双精度选2)\n");
		scanf("%d", &time);
		while (1)
		{
			if (time == 1)
			{
				for (i = 0; i < ps->size; i++)
				{
					printf("%f\t", ps->a[i]);
				}
				break;
			}
			else if (time == 2)
			{
				for (i = 0; i < ps->size; i++)
				{
					printf("%lf\t", ps->a[i]);
				}
				break;
			}
			else
			{
				printf("您输入的信息有误，请重新输入！\n");
			}
		}
	}
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPopBack(SL* ps)
{
	if (ps->size == 0)
	{
		printf("尾删失败！失败原因：数组中已经不存在任何数据！\n");
		exit(-1);
	}
	ps->a[ps->size - 1] = 0;
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);

	/*额外开创一份空间*/
	/*SLDataType* temp_1 = (SLDataType*)malloc(sizeof(SLDataType) * ps->capacity);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		temp_1[i + 1] = ps->a[i];
	}
	temp_1[0] = x;
	ps->a = temp_1;
	ps->size++;*/

	int temp = ps->size - 1;
	int i = 0;
	for (i = temp; i >= 0; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	if (ps->size == 0)
	{
		printf("头删失败！失败原因：数组中已经不存在任何数据！\n");
		exit(-1);
	}
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

int SeqListFind(SL* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (x == ps->a[i])
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	SeqListCheckCapacity(ps);
	if (pos > ps->size || pos < 0)
	{
		printf("不存在该下标！\n");
		exit(-1);
	}
	if (pos != ps->size)
	{
		int i = 0;
		for (i = ps->size - 1; i >= pos; i--)
		{
			ps->a[i + 1] = ps->a[i];
		}
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
	if (pos >= ps->size || pos < 0 || ps->size == 0)
	{
		printf("删除数据失败！\n");
		exit(-1);
	}
	int i = 0;
	for (i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void cls_screen()
{
	system("pause");
	system("cls");
}

int data_judgement()
{
	SLDataType num = 0;
	if (sizeof(SLDataType) == 4)
	{
		printf("请输入您要输入的数据：\n");
		scanf("%d", &num);
	}
	else if (sizeof(SLDataType) == 1)
	{
		printf("请输入您要输入的数据：\n");
		scanf("%c", &num);
	}
	else
	{
		int time = 0;
		printf("请问是单精度浮点型还是双精度浮点型？(单精度选1，双精度选2)\n");
		scanf("%d", &time);
		while (1)
		{
			if (time == 1)
			{
				printf("请输入您要输入的数据：\n");
				scanf("%f", &num);
				break;
			}
			else if (time == 2)
			{
				printf("请输入您要输入的数据：\n");
				scanf("%lf", &num);
				break;
			}
			else
			{
				printf("您输入的信息有误，请重新输入！\n");
			}
		}
	}
	return num;
}