#include"game.h"

int main()
{
	//srand((unsigned)time(NULL));
	int input = 0;
	char mine[ROW][COL];//定义后台版面
	char show[ROW][COL];//定义给玩家展示的版面
	int i, j = 0;
	for (i = 0; i < ROW - 1; i++)
	{
		for (j = 0; j < COL - 1; j++)
		{
			mine[i][j] = '0';//后台版面游戏区初始化为“0”
			show[i][j] = '*';//玩家可视版面游戏去初始化为“1”
		}
	}
	do
	{
		menu();
		printf("进入游戏或者退出：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game(mine, show);//输入1开始游戏  
		case 0:
			printf("退出游戏");//输入0退出游戏  
			break;
		default:
			printf("选择错误");
			break;
		}
	} while (input);//当选择1进入游戏一局结束时再次进入循环选择是否再次游戏，实现连续游戏  
	return 0;
}