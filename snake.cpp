#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int width=40;
int height=20;
bool gameover;
int x,y,fx,fy;
enum eDirection{STOP=0,RIGHT,LEFT,UP,DOWN };
eDirection dir;
void start(){
	gameover=true;
	dir=STOP;
	x=width/2;
	y=height/2;
	fx=rand() %width;
	fy=rand() %height;
}
void block(){
	int i,j;
	system("cls");
	for (i=0;i<width+1;i++)
		cout<<"#";
	cout<<endl;
	for (i=0;i<height;i++){
		for (j=0;j<width;j++){
			if (j==0)
				cout<<"#";
			else if (i==y && j==x)
				cout<<"O";
			else if (i==fy && j==fx)
				cout<<"F";
			else
				cout<<" ";
			if (j==width-1)
				cout<<"#";
		}
		cout<<endl;
	}
	for (i=0;i<width+1;i++)
		cout<<"#";
	cout<<endl;
}
void input(){
	char p;
	if (_kbhit()){
//		scanf ("%c",&p);
		p=_getch();
		switch(p){
			case 'a': dir=LEFT;
					break;
			case 'd': dir=RIGHT;
					break;
			case 'w': dir=UP;
					break;
			case 's': dir=DOWN;
					break;
			default: gameover=false;
		}
	}
}
void logic(){
	switch(dir){
		case LEFT: x--;
				break;
		case RIGHT: x++;
				break;
		case UP: y--;
				break;
		case DOWN: y++;
				break;
	}
	if (x==width-1 || x==0 || y==height-1 || y==0)
		gameover=false;
	if (x==fx && y==fy){
		fx=rand()%width;
		fy=rand()%height;
	}
}
int main (){
	start();
	while(gameover){
		block();
		input();
		logic();
//		block();
		
	}
	return 0;
}
