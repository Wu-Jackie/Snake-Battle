#include<iostream>
#include<string>
#include<fstream>
#include"Food.h"
#include"Score.h"
using namespace std;

Score1::Score1()//��ʼ������Ϊ0
{
	score1=0;
	Maxscore1=0;
}
void Score1::ShowScore()//������߷ֲ���ʾ
{
	char scores[50];//��������ʽ�����ת��Ϊ�ַ���
	settextcolor(BLUE);
	sprintf(scores,"��ķ���Ϊ��%d",score1);
	outtextxy(0,0,scores);
	settextstyle(25,0,"����");
	if(score1>Maxscore1)
	{
		Maxscore1=score1;
		this->SaMScore();
	}
}
int& Score1::getscore1()//���ط���
{
	return score1;
}
void Score1::SaMScore()//������߷�
{
	ofstream outfile;
	outfile.open("Score1.txt",ios::out);
	outfile<<Maxscore1;
	outfile.close();
}
void Score1::ifsScore()//��ʾ��߷�
{
	ifstream infile;
	infile.open("Score1.txt",ios::in);
	infile>>Maxscore1;
	char maxscores[50];
	settextcolor(BLUE);
	sprintf(maxscores,"��߷ַ�����%d",Maxscore1);
	outtextxy(0,775,maxscores);
	settextstyle(25,0,"����");
}
Score2::Score2()
{
	score2=0;
	Maxscore2=0;
}
void Score2::ShowScore()//������߷ֲ���ʾ
{
	char scores[50];//��������ʽ�����ת��Ϊ�ַ���
	settextcolor(RED);
	sprintf(scores,"��ķ���Ϊ��%d",score2);
	outtextxy(0,0,scores);
	settextstyle(25,0,"����");
	if(score2>Maxscore2)
	{
		Maxscore2=score2;
		this->SaMScore();
	}
}
int& Score2::getscore2()//���ط���
{
	return score2;
}
void Score2::SaMScore()//������߷�
{
	ofstream outfile;
	outfile.open("Score2.txt",ios::out);
	outfile<<Maxscore2;
	outfile.close();
}
void Score2::ifsScore()//��ʾ��߷�
{
	ifstream infile;
	infile.open("Score2.txt",ios::in);
	infile>>Maxscore2;
	char maxscores[50];
	settextcolor(RED);
	sprintf(maxscores,"��߷ַ�����%d",Maxscore2);
	outtextxy(0,775,maxscores);
	settextstyle(25,0,"����");
}