#include<stdio.h>
#include"settings.h"
#include"stack.h"
bool flag[MAXSIZE][MAXSIZE];//�������
int visitnum[MAXSIZE][MAXSIZE];//visitnum��¼ÿ��λ�������������Ĵ���
pos ans_1[MAXSIZE];//�洢���·������

void copy(stack s, int size)
{
	for (int i = 0; i <= size; i++)
		ans_1[i] = s.base[i];
}
int solve1()
{
	if (map[0][0] == '0' || map[row - 1][col - 1] == '0')//�����޽����
		return INF;
	stack s;
	stackinit(s);
	stackpush(s,{0,0});
	int minstep = INF;
	while (!stackempty(s))
	{
		pos now = stacktop(s);
		flag[now.posx][now.posy] = true;//���ջ��Ԫ��
		if (now.posx == row - 1 && now.posy == col - 1)//���������յ�
		{
			if (s.top - s.base - 1  < minstep)//����ǰ������·������С�����·��,�����
			{
				minstep = s.top - s.base - 1;
				copy(s, minstep);
			}
		}
		if (visitnum[now.posx][now.posy] == 4)//��������ܵ�����,��ջ
		{
			stackpop(s);
			visitnum[now.posx][now.posy] = 0;
			flag[now.posx][now.posy] = false;
			continue;
		}
		int x = now.posx + dx[visitnum[now.posx][now.posy]];
		int y = now.posy + dy[visitnum[now.posx][now.posy]];
		visitnum[now.posx][now.posy]++;//��ʾ�������һ���������
		//����Ҫ������λ��δԽ���Ҳ���ջ��
		if (x >= 0 && x < row && y >= 0 && y < col && map[x][y] == '1' && !flag[x][y])
			stackpush(s, { x,y });
	}
	if (minstep < INF && ans_1[minstep].posx == row - 1 && ans_1[minstep].posy == col - 1)
	{
		printf("���·��Ϊ:\n");
		for (int i = 0; i <= minstep; i++)
		{
			map[ans_1[i].posx][ans_1[i].posy] = '#';//��map�н����·����λ�ø�ֵ'#',ʹ����ͼ�ν����г�����ɫ
			printf("(%d,%d)\n", ans_1[i].posx + 1, ans_1[i].posy + 1);
		}
		return minstep;
	}
	return INF;
}