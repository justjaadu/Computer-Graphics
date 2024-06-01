//24. Write a Program to implement rotation about arbitrary point.

#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to perform translation
void translatePoint(int *x, int *y, int tx, int ty) {
    *x = *x + tx;
    *y = *y + ty;
}

// Function to rotate a point around the origin
void rotateAroundOrigin(int *x, int *y, float angle) {
    float rad = angle * M_PI / 180.0;
    int nx = (int)(*x * cos(rad) - *y * sin(rad));
    int ny = (int)(*x * sin(rad) + *y * cos(rad));
    *x = nx;
    *y = ny;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x1, y1, x2, y2, x3, y3, cx, cy;
    float angle;

    // Ask the user to enter the coordinates of the triangle
    printf("Enter the coordinates of the triangle:\n");
    printf("Point 1 (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Point 2 (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Point 3 (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    // Ask the user to enter the coordinates of the center of rotation
    printf("Enter the coordinates of the center of rotation (cx, cy): ");
    scanf("%d %d", &cx, &cy);

    // Ask the user to enter the angle of rotation
    printf("Enter the angle of rotation (in degrees): ");
    scanf("%f", &angle);

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);
    outtextxy(10, 10, "Original Triangle");

    // Translate points to the origin relative to the center of rotation
    int tx1 = x1 - cx, ty1 = y1 - cy;
    int tx2 = x2 - cx, ty2 = y2 - cy;
    int tx3 = x3 - cx, ty3 = y3 - cy;

    // Rotate the translated points around the origin
    rotateAroundOrigin(&tx1, &ty1, angle);
    rotateAroundOrigin(&tx2, &ty2, angle);
    rotateAroundOrigin(&tx3, &ty3, angle);

    // Translate points back to the original position
    translatePoint(&tx1, &ty1, cx, cy);
    translatePoint(&tx2, &ty2, cx, cy);
    translatePoint(&tx3, &ty3, cx, cy);

    // Draw the rotated triangle
    drawTriangle(tx1, ty1, tx2, ty2, tx3, ty3, YELLOW);
    outtextxy(10, 30, "Rotated Triangle");

    getch();
    closegraph();
    return 0;
}

