#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3


//初始化棋盘
void Init_board(char chessboard[ROW][COL], int row, int col);

//打印棋盘
void print_board(char chessboard[ROW][COL], int row, int col);


//玩家下棋
void Player_chess(char chessboard[ROW][COL], int row, int col);


//电脑下棋
void Computer_chess(char chessboard[ROW][COL], int row, int col);

//判断输赢
char Is_win(char chessboard[ROW][COL], int row, int col);

//棋盘是否已满
int Is_full(char chessboard[ROW][COL], int row, int col);