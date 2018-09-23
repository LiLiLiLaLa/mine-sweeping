#include"game.h"  

void menu()
{
	printf("******************\n");
	printf("******1.play******\n");
	printf("******0.exit******\n");
	printf("******************\n");
}//ѡ�������Ϸ���˳�  

void set_mine(char mine[ROW][COL])
{
	int count = COUNT;
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));
	while (count)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;//��������1��9���������Ϊ�׵�����
		if (mine[x][y] == '0')//�����������λ���ǡ�0��ʱ����ѭ��
		{
			mine[x][y] = '1';//����0��������Ϊ��1���������
			count--;//����һ����count��С1
		}
	}
}//�����������ʮ����

void display(char show[ROW][COL])
{
	int i, j = 0;
	printf("   ");//������ϽǴ�ӡ�ո�
	for (i = 1; i < COL - 1; i++)
	{
		printf(" %d ", i);//��ӡ��һ��������
	}
	printf("\n");//��ӡ���һ�����ֻ���
	for (i = 1; i < ROW - 1; i++)
	{
		printf(" %d ", i);//ÿ�ŵ�һ��λ�ô�ӡ������
		for (j = 1; j < COL - 1; j++)
		{
			printf(" %c ", show[i][j]);//����һ���������ӡ��*��
		}
		printf("\n");//��ӡ��һ��֮����
	}
}//չʾ����ҵİ���

int get_num(char mine[ROW][COL], int x, int y)
{
	int count = 0;
	if (mine[x - 1][y - 1] == '1')
	{
		count++;
	}//���Ϸ�
	if (mine[x - 1][y] == '1')
	{
		count++;
	}//�ϱ�
	if (mine[x - 1][y + 1] == '1')
	{
		count++;
	}//���Ϸ�
	if (mine[x][y - 1] == '1')
	{
		count++;
	}//���
	if (mine[x][y + 1] == '1')
	{
		count++;
	}//�ұ�
	if (mine[x + 1][y - 1] == '1')
	{
		count++;
	}//���·�
	if (mine[x + 1][y] == '1')
	{
		count++;
	}//�±�
	if (mine[x + 1][y + 1] == '1')
	{
		count++;
	}//���·�
	return count;
}//�����׵�����

int sweep(char mine[ROW][COL], char show[ROW][COL])
{
	int is_first = 1;//����һ�������Ϊ1
	int count = 0;
	int x, y = 0;
	while (count != (ROW - 2)*(COL - 2) - COUNT)//��������û����ʱ����ѭ��
	{
		printf("���������꣺\n");
		scanf("%d%d", &x, &y);
		if (is_first)
		{
			while (mine[x][y] == '1')
			{
				set_mine(mine);
			}//�����һ���ȵ��������������
			is_first = 0;//��һ��������ʱ�ı�is_firstΪ0��ʹ�����ٽ���ѭ��
		}//��ֹ��һ���ȵ���
		if (mine[x][y] == '1')
		{
			printf("��ѽѽ����ȵ����ˣ��´οɳ����İɣ�\n");
			return 0;
		}
		else
		{
			int ret = get_num(mine, x, y);
			show[x][y] = ret + '0';//�׵��������������֣�show������char�ͣ�����Ҫ������ת���ɶ�Ӧ���ַ����ֲ��ܷ��룬ת��������������ֱ�Ӽ����ַ�'0'
			display(show);//����ҿ�����λ����Χ������
			count++;
		}
	}
	printf("���׳ɹ��������գ�\n");
	void display(mine);//������׳ɹ���չʾ���岼�����
	return 0;
}

int game(char mine[ROW][COL], char show[ROW][COL])
{
	set_mine(mine);//����
	display(show);//չʾ��Ұ���
	sweep(mine, show);//����
	return 0;
}//����Ϸ����