#pragma once//Ϊ�˱���ͬһ��ͷ�ļ����������
#include<iostream>
#include<graphics.h>
#include"point.h"
#pragma warning(disable:4996)
using namespace std;

class Snake
{
public:
	Snake();
	void DrawSnake();//����
	void MoveSnake();//�ƶ���
	void Control();//������
	int& GetSnkStSz();//���˽�г�Ա���ݽӿ�
	point& GetSnkPos(int pos);
	int SnakeStarSize;//�����ߵĳ�ʼ����
	point SnakeSize[1000];//�����ߵ���󳤶�
private:
	char goposition;//�ߵ�ǰ������
	enum position{left,right,up,down};//ö�ٳ��ĸ�����
};