//33. Write a Program to draw a mountain using Fractal surface upto ‘n’ iterations.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

// Function to draw a line
void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

// Function to draw a fractal curve
void fractalCurve(int x1, int y1, int x2, int y2, int depth) {
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    int x3 = x1 + deltaX / 3;
    int y3 = y1 + deltaY / 3;
    int x4 = x1 + deltaX * 2 / 3;
    int y4 = y1 + deltaY * 2 / 3;
    int x = x3 + (x4 - x3) / 2 - (int)(deltaY * sqrt(3) / 6);
    int y = y3 + (y4 - y3) / 2 + (int)(deltaX * sqrt(3) / 6);

    if (depth == 0) {
        drawLine(x1, y1, x2, y2);
        return;
    }

    fractalCurve(x1, y1, x3, y3, depth - 1);
    fractalCurve(x3, y3, x, y, depth - 1);
    fractalCurve(x, y, x4, y4, depth - 1);
    fractalCurve(x4, y4, x2, y2, depth - 1);
}

int main() {
    int choice, gd = DETECT, gm;
    int x1, y1, x2, y2, depth;

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

            printf("Enter the starting point (x1, y1): ");
            // 100 200
            scanf("%d%d", &x1, &y1);
            printf("Enter the end point (x2, y2): ");
            // 700 600
            scanf("%d%d", &x2, &y2);
            printf("Enter the depth of recursion: ");
            // 4
            scanf("%d", &depth);
            fractalCurve(x1, y1, x2, y2, depth);
        

    getch();
    closegraph();

    return 0;
}

