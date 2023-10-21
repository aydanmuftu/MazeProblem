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

void adlistinit(adlist*& list)//��ʼ���ڽӱ�
{
	list = (adlist*)malloc(sizeof(adlist) * row * col);
	for (int i = 0; i < row * col; i++)
		list[i].next = NULL;
}
void adlistinsert(adlist*& list,pos now, pos ne)//ʹ��ͷ�巨ά��ÿ������ڽӵ�
{
	int location = now.posx * col + now.posy;
	adlist* p = (adlist*)malloc(sizeof(adlist));
	p->next = list[location].next;
	list[location].next = p;
	p->position = ne;
}
void adlistcreate(adlist*& list)//�����Թ�,�����ڽӱ�
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
void adlistprint(adlist*& list)//����ڽӱ�
{
	printf("�Թ����ڽӱ��ʾΪ:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int location = i * col + j;
			if (map[i][j] == '0')
			{
				printf("��(%d,%d)Ϊ�ϰ�\n\n", i + 1, j + 1);
				continue;
			}
			if (!list[location].next)
				printf("��(%d,%d)Ϊͨ·,���ڽӵ�\n\n", i + 1, j + 1);
			else
			{
				printf("��(%d,%d)Ϊͨ·,�ڽӵ���:", i + 1, j + 1);
				for (adlist* p = list[location].next; p; p = p->next)
					printf("(%d,%d)\t", p->position.posx + 1, p->position.posy + 1);
				printf("\n\n");
			}
		}
	}
}