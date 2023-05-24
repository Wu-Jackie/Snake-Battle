#pragma once//为了避免同一个头文件被包含多次
#include<iostream>
#pragma warning(disable:4996)
#include<graphics.h>
#include"point.h"
#include"Snake.h"
using namespace std;

class Food:public Snake//由于要在Food.cpp中访问蛇的长度
{
public:
	virtual void CrtFood()=0;//创建食物
	virtual void SetFoodPos()=0;//定义食物的位置
};

class GoodFood:public Food
{
public:
	GoodFood();
	void CrtFood();
	void SetFoodPos();
	point& Getpos1();//返回食物的位置
private:
	point pos1;
};

class BadFood:public Food
{
public:
	BadFood();
	void CrtFood();
	void SetFoodPos();
	point& Getpos2(int i);
private:
	point pos2[10];//定义十个有毒的食物
};