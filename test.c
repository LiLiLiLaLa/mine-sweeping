#include"game.h"

int main()
{
	//srand((unsigned)time(NULL));
	int input = 0;
	char mine[ROW][COL];//�����̨����
	char show[ROW][COL];//��������չʾ�İ���
	int i, j = 0;
	for (i = 0; i < ROW - 1; i++)
	{
		for (j = 0; j < COL - 1; j++)
		{
			mine[i][j] = '0';//��̨������Ϸ����ʼ��Ϊ��0��
			show[i][j] = '*';//��ҿ��Ӱ�����Ϸȥ��ʼ��Ϊ��1��
		}
	}
	do
	{
		menu();
		printf("������Ϸ�����˳���");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game(mine, show);//����1��ʼ��Ϸ  
		case 0:
			printf("�˳���Ϸ");//����0�˳���Ϸ  
			break;
		default:
			printf("ѡ�����");
			break;
		}
	} while (input);//��ѡ��1������Ϸһ�ֽ���ʱ�ٴν���ѭ��ѡ���Ƿ��ٴ���Ϸ��ʵ��������Ϸ  
	return 0;
}