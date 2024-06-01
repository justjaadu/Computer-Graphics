//27. Write a Program to implement Sutherland-Hodgeman Polygon clipping algorithm.


#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

void clipLeft(Point *input, int inputCount, Point *output, int *outputCount, int xmin) {
    int i;
    *outputCount = 0;
    for (i = 0; i < inputCount; i++) {
        int k = (i + 1) % inputCount;
        Point current = input[i];
        Point next = input[k];
        int x, y;

        if (current.x >= xmin && next.x >= xmin) {
            output[*outputCount] = next;
            (*outputCount)++;
        } else if (current.x >= xmin && next.x < xmin) {
            x = xmin;
            y = current.y + (next.y - current.y) * (xmin - current.x) / (next.x - current.x);
            output[*outputCount].x = x;
            output[*outputCount].y = y;
            (*outputCount)++;
        } else if (current.x < xmin && next.x >= xmin) {
            x = xmin;
            y = current.y + (next.y - current.y) * (xmin - current.x) / (next.x - current.x);
            output[*outputCount].x = x;
            output[*outputCount].y = y;
            (*outputCount)++;
            output[*outputCount] = next;
            (*outputCount)++;
        }
    }
}

void clipRight(Point *input, int inputCount, Point *output, int *outputCount, int xmax) {
    int i;
    *outputCount = 0;
    for (i = 0; i < inputCount; i++) {
        int k = (i + 1) % inputCount;
        Point current = input[i];
        Point next = input[k];
        int x, y;

        if (current.x <= xmax && next.x <= xmax) {
            output[*outputCount] = next;
            (*outputCount)++;
        } else if (current.x <= xmax && next.x > xmax) {
            x = xmax;
            y = current.y + (next.y - current.y) * (xmax - current.x) / (next.x - current.x);
            output[*outputCount].x = x;
            output[*outputCount].y = y;
            (*outputCount)++;
        } else if (current.x > xmax && next.x <= xmax) {
            x = xmax;
            y = current.y + (next.y - current.y) * (xmax - current.x) / (next.x - current.x);
            output[*outputCount].x = x;
            output[*outputCount].y = y;
            (*outputCount)++;
            output[*outputCount] = next;
            (*outputCount)++;
        }
    }
}

void clipBottom(Point *input, int inputCount, Point *output, int *outputCount, int ymin) {
    int i;
    *outputCount = 0;
    for (i = 0; i < inputCount; i++) {
        int k = (i + 1) % inputCount;
        Point current = input[i];
        Point next = input[k];
        int x, y;

        if (current.y >= ymin && next.y >= ymin) {
            output[*outputCount] = next;
            (*outputCount)++;
        } else if (current.y >= ymin && next.y < ymin) {
            x = current.x + (next.x - current.x) * (ymin - current.y) / (next.y - current.y);
            y = ymin;
            output[*outputCount].x = x;
            output[*outputCount].y = y;
            (*outputCount)++;
        } else if (current.y < ymin && next.y >= ymin) {
            x = current.x + (next.x - current.x) * (ymin - current.y) / (next.y - current.y);
            y = ymin;
            output[*outputCount].x = x;
            output[*outputCount].y = y;
            (*outputCount)++;
            output[*outputCount] = next;
            (*outputCount)++;
        }
    }
}

void clipTop(Point *input, int inputCount, Point *output, int *outputCount, int ymax) {
    int i;
    *outputCount = 0;
    for (i = 0; i < inputCount; i++) {
        int k = (i + 1) % inputCount;
        Point current = input[i];
        Point next = input[k];
        int x, y;

        if (current.y <= ymax && next.y <= ymax) {
            output[*outputCount] = next;
            (*outputCount)++;
        } else if (current.y <= ymax && next.y > ymax) {
            x = current.x + (next.x - current.x) * (ymax - current.y) / (next.y - current.y);
            y = ymax;
            output[*outputCount].x = x;
            output[*outputCount].y = y;
            (*outputCount)++;
        } else if (current.y > ymax && next.y <= ymax) {
            x = current.x + (next.x - current.x) * (ymax - current.y) / (next.y - current.y);
            y = ymax;
            output[*outputCount].x = x;
            output[*outputCount].y = y;
            (*outputCount)++;
            output[*outputCount] = next;
            (*outputCount)++;
	}
    }
}

void sutherlandHodgmanClip(Point *polygon, int *vertexCount, int xmin, int ymin, int xmax, int ymax) {
    Point temp1[20], temp2[20];
    int i, tempCount1, tempCount2;

    clipLeft(polygon, *vertexCount, temp1, &tempCount1, xmin);
    clipRight(temp1, tempCount1, temp2, &tempCount2, xmax);
    clipBottom(temp2, tempCount2, temp1, &tempCount1, ymin);
    clipTop(temp1, tempCount1, temp2, &tempCount2, ymax);

    *vertexCount = tempCount2;
    for ( i = 0; i < tempCount2; i++) {
        polygon[i] = temp2[i];
    }
}

int main() {
    int n, i;
    int xmin, ymin, xmax, ymax;
    Point polygon[20];
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


    printf("Enter number of vertices of the polygon: ");
    scanf("%d", &n);
    printf("Enter the coordinates of the polygon:\n");
    for (i = 0; i < n; i++) {
	printf("Vertex %d: ", i + 1);
	scanf("%d %d", &polygon[i].x, &polygon[i].y);
    }
    printf("Enter the clipping window (xmin, ymin, xmax, ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    setcolor(WHITE);
    for (i = 0; i < n; i++) {
        int j = (i + 1) % n;
        line(polygon[i].x, polygon[i].y, polygon[j].x, polygon[j].y);
    }

    rectangle(xmin, ymin, xmax, ymax);
    getch();
    cleardevice();

    sutherlandHodgmanClip(polygon, &n, xmin, ymin, xmax, ymax);

    setcolor(WHITE);
    for (i = 0; i < n; i++) {
        int j = (i + 1) % n;
        line(polygon[i].x, polygon[i].y, polygon[j].x, polygon[j].y);
    }

    rectangle(xmin, ymin, xmax, ymax);
    getch();
    closegraph();
    return 0;
}
