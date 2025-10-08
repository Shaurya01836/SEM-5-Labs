#include<stdio.h>
#include<graphics.h>
#include<conio.h>


void MidPoint(int r , int X0 , int Y0){
int x = r ;
int y = 0 ;
int p = 1-r ;
while(x>=y){
	putpixel(X0+x,Y0+y,RED);
	putpixel(X0-x,Y0+y,RED);
	putpixel(X0+x,Y0-y,RED);
	putpixel(X0-x,Y0-y,RED);
	putpixel(X0+y,Y0+x,RED);
	putpixel(X0-y,Y0+x,RED);
	putpixel(X0+y,Y0-x,RED);
	putpixel(X0-y,Y0-x,RED);
	y++;
if(p <= 0){
p+=2 * y + 1;
}
else{
x--;
p+= 2*(y-x)+1;
}
}
}

void main(){
int gd = DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
MidPoint(50,300,250);
getch();
closegraph();
}