//13. Write a Program to implement 2D Scaling and translation of a triangle.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    float sx, sy, tx, ty;
    int x1_new, y1_new, x2_new, y2_new, x3_new, y3_new;
    
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    cleardevice();

    // Input the coordinates of the triangle
    printf("Enter the coordinates of the first vertex (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second vertex (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third vertex (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Input the scaling factors
    printf("Enter the scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

    // Scale the triangle
    x1_new = x1 * sx;
    y1_new = y1 * sy;
    x2_new = x2 * sx;
    y2_new = y2 * sy;
    x3_new = x3 * sx;
    y3_new = y3 * sy;

    // Draw the scaled triangle
    setcolor(RED);
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);

    // Input the translation factors
    printf("Enter the translation factors (tx ty): ");
    scanf("%f %f", &tx, &ty);

    // Translate the triangle
    x1_new += tx;
    y1_new += ty;
    x2_new += tx;
    y2_new += ty;
    x3_new += tx;
    y3_new += ty;

    // Draw the translated triangle
    setcolor(GREEN);
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);

    getch();
    closegraph(); 
    return 0;
}
