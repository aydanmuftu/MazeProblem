#include<stdio.h>
#include<easyx.h>
#include <graphics.h>
#include"settings.h"

void bkinit()
{
	//��ʼ������
	initgraph(WINDOW_UNIT * col, WINDOW_UNIT * row, EW_SHOWCONSOLE);

	//���ñ�����ɫ
	setbkcolor(RGB(255, 255, 255));

	//Ӧ�ñ�����ɫ
	cleardevice();
}
void drawframe()
{
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);

	printf("չʾ�Թ�����(��ɫ�����ʾ�ϰ�,��ɫ�����ʾͨ·)\n\n");
	//�����Թ����
	for (int i = 1; i <= row; i++)
	{
		line(0, i * WINDOW_UNIT, WINDOW_UNIT * col, i * WINDOW_UNIT);
		line(WINDOW_UNIT * i, 0, WINDOW_UNIT * i, WINDOW_UNIT * (row + 1));
	}
}
void fill()
{
	//�����Թ��е�ɫ��
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int x = WINDOW_UNIT * j, y = WINDOW_UNIT * i;
			if (map[i][j] == '0')
			{
				setfillcolor(RGB(128, 128, 128));
				fillrectangle(x, y, x + WINDOW_UNIT, y + WINDOW_UNIT);
			}
			if (map[i][j] == '#')
			{
				setfillcolor(RGB(117, 249, 77));
				fillrectangle(x, y, x + WINDOW_UNIT, y + WINDOW_UNIT);
			}
		}
	}
}