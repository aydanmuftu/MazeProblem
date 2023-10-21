#pragma once
typedef struct queue
{
	pos* front, * rear;
	pos* base;
}queue;
void queueinit(queue& q);
void queuepush(queue& q, pos now);
bool queueempty(queue q);
pos queuefront(queue q);
void queuepop(queue& q);