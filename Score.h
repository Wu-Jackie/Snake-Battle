#pragma once//为了避免同一个头文件被包含多次
#include<iostream>
#include<string>
#include<fstream> 
#pragma warning(disable:4996)

class Score
{
public:
	virtual void ShowScore()=0;//设置新的最高分
	virtual void SaMScore()=0;//保存最高分
	virtual void ifsScore()=0;//写出分数
};

class Score1:public Score
{
public:
	Score1();
	void ShowScore();
	int& getscore1();//接口
	void SaMScore();
	void ifsScore();
private:
	int score1;
	int Maxscore1;
};

class Score2:public Score
{
public:
	Score2();
	void ShowScore();
	int& getscore2();//接口
	void SaMScore();
	void ifsScore();
private:
	int score2;
	int Maxscore2;
};