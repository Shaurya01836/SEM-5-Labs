#include <stdio.h>
#include <conio.h>
#include <graphics.h>


void draw_rectangle(int x_coords[4], int y_coords[4], int color) {
    setcolor(color);
    line(x_coords[0], y_coords[0], x_coords[1], y_coords[1]);
    line(x_coords[1], y_coords[1], x_coords[2], y_coords[2]);
    line(x_coords[2], y_coords[2], x_coords[3], y_coords[3]);
    line(x_coords[3], y_coords[3], x_coords[0], y_coords[0]);
}

void main() {
    int gd = DETECT, gm;
    int i;
    float shx;

   
    int x[] = {100, 200, 200, 100};
    int y[] = {100, 100, 150, 150};
    
  
    int x_new[4];
    int y_new[4];

  
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    cleardevice();

    printf("--- 2D SHEAR (Along X-axis) ---\n");
    printf("Enter shear factor for X (Shx): ");
    scanf("%f", &shx);

    cleardevice();
    
  
    draw_rectangle(x, y, WHITE);
    outtextxy(10, 10, "Original Object (White)");

    // Apply the shear transformation
    // x' = x + shx * y
    // y' = y
    for (i = 0; i < 4; i++) {
        x_new[i] = (int)(x[i] + shx * y[i]);
        y_new[i] = y[i];
    }

    // Draw the sheared object
    draw_rectangle(x_new, y_new, GREEN);
    outtextxy(10, 30, "Sheared Object (Green)");

    getch();
    closegraph();
}