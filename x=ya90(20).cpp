#include <stdio.h>
#include <graphics.h>
#include <math.h>


void printMatrix(int matrix[][2], int n) 
{
    int i, j;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void draw(int arr[5][2], int n)
{
    int i, x, y, x1, y1;
    for (i = 0; i < n; i++)
    {
        x = arr[i][0];
        y = arr[i][1];
        if (i != 0)
            line(x1, y1, x, y);
        x1 = x;
        y1 = y;
    }
    line(x1, y1, arr[0][0], arr[0][1]);
}

void reflection_x(int a[5][2], int n, int mul[5][2])
{
    int i, j, k;
    int b[2][2];
    int ar[5][2];
    //	b[2][2];   //transformation matrix
    b[0][0] = 1;
    b[0][1] = 0;
    b[1][0] = 0;
    b[1][1] = -1;

    for (i = 0; i < n; i++)
    {

        ar[i][0] = a[i][0] - 320;
        ar[i][1] = 240 - a[i][1];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < 2; k++)
            {
                mul[i][j] += ar[i][k] * b[k][j];
            }
        }
    }
    for (i = 0; i < n; i++)
    {

	mul[i][0] += 320;
	mul[i][1] = 240 - mul[i][1];
    }
    setcolor(RED);
    draw(mul, n);
}

void reflection_yx(int a[5][2], int n, int mul[5][2])
{
    int i, j, k;
    int b[2][2];
    int ar[5][2];
    //	b[2][2];   //transformation matrix
    b[0][0] = 0;
    b[0][1] = 1;
    b[1][0] = 1;
    b[1][1] = 0;

    for (i = 0; i < n; i++)
    {

	ar[i][0] = a[i][0] - 320;
	ar[i][1] = 240 - a[i][1];
    }

    for (i = 0; i < n; i++)
    {
	for (j = 0; j < 2; j++)
	{
	    mul[i][j] = 0;
	    for (k = 0; k < 2; k++)
	    {
		mul[i][j] += ar[i][k] * b[k][j];
	    }
	}
    }
    for (i = 0; i < n; i++)
    {

	mul[i][0] += 320;
	mul[i][1] = 240 - mul[i][1];
    }
    setcolor(RED);
    draw(mul, n);
}

void rotation(int a[5][2], int n, float angle)
{
    int i, j, k;
    float s, c;
    int b[2][2], mul[5][2];
    int as[5][2];
    c = cos(angle * 0.017453);
    s = sin(angle * 0.017453);
    //	    b[2][2];   //transformation matrix
    b[0][0] = c;
    b[0][1] = s;
    b[1][0] = -s;
    b[1][1] = c;

    for (i = 0; i < n; i++)
    {
	as[i][0] = a[i][0] - 320;
	as[i][1] = 240 - a[i][1];
    }

    for (i = 0; i < n; i++)
    {
	for (j = 0; j < 2; j++)
	{
	    mul[i][j] = 0;
	    for (k = 0; k < 2; k++)
	    {
		mul[i][j] += as[i][k] * b[k][j];
	    }
	}
    }
    for (i = 0; i < n; i++)
    {
	mul[i][0] += 320;
	mul[i][1] = 240 - mul[i][1];
    }
    setcolor(WHITE);
    draw(mul, n);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    int i, n, ch;
    float angle;
    int a[5][2], mul[5][2];
    int sx, sy, tx, ty;
    cleardevice();
    printf("\nEnter number of vertices : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
	printf("Enter x%d and y%d : ", i + 1, i + 1);
	scanf("%d %d", &a[i][0], &a[i][1]);
	a[i][0] += 320;
	a[i][1] = 240 - a[i][1];
    }
    for (i = 0; i < n; i++)
    {

	printf("\n%d %d", a[i][0], a[i][1]);
    }

    
    draw(a, n);
    line(320, 0, 320, 479);
    line(0, 240, 679, 240);
    line(560, 0, 80, 480);
    reflection_yx(a, n, mul);
    printf("This is the graphical representation of y = x reflection : ");
    printf("\nThis is the matrix : \n");
    printMatrix(mul, n);
    getch();
    cleardevice();
    draw(a, n);
    line(320, 0, 320, 479);
    line(0, 240, 679, 240);
    reflection_x(a, n, mul);
    printf("This is the graphical representation of x reflection : ");
//    printf("\nThis is the matrix : \n");
//    printMatrix(mul, n);
    getch();

    draw(a, n);
    rotation(mul, n, 90.00);
    printf("\nThis is the graphical representation of rotation 90 : ");
    printf("\nThis is the matrix : \n");
    printMatrix(mul, n);
    getch();
    

    printf("As we saw the LHS and RHS matrix are equal.\nWe proved that reflection about a line Y=X is equivalent to reflection relative to X-axis followed by anticlockwise rotation of 90 deg");
    getch();
    closegraph();
    return 0;
}