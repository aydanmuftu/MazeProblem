#pragma once
#define INF 0x3f3f3f3f //无穷大,用于初始化最短路径长度
#define MAXSIZE 100 //动态分配空间的最大尺寸
#define ADDSIZE 10  //栈空间每次增加的大小
#define WINDOW_UNIT 60  //图形界面的单位长度
extern char** map;
extern int row, col;
const int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };//方向向量,表示四个方向