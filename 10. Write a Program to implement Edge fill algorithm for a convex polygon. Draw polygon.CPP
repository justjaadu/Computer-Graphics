//10. Write a Program to implement Edge fill algorithm for a convex polygon. Draw polygon edges by DDA / Bresenham line algorithm.


#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

// Function to draw a line using DDA Line Drawing Algorithm
void drawLineDDA(int x1, int y1, int x2, int y2, int color) {
    int dx, dy, steps, i;
    float xIncrement, yIncrement, x, y;

    dx = x2 - x1;
    dy = y2 - y1;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xIncrement = (float)dx / steps;
    yIncrement = (float)dy / steps;
    x = x1;
    y = y1;

    for (i = 0; i <= steps; i++) {
        putpixel(x, y, color);
        x += xIncrement;
        y += yIncrement;
    }
}

// Function to implement Edge Fill Algorithm for a convex polygon
void edgeFill(int x[], int y[], int n, int fill_color, int boundary_color) {
    int yMin, yMax, scanline, xIntersections[20], xCount, i, j, k;
    float slope;

    yMin = y[0];
    yMax = y[0];

    // Find the minimum and maximum y-coordinates of the polygon
    for (i = 1; i < n; i++) {
        if (y[i] < yMin)
            yMin = y[i];
        if (y[i] > yMax)
            yMax = y[i];
    }

    // Scan each horizontal line within the polygon bounds
    for (scanline = yMin + 1; scanline < yMax; scanline++) {
        xCount = 0;

        // Find intersections of the scanline with polygon edges
        for (i = 0; i < n; i++) {
            j = (i + 1) % n;
            if ((y[i] <= scanline && y[j] > scanline) || (y[j] <= scanline && y[i] > scanline)) {
                slope = (float)(x[j] - x[i]) / (y[j] - y[i]);
                xIntersections[xCount++] = x[i] + slope * (scanline - y[i]);
            }
        }

        // Sort the intersections in ascending order
        for (i = 0; i < xCount - 1; i++) {
            for (j = 0; j < xCount - i - 1; j++) {
                if (xIntersections[j] > xIntersections[j + 1]) {
                    float temp = xIntersections[j];
                    xIntersections[j] = xIntersections[j + 1];
                    xIntersections[j + 1] = temp;
                }
            }
        }

        // Fill the space between pairs of intersections
        for (k = 0; k < xCount - 1; k += 2) {
            drawLineDDA(xIntersections[k], scanline, xIntersections[k + 1], scanline, fill_color);
        }
    }

    // Draw the boundary of the polygon
    for (i = 0; i < n; i++) {
        j = (i + 1) % n;
        drawLineDDA(x[i], y[i], x[j], y[j], boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;
    // Modified polygon shape
    int x[] = {200, 300, 400, 350, 250}; 
    int y[] = {100, 150, 100, 200, 250};
    int n = sizeof(x) / sizeof(x[0]);
    int i;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Apply edge fill algorithm to fill the polygon and draw its boundary
    edgeFill(x, y, n, YELLOW, WHITE);

    getch();
    closegraph(); // Close the graphics mode before exiting

    return 0;
}

