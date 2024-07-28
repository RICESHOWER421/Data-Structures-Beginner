#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

/*��������*/
void swap(int* left, int* right);
/*��ӡ����*/
void PrintArray(int* nums, int n);
/*��������*/
void InsertSort(int* nums, int n);
/*ϣ������*/
void ShellSort(int* num, int n);
/*ð�������Ż��汾��*/
void BubbleSort(int* nums, int n);
/*ѡ������*/
void SelectSort(int* nums, int n);
/*����ȡ��*/
int GetMiddle(int* nums, int left, int right);
/*�������򣨲�������,�����汾��*/
int PartSort_1(int* nums, int left, int right);
/*�������򣨲��������ڿӷ���*/
int PartSort_2(int* nums, int left, int right);
/*�������򣨲�������ǰ��ָ�뷨��*/
int PartSort_3(int* nums, int left, int right);
/*�������򣨵ݹ�汾��*/
void QuickSort(int* nums, int begin, int end);
/*�������򣨷ǵݹ�汾��*/
void QuickSortNonR(int* nums, int begin, int end);
/*������������·�鲢�Ż�˼��ģ�*/
void QuickSort_2(int* nums, int left, int right);
/*�鲢���򣨵ݹ�汾��*/
void MergeSort(int* nums, int n);
/*�鲢����������Ϊ�����õݹ����ʼ��ֻ����һ������ռ�*/
void _MergeSort(int* nums, int* temp, int begin, int end);
/*�鲢���򣨷ǵݹ�汾��*/
void MergeSortNonR(int* nums, int n);
/*��������*/
void CountSort(int* nums, int n);