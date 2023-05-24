#pragma once//为了避免同一个头文件被包含多次
#include<iostream>
#include<graphics.h>
#include"point.h"
#pragma warning(disable:4996)
using namespace std;

class Snake
{
public:
	Snake();
	void DrawSnake();//画蛇
	void MoveSnake();//移动蛇
	void Control();//控制蛇
	int& GetSnkStSz();//获得私有成员数据接口
	point& GetSnkPos(int pos);
	int SnakeStarSize;//设置蛇的初始长度
	point SnakeSize[1000];//设置蛇的最大长度
private:
	char goposition;//蛇的前进方向
	enum position{left,right,up,down};//枚举出四个方向
};