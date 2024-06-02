#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <conio.h>
#define PI 3.14

int gd = DETECT, gm;
int pivotx, pivoty;
double thetamax, theta;
double len = 260;
int x, y, ymax, xmax;
int bobradius = 30;
int xsign = -1, ysign = 1;
double omega;

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float xIncrement, yIncrement, x = x1, y = y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = dx / (float) steps;
    yIncrement = dy / (float) steps;

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        if ((int)(x + 0.5) == x2 && (int)(y + 0.5) == y2) {
            break; // Stop drawing at the endpoint
        }
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
    }
}
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
void paint() {
    // Clear the screen
    cleardevice();

    // Draw the pivot
    setcolor(WHITE);
    brescir(pivotx, pivoty, 8,WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(pivotx, pivoty, WHITE);

    // Draw the pendulum line and bob
    drawLine(pivotx, pivoty, x, y);
    setcolor(WHITE);
    brescir(x, y, bobradius,WHITE);
      setfillstyle(SOLID_FILL, WHITE);
    floodfill(x,y, WHITE);

}

int main(){
    double decr;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI\\");
    thetamax = 60 * PI / 180;
    pivotx = getmaxx() / 2;
    pivoty = 30;
    ymax = (int)(pivoty + len * cos(thetamax));
    xmax = (int)(pivotx + len * sin(thetamax));
    x = xmax;
    y = ymax;
    theta = thetamax;

    while (1) {
        if (kbhit() && getch() == 13) { // Check if Enter key (ASCII 13) is pressed
            break;
        }

        if (x >= pivotx + abs(len * sin(thetamax))) {
            xsign = -1;
            ysign *= -1;
            x = xmax - 1;
            delay(40);
        } else if (x <= pivotx - abs(len * sin(thetamax))) {
            ysign *= -1;
            xsign = 1;
            x = (int)(pivotx - abs(len * sin(thetamax)) + 2);
            delay(40);
        } else if (y >= pivoty + len) {
            ysign *= -1;
        }

        omega = y / 60 * PI / 180;
        decr = xsign * omega;
        theta = theta + decr;
        x = (int)(pivotx + len * sin(theta));
        y = (int)(pivoty + len * cos(theta));
        paint();
        delay(40);
    }

closegraph();
return 0;
}


