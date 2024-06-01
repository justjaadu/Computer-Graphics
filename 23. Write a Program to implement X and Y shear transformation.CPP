//23. Write a Program to implement X and Y shear transformation


#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main() {
    int gm, gr, x, y, az, w, ch2;
    float x1, y1, az1, w1, x1s, y1s;

    detectgraph(&gm, &gr);
    initgraph(&gm, &gr, "C:\\TURBOC3\\BGI");

    printf("Enter the upper left corner of the rectangle:\n");
    scanf("%d%d", &x, &y);
    printf("Enter the lower right corner of the rectangle:\n");
    scanf("%d%d", &az, &w);

    rectangle(x, y, az, w);

    printf("Shearing\n\n");
    printf("1.x-direction shear\n2.y-direction shear\nEnter your choice:\n");
    scanf("%d", &ch2);

    switch (ch2) {
        case 1:
            printf("Enter the value of shear in x-direction:\n");
            scanf("%f", &x1s);
            x1 = x + (y * x1s);
            y1 = y;
            az1 = az + (w * x1s);
            w1 = w;
            rectangle(x1, y1, az1, w1);
            break;

        case 2:
            printf("Enter the value of shear in y-direction:\n");
            scanf("%f", &y1s);
            x1 = x;
            y1 = y + (x * y1s);
            az1 = az;
            w1 = w + (az * y1s);
            rectangle(x1, y1, az1, w1);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    getch();
    closegraph();
    return 0;
}
