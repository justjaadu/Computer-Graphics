//2. Write a Program to implement Bresenham’s Line drawing algorithm.

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int slope_x = x1 < x2 ? 1 : -1;
    int slope_y = y1 < y2 ? 1 : -1;
    int x, y;
    if (dy <= dx) {
        int d = 2 * dy - dx;
        int y = y1;

        for (x = x1; x != x2; x += slope_x) {
	    putpixel(x, y, BLUE);
            if (d > 0) {
                y += slope_y;
                d -= 2 * dx;
            }
            d += 2 * dy;
        }
    } else {
        int d = 2 * dx - dy;
        int x = x1;
        for (y = y1; y != y2; y += slope_y) {
	    putpixel(x, y, BLUE);
            if (d > 0) {
                x += slope_x;
                d -= 2 * dy;
            }
            d += 2 * dx;
        }
    }
}

int main() {
    int gm, gd = DETECT;
    int x0, y0, x1, y1;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter the coordinates of the first point of the first line (x0, y0): ");
    scanf("%d %d", &x0, &y0);
    printf("Enter the coordinates of the second point of the first line (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    drawLine(x0, y0, x1, y1);
    getch();
    closegraph(); // Close the graphics mode before exiting

    return 0;
}
