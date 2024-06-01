//21. Write a Program to implement all type of reflections about X axis and about Y axis of a triangle.


#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x1, y1, x2, y2, x3, y3;

    // Ask the user to enter the coordinates of the triangle
    printf("Enter the coordinates of the triangle:\n");
    printf("Point 1 (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Point 2 (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Point 3 (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);
    outtextxy(100, 20, "Original Triangle");

    // Reflect about X-axis
    drawTriangle(x1, getmaxy() - y1, x2, getmaxy() - y2, x3, getmaxy() - y3, RED);
    outtextxy(100, getmaxy() - 40, "Reflected about X-axis");

    // Reflect about Y-axis
    drawTriangle(getmaxx() - x1, y1, getmaxx() - x2, y2, getmaxx() - x3, y3, GREEN);
    outtextxy(getmaxx() - 300, 20, "Reflected about Y-axis");

    // Reflect about both X-axis and Y-axis
    drawTriangle(getmaxx() - x1, getmaxy() - y1, getmaxx() - x2, getmaxy() - y2, getmaxx() - x3, getmaxy() - y3, BLUE);
    outtextxy(getmaxx() - 300, getmaxy() - 40, "Reflected about Both axes");

    getch();
    closegraph();
    return 0;
}

