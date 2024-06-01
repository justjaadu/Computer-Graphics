//25. Write a Program to implement Cohen Sutherland line clipping algorithm.



#include <graphics.h>
#include <stdio.h>
#include<conio.h>

// Define region codes
#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

// Define screen boundaries
#define X_MIN 100
#define Y_MIN 100
#define X_MAX 500
#define Y_MAX 400

// Function to compute region code for a point (x, y)
int computeCode(int x, int y) {
    int code = INSIDE; // Initialize code as inside

    if (x < X_MIN)      // to the left of rectangle
        code |= LEFT;
    else if (x > X_MAX) // to the right of rectangle
        code |= RIGHT;
    if (y < Y_MIN)      // below rectangle
        code |= BOTTOM;
    else if (y > Y_MAX) // above rectangle
        code |= TOP;

    return code;
}

// Cohen-Sutherland clipping algorithm
void cohenSutherland(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    // Initially assume both points are inside the clip window
    int accept = 0;

    while (1) {
        if (!(code1 | code2)) { // Both endpoints are inside
            accept = 1;
            break;
        } else if (code1 & code2) { // Both endpoints are outside on same side
            break;
        } else {
            // Clip the line from an outside point to the edge of the window
            int x, y;

            // Select an endpoint that is outside
            int codeOut = code1 ? code1 : code2;

            // Find intersection point
            if (codeOut & TOP) {        // Point is above the clip window
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) { // Point is below the clip window
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) {  // Point is to the right of clip window
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (codeOut & LEFT) {   // Point is to the left of clip window
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            // Replace the outside point with the intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    // If line is accepted, draw it
    if (accept) {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the clipping window
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    // Input the endpoints of the line
    int x1, y1, x2, y2;
    printf("Enter endpoints of line (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Clip and draw the line
    cohenSutherland(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

