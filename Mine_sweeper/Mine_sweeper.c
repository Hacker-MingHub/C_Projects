#include "Mine_sweeper.h"


void Init_board(char board[ROW][COL], int row, int col, char value) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = value;
		}
	}
}


void print_board(char board[ROW][COL], int row, int col) {
	printf("-------扫雷游戏-----\n");
	printf("  ");
	for (int i = 1; i < col - 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i < row - 1; i++)
	{
		printf("%d ", i);
		for (int j = 1; j < col - 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------扫雷游戏-----\n");
}


void Set_Mine(char board[ROW][COL], int row, int col, int num) {
	while (num)
	{
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			num--;
		}
	}
}


int get_mine_count(char board[ROW][COL], int x, int y) {
	//printf("%c\n", board[x - 1][y - 1]);
	//return board[x - 1][y - 1] - '0';
	return (board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] +
		board[x][y - 1] + board[x][y + 1] +
		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0');
}

void Fine_Mine(char mine[ROW][COL], char sweep[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	int step = 0;

	while (step < row * col - Easy_Count)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);

		//判断坐标是否合法
		if ((x > 0 && x < row - 1) && (y > 0 && y < col - 1))
		{
			if (sweep[x][y] != '*')
			{
				printf("该坐标被排查过了\n");
			}
			else
			{
				//判断坐标点是不是雷
				if (mine[x][y] == '1') {
					printf("扫雷失败\n");
					print_board(mine, row, col);
					break;
				}
				else
				{
					//计算坐标点周围有几颗雷
					int num = get_mine_count(mine, x, y);
					//printf("num=%d\n", num);
					sweep[x][y] = num + '0';
					print_board(sweep, row, col);
					step++;
				}
			}
		}
		else
		{
			printf("输入不合法，请重新输入");
		}

		if (step == row * col - Easy_Count)
		{
			printf("恭喜你，排雷成功\n");
			print_board(mine, row, col);
		}
	}
}