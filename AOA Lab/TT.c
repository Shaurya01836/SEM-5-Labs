#include <stdio.h>
#include <stdlib.h>     // Required for malloc() and exit()
#include <conio.h>      // Required for kbhit() and getch()
#include <graphics.h>
#include <dos.h>        // Required for delay()

// --- Global Variables ---
int ch, x, y, i, j, n;
char xoro, winp[2], wong;
char *buffo, *buffx, *buffch;
int maxx, maxy;
char mat[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char pattern[] = {0xF8, 0x20, 0x2E, 0x22, 0x26, 0x22, 0xE, 0x0};

// --- Function Prototypes ---
void start(void);
void boundary(void);
void mainscreen(void);
void game(void);
void puto(void);
void putx(void);
void matchdraw(void);
void win(char);
void result(void);

// --- Main Function ---
int main(void) {
    int driver = DETECT, mode;
    int areao, areax, areach;

    // Initialization of graphics
    initgraph(&driver, &mode, "c:\\turboC3\\bgi");
    maxx = getmaxx();
    maxy = getmaxy();

    // Create 'O' symbol image buffer
    setlinestyle(0, 0, 3);
    setcolor(GREEN);
    circle(maxx / 2 + 150, maxy / 2, 55);
    areao = imagesize(maxx / 2 + 90, maxy / 2 - 60, maxx / 2 + 210, maxy / 2 + 60);
    buffo = (char*)malloc(areao);
    getimage(maxx / 2 + 90, maxy / 2 - 60, maxx / 2 + 210, maxy / 2 + 60, buffo);
    cleardevice();

    // Create 'X' symbol image buffer
    setcolor(LIGHTBLUE);
    line(maxx / 2 - 49, maxy / 2 - 49, maxx / 2 + 49, maxy / 2 + 49);
    line(maxx / 2 - 49, maxy / 2 + 49, maxx / 2 + 49, maxy / 2 - 49);
    areax = imagesize(maxx / 2 - 50, maxy / 2 - 50, maxx / 2 + 50, maxy / 2 + 50);
    buffx = (char*)malloc(areax);
    // This is the corrected line:
    getimage(maxx / 2 - 50, maxy / 2 - 50, maxx / 2 + 50, maxy / 2 + 50, buffx);
    cleardevice();

    // Create Red Tick Mark image buffer
    setcolor(RED);
    line(maxx / 2, maxy / 2 + 110, maxx / 2 + 10, maxy / 2 + 120);
    line(maxx / 2 + 10, maxy / 2 + 120, maxx / 2 + 40, maxy / 2 + 100);
    areach = imagesize(maxx / 2 - 1, maxy / 2 + 99, maxx / 2 + 41, maxy / 2 + 121);
    buffch = (char*)malloc(areach);
    getimage(maxx / 2 - 1, maxy / 2 + 99, maxx / 2 + 41, maxy / 2 + 121, buffch);
    cleardevice();

    start();
    mainscreen();

    // Free allocated memory before closing
    free(buffo);
    free(buffx);
    free(buffch);
    closegraph();
    return 0;
}

// Shows the first screen
void start(void) {
    setcolor(15);
    settextstyle(7, 0, 9);
    setfillpattern(pattern, 1);
    bar(0, 0, maxx, maxy);
    outtextxy(maxx / 2 - (textwidth("Tic Tac Toe") / 2), maxy / 2 - (textheight("Tic Tac Toe") / 2) - 100, "Tic Tac Toe");
    boundary();
    settextstyle(0, HORIZ_DIR, 1);
    delay(2000); // Wait for 2 seconds
}

// Makes boundary over the current screen
void boundary(void) {
    setcolor(6);
    rectangle(0, 0, maxx, maxy);
    setcolor(15);
}

// Shows the main menu
void mainscreen(void) {
    cleardevice();
    setfillpattern(pattern, 1);
    bar(0, 0, maxx, maxy);
    setcolor(15);
    settextstyle(7, 0, 9);
    outtextxy(maxx / 2 - (textwidth("Tic Tac Toe") / 2), maxy / 2 - (textheight("Tic Tac Toe") / 2) - 150, "Tic Tac Toe");
    boundary();
    settextstyle(3, HORIZ_DIR, 5);
    outtextxy(maxx / 2 - 100, maxy / 2 - textheight("P"), "Play Game");
    outtextxy(maxx / 2 - 100, maxy / 2 + textheight("E") + 20, "Exit");
    y = maxy / 2 - textheight("P") / 2;
    putimage(maxx / 2 - 160, y, buffch, XOR_PUT);

    while (1) {
        if (kbhit()) {
            putimage(maxx / 2 - 160, y, buffch, XOR_PUT);
            ch = getch();

            if (ch == 80 || ch == 's' || ch == 'S') // Down arrow
                y = maxy / 2 + textheight("E") / 2 + 20;
            else if (ch == 72 || ch == 'w' || ch == 'W') // Up arrow
                y = maxy / 2 - textheight("P") / 2;
            else if (ch == 27) { // ESC key
                exit(0);
            } else if (ch == '\r' || ch == ' ') { // Enter or Space
                // Check which option is selected based on y-coordinate
                if (y < maxy / 2) { // "Play Game" is selected
                    game();
                } else { // "Exit" is selected
                    exit(0);
                }
            }
            putimage(maxx / 2 - 160, y, buffch, XOR_PUT);
        }
    }
}

void game(void) {
    // Reinitialisation of variables
    n = 5; // Total turns for one player (max)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat[i][j] = ' ';
        }
    }
    cleardevice();
    boundary();
    settextstyle(3, 0, 4);
    setcolor(15);
    outtextxy(maxx / 2 - textwidth("Player 1! Choose your option:") / 2, maxy / 2 - 150, "Player 1! Choose your option:");
    putimage(maxx / 2 - 200, maxy / 2, buffx, COPY_PUT);
    putimage(maxx / 2 + 100, maxy / 2 - 10, buffo, COPY_PUT);
    x = maxx / 2 - 170;
    putimage(x, maxy / 2 + 130, buffch, XOR_PUT);

    while (1) {
        if (kbhit()) {
            putimage(x, maxy / 2 + 130, buffch, XOR_PUT);
            ch = getch();
            if (ch == 75 || ch == 'a' || ch == 'A') // Left
                x = maxx / 2 - 170;
            else if (ch == 77 || ch == 'd' || ch == 'D') // Right
                x = maxx / 2 + 140;
            else if (ch == 27) { // ESC
                mainscreen();
            } else if (ch == '\r' || ch == ' ') { // Select
                break;
            }
            putimage(x, maxy / 2 + 130, buffch, XOR_PUT);
        }
    }

    if (x < maxx / 2)
        xoro = 'x';
    else
        xoro = 'o';

    cleardevice();
    // Makes the grid for the game
    line(maxx / 2 - 75, 20, maxx / 2 - 75, maxy - 20);
    line(maxx / 2 + 75, 20, maxx / 2 + 75, maxy - 20);
    line(maxx / 2 - 225, maxy / 2 - 75, maxx / 2 + 225, maxy / 2 - 75);
    line(maxx / 2 - 225, maxy / 2 + 75, maxx / 2 + 225, maxy / 2 + 75);
    boundary();

    if (xoro == 'x') {
        do {
            putx();
            if (--n == 0) break;
            puto();
        } while (n > 0);
    } else {
        do {
            puto();
            if (--n == 0) break;
            putx();
        } while (n > 0);
    }
    matchdraw();
}

