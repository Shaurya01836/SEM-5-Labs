#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#define MAXCOUNT 30

void fractal(float left, float top, float xside, float yside) {
    float xscale, yscale, zx, zy, cx, tempx, cy;
    int x, y, i, j;
    int maxx, maxy, count;

    maxx = getmaxx();
    maxy = getmaxy();
    xscale = xside / maxx;
    yscale = yside / maxy;

    rectangle(0, 0, maxx, maxy);

    for(y = 1; y < maxy - 1; y++) {
	for(x = 1; x < maxx - 1; x++) {
	    cx = x * xscale + left;
	    cy = y * yscale + top;
	    zx = 0;
	    zy = 0;
	    count = 0;
	    while(zx*zx + zy*zy < 4 && count < MAXCOUNT) {
		tempx = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = tempx;
		count = count + 1;
	    }
	    putpixel(x, y, count);
	}
    }
}

void main() {
    int gd = DETECT, gm, errorcode;
    float left, top, xside, yside;
    // setting the left, top, xside and yside for the screen and image to be displayed
    left = -1.75;
    top = -0.25;
    xside = 0.25;
    yside = 0.45;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    fractal(left, top, xside, yside);
    getch();
    closegraph();
}
