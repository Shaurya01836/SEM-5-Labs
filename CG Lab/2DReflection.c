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
    int i, choice;
    int mid_x, mid_y;

    int x[] = {150, 250, 250, 150};
    int y[] = {150, 150, 200, 200};
    
   
    int x_new[4];
    int y_new[4];

   
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


   
    mid_x = getmaxx() / 2;
    mid_y = getmaxy() / 2;
    
   
    line(0, mid_y, getmaxx(), mid_y); // X-axis
    line(mid_x, 0, mid_x, getmaxy()); // Y-axis

    printf("--- 2D REFLECTION ---\n");
    printf("1. Reflect across X-axis\n");
    printf("2. Reflect across Y-axis\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    cleardevice();
    
    
    draw_rectangle(x, y, WHITE);
    outtextxy(10, 10, "Original Object (White)");

   
    if (choice == 1) { // Reflect across X-axis
        for (i = 0; i < 4; i++) {
            x_new[i] = x[i];
            y_new[i] = mid_y + (mid_y - y[i]); // y' = 2*mid_y - y
        }
    } else if (choice == 2) { // Reflect across Y-axis
        for (i = 0; i < 4; i++) {
            x_new[i] = mid_x + (mid_x - x[i]); // x' = 2*mid_x - x
            y_new[i] = y[i];
        }
    }

    
    draw_rectangle(x_new, y_new, GREEN);
    outtextxy(10, 30, "Reflected Object (Green)");

    getch();
    closegraph();
}