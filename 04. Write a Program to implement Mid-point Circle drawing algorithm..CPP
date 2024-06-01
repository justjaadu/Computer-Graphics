//4. Write a Program to implement Mid-point Circle drawing algorithm

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

// Function to draw a circle using Midpoint Circle Drawing Algorithm
void midcir(int x, int y, int r) {
    int p = 1 - r;
    int i = 0;
    int j = r;

    while (i <= j) {
        putpixel(x + i, y + j, WHITE);
        putpixel(x + j, y + i, WHITE);
        putpixel(x - j, y + i, WHITE);
        putpixel(x + j, y - i, WHITE);
        putpixel(x - i, y - j, WHITE);
        putpixel(x - j, y - i, WHITE);
        putpixel(x - i, y + j, WHITE);
        putpixel(x + i, y - j, WHITE);

        if (p < 0) {
            i++;
            p = p + 2 * i + 1;
        } else {
            i++;
            j--;
            p = p - 2 * j + 2 * i + 1;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int x, y, r;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Take user input for circles
    printf("Enter the center coordinates of the first circle (x, y) and radius: ");
    scanf("%d %d %d", &x, &y, &r);

    midcir(x, y, r);
     getch();
    closegraph(); // Close the graphics mode before exiting

    return 0;
}

