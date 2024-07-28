#include "Sort.h"
#include "Stack.h"

void Test01()
{
	int nums[]= {4,5,6,24,5,2,6,7,8,6,5,4,3,0,9,8,9,0,9,1,2,3,2,4,7,6,8,5,3,4};
	int n = sizeof(nums) / sizeof(int);
	InsertSort(nums, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}

void Test02()
{
	int nums[] = {9,2,3,5,1,6,8,4,0};
	int size = sizeof(nums) / sizeof(int);
	ShellSort(nums, size);
	PrintArray(nums, size);
}

void Test03()
{
	int nums[] = {9,2,3,5,1,6,8,4,0};
	int size = sizeof(nums) / sizeof(int);
	BubbleSort(nums, size);
	PrintArray(nums, size);
}

void Test04()
{
	int nums[] = { 9,2,3,5,1,6,8,4,0 };
	int size = sizeof(nums) / sizeof(int);
	SelectSort(nums, size);
	PrintArray(nums, size);
}

void Test05()
{
	int nums[] = {1,4,5,3,5,3,3,3,5,6,5,3,3,3,3,2,1};
	int size = sizeof(nums) / sizeof(int);
	QuickSort_2(nums, 0, size - 1);
	PrintArray(nums, size);
}

void Test06()
{
	int nums[] = { 1,3,2,4,3,5,4,5,6,7,6,8,7,9,7,0,9,0,8,7,6,7,8,5,6,4,5,3,2,1 };
	int size = sizeof(nums) / sizeof(int);
	MergeSortNonR(nums, size);
	PrintArray(nums, size);
}

void Compare()
{
	srand((unsigned int)time(NULL));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	if (a1 == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	int* a2 = (int*)malloc(sizeof(int) * N);
	if (a2 == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	int* a3 = (int*)malloc(sizeof(int) * N);
	if (a3 == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	int* a4 = (int*)malloc(sizeof(int) * N);
	if (a4 == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	int* a5 = (int*)malloc(sizeof(int) * N);
	if (a5 == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	int* a6 = (int*)malloc(sizeof(int) * N);
	if (a6 == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	int begin1 = clock();
	/*InsertSort(a1, N);*/
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	/*BubbleSort(a3, N);*/
	int end3 = clock();

	int begin4 = clock();
	/*SelectSort(a4, N);*/
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a2, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort time:%d\n", end1 - begin1);
	printf("ShellSort time:%d\n", end2 - begin2);
	printf("BubbleSort time:%d\n", end3 - begin3);
	printf("SelectSort time:%d\n", end4 - begin4);
	printf("QuickSort time:%d\n", end5 - begin5);
	printf("MergeSort time:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

void Compare_1()
{
	int nums[] = { 1,3,2,4,5,6,7,8,9 };
	int size = sizeof(nums) / sizeof(nums[0]);
	int* a1 = (int*)malloc(sizeof(int) * size);
	int* a2 = (int*)malloc(sizeof(int) * size);
	int* a3 = (int*)malloc(sizeof(int) * size);
	int* a4 = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		a1[i] = nums[i];
		a2[i] = nums[i];
		a3[i] = nums[i];
		a4[i] = nums[i];
	}

	int begin1 = clock();
	InsertSort(a1, size);
	int end1 = clock();

	int begin2 = clock();
	QuickSort(a2, 0, size - 1);
	int end2 = clock();

	int begin3 = clock();
	MergeSort(a3, size);
	int end3 = clock();

	printf("%d %d %d",begin1 - end1, begin2 - end2, begin3 - end3);
}
int main()
{
	/*Test01();
	Test02();
	Test03();
	Test04();*/
	Test05();
	//Test06();
	/*Compare();*/
	/*Compare_1();*/
	return 0;
}