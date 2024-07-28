#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef double SLDataType;

/*��̬˳���*/
//��̬�ص㣺������˾Ͳ��ò��� ȱ�㣺����ȷ����������
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int x;  //��ʾ�����д洢�˶��ٸ�����
//	int capacity;  //����ʵ�ʴ����ݵĿռ������Ƕ��
//}SL;   

/*��̬˳���*/
typedef struct SeqList
{
	SLDataType* a;
	int size;     //��ʾ�����д洢�˶�������
	int capacity;   //����ʵ�ʴ����ݵĿռ������Ƕ��
}SL;

//�ӿں��� 
/*��ʼ��˳���*/
void SeqListInit(SL* ps);
/*βɾ˳���*/
void SeqListPopBack(SL* ps);
/*β��˳���*/
void SeqListPushBack(SL* ps, SLDataType x);
/*ͷ��˳���*/
void SeqListPushFront(SL* ps, SLDataType x);
/*ͷɾ˳���*/
void SeqListPopFront(SL* ps);
/*��ӡ˳���*/
void SeqListPrint(SL* ps);
/*����˳���*/
void SeqListDestory(SL* ps);
/*���˳����������С�Ƿ�����*/
void SeqListCheckCapacity(SL* ps);
/*�ҵ��˷���xλ�õ��±꣬û�з���-1*/
int SeqListFind(SL* ps, SLDataType x);
/*ָ��pos�±�λ�ò���*/
void SeqListInsert(SL* ps, int pos, SLDataType x);
/*ɾ��posλ�õ�����*/
void SeqListErase(SL* ps, int pos);
/*�����Ļ����*/
void cls_screen();
/*���������ж�*/
int data_judgement();
