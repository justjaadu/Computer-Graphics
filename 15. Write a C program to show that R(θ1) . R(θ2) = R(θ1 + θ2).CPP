//15. Write a C program to show that R(θ1) . R(θ2) = R(θ1 + θ2)

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

// Function to rotate a point (x, y) by an angle theta
void rotatePoint(int *x, int *y, float theta) {
    float rad = theta * M_PI / 180;
    int x_new = *x * cos(rad) - *y * sin(rad);
    int y_new = *x * sin(rad) + *y * cos(rad);
    *x = x_new;
    *y = y_new;
}

// Function to rotate a triangle by an angle theta
void rotateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, float theta) {
    rotatePoint(x1, y1, theta);
    rotatePoint(x2, y2, theta);
    rotatePoint(x3, y3, theta);
}

int main() {
    int gd = DETECT, gm;
    int x1 = 200, y1 = 100, x2 = 100, y2 = 200, x3 = 300, y3 = 200;
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

    // Rotate the triangle by theta1
    rotateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, theta1);
    cleardevice();
    setcolor(YELLOW);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();

    // Rotate the triangle by theta2
    rotateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, theta2);
    cleardevice();
    setcolor(GREEN);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();

    // Reset triangle points for direct rotation by (theta1 + theta2)
    x1 = 200, y1 = 100, x2 = 100, y2 = 200, x3 = 300, y3 = 200;

    // Rotate the triangle directly by (theta1 + theta2)
    rotateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, theta1 + theta2);
    cleardevice();
    setcolor(CYAN);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();

    closegraph();
    return 0;
}
