#include<iostream>
#include<string>
#include<fstream>
#include"Food.h"
#include"Score.h"
using namespace std;

Score1::Score1()//初始化分数为0
{
	score1=0;
	Maxscore1=0;
}
void Score1::ShowScore()//设置最高分并显示
{
	char scores[50];//把整数格式化输出转化为字符串
	settextcolor(BLUE);
	sprintf(scores,"你的分数为：%d",score1);
	outtextxy(0,0,scores);
	settextstyle(25,0,"等线");
	if(score1>Maxscore1)
	{
		Maxscore1=score1;
		this->SaMScore();
	}
}
int& Score1::getscore1()//返回分数
{
	return score1;
}
void Score1::SaMScore()//保存最高分
{
	ofstream outfile;
	outfile.open("Score1.txt",ios::out);
	outfile<<Maxscore1;
	outfile.close();
}
void Score1::ifsScore()//显示最高分
{
	ifstream infile;
	infile.open("Score1.txt",ios::in);
	infile>>Maxscore1;
	char maxscores[50];
	settextcolor(BLUE);
	sprintf(maxscores,"最高分分数：%d",Maxscore1);
	outtextxy(0,775,maxscores);
	settextstyle(25,0,"等线");
}
Score2::Score2()
{
	score2=0;
	Maxscore2=0;
}
void Score2::ShowScore()//设置最高分并显示
{
	char scores[50];//把整数格式化输出转化为字符串
	settextcolor(RED);
	sprintf(scores,"你的分数为：%d",score2);
	outtextxy(0,0,scores);
	settextstyle(25,0,"等线");
	if(score2>Maxscore2)
	{
		Maxscore2=score2;
		this->SaMScore();
	}
}
int& Score2::getscore2()//返回分数
{
	return score2;
}
void Score2::SaMScore()//保存最高分
{
	ofstream outfile;
	outfile.open("Score2.txt",ios::out);
	outfile<<Maxscore2;
	outfile.close();
}
void Score2::ifsScore()//显示最高分
{
	ifstream infile;
	infile.open("Score2.txt",ios::in);
	infile>>Maxscore2;
	char maxscores[50];
	settextcolor(RED);
	sprintf(maxscores,"最高分分数：%d",Maxscore2);
	outtextxy(0,775,maxscores);
	settextstyle(25,0,"等线");
}