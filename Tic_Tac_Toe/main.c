#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("*****  1. play  0. exit *****\n");
	printf("*****************************\n");
}

void game() {
	char chessboard[ROW][COL] = { 0 };
	Init_board(chessboard, ROW, COL);
	print_board(chessboard, ROW, COL);

	int ret = 0;
	while (1)
	{
		Player_chess(chessboard, ROW, COL);
		print_board(chessboard, ROW, COL);

		ret = Is_win(chessboard, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		Computer_chess(chessboard, ROW, COL);
		print_board(chessboard, ROW, COL);

		ret = Is_win(chessboard, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}

	//判断是谁赢了
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}

}

int main(int argc, char const* argv[])
{
	int n = 0;

	//初始化随机种子
	srand((unsigned int)time(NULL));

	do
	{
		// 打印菜单
		menu();
		printf("请输入:>");

		//获取用户输入 
		scanf("%d", &n);

		// 判断是否玩游戏
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
