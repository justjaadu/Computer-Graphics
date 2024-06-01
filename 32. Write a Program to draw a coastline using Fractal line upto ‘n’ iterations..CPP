//32. Write a Program to draw a coastline using Fractal line upto ‘n’ iterations.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

// Function to draw a line
void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}
// Function to draw a fractal line
void fractalLine(int x1, int y1, int x2, int y2, int depth) {
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;
    int newX = (x1 + midX) / 2 + (x2 + midX) / 2 - midX;
    int newY = (y1 + midY) / 2 + (y2 + midY) / 2 - midY;

    if (depth == 0) {
        drawLine(x1, y1, x2, y2);
        return;
    }
    fractalLine(x1, y1, midX, midY, depth - 1);
    fractalLine(midX, midY, newX, newY, depth - 1);
    fractalLine(newX, newY, x2, y2, depth - 1);
}


int main() {
    int choice, gd = DETECT, gm;
    int x1, y1, x2, y2, depth;

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

            printf("Enter the starting point (x1, y1): ");
            //100 100
            scanf("%d%d", &x1, &y1);
            printf("Enter the end point (x2, y2): ");
            //700 200
            scanf("%d%d", &x2, &y2);
            printf("Enter the depth of recursion: ");
            // 5
            scanf("%d", &depth);
            fractalLine(x1, y1, x2, y2, depth);

    getch();
    closegraph();

    return 0;
}
