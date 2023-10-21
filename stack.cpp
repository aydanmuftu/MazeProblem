#include<stdio.h>
#include<stdlib.h>
#include"settings.h"
typedef struct pos
{
	int posx, posy;
}pos;
typedef struct stack
{
	pos* base, * top;
	int stakcsize;
}stack;
void stackinit(stack& s)//��ʼ��ջ
{
	s.base = (pos*)malloc(sizeof(pos) * ADDSIZE);
	s.top = s.base;
	s.stakcsize = ADDSIZE;
}
void stackpush(stack& s, pos now)//��ջ
{
	if (s.top - s.base >= s.stakcsize)
	{
		s.base = (pos*)realloc(s.base, sizeof(pos) * (s.stakcsize + ADDSIZE));
		if (!s.base)
			return;
		s.top = s.base + s.stakcsize;
		s.stakcsize += ADDSIZE;
	}
	*s.top++ = now;
}
void stackpop(stack& s)//��ջ
{
	if (s.base == s.top)
		return;
	s.top--;
}
pos stacktop(stack s)//��ѯջ��Ԫ��
{
	return *(s.top - 1);
}
bool stackempty(stack s)//ջ�п�
{
	if (s.top == s.base)
		return true;
	return false;
}