// Function to place 'O'
void puto(void) {
    x = 10;
    y = maxy - 120; // Start at a consistent position
    putimage(x, y, buffo, XOR_PUT);

    while (1) {
        if (kbhit()) {
            putimage(x, y, buffo, XOR_PUT); // Erase old image
            ch = getch();
            if (ch == 77 || ch == 'd' || ch == 'D') x += 5;
            else if (ch == 75 || ch == 'a' || ch == 'A') x -= 5;
            else if (ch == 72 || ch == 'w' || ch == 'W') y -= 5;
            else if (ch == 80 || ch == 's' || ch == 'S') y += 5;
            else if (ch == 27) mainscreen();
            else if (ch == '\r' || ch == ' ') {
                // --- Check Grid Position and if it's empty ---
                // Top Row
                if (y < maxy / 2 - 75) {
                    if (x < maxx / 2 - 75 && mat[0][0] == ' ') { mat[0][0] = 'o'; putimage(maxx / 2 - 150 - 50, maxy / 2 - 150 - 25, buffo, COPY_PUT); break; }
                    if (x > maxx / 2 - 75 && x < maxx / 2 + 75 && mat[0][1] == ' ') { mat[0][1] = 'o'; putimage(maxx / 2 - 50, maxy / 2 - 150 - 25, buffo, COPY_PUT); break; }
                    if (x > maxx / 2 + 75 && mat[0][2] == ' ') { mat[0][2] = 'o'; putimage(maxx / 2 + 150 - 50, maxy / 2 - 150 - 25, buffo, COPY_PUT); break; }
                }
                // Middle Row
                else if (y < maxy / 2 + 75) {
                    if (x < maxx / 2 - 75 && mat[1][0] == ' ') { mat[1][0] = 'o'; putimage(maxx / 2 - 150 - 50, maxy / 2 - 25, buffo, COPY_PUT); break; }
                    if (x > maxx / 2 - 75 && x < maxx / 2 + 75 && mat[1][1] == ' ') { mat[1][1] = 'o'; putimage(maxx / 2 - 50, maxy / 2 - 25, buffo, COPY_PUT); break; }
                    if (x > maxx / 2 + 75 && mat[1][2] == ' ') { mat[1][2] = 'o'; putimage(maxx / 2 + 150 - 50, maxy / 2 - 25, buffo, COPY_PUT); break; }
                }
                // Bottom Row
                else {
                    if (x < maxx / 2 - 75 && mat[2][0] == ' ') { mat[2][0] = 'o'; putimage(maxx / 2 - 150 - 50, maxy / 2 + 150 - 25, buffo, COPY_PUT); break; }
                    if (x > maxx / 2 - 75 && x < maxx / 2 + 75 && mat[2][1] == ' ') { mat[2][1] = 'o'; putimage(maxx / 2 - 50, maxy / 2 + 150 - 25, buffo, COPY_PUT); break; }
                    if (x > maxx / 2 + 75 && mat[2][2] == ' ') { mat[2][2] = 'o'; putimage(maxx / 2 + 150 - 50, maxy / 2 + 150 - 25, buffo, COPY_PUT); break; }
                }
            }
            putimage(x, y, buffo, XOR_PUT); // Draw new image
        }
    }
    // Check for win after placing a mark
    if ((mat[0][0] == 'o' && mat[0][1] == 'o' && mat[0][2] == 'o') || (mat[1][0] == 'o' && mat[1][1] == 'o' && mat[1][2] == 'o') || (mat[2][0] == 'o' && mat[2][1] == 'o' && mat[2][2] == 'o') || (mat[0][0] == 'o' && mat[1][0] == 'o' && mat[2][0] == 'o') || (mat[0][1] == 'o' && mat[1][1] == 'o' && mat[2][1] == 'o') || (mat[0][2] == 'o' && mat[1][2] == 'o' && mat[2][2] == 'o') || (mat[0][0] == 'o' && mat[1][1] == 'o' && mat[2][2] == 'o') || (mat[0][2] == 'o' && mat[1][1] == 'o' && mat[2][0] == 'o'))
        win('o');
}

