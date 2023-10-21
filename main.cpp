#include<stdio.h>
#include<stdlib.h>
#include<easyx.h>
#include"drawings.h"
#include"solutions.h"
char** map;
int row, col;

void createmap()
{
	//申请迷宫的内存空间
	printf("请输入迷宫的长和宽\n");
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
	printf("请输入迷宫的具体情况,0表示障碍,1表示通路\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			scanf_s("%c", &map[i][j]);
		getchar();
	}

	printf("迷宫创建成功!\n\n");
}
void solve()
{
	printf("请选择一种求解算法,输入1或2或3,分别表示非递归/递归/BFS\n");
	char order;
	scanf_s("%c", &order);
	int minstep = -1;
	//根据不同的指令选择不同的算法
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
		printf("指令错误!\n");
		break;
	}
	if (minstep == 0x3f3f3f3f)
		printf("无解!\n\n");
	else
		printf("最短路径长度为%d, 用绿色色块标出一条路径\n\n",minstep);
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