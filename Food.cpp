#include<iostream>
#include<graphics.h>
#include"point.h"
#include"Food.h"
using namespace std;

GoodFood::GoodFood()//���캯�����ʳ�����λ��                    
{
	pos1.x = rand() % 80 * 10;               
	pos1.y = rand() % 60 * 10;
}
void GoodFood::CrtFood()//�����ɫ
{
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(pos1.x, pos1.y, pos1.x + 10, pos1.y + 10);
}

void GoodFood::SetFoodPos()
{
	pos1.x = rand() % 80 * 10;
	pos1.y = rand() % 60 * 10;
	for(int i=0;i<SnakeStarSize;i++)
	{
		if(pos1.x==SnakeSize[i].x && pos1.y==SnakeSize[i].y)//����ʳ��ˢ����������
		{
			pos1.x = rand() % 80 * 10;
			pos1.y = rand() % 60 * 10;
		}
	}
}
point& GoodFood::Getpos1()//����ʳ��λ��
{
	return pos1;
}
BadFood::BadFood()
{
	for(int i=0;i<10;i++)//�������ʮ���ж���ʳ��
	{
		pos2[i].x = rand() %70 *10;
		pos2[i].y = rand() %50 *10;
	}
}
void BadFood::CrtFood()
{
	for(int i=0;i<10;i++)
	{
		setfillcolor(RGB(0,0,0));//��ɫ
		fillrectangle(pos2[i].x,pos2[i].y,pos2[i].x + 10 ,pos2[i].y + 10);
	}
}
void BadFood::SetFoodPos()
{
	for(int i=0;i<10;i++)//����ʮ���ж���ʳ��
	{
		pos2[i].x = rand() %70 *10;
		pos2[i].y = rand() %50 *10;
	}
	for(int i=0;i<SnakeStarSize;i++)
	{
		if(pos2[10].x==SnakeSize[i].x && pos2[10].y==SnakeSize[i].y)
		{
			for(int i=0;i<10;i++)
			{
				pos2[i].x = rand() %70 *10;
				pos2[i].y = rand() %50 *10;
			}
		}
	}
}
point& BadFood::Getpos2(int i)
{
	return pos2[i];
}