// Function to place 'X'
void putx(void) {
    x = 10;
    y = maxy - 120; // Start at a consistent position
    putimage(x, y, buffx, XOR_PUT);

    while (1) {
        if (kbhit()) {
            putimage(x, y, buffx, XOR_PUT); // Erase old image
            ch = getch();
            if (ch == 77 || ch == 'd' || ch == 'D') x += 5;
            else if (ch == 75 || ch == 'a' || ch == 'A') x -= 5;
            else if (ch == 72 || ch == 'w' || ch == 'W') y -= 5;
            else if (ch == 80 || ch == 's' || ch == 'S') y += 5;
            else if (ch == 27) mainscreen();
            else if (ch == '\r' || ch == ' ') {
                 // --- Check Grid Position and if it's empty ---
                // Top Row
                if (y < maxy / 2 - 75) {
                    if (x < maxx / 2 - 75 && mat[0][0] == ' ') { mat[0][0] = 'x'; putimage(maxx / 2 - 150 - 50, maxy / 2 - 150 - 25, buffx, COPY_PUT); break; }
                    if (x > maxx / 2 - 75 && x < maxx / 2 + 75 && mat[0][1] == ' ') { mat[0][1] = 'x'; putimage(maxx / 2 - 50, maxy / 2 - 150 - 25, buffx, COPY_PUT); break; }
                    if (x > maxx / 2 + 75 && mat[0][2] == ' ') { mat[0][2] = 'x'; putimage(maxx / 2 + 150 - 50, maxy / 2 - 150 - 25, buffx, COPY_PUT); break; }
                }
                // Middle Row
                else if (y < maxy / 2 + 75) {
                    if (x < maxx / 2 - 75 && mat[1][0] == ' ') { mat[1][0] = 'x'; putimage(maxx / 2 - 150 - 50, maxy / 2 - 25, buffx, COPY_PUT); break; }
                    if (x > maxx / 2 - 75 && x < maxx / 2 + 75 && mat[1][1] == ' ') { mat[1][1] = 'x'; putimage(maxx / 2 - 50, maxy / 2 - 25, buffx, COPY_PUT); break; }
                    if (x > maxx / 2 + 75 && mat[1][2] == ' ') { mat[1][2] = 'x'; putimage(maxx / 2 + 150 - 50, maxy / 2 - 25, buffx, COPY_PUT); break; }
                }
                // Bottom Row
                else {
                    if (x < maxx / 2 - 75 && mat[2][0] == ' ') { mat[2][0] = 'x'; putimage(maxx / 2 - 150 - 50, maxy / 2 + 150 - 25, buffx, COPY_PUT); break; }
                    if (x > maxx / 2 - 75 && x < maxx / 2 + 75 && mat[2][1] == ' ') { mat[2][1] = 'x'; putimage(maxx / 2 - 50, maxy / 2 + 150 - 25, buffx, COPY_PUT); break; }
                    if (x > maxx / 2 + 75 && mat[2][2] == ' ') { mat[2][2] = 'x'; putimage(maxx / 2 + 150 - 50, maxy / 2 + 150 - 25, buffx, COPY_PUT); break; }
                }
            }
            putimage(x, y, buffx, XOR_PUT); // Draw new image
        }
    }
    // Check for win after placing a mark
    if ((mat[0][0] == 'x' && mat[0][1] == 'x' && mat[0][2] == 'x') || (mat[1][0] == 'x' && mat[1][1] == 'x' && mat[1][2] == 'x') || (mat[2][0] == 'x' && mat[2][1] == 'x' && mat[2][2] == 'x') || (mat[0][0] == 'x' && mat[1][0] == 'x' && mat[2][0] == 'x') || (mat[0][1] == 'x' && mat[1][1] == 'x' && mat[2][1] == 'x') || (mat[0][2] == 'x' && mat[1][2] == 'x' && mat[2][2] == 'x') || (mat[0][0] == 'x' && mat[1][1] == 'x' && mat[2][2] == 'x') || (mat[0][2] == 'x' && mat[1][1] == 'x' && mat[2][0] == 'x'))
        win('x');
}

