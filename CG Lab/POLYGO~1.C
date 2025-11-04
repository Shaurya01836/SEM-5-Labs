#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define round(a) ((int)(a+0.5))

int k;
float xmin, xmax, ymin, ymax, arr[20], m;

void clipleft(float x1, float y1, float x2, float y2) {
    if(x2 - x1)
        m = (y2 - y1) / (x2 - x1);
    else
        m = -100000;
    if(x1 >= xmin && x2 >= xmin) {
        arr[k++] = x2;
        arr[k++] = y2;
    }
    if(x1 < xmin && x2 >= xmin) {
        arr[k++] = xmin;
        arr[k++] = y1 + m * (xmin - x1);
        arr[k++] = x2;
        arr[k++] = y2;
    }
    if(x1 >= xmin && x2 < xmin) {
        arr[k++] = xmin;
        arr[k++] = y1 + m * (xmin - x1);
    }
}

void cliptop(float x1, float y1, float x2, float y2) {
    if(y2 - y1)
        m = (x2 - x1) / (y2 - y1);
    else
        m = 100000;
    if(y1 <= ymax && y2 <= ymax) {
        arr[k++] = x2;
        arr[k++] = y2;
    }
    if(y1 > ymax && y2 <= ymax) {
        arr[k++] = x1 + m * (ymax - y1);
        arr[k++] = ymax;
        arr[k++] = x2;
        arr[k++] = y2;
    }
    if(y1 <= ymax && y2 > ymax) {
        arr[k++] = x1 + m * (ymax - y1);
        arr[k++] = ymax;
    }
}

void clipright(float x1, float y1, float x2, float y2) {
    if(x2 - x1)
        m = (y2 - y1) / (x2 - x1);
    else
        m = 100000;
    if(x1 <= xmax && x2 <= xmax) {
        arr[k++] = x2;
        arr[k++] = y2;
    }
    if(x1 > xmax && x2 <= xmax) {
        arr[k++] = xmax;
        arr[k++] = y1 + m * (xmax - x1);
        arr[k++] = x2;
        arr[k++] = y2;
    }
    if(x1 <= xmax && x2 > xmax) {
        arr[k++] = xmax;
        arr[k++] = y1 + m * (xmax - x1);
    }
}

void clipBottom(float x1, float y1, float x2, float y2) {
    if(y2 - y1)
        m = (x2 - x1) / (y2 - y1);
    else
        m = 100000;
    if(y1 >= ymin && y2 >= ymin) {
        arr[k++] = x2;
        arr[k++] = y2;
    }
    if(y1 < ymin && y2 >= ymin) {
        arr[k++] = x1 + m * (ymin - y1);
        arr[k++] = ymin;
	arr[k++] = x2;
	arr[k++] = y2;
    }
    if(y1 >= ymin && y2 < ymin) {
	arr[k++] = x1 + m * (ymin - y1);
	arr[k++] = ymin;
    }
}

void main() {
    int gd = DETECT, gm, n, poly[20];
    float xi, yi, xf, yf, polygon[20];
    int i ;
    clrscr();
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("Enter xmin, ymin: ");
    scanf("%f%f", &xmin, &ymin);
    printf("Enter xmax, ymax: ");
    scanf("%f%f", &xmax, &ymax);
    printf("Enter sides: ");
    scanf("%d", &n);

    printf("Enter coordinates:\n");
    for( i = 0; i < 2 * n; i++)
	scanf("%f", &polygon[i]);
    for( i = 0; i < 2 * n; i++)
	poly[i] = round(polygon[i]);

    rectangle(xmin, ymin, xmax, ymax);
    fillpoly(n, poly);
    getch();
    cleardevice();

    k = 0;
    for( i = 0; i < 2 * n; i += 2)
	clipleft(polygon[i], polygon[i+1], polygon[(i+2)%(2*n)], polygon[(i+3)%(2*n)]);
    for( i = 0; i < k; i++)
	polygon[i] = arr[i];
    n = k / 2;
    k = 0;

    for( i = 0; i < 2 * n; i += 2)
	cliptop(polygon[i], polygon[i+1], polygon[(i+2)%(2*n)], polygon[(i+3)%(2*n)]);
    for( i = 0; i < k; i++)
	polygon[i] = arr[i];
    n = k / 2;
    k = 0;

    for( i = 0; i < 2 * n; i += 2)
	clipright(polygon[i], polygon[i+1], polygon[(i+2)%(2*n)], polygon[(i+3)%(2*n)]);
    for( i = 0; i < k; i++)
	polygon[i] = arr[i];
    n = k / 2;
    k = 0;

    for( i = 0; i < 2 * n; i += 2)
	clipBottom(polygon[i], polygon[i+1], polygon[(i+2)%(2*n)], polygon[(i+3)%(2*n)]);
    for( i = 0; i < k; i++)
	poly[i] = round(arr[i]);
    if(k)
	fillpoly(k/2, poly);

    rectangle(xmin, ymin, xmax, ymax);
    getch();
}
