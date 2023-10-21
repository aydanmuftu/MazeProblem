#include<stdio.h>
#include<stdlib.h>
#include"settings.h"
#include"adlist.h"
#include"queue.h"
pos ans_3[MAXSIZE];
int dis[MAXSIZE][MAXSIZE];//dis����洢��λ�õ����ľ���

int bfs()
{
	for (int i = 0; i < row; i++)//dis��ʼ��Ϊ-1,��ʾδ����
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
		for (int i = 0; i < 4; i++)//���÷������������ܽ�������
		{
			int x = now.posx + dx[i], y = now.posy + dy[i];
			if (x >= 0 && x < row && y >= 0 && y < col && map[x][y] == '1' && dis[x][y] == -1)
			{
				dis[x][y] = dis[now.posx][now.posy] + 1;//��������λ�õ����ľ���
				queuepush(q, { x,y });
			}
		}
	}
	free(q.base);
	return dis[row - 1][col - 1];
}
void findpath(pos now, int step, pos path[])//������·������
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
		//ÿ�������ȵ�ǰλ�õ�������С1��λ��
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
	adlistprint(l);//����Թ����ڽӱ�
	free(l);
	if (map[0][0] == '0' || map[row - 1][col - 1] == '0')
		return INF;
	int ans = bfs();
	if (ans != -1)
	{
		pos* path = (pos*)malloc(sizeof(pos) * row * col);
		findpath({ row - 1,col - 1 }, 0, path);//����dis����,���յ�ݹ��������һ�����·��
		free(path);
		printf("���·��Ϊ:\n");
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