void matchdraw(void) {
    setfillstyle(SOLID_FILL, BLACK);
    bar(maxx / 2 - 150, maxy / 2 - 100, maxx / 2 + 150, maxy / 2 + 100);
    setcolor(RED);
    rectangle(maxx / 2 - 150, maxy / 2 - 100, maxx / 2 + 150, maxy / 2 + 100);
    setcolor(WHITE);
    outtextxy(maxx / 2 - textwidth("Game Drawn!!") / 2, maxy / 2 - textheight("G") / 2, "Game Drawn!!");
    delay(2000);
    mainscreen();
}

void win(char won) {
    wong = won;
    if (won == 'o' && xoro == 'o') winp[0] = '1';
    else if (won == 'o' && xoro == 'x') winp[0] = '2';
    else if (won == 'x' && xoro == 'o') winp[0] = '2';
    else if (won == 'x' && xoro == 'x') winp[0] = '1';
    winp[1] = '\0';
    result();
}

void result(void)
{
    char wintext[20]; // <-- MOVED to the top of the function block

    setfillstyle(SOLID_FILL, BLACK);
    bar(maxx / 2 - 150, maxy / 2 - 100, maxx / 2 + 150, maxy / 2 + 100);

    if (wong == 'o') setcolor(GREEN);
    else setcolor(LIGHTBLUE);

    rectangle(maxx / 2 - 150, maxy / 2 - 100, maxx / 2 + 150, maxy / 2 + 100);
    setcolor(WHITE);
    sprintf(wintext, "Player %s won!", winp);
    outtextxy(maxx / 2 - textwidth(wintext) / 2, maxy / 2 - textheight("P") / 2, wintext);
    delay(3000);
    mainscreen();
}