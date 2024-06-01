//22. Write a Program to implement all type of reflections about origin and about a line Y = X for a triangle.


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

    // Reflect about the origin
    drawTriangle(-x1 + getmaxx() / 2, -y1 + getmaxy() / 2, 
                 -x2 + getmaxx() / 2, -y2 + getmaxy() / 2, 
                 -x3 + getmaxx() / 2, -y3 + getmaxy() / 2, YELLOW);
    outtextxy(100, 40, "Reflected about Origin");

    // Reflect about the line y = x
    drawTriangle(y1 + getmaxx() / 2, x1 + getmaxy() / 2, 
                 y2 + getmaxx() / 2, x2 + getmaxy() / 2, 
                 y3 + getmaxx() / 2, x3 + getmaxy() / 2, CYAN);
    outtextxy(100, 60, "Reflected about line y=x");

    getch();
    closegraph();
    return 0;
}

