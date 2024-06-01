//19. Write a C program to show that two successive translations are commutative in nature.

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<conio.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to translate a triangle
void translateTriangle(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int dx, int dy) {
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
    x3 += dx;
    y3 += dy;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    // Original triangle vertices
    int x1 = 100, y1 = 100;
    int x2 = 150, y2 = 200;
    int x3 = 50, y3 = 200;

    // Draw original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);
    delay(1000); // Delay to show the original triangle

    // Translation values
    int dx1 = 50, dy1 = 50;
    int dx2 = 100, dy2 = 100;

    // First translation sequence: T(dx1, dy1) followed by T(dx2, dy2)
    int x1_t1 = x1, y1_t1 = y1;
    int x2_t1 = x2, y2_t1 = y2;
    int x3_t1 = x3, y3_t1 = y3;
    translateTriangle(x1_t1, y1_t1, x2_t1, y2_t1, x3_t1, y3_t1, dx1, dy1);
    drawTriangle(x1_t1, y1_t1, x2_t1, y2_t1, x3_t1, y3_t1, RED);
    delay(1000); // Delay to show the first translation

    translateTriangle(x1_t1, y1_t1, x2_t1, y2_t1, x3_t1, y3_t1, dx2, dy2);
    drawTriangle(x1_t1, y1_t1, x2_t1, y2_t1, x3_t1, y3_t1, BLUE);
    delay(1000); // Delay to show the second translation

    // Second translation sequence: T(dx2, dy2) followed by T(dx1, dy1)
    int x1_t2 = x1, y1_t2 = y1;
    int x2_t2 = x2, y2_t2 = y2;
    int x3_t2 = x3, y3_t2 = y3;
    translateTriangle(x1_t2, y1_t2, x2_t2, y2_t2, x3_t2, y3_t2, dx2, dy2);
    drawTriangle(x1_t2, y1_t2, x2_t2, y2_t2, x3_t2, y3_t2, GREEN);
    delay(1000); // Delay to show the first translation

    translateTriangle(x1_t2, y1_t2, x2_t2, y2_t2, x3_t2, y3_t2, dx1, dy1);
    drawTriangle(x1_t2, y1_t2, x2_t2, y2_t2, x3_t2, y3_t2, YELLOW);
    delay(1000); // Delay to show the second translation

    // Check if both triangles coincide
    if (x1_t1 == x1_t2 && y1_t1 == y1_t2 && x2_t1 == x2_t2 && y2_t1 == y2_t2 && x3_t1 == x3_t2 && y3_t1 == y3_t2) {
        outtextxy(10, getmaxy() - 20, "Both final triangles coincide, demonstrating commutativity.");
    } else {
        outtextxy(10, getmaxy() - 20, "Translations do not coincide. There is an error.");
    }

    // Wait for a key press
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}
