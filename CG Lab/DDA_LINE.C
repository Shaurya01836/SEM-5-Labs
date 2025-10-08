#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void DDL_Line_Algo(int x0, int x1 , int y0 ,int y1 ){
int dx = x1 - x0 ;
int dy = y1 - y0 ;
int steps , i ;
float Xinc , Yinc, x , y ;

	if(abs(dx) >= abs(dy)){
	steps = abs(dx);
	}
	else{
	steps = abs(dy);
	}

	Xinc = (float)dx/steps;
	Yinc = (float)dy/steps;

	x = x0 ;
	y = y0;

	putpixel(x,y,RED);

	for(i = 0 ; i <steps ; i++){
	x+= Xinc ;
	y+= Yinc ;
	putpixel(x,y,WHITE);
	}

}


void main (){
	    int gd = DETECT,gm;
	    int x0 = 100 , x1 = 200 , y0 = 50 , y1 = 100 ;
	    initgraph(&gd , &gm , "C:\\TURBOC3\\BGI");
	    DDL_Line_Algo(x0 , x1 , y0 , y1);
	    getch();

}