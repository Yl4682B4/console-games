#ifndef MY_H
#define MY_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#endif
int skills[10];
int compare(int,int,int);
int Give_ATK(int,int,int);
void Chicken();
void Shop();
void FIGHTERs();
void skill();
void CAll(int,int,int);
void Enemy_mv(int);
void Battle_draw();
void Tiger();
void Mapdraw();
int Mov_system(int,int,int);
void Battle(int,int,int,int);
void Clear(int,int,int,int);
void Battle_TP();
void Mapset(char[21][23]);
void Fillwith(WORD,int,int,int,int);
void MAP();
void ps(int);
void MajSelect();
void Show_words(char*,int,int,int);
void title();
void title_draw(char*,int,int,int,int,int,int);
class Fighter{
	public:
		char lk[10];
		char name[20];
		clock_t lst_atk;
		int price;
		int x;
		int y;
		int dirc;
		int type;
		int size;
		int speed;
		int hp;
		int spec;
		int exist;
		Fighter(){
			lst_atk=0;
			exist=-1;
		}
		void set(int ax=0,int by=0,int cdirc=0,int dtype=0,int esize=0,int fspeed=0,int ghp=0,int hspec=0,int iexist=0){
			x=ax;
			y=by;
			dirc=cdirc;
			type=dtype;
			size=esize;
			speed=fspeed;
			hp=ghp;
			spec=hspec;
			exist=iexist;
		}
};
Fighter ours[500];
Fighter enemys[8000];
Fighter selfTYPE[10];
class charactar{
	public:
		char lk[10];
		int gold;
		int pro;
		int x;
		int y;
		charactar(){
		gold=0;
		pro=0;
		}
};
class MAPtp{
	public:
		int pass;
		int type;
		MAPtp(){
			pass=0;
			type=0;
		}
};
char bkst[21][23]={
	"1111111111111111111111",
	"1000000010000010000001",
	"1000100010000010000001",
	"1000104010050010006001",
	"1000100010000010000001",
	"1000100010000010000001",
	"1000100010000010000001",
	"1111110111011111110111",
	"1000100000000000000001",
	"1011100000000000000001",
	"1000000000000000000001",
	"1000100000000000010101",
	"1000100000000000010101",
	"1000100000000000010101",
	"1300100000000000010101",
	"1111100000000000010101",
	"1700000000000000010101",
	"1000100000000000010101",
	"1000100000000000010101",
	"1111111111111111112111"
};  //0为普通空地 1为墙壁 2为战场入口 3为老虎机 4567 技股商闷
char btmp[21][23]={
	"1111111111211111111111",
	"1000000000200000000001",
	"1002222200200000000001",
	"1002000200200000000001",
	"1002000200222222222001",
	"1002000200000000002001",
	"1002000200000000002001",
	"1002000200222222202001",
	"1002000200200000202001",
	"1002000200200000202001",
	"1002000200200000202001",
	"1002000200200000202001",
	"1002000300200000202001",
	"1002000000200000202001",
	"1002000000200000202001",
	"1002000000200000202001",
	"1002222222200000222001",
	"1000000000000000000001",
	"1000000000000000000001",
	"1111111111111111111111"
};	// 0为自由地 1为障碍 2为怪物道路 3为终点 4为守卫单位 5为怪物单位
MAPtp bk[30][30]; //2-21(行) ; 2-23(列) accessable;
HANDLE hd_in=GetStdHandle(STD_INPUT_HANDLE);
HANDLE hd_ot=GetStdHandle(STD_OUTPUT_HANDLE);
INPUT_RECORD event;
COORD pos;
CONSOLE_CURSOR_INFO cci;
CONSOLE_SCREEN_BUFFER_INFO sbi;
DWORD res;
void GotoXY(int x,int y){
	pos.X = 2*x;
	pos.Y = y;
	SetConsoleCursorPosition(hd_ot,pos);
}
void SetTxtMode(WORD a,int c=1){
	if(c==0) a= FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN ;
	SetConsoleTextAttribute(hd_ot,a);
}
void Hide(){
	GetConsoleCursorInfo(hd_ot, &cci);
	cci.bVisible=false;
	SetConsoleCursorInfo(hd_ot, &cci);  
}
int SeeMessage(){
	unsigned long a;
	GetNumberOfConsoleInputEvents(hd_in,&a);
	return a;
}
void SetWindow()
{
	GetConsoleScreenBufferInfo(hd_ot, &sbi);
	COORD size = {60,30};
	SetConsoleTitle("Game");
	SetConsoleScreenBufferSize(hd_ot, size);
	SMALL_RECT rc = {0, 0, 59, 29};
    SetConsoleWindowInfo(hd_ot, 1, &rc);
}
void TYPEset()
{
	//module-------------------------------
	strcpy(selfTYPE[0].lk,"剑");
	selfTYPE[0].spec = 20;
	selfTYPE[0].speed = 400;
	strcpy(selfTYPE[0].name,"剑士");
	selfTYPE[0].exist = 1;
	selfTYPE[0].price = 25;
	selfTYPE[0].size = 1;
	selfTYPE[0].type = 2;
	//moduleEND----------------------------
	strcpy(selfTYPE[1].lk,"弓");
	selfTYPE[1].spec = 50;
	selfTYPE[1].speed = 500;
	strcpy(selfTYPE[1].name,"弓手");
	selfTYPE[1].exist = 1;
	selfTYPE[1].price = 25;
	selfTYPE[1].size = 3;
	selfTYPE[1].type = 2;
	//moduleEND----------------------------
	strcpy(selfTYPE[2].lk,"炮");
	selfTYPE[2].spec = 50;
	selfTYPE[2].speed = 2000;
	strcpy(selfTYPE[2].name,"火炮");
	selfTYPE[2].exist = 1;
	selfTYPE[2].price = 25;
	selfTYPE[2].size = 3;
	selfTYPE[2].type = 9;
	//moduleEND----------------------------
	strcpy(selfTYPE[3].lk,"刺");
	selfTYPE[3].spec = 9999999;
	selfTYPE[3].speed = 5000;
	strcpy(selfTYPE[3].name,"刺客");
	selfTYPE[3].exist = -1;
	selfTYPE[3].price = 140;
	selfTYPE[3].size = 3;
	selfTYPE[3].type = 9;
	//moduleEND----------------------------
	strcpy(selfTYPE[4].lk,"搜");
	selfTYPE[4].spec = 55;
	selfTYPE[4].speed = 300;
	strcpy(selfTYPE[4].name,"搜尸");
	selfTYPE[4].exist = -1;
	selfTYPE[4].price = 100;
	selfTYPE[4].size = 1;
	selfTYPE[4].type = 6;
	//moduleEND----------------------------
	strcpy(selfTYPE[5].lk,"法");
	selfTYPE[5].spec = 166;
	selfTYPE[5].speed = 400;
	strcpy(selfTYPE[5].name,"法师");
	selfTYPE[5].exist = -1;
	selfTYPE[5].price = 200;
	selfTYPE[5].size = 50;
	selfTYPE[5].type = 2;
	//moduleEND----------------------------
}
void swap(int* a,int *b){
	int c=*a;
	*a = *b;
	*b = c;
}