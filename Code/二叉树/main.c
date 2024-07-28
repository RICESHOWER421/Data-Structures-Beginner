#include "Heap.h"

void Test01()
{
	int a[6] = {30,10,80,40,50,60};
	HP php;
	int size = sizeof(a) / sizeof(a[0]);
	HeapInit(&php);
	for (int i = 0; i < size; i++)
	{
		HeapPush(&php, a[i]);
	}
	HeapPrint(&php);
	HeapDestroy(&php);
}

void Test02()
{
	int a[15] = { 5,7,3,8,6,9,4,1,0,11,45,65,23,11,74 };
	int num = sizeof(a) / sizeof(int);
	HeapSort(a, num);
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d ",a[i]);
	}
}

/*TopKÎÊÌâ*/
void Test03()
{
	CreateNDate();
	PrintTopK("data.txt", 10);
}

int main()
{
	Test02();
	return 0;
}