//18. Write a C program to show that two successive rotations are commutative in nature.

#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to rotate a point (x, y) around (cx, cy) by an angle theta
void rotatePoint(int *x, int *y, int cx, int cy, float theta) {
    float rad = theta * M_PI / 180;
    int x_shifted = *x - cx;
    int y_shifted = *y - cy;
    float x_new = x_shifted * cos(rad) - y_shifted * sin(rad);
    float y_new = x_shifted * sin(rad) + y_shifted * cos(rad);
    *x = cx + (int)(x_new + 0.5);
    *y = cy + (int)(y_new + 0.5);
}

// Function to rotate a triangle around its centroid by an angle theta
void rotateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float theta) {
    int cx = (*x1 + *x2 + *x3) / 3;
    int cy = (*y1 + *y2 + *y3) / 3;
    rotatePoint(x1, y1, cx, cy, theta);
    rotatePoint(x2, y2, cx, cy, theta);
    rotatePoint(x3, y3, cx, cy, theta);
}

int main() {
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100, x2 = 150, y2 = 50, x3 = 200, y3 = 100;
    float theta1, theta2;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the original triangle
    setcolor(WHITE);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();

    // Prompt for two rotation angles
    printf("Enter first rotation angle (theta1): ");
    scanf("%f", &theta1);
    printf("Enter second rotation angle (theta2): ");
    scanf("%f", &theta2);

    // Reset triangle points for rotation sequence R(theta1) followed by R(theta2)
    int x1_1 = x1, y1_1 = y1, x2_1 = x2, y2_1 = y2, x3_1 = x3, y3_1 = y3;
    rotateTriangle(&x1_1, &y1_1, &x2_1, &y2_1, &x3_1, &y3_1, theta1);
    rotateTriangle(&x1_1, &y1_1, &x2_1, &y2_1, &x3_1, &y3_1, theta2);

    // Reset triangle points for rotation sequence R(theta2) followed by R(theta1)
    int x1_2 = x1, y1_2 = y1, x2_2 = x2, y2_2 = y2, x3_2 = x3, y3_2 = y3;
    rotateTriangle(&x1_2, &y1_2, &x2_2, &y2_2, &x3_2, &y3_2, theta2);
    rotateTriangle(&x1_2, &y1_2, &x2_2, &y2_2, &x3_2, &y3_2, theta1);

    // Clear the screen and draw both results
    cleardevice();
    setcolor(YELLOW);
    drawTriangle(x1_1, y1_1, x2_1, y2_1, x3_1, y3_1);
    setcolor(CYAN);
    drawTriangle(x1_2, y1_2, x2_2, y2_2, x3_2, y3_2);
    getch();

    closegraph();
    return 0;
}