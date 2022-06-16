#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{

	//1.雷区的布置
	char mine[ROWS][COLS] = { 0 }; //11*11
	//2.雷区的排查信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBox(mine, ROWS, COLS, '0');
	InitBox(show, ROWS, COLS, '*');
	//显示雷区信息，不包括外扩的行列
	//DisplayBox(mine, ROW, COL);
	DisplayBox(show, ROW, COL);
	//布雷
	SetMine(mine, ROW, COL);
	//DisplayBox(mine, ROW, COL);

	//扫雷,mine数组中找雷，传递到show数组，
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