#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBox(char box[ROWS][COLS], int rows, int cols, char value)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			box[i][j] = value;
		}
	}

}

void DisplayBox(char box[ROWS][COLS], int row, int col)
{
	// ��ӡ�к�
	for (int i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		// ��ӡ�к�
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", box[i][j]);
		}
		printf("\n");
	}
}


void SetMine(char box[ROWS][COLS], int row, int col)
{
	int count = Diff_LEVEL;
	while (count)
	{
		int x = rand() % row + 1;// 1=<x<=row [1,9]
		int y = rand() % col + 1;
		if ('0' == box[x][y]) // û�в��׵�λ�÷���
		{
			box[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0'; // '0' - '0' = 0, '1' - '0' = 1, ����axciiֵ�����
}


void DisplayRecursion(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{

	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		
		if ('1' != mine[x][y])
		{
			int count = get_mine_count(mine, x, y);

			if (' ' == show[x][y]) //������и��жϣ���ֹ�ú������е���ʱ get_mine_count������������ ' ' ջ�������ε������ �ֲ����� ���ڴ治�㣩
			{
				return;
			}

			else if (0 != count)
			{
				
				show[x][y] = count + '0'; // count ��int �ͣ�'0' �ַ���, + '0' ���ɱ�Ϊ�ַ���
				//return;
			}

			else
			{
				show[x][y] = ' ';
				for (int i = x - 1; i <= x + 1; i++)
				{
					for (int j = y - 1; j <= y + 1; j++)
					{
						DisplayRecursion(mine, show, row, col, i, j);
					}
				}
			}
		}
	
	}
	
}

int check_win(char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if ('*' == show[i][j])
				count++;
		}
	}
		
	return count;
}

void MineSweep(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("Please input a 2D coordinate:>");
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			// ����
			if ('1' == mine[x][y])
			{
				printf("Sorry, You died!\n");
				DisplayBox(mine, row, col);
				break;
			}
			// ����������
			else
			{
				DisplayRecursion(mine, show, ROW, COL, x, y);
				DisplayBox(show, row, col);
			}
		}
		else
		
		{
			printf("Please try again~\n");
		}

		if (Diff_LEVEL == check_win(show, row, col))
		{
			printf("You win!\n");
			DisplayBox(mine, row, col);
			break;
		}
	}

}

