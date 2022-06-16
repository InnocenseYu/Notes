#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�����������βο��Բ�д�����ǲ�������Ҫд
void InitBox(char box[ROW][COL], int row, int col);

// Display the box, box board, and have assigned content
void DisplayBox(char box[ROW][COL], int row, int col);

// Humen player move
void PlayerMove(char box[ROW][COL], int row, int col);
// Computer move
void ComputerMove(char box[ROW][COL], int row, int col);

//judegment symbole of IsWin function:
//win: *
//lose: #
//dogfall: 'D'
//continue: 'C'
//win lose dogfall. game over, don't need continue to play

char IsWin(char box[ROW][COL], int row, int col);