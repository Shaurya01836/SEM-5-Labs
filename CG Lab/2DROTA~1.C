#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void draw_rectangle(int x[4], int y[4], int color)
{
    setcolor(color);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[3], y[3]);
    line(x[3], y[3], x[0], y[0]);
}

void main()
{
    int gd = DETECT, gm;
    int i;
    float angle_deg, t;

    int x[] = {300, 400, 400, 300};
    int y[] = {100, 100, 150, 150};

    int x_new[4];
    int y_new[4];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("2D ROTATION :\n");
    printf("Enter rotation angle in degrees: ");
    scanf("%f", &angle_deg);

    cleardevice();

    draw_rectangle(x, y, WHITE);

    t = angle_deg * (3.14 / 180.0);

    for (i = 0; i < 4; i++)
    {
        x_new[i] = (int)(x[i] * cos(t) - y[i] * sin(t));
        y_new[i] = (int)(x[i] * sin(t) + y[i] * cos(t));
    }

    draw_rectangle(x_new, y_new, GREEN);

    getch();
    closegraph();
}