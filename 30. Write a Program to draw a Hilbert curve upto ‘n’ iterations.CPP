//30. Write a Program to draw a Hilbert curve upto ‘n’ iterations.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

// Function to draw a line
void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

// Function to draw a Hilbert curve
void hilbertCurve(int x, int y, int xi, int xj, int yi, int yj, int depth) {
    if (depth <= 0) {
        drawLine(x, y, x + xi, y + xj);
        return;
    }

    hilbertCurve(x, y, yi / 2, yj / 2, xi / 2, xj / 2, depth - 1);
    hilbertCurve(x + xi / 2, y + xj / 2, xi / 2, xj / 2, yi / 2, yj / 2, depth - 1);
    hilbertCurve(x + xi / 2 + yi / 2, y + xj / 2 + yj / 2, xi / 2, xj / 2, yi / 2, yj / 2, depth - 1);
    hilbertCurve(x + xi / 2 + yi, y + xj / 2 + yj, -yi / 2, -yj / 2, -xi / 2, -xj / 2, depth - 1);
}

int main() {
    int choice, gd = DETECT, gm;
    int x1, y1, x2, y2, depth;

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

            printf("Enter the starting point (x1, y1): ");
            // 100 100
            scanf("%d%d", &x1, &y1);
            printf("Enter the depth of recursion: ");
            // 3
            scanf("%d", &depth);
            hilbertCurve(x1, y1, getmaxx() / 2, 0, 0, getmaxy() / 2, depth);
 

    getch();
    closegraph();

    return 0;
}


