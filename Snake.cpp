#include<iostream>
#include<graphics.h>
#include"point.h"
#include"Snake.h"
#include<conio.h>
using namespace std;

Snake::Snake()//构造函数
{
	SnakeStarSize=3;//设置初始长度
	for(int i=0;i<SnakeStarSize;i++)
	{
		SnakeSize[i].x=(2-i)*10;
		SnakeSize[i].y=0;
	}
	goposition=right;//默认前进方向
}
void Snake::DrawSnake()
{
	for(int i=0;i<SnakeStarSize;i++)
	{
		setfillcolor(RGB(rand() % 255,rand() % 255,rand() % 255));//设置蛇的颜色
		fillrectangle(SnakeSize[i].x,SnakeSize[i].y,SnakeSize[i].x+10,SnakeSize[i].y+10);//设置蛇身的位置
	}
}
void Snake::MoveSnake()
{
	for(int i=SnakeStarSize-1;i>0;i--)//将前一个方块的位置重新赋给后一个方块，实现蛇的移动
	{
		SnakeSize[i].x=SnakeSize[i-1].x;
		SnakeSize[i].y=SnakeSize[i-1].y;
	}
	switch(goposition)//蛇的移动，每次移动十个单位
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
	case 72://返回值是↑
		if(goposition != down)
		{
			goposition=up;
		}
		break;
	case'S':
	case's':
	case 80://返回值是↓
		if(goposition != up)
		{
			goposition=down;
		}
		break;
	case'A':
	case'a':
	case 75://返回值是←
		if(goposition != right)
		{
			goposition=left;
		}
		break;
	case'D':
	case'd':
	case 77://返回值是→
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
point& Snake::GetSnkPos(int pos)//返回位置
{
	return SnakeSize[pos];
}