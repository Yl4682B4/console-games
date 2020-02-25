#include <iostream>
#include <Windows.h>
#include <ctime>
int LES;
using namespace std;
int COML=0;
HANDLE handle_out;  
HANDLE handle_in;
CONSOLE_SCREEN_BUFFER_INFO csbi;
void gotoxy(int x, int y)  {  
    COORD pos = {x,y};  
    SetConsoleCursorPosition(handle_out, pos);  
}
class MAP{
	public:
		int value;
		int clicked;
		int BOOM;
		int sign;
		MAP(){
			value=-1;
			clicked=0;
			BOOM=0;
			sign=0;
		}
};
MAP map[22][22];
void Clear(int x,int y){
	if(map[x][y].clicked==0) COML++;
	map[x][y].clicked=1;
	for(int qq=x-1;qq<=x+1;qq++){
		for(int ww=y-1;ww<=y+1;ww++){
			if(qq==0 || qq==21 || ww==0 || ww==21 || map[qq][ww].clicked==1) continue;
			gotoxy(qq*2,ww);
			cout<<map[qq][ww].value<<" ";
			if(map[qq][ww].clicked==0)	COML++;
			if(map[qq][ww].value==0 && map[qq][ww].clicked==0){
				map[qq][ww].clicked=1;
				Clear(qq,ww);
			}
			map[qq][ww].clicked=1;
		}
	}
}
int main(){
	do{
		cout<<"˵���,����Ҫ���ٸ�����?(1-300)";
		cin>>LES;
	}while(LES>=300 || LES<=0);
	int bgck = clock();
	int count=0;
	handle_in = GetStdHandle(STD_INPUT_HANDLE);      //��ñ�׼�����豸���  
    handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //��ñ�׼����豸���  
    INPUT_RECORD mouserec;      //���������¼��ṹ��  
    DWORD res;      //���ڴ洢��ȡ��¼  
    COORD pos;      //���ڴ洢��굱ǰλ��  
    COORD size = {80, 25};  //���ڻ�������С  
    GetConsoleScreenBufferInfo(handle_out, &csbi);  //��ô��ڻ�������Ϣ  
    SetConsoleScreenBufferSize(handle_out, size);   //���ô��ڻ�������С  
	int i,j;
	srand(time(NULL));
	while(count != LES){
		int x=rand()%20;
		int y=rand()%20;
		x++;y++;
		if(map[x][y].BOOM==0 && (x>=3 || y>=3)){
			map[x][y].BOOM=1;
			count++;
			gotoxy(x*2,y);
		}
	}
	for(i=1;i<=20;i++){
		for(j=1;j<=20;j++){
			gotoxy(i*2,j);
			cout<<"��";
			int num=0;
			for(int qq=i-1;qq<=i+1;qq++){
				for(int ww=j-1;ww<=j+1;ww++){
					if(map[qq][ww].BOOM==1 && (qq!=i || ww!=j))
						num++;
				}
			}
			map[i][j].value=num;
		}
	}
	int lst=0;
	int nw=0;
	int k=0;
	while(1){
		nw = clock();
		if(nw-lst>=1000){
			lst=nw;
			k=nw/1000;
			gotoxy(3,22);
			cout<<"����ʱ:"<<k<<"��"<<"����"<<400-LES-COML<<"����������";
		}
		
		if(COML==400-LES){
			gotoxy(3,22);
			cout<<"�Բۣ�����ô��ȻӮ�ˣ���ʱΪ"<<(1.0*clock()-bgck)/1000<<"��"<<endl;
			exit(0);
		}
		unsigned long hh;
		GetNumberOfConsoleInputEvents(handle_in,&hh);
		if(hh==0) continue;
		ReadConsoleInput(handle_in, &mouserec, 1, &res);
		pos = mouserec.Event.MouseEvent.dwMousePosition;
		if (mouserec.EventType == MOUSE_EVENT){  
            if (mouserec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
				if(pos.X>=2 && pos.X<=40 && pos.Y >=1 && pos.Y<=20){
					if(pos.X%2==1) pos.X--;
					if(map[pos.X/2][pos.Y].clicked==1 || map[pos.X/2][pos.Y].sign==1) continue;
					gotoxy(pos.X,pos.Y);
					if(map[pos.X/2][pos.Y].BOOM==1){
						gotoxy(3,22);
						cout<<"�����ˣ���������!"<<COML<<endl;
						exit(0);
					}
					cout<<map[pos.X/2][pos.Y].value<<" ";
					if(map[pos.X/2][pos.Y].value==0)
						Clear(pos.X/2,pos.Y);
					else COML++;map[pos.X/2][pos.Y].clicked=1;
				}
			}
			if (mouserec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED && mouserec.Event.MouseEvent.dwControlKeyState)  
            {  
				Sleep(100);
                if(pos.X>=2 && pos.X<=40 && pos.Y >=1 && pos.Y<=20){
					if(pos.X%2==1) pos.X--;
					if(map[pos.X/2][pos.Y].clicked==1) continue;
					gotoxy(pos.X,pos.Y);
					if(map[pos.X/2][pos.Y].sign==0){
						map[pos.X/2][pos.Y].sign=1;
						cout<<"��";
						Sleep(80);
					}
					else{
						map[pos.X/2][pos.Y].sign=0;
						cout<<"��";
					}
				}
            } 
        } 
	}
	return 0;
}