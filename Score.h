#pragma once//Ϊ�˱���ͬһ��ͷ�ļ����������
#include<iostream>
#include<string>
#include<fstream> 
#pragma warning(disable:4996)

class Score
{
public:
	virtual void ShowScore()=0;//�����µ���߷�
	virtual void SaMScore()=0;//������߷�
	virtual void ifsScore()=0;//д������
};

class Score1:public Score
{
public:
	Score1();
	void ShowScore();
	int& getscore1();//�ӿ�
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
	int& getscore2();//�ӿ�
	void SaMScore();
	void ifsScore();
private:
	int score2;
	int Maxscore2;
};