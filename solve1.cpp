#include<stdio.h>
#include"settings.h"
#include"stack.h"
bool flag[MAXSIZE][MAXSIZE];//标记数组
int visitnum[MAXSIZE][MAXSIZE];//visitnum记录每个位置向四周搜索的次数
pos ans_1[MAXSIZE];//存储最短路径集合

void copy(stack s, int size)
{
	for (int i = 0; i <= size; i++)
		ans_1[i] = s.base[i];
}
int solve1()
{
	if (map[0][0] == '0' || map[row - 1][col - 1] == '0')//特判无解情况
		return INF;
	stack s;
	stackinit(s);
	stackpush(s,{0,0});
	int minstep = INF;
	while (!stackempty(s))
	{
		pos now = stacktop(s);
		flag[now.posx][now.posy] = true;//标记栈中元素
		if (now.posx == row - 1 && now.posy == col - 1)//若搜索到终点
		{
			if (s.top - s.base - 1  < minstep)//若当前搜索的路径长度小于最短路径,则更新
			{
				minstep = s.top - s.base - 1;
				copy(s, minstep);
			}
		}
		if (visitnum[now.posx][now.posy] == 4)//当完成四周的搜索,出栈
		{
			stackpop(s);
			visitnum[now.posx][now.posy] = 0;
			flag[now.posx][now.posy] = false;
			continue;
		}
		int x = now.posx + dx[visitnum[now.posx][now.posy]];
		int y = now.posy + dy[visitnum[now.posx][now.posy]];
		visitnum[now.posx][now.posy]++;//表示已完成这一方向的搜索
		//若将要搜索的位置未越界且不在栈中
		if (x >= 0 && x < row && y >= 0 && y < col && map[x][y] == '1' && !flag[x][y])
			stackpush(s, { x,y });
	}
	if (minstep < INF && ans_1[minstep].posx == row - 1 && ans_1[minstep].posy == col - 1)
	{
		printf("最短路径为:\n");
		for (int i = 0; i <= minstep; i++)
		{
			map[ans_1[i].posx][ans_1[i].posy] = '#';//在map中将最短路径上位置赋值'#',使其在图形界面中呈现绿色
			printf("(%d,%d)\n", ans_1[i].posx + 1, ans_1[i].posy + 1);
		}
		return minstep;
	}
	return INF;
}