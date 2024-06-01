//20. Write a C Program to show that Reflection about a line Y=X is equivalent to reflection relative to X-axis followed by anticlockwise rotation of 90 .


#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include<dos.h>
#include<conio.h>


// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to reflect a point about the line y=x
void reflectAboutLineYX(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Function to reflect a point about the x-axis
void reflectAboutXAxis(int &y) {
    y = -y;
}

// Function to rotate a point 90 degrees counterclockwise
void rotate90Counterclockwise(int &x, int &y) {
    int temp = x;
    x = -y;
    y = temp;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    // Original triangle vertices
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 200;

    // Draw original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);
    delay(1000); // Delay to show the original triangle

    // Reflection about the line y = x
    int x1_reflect = x1, y1_reflect = y1;
    int x2_reflect = x2, y2_reflect = y2;
    int x3_reflect = x3, y3_reflect = y3;

    reflectAboutLineYX(x1_reflect, y1_reflect);
    reflectAboutLineYX(x2_reflect, y2_reflect);
    reflectAboutLineYX(x3_reflect, y3_reflect);

    // Draw triangle after reflection about y = x (RED)
    drawTriangle(x1_reflect, y1_reflect, x2_reflect, y2_reflect, x3_reflect, y3_reflect, RED);
    delay(1000); // Delay to show the reflection about y = x

    // Reflection about the x-axis followed by 90 degrees counterclockwise rotation
    int x1_transform = x1, y1_transform = y1;
    int x2_transform = x2, y2_transform = y2;
    int x3_transform = x3, y3_transform = y3;

    reflectAboutXAxis(y1_transform);
    reflectAboutXAxis(y2_transform);
    reflectAboutXAxis(y3_transform);

    rotate90Counterclockwise(x1_transform, y1_transform);
    rotate90Counterclockwise(x2_transform, y2_transform);
    rotate90Counterclockwise(x3_transform, y3_transform);

    // Draw triangle after reflection about x-axis and rotation (GREEN)
    drawTriangle(x1_transform, y1_transform, x2_transform, y2_transform, x3_transform, y3_transform, GREEN);
    delay(1000); // Delay to show the combined transformation

    // Wait for a key press
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}
