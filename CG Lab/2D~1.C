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

int main()
{
    int gd = DETECT, gm;
    int i, choice, mid_x, mid_y, sub_choice;
    float sx, sy, shx;
    float angle_deg, t;

    int x[] = {100, 150, 150, 100};
    int y[] = {100, 100, 150, 150};

    int x_new[4];
    int y_new[4];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    do
    {
	printf("1.Scaling\n");
	printf("2.Rotation\n");
	printf("3.Reflection\n");
	printf("4.Shear\n");
	printf("5.Exit\n");
	printf("Enter your choice : ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
	    printf("2D SCALING :\n");
	    printf("Enter scaling factor for X (Sx): ");
	    scanf("%f", &sx);
	    printf("Enter scaling factor for Y (Sy): ");
	    scanf("%f", &sy);
	    cleardevice();

	    draw_rectangle(x, y, WHITE);

	    for (i = 0; i < 4; i++)
	    {
		x_new[i] = (int)(x[i] * sx);
		y_new[i] = (int)(y[i] * sy);
	    }

	    draw_rectangle(x_new, y_new, GREEN);

	    break;
	case 2:
	    printf("2D ROTATION :\n");
	    printf("Enter rotation angle in degrees: ");
	    scanf("%f", &angle_deg);

	    cleardevice();

	    draw_rectangle(x, y, WHITE);

	    t = angle_deg * (3.1416 / 180.0);

	    for (i = 0; i < 4; i++)
	    {
		x_new[i] = (int)(x[i] * cos(t) - y[i] * sin(t));
		y_new[i] = (int)(x[i] * sin(t) + y[i] * cos(t));
	    }

	    draw_rectangle(x_new, y_new, GREEN);
	    break;

	case 3:
	    mid_x = getmaxx() / 2;
	    mid_y = getmaxy() / 2;

	    printf(" 2D REFLECTION \n");
	    printf("1. Reflect across X-axis\n");
	    printf("2. Reflect across Y-axis\n");
	    printf("Enter your choice: ");
	    scanf("%d", &sub_choice);

	    cleardevice();
	    // Draw axes
	    line(0, mid_y, getmaxx(), mid_y);
	    line(mid_x, 0, mid_x, getmaxy());

	    draw_rectangle(x, y, WHITE);

	    if (sub_choice == 1)
	    {
		for (i = 0; i < 4; i++)
		{
		    x_new[i] = x[i];
		    y_new[i] = 2 * mid_y - y[i];
		}
	    }
	    else if (sub_choice == 2)
	    {
		for (i = 0; i < 4; i++)
		{
		    x_new[i] = 2 * mid_x - x[i];
		    y_new[i] = y[i];
		}
	    }
	    else
	    {
		printf("Invalid input\n");
		break;
	    }

	    draw_rectangle(x_new, y_new, GREEN);

	    break;

	case 4:
	    printf("2D SHEAR (Along X-axis)\n");
	    printf("Enter shear factor for X (Shx): ");
	    scanf("%f", &shx);

	    cleardevice();

	    draw_rectangle(x, y, WHITE);

	    for (i = 0; i < 4; i++)
	    {
		x_new[i] = (int)(x[i] + shx * y[i]);
		y_new[i] = y[i];
	    }

	    draw_rectangle(x_new, y_new, GREEN);

	    break;

	case 5:
	    printf("exit");
	    break;
	default:
	    printf("Invalid input");
	    break;
	}

	getch();
	cleardevice();
    } while (choice != 5);

    closegraph();
    return 0;
}
