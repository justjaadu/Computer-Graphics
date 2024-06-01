//28. Write a Program to implement Generalized Polygon clipping algorithm.



#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 20

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int n;
} Poly;

typedef struct {
    Point p1, p2;
} Edge;

Point intersection(Point p1, Point p2, Point cp1, Point cp2) {
    Point i;
    float a1 = p2.y - p1.y;
    float b1 = p1.x - p2.x;
    float c1 = a1 * p1.x + b1 * p1.y;

    float a2 = cp2.y - cp1.y;
    float b2 = cp1.x - cp2.x;
    float c2 = a2 * cp1.x + b2 * cp1.y;

    float determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        i.x = p1.x;
        i.y = p1.y;
    } else {
        i.x = (b2 * c1 - b1 * c2) / determinant;
        i.y = (a1 * c2 - a2 * c1) / determinant;
    }
    return i;
}

int inside(Point p, Point cp1, Point cp2) {
    return (cp2.x - cp1.x) * (p.y - cp1.y) > (cp2.y - cp1.y) * (p.x - cp1.x);
}

void addPoint(Poly *poly, Point p) {
    if (poly->n < MAX_POINTS) {
        poly->points[poly->n] = p;
	poly->n++;
    }
}

void weilerAtherton(Poly *subject, Poly *clipper, Poly *result) {
    int i, j, k;
    Point p, s, iP;
    Poly temp;
    Point cp1 = clipper->points[j];
    Point cp2 = clipper->points[(j + 1) % clipper->n];

    for (i = 0; i < subject->n; i++) {
	s = subject->points[i];
	for (j = 0; j < clipper->n; j++) {
	    temp.n = 0;

            for (k = 0; k < subject->n; k++) {
                p = subject->points[k];
                if (inside(p, cp1, cp2)) {
                    if (!inside(s, cp1, cp2)) {
                        iP = intersection(s, p, cp1, cp2);
                        addPoint(&temp, iP);
                    }
                    addPoint(&temp, p);
                } else if (inside(s, cp1, cp2)) {
                    iP = intersection(s, p, cp1, cp2);
                    addPoint(&temp, iP);
                }
                s = p;
            }
            *subject = temp;
        }
    }

    *result = *subject;
}

void drawPolygon(Poly *poly, int color) {
    int i;
    setcolor(color);
    for (i = 0; i < poly->n; i++) {
        line(poly->points[i].x, poly->points[i].y, poly->points[(i + 1) % poly->n].x, poly->points[(i + 1) % poly->n].y);
    }
}

void inputPolygon(Poly *poly) {
    int i;
    printf("Enter number of vertices: ");
    scanf("%d", &poly->n);
    if (poly->n > MAX_POINTS) {
        printf("Number of vertices should not exceed %d\n", MAX_POINTS);
        exit(1);
    }
    for (i = 0; i < poly->n; i++) {
        printf("Enter vertex %d (x y): ", i + 1);
        scanf("%d %d", &poly->points[i].x, &poly->points[i].y);
    }
}

int main() {
     Poly subject, clipper, result;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


    result.n = 0;

    printf("Enter the subject polygon:\n");
    inputPolygon(&subject);

    printf("Enter the clipping polygon:\n");
    inputPolygon(&clipper);

    setbkcolor(WHITE);
    cleardevice();

    drawPolygon(&subject, RED);
    drawPolygon(&clipper, BLUE);

    getch();
    cleardevice();

    weilerAtherton(&subject, &clipper, &result);

    drawPolygon(&result, GREEN);
    drawPolygon(&clipper, BLUE);

    getch();
    closegraph();
    return 0;
}


