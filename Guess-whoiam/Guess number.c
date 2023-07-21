#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>

void menu() {
  printf("*****************************\n");
  printf("*********** 1.play **********\n");
  printf("*********** 0.exit **********\n");
  printf("*****************************\n");
}

void game() {
  int rand_num = rand() % 100 + 1;
  int input = 0;

  while (true)
  {
    printf("请输入猜的数字>:");
    scanf("%d", &input);
    if (input > rand_num)
    {
      printf("猜大了\n");
    }
    else if (input < rand_num)
    {
      printf("猜小了\n");
    }
    else
    {
      printf("恭喜你，猜对了\n");
      break;
    }

  }


}

int main(int argc, char const* argv[])
{
  int input = 0;
  srand((unsigned)time(NULL));
  do
  {
    menu();
    printf("请选择>:");
    scanf("%d", &input);
    switch (input)
    {
    case 1:
      game();
      break;
    case 0:
      printf("退出游戏");
      break;
    default:
      printf("选择错误,请重新输入!\n");
      break;
    }
  } while (input);

  return 0;
}
