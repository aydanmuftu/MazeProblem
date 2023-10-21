#pragma once
typedef struct pos
{
	int posx, posy;
}pos;
typedef struct stack
{
	pos* base, * top;
	int stakcsize;
}stack;
void stackinit(stack& s);
void stackpush(stack& s, pos now);
void stackpop(stack& s);
pos stacktop(stack s);
bool stackempty(stack s);