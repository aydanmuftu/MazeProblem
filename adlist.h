#pragma once
typedef struct pos
{
	int posx, posy;
}pos;
typedef struct adlist
{
	pos position;
	adlist* next;
}adlist;
void adlistinit(adlist*& list);
void adlistcreate(adlist*& list);
void adlistprint(adlist*& list);