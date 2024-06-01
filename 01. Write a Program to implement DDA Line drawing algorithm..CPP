//1. Write a Program to implement DDA Line drawing algorithm.


#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void drawLine(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = dx / (float) steps;
    yIncrement = dy / (float) steps;

    putpixel(x, y, WHITE);

    for (k = 0; k < steps; k++) {
	x += xIncrement;
	y += yIncrement;
	putpixel(abs(x), abs(y), WHITE);
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

