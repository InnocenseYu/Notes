#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{

	//1.�����Ĳ���
	char mine[ROWS][COLS] = { 0 }; //11*11
	//2.�������Ų���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBox(mine, ROWS, COLS, '0');
	InitBox(show, ROWS, COLS, '*');
	//��ʾ������Ϣ������������������
	//DisplayBox(mine, ROW, COL);
	DisplayBox(show, ROW, COL);
	//����
	SetMine(mine, ROW, COL);
	//DisplayBox(mine, ROW, COL);

	//ɨ��,mine���������ף����ݵ�show���飬
	MineSweep(mine, show, ROW, COL);
}

void menu()
{
	printf("*******************************\n");
	printf("***********  1. Play  *********\n");
	printf("***********  0. Exit  *********\n");
	printf("*******************************\n");

}

void test()
{

	int input = 0;
	srand((unsigned int)time(NULL));

	do {
		
		menu();
		printf("Please input:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit game!");
			break;
		default:
			printf("please try again!\n");
			break;
		}

	} while (input);
}


int main()
{
	test();

	return 0;
}