//8. Write a Program to implement Boundary fill algorithm for a convex polygon. Draw polygon edges by DDA / Bresenham line algorithm.

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

// Function to draw a line using DDA Line Drawing Algorithm
void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;
    float x = x1;
    float y = y1;
    int i;
    for (i = 0; i <= steps; i++) {
        putpixel(x, y, WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

// Function to implement Boundary Fill Algorithm
void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    int current = getpixel(x, y);
    if (current != boundary_color && current != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;
    // Vertices of the convex polygon
    int poly[] = {100, 100, 150, 50, 200, 100, 150, 150};
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw the polygon using DDA line algorithm
    drawLineDDA(poly[0], poly[1], poly[2], poly[3]);
    drawLineDDA(poly[2], poly[3], poly[4], poly[5]);
    drawLineDDA(poly[4], poly[5], poly[6], poly[7]);
    drawLineDDA(poly[6], poly[7], poly[0], poly[1]);

    // Apply boundary fill algorithm to fill the polygon
    boundaryFill(150, 100, YELLOW, WHITE);

    getch();
    closegraph(); // Close the graphics mode before exiting

    return 0;
}




