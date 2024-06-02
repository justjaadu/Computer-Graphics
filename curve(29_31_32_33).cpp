#include <graphics.h>
#include <conio.h>
#include <math.h>

void koch(int x1, int y1, int x2, int y2, int it)
{
    float angle = 60 * M_PI / 180;
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;

    int x4 = (x1 + 2 * x2) / 3;
    int y4 = (y1 + 2 * y2) / 3;

    int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
    int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

    if (it > 0)
    {
        koch(x1, y1, x3, y3, it - 1);
        koch(x3, y3, x, y, it - 1);
        koch(x, y, x4, y4, it - 1);
        koch(x4, y4, x2, y2, it - 1);
    }
    else
    {

        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
    }
}

void fractal_Lines(int x1, int y1, int x2, int y2, int depth)
{
    if (depth == 0)
    {
        line(x1, y1, x2, y2);
    }
    else
    {
        int dx = x2 - x1;
        int dy = y2 - y1;

        int x3 = x1 + dx / 3;
        int y3 = y1 + dy / 3;

        int x4 = x2 - dx / 3;
        int y4 = y2 - dy / 3;

        int x5 = x3 + (int)(dx - dy * sqrt(3)) / 6;
        int y5 = y3 + (int)(dy + dx * sqrt(3)) / 6;

        fractal_Lines(x1, y1, x3, y3, depth - 1);
        fractal_Lines(x3, y3, x5, y5, depth - 1);
        fractal_Lines(x5, y5, x4, y4, depth - 1);
        fractal_Lines(x4, y4, x2, y2, depth - 1);
    }
}

void drawBezierCurve(int x[], int y[])
{
    int i;
    double t, xt, yt;

    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
        yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
        putpixel((int)xt, (int)yt, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    int x1, y1, x2, y2, n, i;
    int choice;
    int x[30], y[30]; // for four bezier curve
	cleardevice();

    while (1)
    {
	printf("\n1. Bezier Curve\n2. Triadic Koch Curve\n3. Fractal lines\n4. Exit ");
	printf("\nEnter your choice : ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
        cleardevice();
	    printf("Enter the no. of control points: ");
	    scanf("%d", &n);

	    printf("Enter the co-ordinates of control points:\n");
	    for (i = 0; i < n; i++)
	    {
		printf("Control Point %d (x, y): ", i + 1);
		scanf("%d %d", &x[i], &y[i]);
	    }

	    drawBezierCurve(x, y);
	    getch();
	    break;
	case 2:
	    printf("\nEnter x1 y1 x2 y2 :");
	    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	    printf("Enter no. of points : ");
	    scanf("%d", &n);
	    cleardevice();
	    koch(x1, y1, x2, y2, n);
	    getch();
	    break;

    case 3:
        printf("\nEnter x1 y1 x2 y2 :");
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("Enter no. of points : ");
        scanf("%d", &n);
        cleardevice();
        fractal_Lines(x1, y1, x2, y2, n);
        getch();
        break;
    case 4:
        exit(0);
    default:
        printf("\nInvalid choicw...!");
        }
    }
	    closegraph();
        return 0;
}