//31. Write a Program to draw a Bezier curve upto ‘n’ iterations using midpoint method.


#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

typedef struct {
    double x;
    double y;
} Point;

Point midpoint(Point p1, Point p2) {
    Point mid;
    mid.x = (p1.x + p2.x) / 2;
    mid.y = (p1.y + p2.y) / 2;
    return mid;
}

void drawBezier(Point p0, Point p1, Point p2, Point p3, int iterations) {
    if (iterations == 0) {
        line((int)p0.x, (int)p0.y, (int)p3.x, (int)p3.y);
    } else {
        Point p01 = midpoint(p0, p1);
        Point p12 = midpoint(p1, p2);
        Point p23 = midpoint(p2, p3);
        Point p012 = midpoint(p01, p12);
        Point p123 = midpoint(p12, p23);
        Point p0123 = midpoint(p012, p123);

        drawBezier(p0, p01, p012, p0123, iterations - 1);
        drawBezier(p0123, p123, p23, p3, iterations - 1);
    }
}

void drawBezierCurve() {
    int gd = DETECT, gm;
    Point p0, p1, p2, p3;
    int iterations;

    printf("Enter x and y coordinates for Point 1: ");
    scanf("%lf %lf", &p0.x, &p0.y);
    printf("Enter x and y coordinates for Point 2: ");
    scanf("%lf %lf", &p1.x, &p1.y);
    printf("Enter x and y coordinates for Point 3: ");
    scanf("%lf %lf", &p2.x, &p2.y);
    printf("Enter x and y coordinates for Point 4: ");
    scanf("%lf %lf", &p3.x, &p3.y);
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    initgraph(&gd, &gm, "C://TURBOC3//BGI");
    setcolor(WHITE);

    drawBezier(p0, p1, p2, p3, iterations);

    getch();
    closegraph();
}

int main() {
    drawBezierCurve();
    return 0;
}

