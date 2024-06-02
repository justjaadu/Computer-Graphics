#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

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

#define PI 3.14159265

int main()
{
    // Radius and center of the main circle
    int centerX = 150;
    int centerY = 150;
    int radius_main = 100; // Radius of the main circle
    int radius_moving = 12; // Radius of the moving circle

    // Initial angle for the moving circle
    float angle = 0;

    int gd = DETECT, gm, i, x, y;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");

    while (1)
    {
        // Clear the screen
        cleardevice();

        // Draw the main circle using Bresenham's algorithm
        brescir(centerX, centerY, radius_main, WHITE);

        // Calculate position of moving circle
        x = centerX + (int)((radius_main - radius_moving) * cos(angle * PI / 180));
        y = centerY + (int)((radius_main - radius_moving) * sin(angle * PI / 180));

        // Draw the moving circle using Bresenham's algorithm
        brescir(x, y, radius_moving, WHITE);

        // Delay to slow down the speed of moving circle
        delay(50);

        // Update the angle for next position
        angle += 1;

        // Reset angle when a complete circle is completed
        if (angle >= 360)
            angle = 0;

        // Check if Enter key is pressed to exit
        if (kbhit()) {
            if (getch() == '\r')  // '\r' represents Enter key
                break;
        }
    }

    getch();
    closegraph();
    return 0;
}

