

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Multiply two 3x3 matrices: C = A * B */
void matMul3x3(double A[3][3], double B[3][3], double C[3][3])
{
    int i, j, k;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
        {
            C[i][j] = 0.0;
            for (k = 0; k < 3; ++k)
                C[i][j] += A[i][k] * B[k][j];
        }
}

/* Apply 3x3 matrix M to point (x,y) using homogeneous coords -> (x', y') */
void applyTransform(double M[3][3], double x, double y, double *xout, double *yout)
{
    double hx = M[0][0] * x + M[0][1] * y + M[0][2] * 1.0;
    double hy = M[1][0] * x + M[1][1] * y + M[1][2] * 1.0;
    double hw = M[2][0] * x + M[2][1] * y + M[2][2] * 1.0;
    if (hw != 0.0)
    {
        *xout = hx / hw;
        *yout = hy / hw;
    }
    else
    { /* fallback */
        *xout = hx;
        *yout = hy;
    }
}

/* Create translation matrix T(tx, ty) */
void translationMatrix(double tx, double ty, double T[3][3])
{
    T[0][0] = 1;
    T[0][1] = 0;
    T[0][2] = tx;
    T[1][0] = 0;
    T[1][1] = 1;
    T[1][2] = ty;
    T[2][0] = 0;
    T[2][1] = 0;
    T[2][2] = 1;
}

/* Create scaling matrix S(sx, sy) */
void scalingMatrix(double sx, double sy, double S[3][3])
{
    S[0][0] = sx;
    S[0][1] = 0;
    S[0][2] = 0;
    S[1][0] = 0;
    S[1][1] = sy;
    S[1][2] = 0;
    S[2][0] = 0;
    S[2][1] = 0;
    S[2][2] = 1;
}

/* Create rotation matrix R(theta) where theta is in degrees */
void rotationMatrix(double theta_deg, double R[3][3])
{
    double theta = theta_deg * PI / 180.0;
    double c = cos(theta), s = sin(theta);
    R[0][0] = c;
    R[0][1] = -s;
    R[0][2] = 0;
    R[1][0] = s;
    R[1][1] = c;
    R[1][2] = 0;
    R[2][0] = 0;
    R[2][1] = 0;
    R[2][2] = 1;
}

/* Draw polygon given arrays of x,y and number of vertices */
void drawPolygonPoints(int x[], int y[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        int nx = (i + 1) % n;
        line(x[i], y[i], x[nx], y[nx]);
    }
}

int main()
{
    int gd = DETECT, gm;
    int maxx, maxy, midx, midy;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;

    double polyX[4] = {100, 160, 140, 80};
    double polyY[4] = {-20, -20, -90, -70}; /* y negative to appear "up" like typical Cartesian */

    int n = 4;

    /* Draw axes */
    setcolor(WHITE);
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
    outtextxy(10, 10, "Original Object (white)");

    /* draw original polygon in white (offset to screen coords) */
    {
        int sx[4], sy[4];
        for (int i = 0; i < n; ++i)
        {
            sx[i] = (int)round(midx + polyX[i]);
            sy[i] = (int)round(midy + polyY[i]);
        }
        setcolor(WHITE);
        drawPolygonPoints(sx, sy, n);
    }

    /* Get transformation parameters from user */
    double sx_factor, sy_factor, angle_deg, tx, ty;
    printf("Enter scaling factors (sx sy): ");
    scanf("%lf %lf", &sx_factor, &sy_factor);
    printf("Enter rotation angle in degrees (theta): ");
    scanf("%lf", &angle_deg);
    printf("Enter translation (tx ty): ");
    scanf("%lf %lf", &tx, &ty);

    /* Build matrices */
    double S[3][3], R[3][3], T[3][3];
    scalingMatrix(sx_factor, sy_factor, S);
    rotationMatrix(angle_deg, R);
    translationMatrix(tx, ty, T);

    double temp[3][3], M[3][3];
    matMul3x3(R, S, temp); /* temp = R * S */
    matMul3x3(T, temp, M); /* M = T * (R * S) = T * R * S */

    /* Apply composite M to polygon and draw transformed polygon */
    {
        int txs[4], tys[4];
        double xout, yout;
        for (int i = 0; i < n; ++i)
        {
            applyTransform(M, polyX[i], polyY[i], &xout, &yout);
            txs[i] = (int)round(midx + xout);
            tys[i] = (int)round(midy + yout);
        }
        setcolor(YELLOW);
        outtextxy(10, 30, "Transformed Object (yellow)");
        drawPolygonPoints(txs, tys, n);
    }

    /* Also draw secondary visuals: show intermediary transforms if you want (optional) */
    outtextxy(10, 50, "Press any key to exit...");
    getch();
    closegraph();
    return 0;
}
