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
	printf("*********              顺序表                 ************\n");
	printf("*********    1.初始化         2.尾删          ************\n");
	printf("*********    3.尾插           4.头插          ************\n");
	printf("*********    5.头删           6.打印          ************\n");
	printf("*********    7.销毁           8.搜索数据      ************\n");
	printf("*********    9.指定插入       10.删除指定数据 ************\n");
	printf("*********              0.退出                 ************\n");
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
		printf("请输入您的选择：\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case EXIT:
			printf("感谢您的使用，再见!\n");
			break;
		case INIT:
			SeqListInit(&sl);
			if (((&sl)->a == NULL) && (sl.capacity == 0) && (sl.size == 0))
			{
				printf("初始化成功！\n");
			}
			else
			{
				printf("初始化失败！\n");
			}
			cls_screen();
			break;
		case POP_BACK:
			SeqListPopBack(&sl);
			printf("尾删成功！\n");
			cls_screen();
			break;
		case PUSH_BACK:
			SeqListPushBack(&sl, data_judgement());
			printf("尾插成功！\n");
			cls_screen();
			break;
		case PUSH_FRONT:
			SeqListPushFront(&sl, data_judgement());
			printf("头插成功！\n");
			cls_screen();
			break;
		case POP_FRONT:
			SeqListPopFront(&sl);
			printf("头删成功！\n");
			cls_screen();
			break;
		case PRINT:
			SeqListPrint(&sl);
			printf("\n打印完成！\n");
			cls_screen();
			break;
		case DESTORY:
			SeqListDestory(&sl);
			printf("销毁成功！\n");
			cls_screen();
			break;
		case FIND:
		{
			int ret = SeqListFind(&sl, data_judgement());
			if (ret == -1)
			{
				printf("没找到\n");
			}
			else
			{
				printf("找到了！下标为%d\n",ret);
			}
			cls_screen();
			break;
		}
		case INSERT:
		{
			int pos = 0;
			printf("请输入您要输入的下标：\n");
			scanf("%d", &pos);
			SeqListInsert(&sl,pos, data_judgement());
			printf("插入成功！\n");
			cls_screen();
			break;
		}
		case ERASE:
		{
			int pos = 0;
			printf("请输入您要输入的下标：\n");
			scanf("%d", &pos);
			SeqListErase(&sl, pos);
			printf("删除成功！\n");
			cls_screen();
			break;
		}
		default:
			printf("您输入的数字有误，请再次尝试！\n");
			cls_screen();
			break;
		}
	} while (choice);
	return 0;
}