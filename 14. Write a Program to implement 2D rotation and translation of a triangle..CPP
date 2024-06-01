//14. Write a Program to implement 2D rotation and translation of a triangle.

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int customRound(float num) {
    return (num >= 0) ? (int)(num + 0.5) : (int)(num - 0.5);
}

void drawPolygon(int a[][2], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
    }
    line(a[n - 1][0], a[n - 1][1], a[0][0], a[0][1]);
}

void scanLineFill(int a[][2], int n) {
    int dy, dx;
    int x, y, i, j;
    int xi[20];
    float slope[20];

    for (i = 0; i < n; i++) {
        dy = a[(i + 1) % n][1] - a[i][1];
        dx = a[(i + 1) % n][0] - a[i][0];
        if (dy != 0) {
            slope[i] = (float)dx / dy;
        } else {
            slope[i] = 0;
        }
    }

    for (y = 0; y < 480; y++) {
        int k = 0;
        for (i = 0; i < n; i++) {
            int ymin = a[i][1] < a[(i + 1) % n][1] ? a[i][1] : a[(i + 1) % n][1];
            int ymax = a[i][1] > a[(i + 1) % n][1] ? a[i][1] : a[(i + 1) % n][1];
            if (y >= ymin && y < ymax) {
                xi[k++] = customRound(a[i][0] + slope[i] * (y - a[i][1]));
            }
        }
        for (i = 0; i < k - 1; i++) {
            for (j = 0; j < k - 1; j++) {
                if (xi[j] > xi[j + 1]) {
                    int temp = xi[j];
                    xi[j] = xi[j + 1];
                    xi[j + 1] = temp;
                }
            }
        }
        setcolor(LIGHTBLUE);
        for (i = 0; i < k; i += 2) {
            if (xi[i] < xi[i + 1]) {
                line(xi[i], y, xi[i + 1] + 1, y);
            }
        }
    }
}

void drawAxes() {
    setcolor(WHITE);
    line(0, 0, 630, 0);
    line(0, 475, 630, 475);
    line(0, 0, 0, 480);
    line(630, 0, 630, 475);
    line(0, 242, 630, 242);
    line(320, 0, 320, 475);
}

void clearScreen() {
    cleardevice();
    drawAxes();
}

void translate(int a[][2], int n, int tx, int ty) {
    int i;
    for (i = 0; i < n; i++) {
        a[i][0] += tx;
        a[i][1] += ty;
    }
}

void rotate(int a[][2], int n, float angle) {
    int i;
    float radians = angle * M_PI / 180.0; // Convert angle to radians

    // Calculate the center of the polygon
    int centerX = 0, centerY = 0;
    for (i = 0; i < n; i++) {
        centerX += a[i][0];
        centerY += a[i][1];
    }
    centerX /= n;
    centerY /= n;

    // Translate polygon to origin
    for (i = 0; i < n; i++) {
        a[i][0] -= centerX;
        a[i][1] -= centerY;
    }

    // Perform rotation
    for (i = 0; i < n; i++) {
        int x = a[i][0];
        int y = a[i][1];
        a[i][0] = centerX + (int)(x * cos(radians) - y * sin(radians));
        a[i][1] = centerY + (int)(x * sin(radians) + y * cos(radians));
    }
}

void drawMenu() {
    printf("\nMenu:\n");
    printf("1. Translate\n");
    printf("2. Rotate\n");
    printf("3. Exit\n");
}

void getTriangleInput(int a[][2]) {
    printf("Enter coordinates for vertex 1 (x y): ");
    scanf("%d %d", &a[0][0], &a[0][1]);
    printf("Enter coordinates for vertex 2 (x y): ");
    scanf("%d %d", &a[1][0], &a[1][1]);
    printf("Enter coordinates for vertex 3 (x y): ");
    scanf("%d %d", &a[2][0], &a[2][1]);
}

int main() {
    int n = 3, i; // Change to represent a triangle
    int gd = DETECT, gm;
    int choice;
    int tx, ty;
    float angle;
    int a[3][2]; // Coordinates of a triangle

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI ");

    drawAxes();
    getTriangleInput(a);
    scanLineFill(a, n);
    getch();

    do {
        cleardevice();
        drawAxes();
        scanLineFill(a, n);
        drawMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter translation values (tx ty): ");
                scanf("%d %d", &tx, &ty);
                translate(a, n, tx, ty);
                break;
            case 2:
                printf("Enter angle of rotation: ");
                scanf("%f", &angle);
                rotate(a, n, angle);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3);

    closegraph();
    return 0;
}

