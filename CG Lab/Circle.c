#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Draw a circle at (x=250, y=200) with radius 100
    circle(250, 200, 100);

    getch(); // Wait for key press
    closegraph(); // Close graphics mode
    return 0;
}
