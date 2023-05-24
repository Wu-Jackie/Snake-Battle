#include<iostream>
#include<graphics.h>
#include<conio.h>//通过控制台进行数据输入和输出
#include<mmsystem.h>//包含多媒体设备接口头文件
#include<Windows.h>
#include"point.h"
#include"Food.h"
#include"Score.h"
#include"Snake.h"
#pragma warning(disable:4996)
#pragma comment(lib,"winmm.lib")//加载静态库
using namespace std;

void Menu()
{
	initgraph(800,800);
	cleardevice();
	loadimage(NULL,"startbg.jpg",800,800);
	setbkmode(TRANSPARENT);
	mciSendString("open startbgm.mp3 alias STARTBGM",0,0,0);//开始音乐
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
		PlaySound(TEXT("click.wav"),NULL,SND_FILENAME | SND_ASYNC);//播放一次
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
		settextstyle(50,0,"等线");
		settextcolor(BLUE);
		outtextxy(330,300,"THANKS");
		outtextxy(330,360,"再见!!!");
		settextstyle(25,0,"等线");
		settextcolor(BLUE);
		outtextxy(20,20,"按任意键继续");
		outtextxy(600,20,"按0返回");
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
void GetFood(Snake* snake,GoodFood* goodfood,Score1& score1,Score2& score2)//获取食物互动
{
	if(goodfood->Getpos1().x==snake->GetSnkPos(0).x && goodfood->Getpos1().y==snake->GetSnkPos(0).y)
	{
		goodfood->SetFoodPos();//重新随机食物位置
		snake->GetSnkStSz()+=2;//蛇的长度增加
		score1.getscore1()+=10;//分数增加十分
		score2.getscore2()+=10;
		PlaySound(TEXT("eat.wav"),NULL, SND_FILENAME | SND_ASYNC);//播放一次
	}
}
void Game()//普通模式
{
	initgraph(800,800);
	setbkcolor(WHITE);
	Snake* psnake = new Snake;//创建蛇
	GoodFood* pgfood = new GoodFood;//创建食物
	Score1 score1;
	Score2 score2;
	mciSendString("open gamebgm.mp3 alias GAMEBGM",0,0,0);//游戏内循环音乐
	mciSendString("play GAMEBGM repeat",0,0,0);
	while(1)
	{
		cleardevice();//刷新窗口
		psnake->DrawSnake();//画蛇
		psnake->MoveSnake();//蛇的移动
		GetFood(psnake,pgfood,score1,score2);
		score1.ShowScore();//设置新的最高分
		score1.ifsScore();//写出分数
		pgfood->CrtFood();//获取食物互动
		if(kbhit())//检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
		{
			psnake->Control();//控制蛇
		}
		Sleep(50);//刷新，控制速度
		if(psnake->GetSnkPos(0).x<0 || psnake->GetSnkPos(0).y<0 ||
			psnake->GetSnkPos(0).x>800 || psnake->GetSnkPos(0).y>800)//设置死亡条件:撞墙  
		{
			mciSendString("close GAMEBGM",0,0,0);
			PlaySound(TEXT("over.wav"),NULL,SND_FILENAME | SND_ASYNC);//播放一次
			MessageBox(NULL,"GAME OVER","TEXT",MB_OK | MB_SYSTEMMODAL);//弹出对话框并置于屏幕最前面；
ABG:
			break;
		}
		for(int i=1;i<psnake->GetSnkStSz();i++)
		{
			if(psnake->GetSnkPos(0).x == psnake->GetSnkPos(i).x && 
				psnake->GetSnkPos(0).y == psnake->GetSnkPos(i).y)//设置死亡条件:撞身子
			{
				mciSendString("close GAMEBGM",0,0,0);
				PlaySound(TEXT("over.wav"),NULL,SND_FILENAME | SND_ASYNC);//播放一次
				MessageBox(NULL,"GAME OVER","TEXT",MB_OK | MB_SYSTEMMODAL);
				goto ABG;
				break;
			}
		}
	}
	delete psnake;//释放对象
	delete pgfood;
}
void Game2()//障碍模式
{
	initgraph(800,800);
	setbkcolor(WHITE);
	Snake* psnake = new Snake;//创建蛇
	GoodFood* pgfood = new GoodFood;//创建食物
	BadFood* pbfood = new BadFood;//创建障碍
	Score1 score1;
	Score2 score2;
	mciSendString("open gamebgm.mp3 alias GAMEBGM",0,0,0);//游戏内循环音乐
	mciSendString("play GAMEBGM repeat",0,0,0);
	while(1)
	{
		cleardevice();//刷新窗口
		psnake->DrawSnake();//画蛇
		psnake->MoveSnake();//蛇的移动
		GetFood(psnake,pgfood,score1,score2);
		score2.ShowScore();//设置新的最高分
		score2.ifsScore();//写出分数
		pgfood->CrtFood();//获取食物互动
		pbfood->CrtFood();
		if(kbhit())//检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
		{
			psnake->Control();//控制蛇
		}
		Sleep(50);//刷新，控制速度
		if(psnake->GetSnkPos(0).x<0 || psnake->GetSnkPos(0).y<0 ||
			psnake->GetSnkPos(0).x>800 || psnake->GetSnkPos(0).y>800)//设置死亡条件:撞墙  
		{
			mciSendString("close GAMEBGM",0,0,0);
			PlaySound(TEXT("over.wav"),NULL,SND_FILENAME | SND_ASYNC);//播放一次
			MessageBox(NULL,"GAME OVER","TEXT",MB_OK | MB_SYSTEMMODAL);//弹出对话框并置于屏幕最前面；
ABG:
			break;
		}
		for(int i=1;i<psnake->GetSnkStSz();i++)
		{
			if(psnake->GetSnkPos(0).x == psnake->GetSnkPos(i).x && 
				psnake->GetSnkPos(0).y == psnake->GetSnkPos(i).y)//设置死亡条件:撞身子
			{
				mciSendString("close GAMEBGM",0,0,0);
				PlaySound(TEXT("over.wav"),NULL,SND_FILENAME | SND_ASYNC);//播放一次
				MessageBox(NULL,"GAME OVER","TEXT",MB_OK | MB_SYSTEMMODAL);
				goto ABG;
				break;
			}
		}
		for(int i=0;i<10;i++)
		{
			if(pbfood->Getpos2(i).x==psnake->GetSnkPos(0).x && pbfood->Getpos2(i).y==psnake->GetSnkPos(0).y)//设置死亡条件:碰到障碍
			{
				mciSendString("close GAMEBGM",0,0,0);
				PlaySound(TEXT("over.wav"),NULL,SND_FILENAME | SND_ASYNC);//播放一次
				MessageBox(NULL,"GAME OVER","TEXT",MB_OK | MB_SYSTEMMODAL);
				goto ABG;
				break;
			}
		}
	}
	delete psnake;//释放对象
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
		if(mouse.uMsg==WM_LBUTTONDOWN && (mouse.x>287 && mouse.x<503)&& (mouse.y>207 && mouse.y<268))//点击鼠标左键的时候发送消息
		{
			mciSendString("close STARTBGM",0,0,0);
			PlaySound(TEXT("click.wav"),NULL,SND_FILENAME | SND_ASYNC);//播放一次
			cleardevice();
			Game();
			break;
		}
		else if(mouse.uMsg==WM_LBUTTONDOWN && (mouse.x>277 && mouse.x<500)&& (mouse.y>326 && mouse.y<383))
		{
			mciSendString("close STARTBGM",0,0,0);
			PlaySound(TEXT("click.wav"),NULL,SND_FILENAME | SND_ASYNC);//播放一次
			cleardevice();
			Game2();
			break;
		}
		else if(mouse.uMsg==WM_LBUTTONDOWN && (mouse.x>274 && mouse.x<494)&& (mouse.y>454 && mouse.y<511))
		{
			mciSendString("close STARTBGM",0,0,0);
			PlaySound(TEXT("click.wav"),NULL,SND_FILENAME | SND_ASYNC);//播放一次
			cleardevice();
			GameExplain();
			break;
		}
		else if(mouse.uMsg==WM_LBUTTONDOWN && (mouse.x>308 && mouse.x<424)&& (mouse.y>588 && mouse.y<648))
		{
			mciSendString("close STARTBGM",0,0,0);
			PlaySound(TEXT("click.wav"),NULL,SND_FILENAME | SND_ASYNC);//播放一次
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