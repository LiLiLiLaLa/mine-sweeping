#include"game.h"  

void menu()
{
	printf("******************\n");
	printf("******1.play******\n");
	printf("******0.exit******\n");
	printf("******************\n");
}//选择进入游戏或退出  

void set_mine(char mine[ROW][COL])
{
	int count = COUNT;
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));
	while (count)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;//产生两个1到9的随机数作为雷的坐标
		if (mine[x][y] == '0')//当产生坐标的位置是“0”时进入循环
		{
			mine[x][y] = '1';//将“0”处更改为“1”，设成雷
			count--;//设置一个雷count减小1
		}
	}
}//里面随机产生十个雷

void display(char show[ROW][COL])
{
	int i, j = 0;
	printf("   ");//表格左上角打印空格
	for (i = 1; i < COL - 1; i++)
	{
		printf(" %d ", i);//打印第一横排数字
	}
	printf("\n");//打印完第一行数字换行
	for (i = 1; i < ROW - 1; i++)
	{
		printf(" %d ", i);//每排第一个位置打印成数字
		for (j = 1; j < COL - 1; j++)
		{
			printf(" %c ", show[i][j]);//除第一列其余均打印“*”
		}
		printf("\n");//打印完一行之后换行
	}
}//展示给玩家的版面

int get_num(char mine[ROW][COL], int x, int y)
{
	int count = 0;
	if (mine[x - 1][y - 1] == '1')
	{
		count++;
	}//左上方
	if (mine[x - 1][y] == '1')
	{
		count++;
	}//上边
	if (mine[x - 1][y + 1] == '1')
	{
		count++;
	}//右上方
	if (mine[x][y - 1] == '1')
	{
		count++;
	}//左边
	if (mine[x][y + 1] == '1')
	{
		count++;
	}//右边
	if (mine[x + 1][y - 1] == '1')
	{
		count++;
	}//左下方
	if (mine[x + 1][y] == '1')
	{
		count++;
	}//下边
	if (mine[x + 1][y + 1] == '1')
	{
		count++;
	}//右下方
	return count;
}//计算雷的数量

int sweep(char mine[ROW][COL], char show[ROW][COL])
{
	int is_first = 1;//设置一个标记置为1
	int count = 0;
	int x, y = 0;
	while (count != (ROW - 2)*(COL - 2) - COUNT)//当还有雷没排完时进入循环
	{
		printf("请输入坐标：\n");
		scanf("%d%d", &x, &y);
		if (is_first)
		{
			while (mine[x][y] == '1')
			{
				set_mine(mine);
			}//如果第一步踩到雷重新随机布雷
			is_first = 0;//第一步不是雷时改变is_first为0，使程序不再进入循环
		}//防止第一步踩到雷
		if (mine[x][y] == '1')
		{
			printf("哎呀呀，你踩到雷了，下次可长点心吧！\n");
			return 0;
		}
		else
		{
			int ret = get_num(mine, x, y);
			show[x][y] = ret + '0';//雷的数量本来是数字，show数组是char型，所以要把数字转化成对应的字符数字才能放入，转换方法就是数字直接加上字符'0'
			display(show);//让玩家看见该位置周围的雷数
			count++;
		}
	}
	printf("排雷成功，棒棒哒！\n");
	void display(mine);//玩家排雷成功后展示整体布雷情况
	return 0;
}

int game(char mine[ROW][COL], char show[ROW][COL])
{
	set_mine(mine);//布雷
	display(show);//展示玩家版面
	sweep(mine, show);//排雷
	return 0;
}//玩游戏过程