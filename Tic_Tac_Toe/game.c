//#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void Init_board(char chessboard[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			chessboard[i][j] = ' ';
		}
	}
}

void print_board(char chessboard[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		// 打印每行结果
		for (int j = 0; j < col; j++)
		{
			// 按格式打印每个单元格
			printf(" %c ", chessboard[i][j]);


			// 打印列分隔符
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");

		// 打印行分隔符
		if (i < row - 1)
		{
			for (int k = 0; k < col; k++)
			{
				printf("---");

				// 打印列分隔符
				if (k < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	printf("\n");
}


void Player_chess(char chessboard[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;

	printf("玩家开始下棋:>\n");
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);

		//判断输入是否合理
		if ((x > 0 && x <= row) && (y > 0 && y <= col))
		{
			//判断坐标是否已经被占用
			if (chessboard[x - 1][y - 1] == ' ')
			{
				chessboard[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标已被占用，请选择其他位置\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}


void Computer_chess(char chessboard[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;

	printf("电脑开始下棋:>\n");
	while (1)
	{
		//生成随机坐标
		x = rand() % row;
		y = rand() % col;

		//判断坐标是否被占用
		if (chessboard[x][y] == ' ')
		{
			chessboard[x][y] = '#';
			break;
		}
	}

}

int Is_full(char chessboard[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (chessboard[i][j] == ' ')
			{
				return 0;
			}
		}
	}

	return 1;
}

char Is_win(char chessboard[ROW][COL], int row, int col) {
	//检查行
	for (int i = 0; i < row; i++)
	{
		if (chessboard[i][0] == chessboard[i][1] && chessboard[i][1] == chessboard[i][2] && chessboard[i][0] != ' ')
		{
			return chessboard[i][0];
		}
	}

	//检查列
	for (int j = 0; j < col; j++)
	{
		if (chessboard[0][j] == chessboard[1][j] && chessboard[1][j] == chessboard[2][j] && chessboard[0][j] != ' ')
		{
			return chessboard[0][j];
		}
	}

	//检查对角线
	if (chessboard[0][0] == chessboard[1][1] && chessboard[1][1] == chessboard[2][2] && chessboard[0][0] != ' ')
	{
		return chessboard[0][0];
	}

	if (chessboard[2][0] == chessboard[1][1] && chessboard[1][1] == chessboard[0][2] && chessboard[2][0] != ' ')
	{
		return chessboard[2][0];
	}

	if (Is_full(chessboard, row, col))
	{
		return 'Q';
	}

	return 'C';

}