#include<iostream>
#include<graphics.h>
#include"point.h"
#include"Snake.h"
#include<conio.h>
using namespace std;

Snake::Snake()//���캯��
{
	SnakeStarSize=3;//���ó�ʼ����
	for(int i=0;i<SnakeStarSize;i++)
	{
		SnakeSize[i].x=(2-i)*10;
		SnakeSize[i].y=0;
	}
	goposition=right;//Ĭ��ǰ������
}
void Snake::DrawSnake()
{
	for(int i=0;i<SnakeStarSize;i++)
	{
		setfillcolor(RGB(rand() % 255,rand() % 255,rand() % 255));//�����ߵ���ɫ
		fillrectangle(SnakeSize[i].x,SnakeSize[i].y,SnakeSize[i].x+10,SnakeSize[i].y+10);//���������λ��
	}
}
void Snake::MoveSnake()
{
	for(int i=SnakeStarSize-1;i>0;i--)//��ǰһ�������λ�����¸�����һ�����飬ʵ���ߵ��ƶ�
	{
		SnakeSize[i].x=SnakeSize[i-1].x;
		SnakeSize[i].y=SnakeSize[i-1].y;
	}
	switch(goposition)//�ߵ��ƶ���ÿ���ƶ�ʮ����λ
	{
	case right:
		SnakeSize[0].x+=10;
		break;
	case left:
		SnakeSize[0].x-=10;
		break;
	case up:
		SnakeSize[0].y-=10;
		break;
	case down:
		SnakeSize[0].y+=10;
		break;
	}
}
void Snake::Control()
{
	char userkey=getch();
	switch(userkey)
	{
	case'W':
	case'w':
	case 72://����ֵ�ǡ�
		if(goposition != down)
		{
			goposition=up;
		}
		break;
	case'S':
	case's':
	case 80://����ֵ�ǡ�
		if(goposition != up)
		{
			goposition=down;
		}
		break;
	case'A':
	case'a':
	case 75://����ֵ�ǡ�
		if(goposition != right)
		{
			goposition=left;
		}
		break;
	case'D':
	case'd':
	case 77://����ֵ�ǡ�
		if(goposition != left)
		{
			goposition=right;
		}
		break;
	}
}
int& Snake::GetSnkStSz()
{
	return SnakeStarSize;
}
point& Snake::GetSnkPos(int pos)//����λ��
{
	return SnakeSize[pos];
}