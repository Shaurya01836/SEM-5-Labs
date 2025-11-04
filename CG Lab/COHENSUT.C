#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

int Left = 1, Right = 2, Bottom = 4, Top = 8, xmin = 200, ymin = 200, xmax = 400, ymax = 400;

int getcode(int x, int y) {
    int code = 0;
    if (y > ymax) code |= Top;
    if (y < ymin) code |= Bottom;
    if (x > xmax) code |= Right;
    if (x < xmin) code |= Left;
    return code;
}

void main() {
    int gd = DETECT, gm;
    int x1 = 150, y1 = 150, x2 = 350, y2 = 350;
    int outcode1, outcode2, accept = 0, x, y, temp;
    float m;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);

    outcode1 = getcode(x1, y1);
    outcode2 = getcode(x2, y2);

    while (1) {
        m = (float)(y2 - y1) / (x2 - x1);
        if (outcode1 == 0 && outcode2 == 0) {
            accept = 1;
            break;
        } else if ((outcode1 & outcode2) != 0) {
           
            break;
        } else {
          
            if (outcode1 != 0)
                temp = outcode1;
            else
                temp = outcode2;

            if (temp & Top) {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            } else if (temp & Bottom) {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            } else if (temp & Left) {
                y = y1 + m * (xmin - x1);
                x = xmin;
            } else if (temp & Right) {
                y = y1 + m * (xmax - x1);
                x = xmax;
            }

           
            if (temp == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }

    cleardevice();
    rectangle(xmin, ymin, xmax, ymax);
    if (accept)
        line(x1, y1, x2, y2);

    getch();
    closegraph();
}