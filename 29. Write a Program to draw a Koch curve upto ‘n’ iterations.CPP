//29. Write a Program to draw a Koch curve upto ‘n’ iterations

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

// Function to draw a line
void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

// Function to draw the Koch curve
void kochCurve(int x1, int y1, int x2, int y2, int depth) {
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

    kochCurve(x1, y1, x3, y3, depth - 1);
    kochCurve(x3, y3, x, y, depth - 1);
    kochCurve(x, y, x4, y4, depth - 1);
    kochCurve(x4, y4, x2, y2, depth - 1);
}


int main() {
    int choice, gd = DETECT, gm;
    int x1, y1, x2, y2, depth;

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");


	    printf("Enter the starting point (x1, y1): ");
	    //200 200
	    scanf("%d%d", &x1, &y1);
	    printf("Enter the length of the side: ");
	    // 400
	    scanf("%d", &depth);
	    kochCurve(x1, y1, x1 + depth, y1, 5);


    getch();
    closegraph();

    return 0;
}
