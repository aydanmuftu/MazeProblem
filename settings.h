#pragma once
#define INF 0x3f3f3f3f //�����,���ڳ�ʼ�����·������
#define MAXSIZE 100 //��̬����ռ�����ߴ�
#define ADDSIZE 10  //ջ�ռ�ÿ�����ӵĴ�С
#define WINDOW_UNIT 60  //ͼ�ν���ĵ�λ����
extern char** map;
extern int row, col;
const int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };//��������,��ʾ�ĸ�����