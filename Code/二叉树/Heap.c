#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void swap(HPDataType* child, HPDataType* parents)
{
	HPDataType temp = 0;
	temp = *child;
	*child = *parents;
	*parents = temp;
}

void Adjustment_up(HPDataType* a, int child)
{
	int parents = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parents])
		{
			swap(&a[child], &a[parents]);
			child = parents;
			parents = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapCreate(HP* php)
{
	int newcapacity = php->_capacity == 0 ? 4 : php->_capacity * 2;
	HPDataType* temp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * newcapacity);
	if (temp == NULL)
	{
		perror("realloc fail");
		exit(-1);
	}
	php->_a = temp;
	php->_capacity = newcapacity;
}

void HeapInit(HP* php)
{
	assert(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_size = php->_capacity = 0;
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->_size == php->_capacity)
	{
		HeapCreate(php);
	}
	php->_size++;
	php->_a[php->_size - 1] = x;

	Adjustment_up(php->_a, php->_size - 1);
}

void HeapPrint(HP* php)
{
	for (int i = 0; i < php->_size; i++)
	{
		printf("%d ",php->_a[i]);
	}
	printf("\n");
}

void Adjustment_down(HPDataType* a, int n, int parents)
{
	int child = parents * 2 + 1;
	while (child < n)
	{
		/*需要满足child + 1 < n是因为完全二叉树可能出现双亲结点只有一个子节点的情况，避免出现比较不存在的数据*/
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}

		if (a[child] > a[parents])
		{
			swap(&a[child], &a[parents]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(php->_size > 0);

	swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	Adjustment_down(php->_a, php->_size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}

bool HeapEmpty(HP* php)
{
	assert(php);

	return php->_size == 0;
}

void HeapSort(HPDataType* a, int num)
{
     /*降序（建小堆）*/
	/*时间复杂度：O(N*logN)*/
	//int i = 0;
	//for (i = 0; i < num; i++)
	//{
	//	Adjustment_up(a, i);
	//}
	for (int i = (num - 2) / 2; i >= 0; i--)
	{
		Adjustment_down(a, num, i);
	}

	/*for (i = 0; i < num; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");*/

	/*建好大堆以后，将第一个数据与最后一个数据进行交换，然后将这个交换的数据进行向下调整进行排序*/
	int end = num - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		Adjustment_down(a, end, 0);
		end--;
	}
}

void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		if (i == 41)
		{
			x = 1000001;
		}
		if (i == 1000)
		{
			x = 1000002;
		}
		if (i == 2034)
		{
			x = 1000003;
		}
		if (i == 4965)
		{
			x = 1000004;
		}
		if (i == 9901)
		{
			x = 1000005;
		}
		if (i == 1029)
		{
			x = 1000006;
		}
		if (i == 9876)
		{
			x = 1000007;
		}
		if (i == 6689)
		{
			x = 1000008;
		}
		if (i == 8848)
		{
			x = 1000009;
		}
		if (i == 1098)
		{
			x = 1000010;
		}
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(const char* filename,int k)
{
	FILE* fout = fopen(filename, "r");
	if (fout == NULL)
	{
		perror("fout fail");
		exit(-1);
	}

	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout,"%d", &minheap[i]);
	}

	for (int i = 0; i < k; i++)
	{
		Adjustment_up(minheap, i);
	}

	/*for (int i = (k - 2) / 2; i >= 0; i--)
	{
		Adjustment_down(minheap, k, i);
	}*/

	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minheap[0])
		{
			minheap[0] = x;
			Adjustment_down(minheap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ",minheap[i]);
	}
	printf("\n");

	fclose(fout);
}
