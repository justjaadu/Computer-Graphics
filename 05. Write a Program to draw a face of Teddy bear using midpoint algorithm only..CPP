
//5. Write a Program to draw a face of Teddy bear using midpoint algorithm only.

#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);


        if (p < 0) {
            p = p + 2 * x + 3;
        } else {
            p = p + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

void drawTeddyFace() {
    // Head
    drawCircle(250, 250, 100);
    
    // Ears
    drawCircle(180, 180, 50);
    drawCircle(320, 180, 50);

    // Eyes
    drawCircle(220, 220, 15);
    drawCircle(280, 220, 15);

    // Nose
    drawCircle(250, 270, 10);

    // Mouth (using 2 circles for simplicity)
    drawCircle(235, 300, 20);
    drawCircle(265, 300, 20);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    drawTeddyFace();

    getch();
    closegraph();
    return 0;
}
