//17. Write a C program to show that two successive translations are additive in nature.


#include <graphics.h>
#include <conio.h>
#include <stdio.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to translate a point (x, y) by translation factors tx and ty
void translatePoint(int *x, int *y, int tx, int ty) {
    *x = *x + tx;
    *y = *y + ty;
}

// Function to translate a triangle by translation factors tx and ty
void translateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int tx, int ty) {
    translatePoint(x1, y1, tx, ty);
    translatePoint(x2, y2, tx, ty);
    translatePoint(x3, y3, tx, ty);
}

int main() {
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100, x2 = 150, y2 = 50, x3 = 200, y3 = 100;
    int tx1, ty1, tx2, ty2;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the original triangle
    setcolor(WHITE);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    getch();

    // Prompt for two translation factors
    printf("Enter first translation factors (tx1 ty1): ");
    scanf("%d %d", &tx1, &ty1);
    printf("Enter second translation factors (tx2 ty2): ");
    scanf("%d %d", &tx2, &ty2);

    // Translate the triangle by (tx1, ty1) followed by (tx2, ty2)
    int x1_1 = x1, y1_1 = y1, x2_1 = x2, y2_1 = y2, x3_1 = x3, y3_1 = y3;
    translateTriangle(&x1_1, &y1_1, &x2_1, &y2_1, &x3_1, &y3_1, tx1, ty1);
    translateTriangle(&x1_1, &y1_1, &x2_1, &y2_1, &x3_1, &y3_1, tx2, ty2);

    // Reset triangle points for single translation by (tx1 + tx2, ty1 + ty2)
    int x1_2 = x1_1, y1_2 = y1_1, x2_2 = x2_1, y2_2 = y2_1, x3_2 = x3_1, y3_2 = y3_1;
    translateTriangle(&x1_2, &y1_2, &x2_2, &y2_2, &x3_2, &y3_2, tx1 + tx2, ty1 + ty2);

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
