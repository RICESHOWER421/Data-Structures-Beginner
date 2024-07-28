#include "test.h"
enum Function
{
	EXIT,
	INIT,
	POP_BACK,
	PUSH_BACK,
	PUSH_FRONT,
	POP_FRONT,
	PRINT,
	DESTORY,
	FIND,
	INSERT,
	ERASE
};

void menu()
{
	printf("**********************************************************\n");
	printf("**********************************************************\n");
	printf("**********************************************************\n");
	printf("*********              ˳���                 ************\n");
	printf("*********    1.��ʼ��         2.βɾ          ************\n");
	printf("*********    3.β��           4.ͷ��          ************\n");
	printf("*********    5.ͷɾ           6.��ӡ          ************\n");
	printf("*********    7.����           8.��������      ************\n");
	printf("*********    9.ָ������       10.ɾ��ָ������ ************\n");
	printf("*********              0.�˳�                 ************\n");
	printf("**********************************************************\n");
	printf("**********************************************************\n");
	printf("**********************************************************\n");
}

int main()
{
	SL sl;
	int choice = 0;
	do {
		menu();
		printf("����������ѡ��\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case EXIT:
			printf("��л����ʹ�ã��ټ�!\n");
			break;
		case INIT:
			SeqListInit(&sl);
			if (((&sl)->a == NULL) && (sl.capacity == 0) && (sl.size == 0))
			{
				printf("��ʼ���ɹ���\n");
			}
			else
			{
				printf("��ʼ��ʧ�ܣ�\n");
			}
			cls_screen();
			break;
		case POP_BACK:
			SeqListPopBack(&sl);
			printf("βɾ�ɹ���\n");
			cls_screen();
			break;
		case PUSH_BACK:
			SeqListPushBack(&sl, data_judgement());
			printf("β��ɹ���\n");
			cls_screen();
			break;
		case PUSH_FRONT:
			SeqListPushFront(&sl, data_judgement());
			printf("ͷ��ɹ���\n");
			cls_screen();
			break;
		case POP_FRONT:
			SeqListPopFront(&sl);
			printf("ͷɾ�ɹ���\n");
			cls_screen();
			break;
		case PRINT:
			SeqListPrint(&sl);
			printf("\n��ӡ��ɣ�\n");
			cls_screen();
			break;
		case DESTORY:
			SeqListDestory(&sl);
			printf("���ٳɹ���\n");
			cls_screen();
			break;
		case FIND:
		{
			int ret = SeqListFind(&sl, data_judgement());
			if (ret == -1)
			{
				printf("û�ҵ�\n");
			}
			else
			{
				printf("�ҵ��ˣ��±�Ϊ%d\n",ret);
			}
			cls_screen();
			break;
		}
		case INSERT:
		{
			int pos = 0;
			printf("��������Ҫ������±꣺\n");
			scanf("%d", &pos);
			SeqListInsert(&sl,pos, data_judgement());
			printf("����ɹ���\n");
			cls_screen();
			break;
		}
		case ERASE:
		{
			int pos = 0;
			printf("��������Ҫ������±꣺\n");
			scanf("%d", &pos);
			SeqListErase(&sl, pos);
			printf("ɾ���ɹ���\n");
			cls_screen();
			break;
		}
		default:
			printf("������������������ٴγ��ԣ�\n");
			cls_screen();
			break;
		}
	} while (choice);
	return 0;
}