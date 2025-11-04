#include<stdio.h>
#include<graphics.h>
#include<conio.h>


void main(){
	int gd = DETECT , gm ;
	initgraph(&gd, & gm , "C:\\TURBOC3\\BGI");
	line(100, 300 , 100, 50);
	line(100 , 300 , 500 , 300);
	bar3d(150 , 200 , 180 , 300 , 5 , 1);
	bar3d(200 , 150 , 230 , 300 , 5 , 1);
	bar3d(250, 220 , 280 , 300 , 5 , 1 );
	bar3d(300 , 180 , 330 , 300 , 5 , 1 );
	bar3d(350 , 250 , 380 , 300 , 5 , 1);
	bar3d(400 , 200 , 430 , 300 , 5 , 1);
	bar3d(450, 50 , 480 , 300 , 5 , 1 );
	getch();
}