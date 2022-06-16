#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("*********************************\n");
	printf("****** 1. Play     0. exit ******\n");
	printf("*********************************\n");

}

void game()
{

	char flag = 0;
	char box[ROW][COL] = {0};
	srand((unsigned int)time(NULL));

	// 数组全部初始化为空格
	InitBox(box, ROW, COL);

	// 展示盒子和输入内容
	DisplayBox(box, ROW, COL);

	// 下棋
	while (1)
	{
		// Player Move, * symbol
		PlayerMove(box, ROW, COL);
		DisplayBox(box, ROW, COL);
		// IsWin
		flag = IsWin(box, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
		// Computer Move, # symbol
		ComputerMove(box, ROW, COL);
		DisplayBox(box, ROW, COL);
		flag = IsWin(box, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
	}

	if ('*' == flag)
	{
		printf("Player Win\n");
	}
	else if ('#' == flag)
	{
		printf("Computer Win\n");
	}
	else
		printf("Dogfall\n");
	
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("please start:>");
		scanf("%d", &input);

		printf("input = %d\n", input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit\n");
			break;
		default:
			printf("please input again!\n");
			break;
		}

	} while (input);

}

int main()
{
	test();

	return 0;
}