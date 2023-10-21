#include<stdio.h>
#include<stdlib.h>
#include"settings.h"
typedef struct pos
{
	int posx, posy;
}pos;
pos ans_2[MAXSIZE];
bool visited[MAXSIZE][MAXSIZE];
int minstep = INF;

void copy(pos path[],int size)
{
	for (int i = 0; i <= size; i++)
		ans_2[i] = path[i];
}
void dfs(pos now,int step,pos path[])//nowΪ��ǰ������λ��,stepΪ�����ľ���,pathΪ����·����λ�ü���
{
	int x = now.posx, y = now.posy;
	path[step] = { x,y };//����ǰλ�ü�������·������
	if (x == row - 1 && y == col - 1)
	{
		if (step < minstep)
		{
			minstep = step;
			copy(path,step);
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nex = x + dx[i], ney = y + dy[i];
		if (nex >= 0 && nex < row && ney >= 0 && ney < col && !visited[nex][ney] && map[nex][ney] == '1')
		{
			visited[nex][ney] = true;//���ϱ��,��ʾ��������
			dfs({ nex,ney }, step + 1, path);//������һ������
			visited[nex][ney] = false;//�������
		}
	}
}
int solve2()
{
	if (map[0][0] == '0' || map[row - 1][col - 1] == '0')
		return INF;
	pos* path = (pos*)malloc(sizeof(pos) * row * col);
	visited[0][0] = true;
	dfs({ 0,0 }, 0, path);
	free(path);
	if (minstep < INF && ans_2[minstep].posx == row - 1 && ans_2[minstep].posy == col - 1)
	{
		printf("���·��Ϊ:\n");
		for (int i = 0; i <= minstep; i++)
		{
			map[ans_2[i].posx][ans_2[i].posy] = '#';
			printf("(%d,%d)\n", ans_2[i].posx + 1, ans_2[i].posy + 1);
		}
		return minstep;
	}
	return INF;
}