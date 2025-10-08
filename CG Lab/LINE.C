#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main(){
	int gDriver = DETECT , gmode ;
	initgraph(&gDriver , &gmode , "C:\\TURBOC3\\BGI");
	setcolor(RED);
	line(100,200,900,100);
	getch();

}