#include <stdio.h>
#include <graphics.h>
#include <math.h>

void draw(int arr[5][2], int n)
{   
    setcolor(WHITE);
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

void translation(int a[5][2], int n, int tx, int ty)
{
	int i, j, k;
	int at[5][2];
	int b[3][3]; // transfomation matrix
	int h[5][3]; // homogenous co - ordinates
	int mul[5][3];
	int x[5][2]; // for display
	b[0][0] = 1;
	b[0][1] = 0;
	b[0][2] = 0;
	b[1][0] = 0;
	b[1][1] = 1;
	b[1][2] = 0;
	b[2][0] = tx;
	b[2][1] = ty;
	b[2][2] = 1;

	for (i = 0; i < n; i++)
	{
		at[i][0] = a[i][0] - 320;
		at[i][1] = 240 - a[i][1];
	}
	for (i = 0; i < n; i++)
	{
		h[i][0] = at[i][0];
		h[i][1] = at[i][1];
		h[i][2] = 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			mul[i][j] = 0;
			for (k = 0; k < 3; k++)
			{
				mul[i][j] += h[i][k] * b[k][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		mul[i][0] += 320;
		mul[i][1] = 240 - mul[i][1];
	}
	// coverting matrix again in 2 columns for display
	for (i = 0; i < n; i++)
	{
		x[i][0] = mul[i][0];
		x[i][1] = mul[i][1];
	}
	line(320, 0, 320, 479);
	line(0, 240, 679, 240);
	setcolor(RED);
	draw(x, n);
}

void reflection_x(int a[5][2], int n)
{
	int i, j, k;
	int b[2][2], mul[5][2];
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
	line(320, 0, 320, 479);
	line(0, 240, 679, 240);
	setcolor(RED);
	draw(mul, n);
}

void reflection_y(int a[5][2], int n)
{
	int i, j, k;
	int b[2][2], mul[5][2];
	int ar[5][2];
	//	b[2][2];   //transformation matrix
	b[0][0] = -1;
	b[0][1] = 0;
	b[1][0] = 0;
	b[1][1] = 1;

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
	line(320, 0, 320, 479);
	line(0, 240, 679, 240);
	setcolor(RED);
	draw(mul, n);
}

void reflection_origin(int a[5][2], int n)
{
	int i, j, k;
	int b[2][2], mul[5][2];
	int ar[5][2];
	//	b[2][2];   //transformation matrix
	b[0][0] = -1;
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
	line(320, 0, 320, 479);
	line(0, 240, 679, 240);
	setcolor(RED);
	draw(mul, n);
}

void reflection_yx(int a[5][2], int n)
{
	int i, j, k;
	int b[2][2], mul[5][2];
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
	line(320, 0, 320, 479);
	line(0, 240, 679, 240);
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
	line(320, 0, 320, 479);
	line(0, 240, 679, 240);
	setcolor(RED);
	draw(mul, n);
}

void rotation_arb(int a[5][2], int n, float angle, int tx, int ty)
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

	translation(a, n, -tx, -ty);
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
	translation(mul, n, tx, ty);
	setcolor(WHITE);
	line(320, 0, 320, 479);
	line(0, 240, 679, 240);
	setcolor(RED);
	draw(mul, n);
}

void scaling(int a[5][2], int n, int sx, int sy)
{
	int i, j, k;
	int b[2][2], mul[5][2];
	int as[5][2];
	//	b[2][2];   //transformation matrix
	b[0][0] = sx;
	b[0][1] = 0;
	b[1][0] = 0;
	b[1][1] = sy;

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
	line(320, 0, 320, 479);
	line(0, 240, 679, 240);
	setcolor(RED);
	draw(mul, n);
}

void shear_x(int a[5][2], int n, int sx)
{
	int i, j, k;
	int b[2][2], mul[5][2];
	int as[5][2];
	//	b[2][2];   //transformation matrix
	b[0][0] = 1;
	b[0][1] = 0;
	b[1][0] = sx;
	b[1][1] = 1;

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
	line(320, 0, 320, 479);
	line(0, 240, 679, 240);
	setcolor(RED);
	draw(mul, n);
}

void shear_y(int a[5][2], int n, int sy)
{
	int i, j, k;
	int b[2][2], mul[5][2];
	int as[5][2];
	//	b[2][2];   //transformation matrix
	b[0][0] = 1;
	b[0][1] = sy;
	b[1][0] = 0;
	b[1][1] = 1;

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
	line(320, 0, 320, 479);
	line(0, 240, 679, 240);
	setcolor(RED);
	draw(mul, n);
}

int main()
{
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
	int i, n, ch;
	float angle;
	int a[5][2];
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

	while (1)
	{
		printf("\n1. Scaling");
		printf("\n2. Rotation");
		printf("\n3. Rotation @ arbitary point");
		printf("\n4. Translation");
		printf("\n5. Reflection @ X - axis");
		printf("\n6. Reflection @ y - axis");
		printf("\n7. Reflection @ origin - axis");
		printf("\n8. Reflection @ Y = X - axis");
		printf("\n9. Shear X");
		printf("\n10. Shear Y");
		printf("\n11. Exit");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
            cleardevice();
			printf("Enter Value of sx and sy : ");
			scanf("%d%d", &sx, &sy);
            setcolor(WHITE);
			draw(a, n);
			line(320, 0, 320, 479);
			line(0, 240, 679, 240);
			scaling(a, n, sx, sy);
			getch();
			break;

		case 2:
        	cleardevice();
			printf("Enter the angle of rotation: ");
			scanf("%f", &angle);
            setcolor(WHITE);
			draw(a, n);
			line(320, 0, 320, 479);
			line(0, 240, 679, 240);
			rotation(a, n, angle);
			getch();
			break;

		case 3:
        	cleardevice();
			printf("Enter the angle of rotation: ");
			scanf("%f", &angle);
			printf("Enter Value of tx and ty : ");
			scanf("%d%d", &tx, &ty);
            setcolor(WHITE);
			draw(a, n);
			line(320, 0, 320, 479);
			line(0, 240, 679, 240);
			rotation_arb(a, n, angle, tx, ty);
			getch();
			break;

		case 4:
        	cleardevice();
			printf("Enter Value of tx and ty : ");
			scanf("%d%d", &tx, &ty);
            setcolor(WHITE);
			draw(a, n);
			line(320, 0, 320, 479);
			line(0, 240, 679, 240);
			translation(a, n, tx, ty);
			getch();
			break;

		case 5:
        	cleardevice();
            setcolor(WHITE);
			draw(a, n);
			line(320, 0, 320, 479);
			line(0, 240, 679, 240);
			reflection_x(a, n);
			getch();
			break;

		case 6:
        	cleardevice();
            setcolor(WHITE);
			draw(a, n);
			line(320, 0, 320, 479);
			line(0, 240, 679, 240);
			reflection_y(a, n);
			getch();
			break;

		case 7:
        	cleardevice();
            setcolor(WHITE);
			draw(a, n);
			line(320, 0, 320, 479);
			line(0, 240, 679, 240);
			reflection_origin(a, n);
			getch();
			break;

		case 8:
        	cleardevice();
             setcolor(WHITE);
			draw(a, n);
			line(320, 0, 320, 479);
			line(0, 240, 679, 240);
			line(560, 0, 80, 480);
			reflection_yx(a, n);
			getch();
			break;

		case 9:
        	cleardevice();
			printf("Enter Value of sx : ");
			scanf("%d", &sx);
             setcolor(WHITE);
			draw(a, n);
			line(320, 0, 320, 479);
			line(0, 240, 679, 240);
			shear_x(a, n, sx);
			getch();
			break;

		case 10:
        	cleardevice();
			printf("Enter Value of sy : ");
			scanf("%d", &sy);
			draw(a, n);
             setcolor(WHITE);
			line(320, 0, 320, 479);
			line(0, 240, 679, 240);
			shear_y(a, n, sy);
			getch();
			break;

		case 11:
			exit(0);
		}

	}
    closegraph();
    return 0;
}