#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
void main()
{
    int x11, y11, x21, y21, x12, y12;
    int x22, y22, x1, y1, x2, y2, x3, y3;
    int x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, sf, sy;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
    // 1st rectangle
    printf("enter coordinates of 1st rectangle : \n");
    scanf("%d%d%d%d", &x11, &y11, &x21, &y21);
    printf("enter coordinate of 2nd rectangle : \n");
    scanf("%d%d%d%d", &x12, &y12, &x22, &y22);
    printf("enter coordinates of first  line  : \n");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("enter coordinates of second line  : \n");
    scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
    printf("enter coordinate of third line : \n");
    scanf("%d%d%d%d", &x5, &y5, &x6, &y6);
    printf("enter coordinates of fourth line : \n");
    scanf("%d%d%d%d", &x7, &y7, &x8, &y8);
    rectangle(x11, y11, x21, y21);
    // 2nd rectangle
    rectangle(x12, y12, x22, y22);
    line(x1, y1, x2, y2);
    line(x3, y3, x4, y4);
    line(x5, y5, x6, y6);
    line(x7, y7, x8, y8);
    printf("enter translation factor\n");
    scanf("%d%d", &sf , &sy);
    setcolor(GREEN);
    rectangle(x11 + sf, y11 + sy, x21 + sf, y21 + sy);
    rectangle(x12 + sf, y12 + sy, x22 + sf, y22 + sy);
    line(x1 + sf, y1 + sy, x2 + sf, y2 + sy);
    line(x3 + sf, y3 + sy, x4 + sf, y4 + sy);
    line(x5 + sf, y5 + sy, x6 + sf, y6 + sy);
    line(x7 + sf, y7 + sy, x8 + sf, y8 + sy);
    getch();
    closegraph();
}
