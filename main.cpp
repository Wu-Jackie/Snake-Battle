#include<iostream>
#include<graphics.h>
#include<conio.h>//ͨ������̨����������������
#include<mmsystem.h>//������ý���豸�ӿ�ͷ�ļ�
#include<Windows.h>
#include"point.h"
#include"Food.h"
#include"Score.h"
#include"Snake.h"
#pragma warning(disable:4996)
#pragma comment(lib,"winmm.lib")//���ؾ�̬��
using namespace std;

void Menu()
{
	initgraph(800,800);
	cleardevice();
	loadimage(NULL,"startbg.jpg",800,800);
	setbkmode(TRANSPARENT);
	mciSendString("open startbgm.mp3 alias STARTBGM",0,0,0);//��ʼ����
	mciSendString("play STARTBGM repeat",0,0,0);
}
int GameExplain()
{
	initgraph(800,800);
	cleardevice();
	setbkcolor(WHITE);
	loadimage(NULL,"explain.png",800,800);
	setbkmode(TRANSPARENT);
	char userkey=getch();
	if (userkey == 0)
	{
		PlaySound(TEXT("click.wav"),NULL,SND_FILENAME | SND_ASYNC);//����һ��
		return 1;
	}
}
int Exit()
{
	initgraph(800,800);
	cleardevice();
	loadimage(NULL,"overbg.png",800,800);
	setbkmode(TRANSPARENT);
	while(1)
	{
		settextstyle(50,0,"����");
		settextcolor(BLUE);
		outtextxy(330,300,"THANKS");
		outtextxy(330,360,"�ټ�!!!");
		settextstyle(25,0,"����");
		settextcolor(BLUE);
		outtextxy(20,20,"�����������");
		outtextxy(600,20,"��0����");
		Sleep(100);
		char userkey=getch();
		if(userkey!='0')
		{
			exit(0);
		}
		else
		{
			return 1;
		}
	}
}
void GetFood(Snake* snake,GoodFood* goodfood,Score1& score1,Score2& score2)//��ȡʳ�ﻥ��
{
	if(goodfood->Getpos1().x==snake->GetSnkPos(0).x && goodfood->Getpos1().y==snake->GetSnkPos(0).y)
	{
		goodfood->SetFoodPos();//�������ʳ��λ��
		snake->GetSnkStSz()+=2;//�ߵĳ�������
		score1.getscore1()+=10;//��������ʮ��
		score2.getscore2()+=10;
		PlaySound(TEXT("eat.wav"),NULL, SND_FILENAME | SND_ASYNC);//����һ��
	}
}
void Game()//��ͨģʽ
{
	initgraph(800,800);
	setbkcolor(WHITE);
	Snake* psnake = new Snake;//������
	GoodFood* pgfood = new GoodFood;//����ʳ��
	Score1 score1;
	Score2 score2;
	mciSendString("open gamebgm.mp3 alias GAMEBGM",0,0,0);//��Ϸ��ѭ������
	mciSendString("play GAMEBGM repeat",0,0,0);
	while(1)
	{
		cleardevice();//ˢ�´���
		psnake->DrawSnake();//����
		psnake->MoveSnake();//�ߵ��ƶ�
		GetFood(psnake,pgfood,score1,score2);
		score1.ShowScore();//�����µ���߷�
		score1.ifsScore();//д������
		pgfood->CrtFood();//��ȡʳ�ﻥ��
		if(kbhit())//��鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
		{
			psnake->Control();//������
		}
		Sleep(50);//ˢ�£������ٶ�
		if(psnake->GetSnkPos(0).x<0 || psnake->GetSnkPos(0).y<0 ||
			psnake->GetSnkPos(0).x>800 || psnake->GetSnkPos(0).y>800)//������������:ײǽ  
		{
			mciSendString("close GAMEBGM",0,0,0);
			PlaySound(TEXT("over.wav"),NULL,SND_FILENAME | SND_ASYNC);//����һ��
			MessageBox(NULL,"GAME OVER","TEXT",MB_OK | MB_SYSTEMMODAL);//�����Ի���������Ļ��ǰ�棻
ABG:
			break;
		}
		for(int i=1;i<psnake->GetSnkStSz();i++)
		{
			if(psnake->GetSnkPos(0).x == psnake->GetSnkPos(i).x && 
				psnake->GetSnkPos(0).y == psnake->GetSnkPos(i).y)//������������:ײ����
			{
				mciSendString("close GAMEBGM",0,0,0);
				PlaySound(TEXT("over.wav"),NULL,SND_FILENAME | SND_ASYNC);//����һ��
				MessageBox(NULL,"GAME OVER","TEXT",MB_OK | MB_SYSTEMMODAL);
				goto ABG;
				break;
			}
		}
	}
	delete psnake;//�ͷŶ���
	delete pgfood;
}
void Game2()//�ϰ�ģʽ
{
	initgraph(800,800);
	setbkcolor(WHITE);
	Snake* psnake = new Snake;//������
	GoodFood* pgfood = new GoodFood;//����ʳ��
	BadFood* pbfood = new BadFood;//�����ϰ�
	Score1 score1;
	Score2 score2;
	mciSendString("open gamebgm.mp3 alias GAMEBGM",0,0,0);//��Ϸ��ѭ������
	mciSendString("play GAMEBGM repeat",0,0,0);
	while(1)
	{
		cleardevice();//ˢ�´���
		psnake->DrawSnake();//����
		psnake->MoveSnake();//�ߵ��ƶ�
		GetFood(psnake,pgfood,score1,score2);
		score2.ShowScore();//�����µ���߷�
		score2.ifsScore();//д������
		pgfood->CrtFood();//��ȡʳ�ﻥ��
		pbfood->CrtFood();
		if(kbhit())//��鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
		{
			psnake->Control();//������
		}
		Sleep(50);//ˢ�£������ٶ�
		if(psnake->GetSnkPos(0).x<0 || psnake->GetSnkPos(0).y<0 ||
			psnake->GetSnkPos(0).x>800 || psnake->GetSnkPos(0).y>800)//������������:ײǽ  
		{
			mciSendString("close GAMEBGM",0,0,0);
			PlaySound(TEXT("over.wav"),NULL,SND_FILENAME | SND_ASYNC);//����һ��
			MessageBox(NULL,"GAME OVER","TEXT",MB_OK | MB_SYSTEMMODAL);//�����Ի���������Ļ��ǰ�棻
ABG:
			break;
		}
		for(int i=1;i<psnake->GetSnkStSz();i++)
		{
			if(psnake->GetSnkPos(0).x == psnake->GetSnkPos(i).x && 
				psnake->GetSnkPos(0).y == psnake->GetSnkPos(i).y)//������������:ײ����
			{
				mciSendString("close GAMEBGM",0,0,0);
				PlaySound(TEXT("over.wav"),NULL,SND_FILENAME | SND_ASYNC);//����һ��
				MessageBox(NULL,"GAME OVER","TEXT",MB_OK | MB_SYSTEMMODAL);
				goto ABG;
				break;
			}
		}
		for(int i=0;i<10;i++)
		{
			if(pbfood->Getpos2(i).x==psnake->GetSnkPos(0).x && pbfood->Getpos2(i).y==psnake->GetSnkPos(0).y)//������������:�����ϰ�
			{
				mciSendString("close GAMEBGM",0,0,0);
				PlaySound(TEXT("over.wav"),NULL,SND_FILENAME | SND_ASYNC);//����һ��
				MessageBox(NULL,"GAME OVER","TEXT",MB_OK | MB_SYSTEMMODAL);
				goto ABG;
				break;
			}
		}
	}
	delete psnake;//�ͷŶ���
	delete pgfood;
	delete pbfood;

}
int main()
{
	while(1)
	{
		Menu();
		MOUSEMSG mouse;
		while(1)
		{
		mouse=GetMouseMsg();
		if(mouse.uMsg==WM_LBUTTONDOWN && (mouse.x>287 && mouse.x<503)&& (mouse.y>207 && mouse.y<268))//�����������ʱ������Ϣ
		{
			mciSendString("close STARTBGM",0,0,0);
			PlaySound(TEXT("click.wav"),NULL,SND_FILENAME | SND_ASYNC);//����һ��
			cleardevice();
			Game();
			break;
		}
		else if(mouse.uMsg==WM_LBUTTONDOWN && (mouse.x>277 && mouse.x<500)&& (mouse.y>326 && mouse.y<383))
		{
			mciSendString("close STARTBGM",0,0,0);
			PlaySound(TEXT("click.wav"),NULL,SND_FILENAME | SND_ASYNC);//����һ��
			cleardevice();
			Game2();
			break;
		}
		else if(mouse.uMsg==WM_LBUTTONDOWN && (mouse.x>274 && mouse.x<494)&& (mouse.y>454 && mouse.y<511))
		{
			mciSendString("close STARTBGM",0,0,0);
			PlaySound(TEXT("click.wav"),NULL,SND_FILENAME | SND_ASYNC);//����һ��
			cleardevice();
			GameExplain();
			break;
		}
		else if(mouse.uMsg==WM_LBUTTONDOWN && (mouse.x>308 && mouse.x<424)&& (mouse.y>588 && mouse.y<648))
		{
			mciSendString("close STARTBGM",0,0,0);
			PlaySound(TEXT("click.wav"),NULL,SND_FILENAME | SND_ASYNC);//����һ��
			cleardevice();
			Exit();
			break;
		}
		}
	}
	getch();
	closegraph();
	return 0;
}