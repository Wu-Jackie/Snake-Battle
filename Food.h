#pragma once//Ϊ�˱���ͬһ��ͷ�ļ����������
#include<iostream>
#pragma warning(disable:4996)
#include<graphics.h>
#include"point.h"
#include"Snake.h"
using namespace std;

class Food:public Snake//����Ҫ��Food.cpp�з����ߵĳ���
{
public:
	virtual void CrtFood()=0;//����ʳ��
	virtual void SetFoodPos()=0;//����ʳ���λ��
};

class GoodFood:public Food
{
public:
	GoodFood();
	void CrtFood();
	void SetFoodPos();
	point& Getpos1();//����ʳ���λ��
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
	point pos2[10];//����ʮ���ж���ʳ��
};