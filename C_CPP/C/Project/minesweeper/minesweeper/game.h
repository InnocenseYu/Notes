#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

//�Ѷȵȼ�
#define EASY 10
#define MIDDLE 15
#define DIFFICULT 20
#define Diff_LEVEL EASY

void InitBox(char box[ROWS][COLS], int row, int col, char value);
void DisplayBox(char box[ROWS][COLS], int row, int col);

//����
void SetMine(char box[ROWS][COLS], int row, int col);


//ɨ��
void MineSweep(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

int get_mine_count(char mine[ROWS][COLS], int x, int y);

void DisplayRecursion(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);

int check_win(char show[ROWS][COLS], int row, int col);