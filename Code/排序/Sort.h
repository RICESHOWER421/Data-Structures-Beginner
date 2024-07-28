#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

/*交换函数*/
void swap(int* left, int* right);
/*打印数组*/
void PrintArray(int* nums, int n);
/*插入排序*/
void InsertSort(int* nums, int n);
/*希尔排序*/
void ShellSort(int* num, int n);
/*冒泡排序（优化版本）*/
void BubbleSort(int* nums, int n);
/*选择排序*/
void SelectSort(int* nums, int n);
/*三数取中*/
int GetMiddle(int* nums, int left, int right);
/*快速排序（部分排序,霍尔版本）*/
int PartSort_1(int* nums, int left, int right);
/*快速排序（部分排序，挖坑法）*/
int PartSort_2(int* nums, int left, int right);
/*快速排序（部分排序，前后指针法）*/
int PartSort_3(int* nums, int left, int right);
/*快速排序（递归版本）*/
void QuickSort(int* nums, int begin, int end);
/*快速排序（非递归版本）*/
void QuickSortNonR(int* nums, int begin, int end);
/*快速排序（有三路归并优化思想的）*/
void QuickSort_2(int* nums, int left, int right);
/*归并排序（递归版本）*/
void MergeSort(int* nums, int n);
/*归并排序子排序，为了能让递归过程始终只开辟一次数组空间*/
void _MergeSort(int* nums, int* temp, int begin, int end);
/*归并排序（非递归版本）*/
void MergeSortNonR(int* nums, int n);
/*计数排序*/
void CountSort(int* nums, int n);