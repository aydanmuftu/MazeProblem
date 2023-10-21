#include<stdio.h>
#include<stdlib.h>
#include<easyx.h>
#include"drawings.h"
#include"solutions.h"
char** map;
int row, col;

void createmap()
{
	//�����Թ����ڴ�ռ�
	printf("�������Թ��ĳ��Ϳ�\n");
	scanf_s("%d%d", &row, &col);
	map = (char**)malloc(sizeof(char*) * row);
	if (!map)
		exit(1);
	for (int i = 0; i < row; i++)
	{
		map[i] = (char*)malloc(sizeof(char) * col);
		if (!map[i])
			exit(1);
	}
	getchar();
	printf("�������Թ��ľ������,0��ʾ�ϰ�,1��ʾͨ·\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			scanf_s("%c", &map[i][j]);
		getchar();
	}

	printf("�Թ������ɹ�!\n\n");
}
void solve()
{
	printf("��ѡ��һ������㷨,����1��2��3,�ֱ��ʾ�ǵݹ�/�ݹ�/BFS\n");
	char order;
	scanf_s("%c", &order);
	int minstep = -1;
	//���ݲ�ͬ��ָ��ѡ��ͬ���㷨
	switch (order)
	{
	case '1':
		minstep = solve1();
		break;
	case '2':
		minstep = solve2();
		break;
	case '3':
		minstep = solve3();
		break;
	default:
		printf("ָ�����!\n");
		break;
	}
	if (minstep == 0x3f3f3f3f)
		printf("�޽�!\n\n");
	else
		printf("���·������Ϊ%d, ����ɫɫ����һ��·��\n\n",minstep);
}
int main()
{
	createmap();
	bkinit();
	drawframe();
	fill();
	solve();
	fill();
	free(map);
	system("pause");
	return 0;
}