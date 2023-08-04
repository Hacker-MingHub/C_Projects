#include "Mine_sweeper.h"

void menu()
{
	printf("*****************************\n");
	printf("*****  1. play  0. exit *****\n");
	printf("*****************************\n");
}

void game() {
	char mine[ROW][COL] = { '0' };
	char sweep[ROW][COL] = { '0' };

	//初始化埋雷棋盘
	Init_board(mine, ROW, COL, '0');

	//初始化扫雷棋盘
	Init_board(sweep, ROW, COL, '*');

	//布置雷
	Set_Mine(mine, ROW, COL, Easy_Count);

	//print_board(mine, ROW, COL);

	//打印棋盘
	print_board(sweep, ROW, COL);

	//排雷
	Fine_Mine(mine, sweep, ROW, COL);

	//打印棋盘
	//print_board(mine, ROW, COL);

}

int main() {
	int n = 0;
	//初始化随机数的种子
	srand((unsigned int)time(NULL));

	do
	{
		// 打印菜单
		menu();
		printf("请选择:>");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (n);
	return 0;
}