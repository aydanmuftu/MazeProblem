#include<stdio.h>
#include<stdlib.h>
#include"settings.h"
#include"adlist.h"
#include"queue.h"
pos ans_3[MAXSIZE];
int dis[MAXSIZE][MAXSIZE];//dis数组存储各位置到起点的距离

int bfs()
{
	for (int i = 0; i < row; i++)//dis初始化为-1,表示未搜索
		for (int j = 0; j < col; j++)
			dis[i][j] = -1;	
	queue q;
	queueinit(q);
	queuepush(q, { 0,0 });
	dis[0][0] = 0;
	while (!queueempty(q))
	{
		pos now = queuefront(q);
		queuepop(q);
		for (int i = 0; i < 4; i++)//利用方向向量对四周进行搜索
		{
			int x = now.posx + dx[i], y = now.posy + dy[i];
			if (x >= 0 && x < row && y >= 0 && y < col && map[x][y] == '1' && dis[x][y] == -1)
			{
				dis[x][y] = dis[now.posx][now.posy] + 1;//计算搜索位置到起点的距离
				queuepush(q, { x,y });
			}
		}
	}
	free(q.base);
	return dis[row - 1][col - 1];
}
void findpath(pos now, int step, pos path[])//求解最短路径集合
{
	if (!dis[now.posx][now.posy])
	{
		for (int i = 0; i < step; i++)
			ans_3[i] = path[i];
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int x = now.posx + dx[i], y = now.posy + dy[i];
		//每次搜索比当前位置到起点距离小1的位置
		if (x >= 0 && x < row && y >= 0 && y < col && dis[x][y] + 1 == dis[now.posx][now.posy])
		{
			path[step] = { x,y };
			findpath({ x,y }, step + 1, path);
		}
	}
}
int solve3()
{
	adlist* l;
	adlistinit(l);
	adlistcreate(l);
	adlistprint(l);//输出迷宫的邻接表
	free(l);
	if (map[0][0] == '0' || map[row - 1][col - 1] == '0')
		return INF;
	int ans = bfs();
	if (ans != -1)
	{
		pos* path = (pos*)malloc(sizeof(pos) * row * col);
		findpath({ row - 1,col - 1 }, 0, path);//根据dis数组,从终点递归回起点求出一条最短路径
		free(path);
		printf("最短路径为:\n");
		for (int i = ans - 1; i >= 0; i--)
		{
			map[ans_3[i].posx][ans_3[i].posy] = '#';
			printf("(%d,%d)\n", ans_3[i].posx + 1, ans_3[i].posy + 1); 
		}
		map[row - 1][col - 1] = '#';
		printf("(%d,%d)\n", row, col);
		return ans;
	}
	return INF;
}