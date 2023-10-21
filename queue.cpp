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

void queueinit(queue& q)//初始化队列
{
	q.base = (pos*)malloc(sizeof(pos) * row * col);
	q.front = q.rear = q.base;
}
void queuepush(queue& q, pos now)//入队
{
	*q.rear++ = now;
}
bool queueempty(queue q)//队列判空
{
	if (q.front == q.rear)
		return true;
	return false;
}
pos queuefront(queue q)//查询队头元素
{
	return *q.front;
}
void queuepop(queue& q)//出队
{
	if (q.front == q.rear)
		return;
	q.front++;
}