#include<stdio.h>
#include<stdlib.h>
#include"settings.h"
typedef struct pos
{
	int posx, posy;
}pos;
typedef struct queue
{
	pos* front, * rear;
	pos* base;
}queue;

void queueinit(queue& q)//��ʼ������
{
	q.base = (pos*)malloc(sizeof(pos) * row * col);
	q.front = q.rear = q.base;
}
void queuepush(queue& q, pos now)//���
{
	*q.rear++ = now;
}
bool queueempty(queue q)//�����п�
{
	if (q.front == q.rear)
		return true;
	return false;
}
pos queuefront(queue q)//��ѯ��ͷԪ��
{
	return *q.front;
}
void queuepop(queue& q)//����
{
	if (q.front == q.rear)
		return;
	q.front++;
}