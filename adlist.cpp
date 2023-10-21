#include<stdio.h>
#include<stdlib.h>
#include"settings.h"
typedef struct pos
{
	int posx, posy;
}pos;
typedef struct adlist
{
	pos position;
	adlist* next;
}adlist;

void adlistinit(adlist*& list)//初始化邻接表
{
	list = (adlist*)malloc(sizeof(adlist) * row * col);
	for (int i = 0; i < row * col; i++)
		list[i].next = NULL;
}
void adlistinsert(adlist*& list,pos now, pos ne)//使用头插法维护每个点的邻接点
{
	int location = now.posx * col + now.posy;
	adlist* p = (adlist*)malloc(sizeof(adlist));
	p->next = list[location].next;
	list[location].next = p;
	p->position = ne;
}
void adlistcreate(adlist*& list)//遍历迷宫,构建邻接表
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k], y = j + dy[k];
				if (x >= 0 && x < row && y >= 0 && y < col && map[x][y] == '1')
					adlistinsert(list, { i, j }, { x,y });
			}
		}
	}
}
void adlistprint(adlist*& list)//输出邻接表
{
	printf("迷宫的邻接表表示为:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int location = i * col + j;
			if (map[i][j] == '0')
			{
				printf("点(%d,%d)为障碍\n\n", i + 1, j + 1);
				continue;
			}
			if (!list[location].next)
				printf("点(%d,%d)为通路,无邻接点\n\n", i + 1, j + 1);
			else
			{
				printf("点(%d,%d)为通路,邻接点有:", i + 1, j + 1);
				for (adlist* p = list[location].next; p; p = p->next)
					printf("(%d,%d)\t", p->position.posx + 1, p->position.posy + 1);
				printf("\n\n");
			}
		}
	}
}