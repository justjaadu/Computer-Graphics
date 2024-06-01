//3. Write a Program to implement Bresenham’s Circle drawing algorithm.

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// Function to draw a circle using Bresenham's Circle Drawing Algorithm
void brescir(int x, int y, int r, int color) {
    int i = 0, j = r, p = 3 - 2 * r;
    while (i <= j) {
        putpixel(x + i, y + j, color);
        putpixel(x - i, y - j, color);
        putpixel(x + j, y + i, color);
        putpixel(x - j, y - i, color);
        putpixel(x - i, y + j, color);
        putpixel(x + i, y - j, color);
        putpixel(x - j, y + i, color);
        putpixel(x + j, y - i, color);
        if (p < 0) {
            i++;
            p = p + 4 * i + 6;
        } else {
            i++;
            j--;
            p = p + 4 * (i - j) + 10;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int x, y, r;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    // Take user input for circles
    printf("Enter the center coordinates of the first circle (x, y) and radius: ");
    scanf("%d %d %d", &x, &y, &r);
    brescir(x, y, r, MAGENTA); //any color you want

    getch();
    closegraph(); // Close the graphics mode before exiting

    return 0;
}
