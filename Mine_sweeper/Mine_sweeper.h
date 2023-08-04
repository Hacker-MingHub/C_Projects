#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 11
#define COL 11
#define Easy_Count 10


void Init_board(char board[ROW][COL], int row, int col, char value);
void print_board(char board[ROW][COL], int row, int col);
void Set_Mine(char board[ROW][COL], int row, int col, int num);
void Fine_Mine(char mine[ROW][COL], char sweep[ROW][COL], int row, int col);
int get_mine_count(char board[ROW][COL], int x, int y);