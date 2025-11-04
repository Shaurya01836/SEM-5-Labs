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
    float sx, sy;
    float angle_deg, t;
    int tx, ty;

   
    int x[] = {100, 150, 150, 100};
    int y[] = {100, 100, 150, 150};

   
    int x_scaled[4], y_scaled[4];
    int x_rotated[4], y_rotated[4];
    int x_final[4], y_final[4];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("COMPOSITE 2D TRANSFORMATIONS\n");

  
    printf("Enter scaling factor for X (Sx): ");
    scanf("%f", &sx);
    printf("Enter scaling factor for Y (Sy): ");
    scanf("%f", &sy);


    printf("Enter rotation angle in degrees: ");
    scanf("%f", &angle_deg);
    t = angle_deg * (3.14 / 180.0); 


    printf("Enter translation factor for X (Tx): ");
    scanf("%d", &tx);
    printf("Enter translation factor for Y (Ty): ");
    scanf("%d", &ty);

    cleardevice();

   
    draw_rectangle(x, y, WHITE);

    /* --- Perform Composite Transformation --- */

    for (i = 0; i < 4; i++)
    {
        x_scaled[i] = (int)(x[i] * sx);
        y_scaled[i] = (int)(y[i] * sy);
    }


    for (i = 0; i < 4; i++)
    {
        x_rotated[i] = (int)(x_scaled[i] * cos(t) - y_scaled[i] * sin(t));
        y_rotated[i] = (int)(x_scaled[i] * sin(t) + y_scaled[i] * cos(t));
    }

  
    for (i = 0; i < 4; i++)
    {
        x_final[i] = x_rotated[i] + tx;
        y_final[i] = y_rotated[i] + ty;
    }

    draw_rectangle(x_final, y_final, GREEN);

    getch();
    closegraph();
}