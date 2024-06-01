#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

// Function to draw a line using Bresenham's Line Drawing Algorithm
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int e2;
    while (1) {
        putpixel(x1, y1, WHITE);
        if (x1 == x2 && y1 == y2)
            break;
        e2 = 2 * err;
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

// Function to implement Flood Fill Algorithm
void floodFill(int x, int y, int fill_color, int boundary_color) {
    int current = getpixel(x, y);
    if (current != boundary_color && current != fill_color) {
        putpixel(x, y, fill_color);
        floodFill(x + 1, y, fill_color, boundary_color);
        floodFill(x - 1, y, fill_color, boundary_color);
        floodFill(x, y + 1, fill_color, boundary_color);
        floodFill(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;

    // Vertices of the convex polygon
    int poly[8] = {40, 40, 60, 20, 80, 40, 60, 60};

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw the polygon using Bresenham's line algorithm
    drawLine(poly[0], poly[1], poly[2], poly[3]);
    drawLine(poly[2], poly[3], poly[4], poly[5]);
    drawLine(poly[4], poly[5], poly[6], poly[7]);
    drawLine(poly[6], poly[7], poly[0], poly[1]);

    // Apply flood fill algorithm to fill the polygon
    floodFill(60, 40, YELLOW, WHITE);

    getch();
    closegraph(); // Close the graphics mode before exiting

    return 0;
}
