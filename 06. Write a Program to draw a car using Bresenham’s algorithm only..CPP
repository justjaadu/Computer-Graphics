//6. Write a Program to draw a car using Bresenham’s algorithm only.


#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

// Function to draw a line using Bresenham's Line Drawing Algorithm
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        putpixel(x1, y1, WHITE);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// Function to draw a circle using Bresenham's Circle Drawing Algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (y >= x) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        if (d < 0)
            d = d + 4 * x + 6;
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw car body
    drawLine(150, 300, 450, 300); // Bottom
    drawLine(150, 200, 450, 200); // Top
    drawLine(150, 200, 150, 300); // Left
    drawLine(450, 200, 450, 300); // Right

    // Draw car roof
    drawLine(200, 200, 250, 150); // Left slope
    drawLine(250, 150, 350, 150); // Top
    drawLine(350, 150, 400, 200); // Right slope

    // Draw car windows
    drawLine(220, 200, 260, 160); // Front left window bottom
    drawLine(260, 160, 340, 160); // Front window top
    drawLine(340, 160, 380, 200); // Front right window bottom
    drawLine(260, 200, 260, 160); // Left window side
    drawLine(340, 200, 340, 160); // Right window side

    // Draw wheels using circles
    drawCircle(200, 310, 25); // Left wheel
    drawCircle(400, 310, 25); // Right wheel

    getch();
    closegraph(); // Close the graphics mode before exiting
    return 0;
}

