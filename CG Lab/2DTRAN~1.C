#include <stdio.h>
#include <conio.h>
#include <graphics.h>


void draw_rectangle(int x[4], int y[4], int color) {
    setcolor(color);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[3], y[3]);
    line(x[3], y[3], x[0], y[0]);
}

void main() {
    int gd = DETECT, gm;
    int i, tx, ty;


    int x[] = {100, 200, 200, 100};
    int y[] = {100, 100, 150, 150};


    int x_new[4];
    int y_new[4];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("2D TRANSLATION:\n");
    printf("Enter translation factor for X (Tx): ");
    scanf("%d", &tx);
    printf("Enter translation factor for Y (Ty): ");
    scanf("%d", &ty);

    cleardevice();


    draw_rectangle(x, y, WHITE);


    for (i = 0; i < 4; i++) {
	x_new[i] = x[i] + tx;
	y_new[i] = y[i] + ty;
    }


    draw_rectangle(x_new, y_new, GREEN);

    getch();
    closegraph();
}