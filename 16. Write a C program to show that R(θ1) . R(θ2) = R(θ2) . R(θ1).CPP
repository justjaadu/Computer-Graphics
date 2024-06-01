//16. Write a C program to show that R(θ1) . R(θ2) = R(θ2) . R(θ1)

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

    // Reset triangle points for rotation sequence R(theta1) . R(theta2)
    int x1_1 = 100, y1_1 = 100, x2_1 = 150, y2_1 = 50, x3_1 = 200, y3_1 = 100;
    rotateTriangle(&x1_1, &y1_1, &x2_1, &y2_1, &x3_1, &y3_1, theta1);
    rotateTriangle(&x1_1, &y1_1, &x2_1, &y2_1, &x3_1, &y3_1, theta2);

    // Reset triangle points for rotation sequence R(theta2) . R(theta1)
    int x1_2 = 100, y1_2 = 100, x2_2 = 150, y2_2 = 50, x3_2 = 200, y3_2 = 100;
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


