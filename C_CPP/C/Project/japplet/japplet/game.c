#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void InitBox(char box[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			box[i][j] = ' '; //全部数组赋值为 空格；
	}
}

// print the box board and content
void DisplayBox(char box[ROW][COL], int row, int col)
{
	/* 
	
	print the following symbol, row1 has three blank and two |, 
	and the list separator contain three --- and two |

	   |   |   
	---|---|---
    ---|---|---
	   |   |   
	*/

	// plan 1
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ",box[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}

}

void PlayerMove(char box[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("Player Move\n");
	printf("\n");
	while (1)
	{
		printf("Please input coordinates row and colume:>");
		scanf("%d%d", &x, &y);

		// judge coordinate's legitimacy
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (box[x - 1][y - 1] == ' ')
			{
				box[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("This coordinate is occupied.\n");
		}
		else
		{
			printf("Your coordinate is illegal, try again.\n");
		}
		
	}
	
}

void ComputerMove(char box[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("Computer Move.\n");

	while (1)
	{
		x = rand() % ROW; // acquire/get numbers less than ROW, 0 1 2
		y = rand() % COL;

		if (box[x][y] == ' ')
		{
			box[x][y] = '#';
			break;
		}
	}

}

char IsDogfall(char box[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (box[i][j] == ' ')
			{
				return 0; // find one is blank, box is not full
			}
		}
	}
	return 1; //all elements in box is not blank
		
}

char IsWin(char box[ROW][COL], int row, int col)
{
	// column equal and no blanks
	for (int i = 0; i < col; i++)
	{
		if (box[0][i] == box[1][i] && box[1][i] == box[2][i] && box[0][i] != ' ')
			return box[0][i];
	}

	// row equal and no blanks
	for (int i = 0; i < row; i++)
	{
		if (box[i][0] == box[i][1] && box[i][1] == box[i][2] && box[i][0] != ' ')
			return box[i][0];
	}

	// diagonal symbold aer equal, no blanks
	if (box[0][0] == box[1][1] && box[1][1] == box[2][2] && box[0][0] != ' ')
		return box[0][0];
	if (box[2][0] == box[1][1] && box[1][1] == box[0][2] && box[2][0] != ' ')
		return box[2][0];

	if (1 == IsDogfall(box, ROW, COL))
	{
		return 'D';
	}
	// all the above "if structment" meet criterion, return C: continune
	return 'C';

}