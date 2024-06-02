#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

struct active_edge
{
	int edges, ymax, xmax, ymin, xmin;
	float m;
} s[10];

struct node
{
	int xd, yd;
	struct node *next;
};
struct node *head = NULL, *tail = NULL;

/*void bresenham(int x1, int y1, int x2, int y2)
{
	int G, dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;
	dx = abs(dx);
	dy = abs(dy);

	if (dx > dy) // Gentle slpe
	{
		G = (2 * dy) - dx;
		do
		{
			if (G >= 0)
			{
				x1 = x1 + 1;
				y1 = y1 + 1;
				G = G + (2 * dy) - (2 * dx);
			}
			else
			{
				x1 = x1 + 1;
				G = G + (2 * dy);
			}
			putpixel(x1, y1, WHITE);
		} while (x1 <= x2);
	}
	else // Steep slope
	{
		G = (2 * dx) - dy;
		do
		{
			if (G >= 0)
			{
				x1 = x1 + 1;
				y1 = y1 + 1;
				G = G + (2 * dx) - (2 * dy);
			}
			else
			{
				y1 = y1 + 1;
				G = G + (2 * dx);
			}
			putpixel(x1, y1, WHITE);
		} while (y1 <= y2);
	}
}*/


void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int slope_x = x1 < x2 ? 1 : -1;
    int slope_y = y1 < y2 ? 1 : -1;
    int x, y;
    if (dy <= dx) {
        int d = 2 * dy - dx;
        int y = y1;

        for (x = x1; x != x2; x += slope_x) {
            putpixel(x, y, WHITE);
            delay(1);
            if (d > 0) {
                y += slope_y;
                d -= 2 * dx;
            }
            d += 2 * dy;
        }
    } else {
        int d = 2 * dx - dy;
        int x = x1;
        for (y = y1; y != y2; y += slope_y) {
            putpixel(x, y, WHITE);
            delay(1);
            if (d > 0) {
                x += slope_x;
                d -= 2 * dy;
            }
            d += 2 * dx;
        }
    }
}


void sorting(int n)
{
	int i, key, key1, key2, key3, key4, j, x1, y1, x2, y2;
	for (i = 1; i < n; i++)
	{
		key = s[i].ymax;
		key1 = s[i].xmax;
		key2 = s[i].ymin;
		key3 = s[i].xmin;
		key4 = s[i].edges;
		j = i - 1;

		while (j >= 0 && s[j].ymax > key)
		{
			s[j + 1].ymax = s[j].ymax;
			s[j + 1].edges = s[j].edges;
			s[j + 1].xmax = s[j].xmax;
			s[j + 1].ymin = s[j].ymin;
			s[j + 1].xmin = s[j].xmin;
			j = j - 1;
		}
		s[j + 1].ymax = key;
		s[j + 1].xmax = key1;
		s[j + 1].ymin = key2;
		s[j + 1].xmin = key3;
		s[j + 1].edges = key4;
	}
	printf("\n");
	printf("\nAfter sorting ....");
	for (i = 0; i < n; i++)
	{
		x1 = s[i].xmin;
		x2 = s[i].xmax;
		y1 = s[i].ymin;
		y2 = s[i].ymax;
		s[i].m = abs(y2 - y1) / (float)abs(x2 - x1);
		printf("\n%d\t%d\t%d\t%d\t%d\t%f", s[i].edges, s[i].ymax, s[i].xmax, s[i].ymin, s[i].xmin, s[i].m);
	}
}

void edge(int arr[10][2], int n)
{
	int i, ymax, ymin, xmax, xmin;
	// int active[10][5];
	for (i = 0; i < n - 1; i++)
	{
		s[i].edges = i + 1;
		if (arr[i][1] >= arr[i + 1][1])
		{
			s[i].ymax = arr[i][1];
			s[i].xmax = arr[i][0];
			s[i].ymin = arr[i + 1][1];
			s[i].xmin = arr[i + 1][0];
		}

		else
		{
			s[i].ymax = arr[i + 1][1];
			s[i].xmax = arr[i + 1][0];
			s[i].ymin = arr[i][1];
			s[i].xmin = arr[i][0];
		}
	}
	s[i].edges = i + 1;
	if (arr[0][1] >= arr[i][1])
	{
		s[i].ymax = arr[0][1];
		s[i].xmax = arr[0][0];
		s[i].ymin = arr[i][1];
		s[i].xmin = arr[i][0];
	}
	else
	{
		s[i].ymax = arr[i][1];
		s[i].xmax = arr[i][0];
		s[i].ymin = arr[0][1];
		s[i].xmin = arr[0][0];
	}

	for (i = 0; i < n; i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d", s[i].edges, s[i].ymax, s[i].xmax, s[i].ymin, s[i].xmin);
	}
}

void scanline(int a[10][2], int n)
{

	int i, j, k, gd = DETECT, gm, dy, dx;
	int x, y, temp;
	int xi[20];
	float slope[20];

	a[n][0] = a[0][0];
	a[n][1] = a[0][1];
	//edge(a, n);
	//sorting(n);
	//getch();

	for (i = 0; i < n; i++)
	{
		line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
	}
	for (i = 0; i < n; i++)
	{
		dy = a[i + 1][1] - a[i][1];
		dx = a[i + 1][0] - a[i][0];

		if (dy == 0)
			slope[i] = 1.0;
		if (dx == 0)
			slope[i] = 0.0;

		if ((dy != 0) && (dx != 0))
		{
			slope[i] = (float)dx / dy;
		}
	}

	for (y = 0; y < 480; y++)
	{
		k = 0;
		for (i = 0; i < n; i++)
		{

			if (((a[i][1] <= y) && (a[i + 1][1] > y)) || ((a[i][1] > y) && (a[i + 1][1] <= y)))
			{
				xi[k] = (int)(a[i][0] + slope[i] * (y - a[i][1]));
				k++;
			}
		}

		for (j = 0; j < k - 1; j++)
			for (i = 0; i < k - 1; i++)
			{
				if (xi[i] > xi[i + 1])
				{
					temp = xi[i];
					xi[i] = xi[i + 1];
					xi[i + 1] = temp;
				}
			}

		setcolor(4);
		for (i = 0; i < k; i += 2)
		{
			line(xi[i], y, xi[i + 1] + 1, y);
			delay(10);
		}
	}
}


void addq(int x, int y)
{
	struct node *newNode = (node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->xd = x;
	newNode->yd = y;
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
		tail->next = NULL;
	}
}

struct node *delq()
{
	struct node *p = head, *q = head;
	head = head->next;
	q = p->next;
	p->next = NULL;
	free(p);
	return q;
}

int check(int x, int y)
{
	int color;
	color = getpixel(x, y);
	if (color == RED || color == WHITE)
		return 0;
	else
		return 1;
}

void b_fill(int xmid, int ymid)
{
	int color, a;
	struct node *p;
	a = check(xmid, ymid);
	if (a == 1)
	{
		putpixel(xmid, ymid, RED);
		addq(xmid, ymid);
	}
	p = head;

	while (head != NULL)
	{

		if (p != NULL)
		{

			a = check((p->xd) + 1, p->yd);
			if (a == 1)
			{
				putpixel((p->xd) + 1, p->yd, RED);
				addq((p->xd) + 1, p->yd);
			}

			a = check((p->xd) - 1, p->yd);
			if (a == 1)
			{
				putpixel((p->xd) - 1, p->yd, RED);
				addq((p->xd) - 1, p->yd);
			}

			a = check(p->xd, (p->yd) - 1);
			if (a == 1)
			{
				putpixel(p->xd, (p->yd) - 1, RED);
				addq(p->xd, (p->yd) - 1);
			}

			a = check(p->xd, (p->yd) + 1);
			if (a == 1)
			{
				putpixel(p->xd, (p->yd) + 1, RED);
				addq(p->xd, (p->yd) + 1);
			}
			p = delq();
		}
	}
}

void draw(int arr[10][2], int n)
{

	int i, x, y, x1, y1;
	for (i = 0; i < n; i++)
	{
		x = arr[i][0];
		y = arr[i][1];
		if (i != 0)
			bresenham(x1, y1, x, y);
		x1 = x;
		y1 = y;
	}
	line(x1, y1, arr[0][0], arr[0][1]);
}

void edge_fill(int a[10][2], int n, int ymin, int ymax)
{

	int dx, dy, x_next, y_next, g, g_next, i;
	int x1, y1, x2, y2, xd, yd = 0;
	for (i = 0; i < n; i++)
	{
		x1 = a[i][0];
		y1 = a[i][1];
		if (i < n - 1)
		{
			x2 = a[i + 1][0];
			y2 = a[i + 1][1];
		}
		else
		{
			x2 = a[0][0];
			y2 = a[0][1];
		}

		dx = abs(x2 - x1);
		dy = abs(y2 - y1);

		x_next = x1;
		y_next = y1;
		if (dx >= dy)
		{

			g = (2 * dy) - dx;
			g_next = g;
			do
			{
				if (yd != y_next)
				{
					for (xd = x_next; xd <= 639; xd++)
					{

						if (getpixel(xd, y_next) == 0 && y_next != ymin && y_next != ymax)
							putpixel(xd, y_next, 4);
						else if (getpixel(xd, y_next) == 4)
							putpixel(xd, y_next, 0);
					}
				}
				yd = y_next;
				if (g_next >= 0)
				{
					if (x1 < x2)
						x_next += 1;
					if (x1 > x2)
						x_next -= 1;
					if (y1 < y2)
						y_next += 1;
					if (y1 > y2)
						y_next -= 1;
					g_next = g_next + (2 * dy) - (2 * dx);
				}
				else
				{
					if (x1 < x2)
						x_next += 1;
					if (x1 > x2)
						x_next -= 1;
					g_next = g_next + (2 * dy);
				}
			} while (x_next != x2);
		}
		else
		{
			g = 2 * dx - dy;
			g_next = g;
			do
			{
				if (yd != y_next)
				{
					for (xd = x_next; xd <= 639; xd++)
					{

						if (getpixel(xd, y_next) == 0 && y_next != ymin && y_next != ymax)
							putpixel(xd, y_next, 4);
						else if (getpixel(xd, y_next) == 4)
							putpixel(xd, y_next, 0);
					}
				}
				yd = y_next;
				if (g_next >= 0)
				{
					if (x1 < x2)
						x_next += 1;
					if (x1 > x2)
						x_next -= 1;
					if (y1 < y2)
						y_next += 1;
					if (y1 > y2)
						y_next -= 1;
					g_next = g_next + (2 * dx) - (2 * dy);
				}
				else
				{
					if (y1 < y2)
						y_next += 1;
					if (y1 > y2)
						y_next -= 1;
					g_next = g_next + (2 * dx);
				}
			} while (y_next != y2);
		}
	}
}

int main() 
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:/TURBOC3/BGI");
	int ch, n, i, x1, y1, x2, y2, x, y, arr[10][2], j, x_init, y_init;
	int xmin = 0, xmax = 0, ymin = 0, ymax = 0, xmid, ymid;
	
	cleardevice();
	printf("\nEnter number of vertices : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter x%d and y%d : ", i + 1, i + 1);
		scanf("%d%d", &arr[i][0], &arr[i][1]);
	}
	xmin = arr[0][0];
	ymin = arr[0][1];
	for (i = 0; i < n; i++)
	{
		printf("%d\t", arr[i][0]);
		printf("%d", arr[i][1]);
		if (arr[i][0] < xmin)
			xmin = arr[i][0];
		if (arr[i][0] > xmax)
			xmax = arr[i][0];
		if (arr[i][1] < ymin)
			ymin = arr[i][1];
		if (arr[i][1] > ymax)
			ymax = arr[i][1];
		printf("\n");
	}
	printf("\n%d\t%d\t%d\t%d", xmin, xmax, ymin, ymax);

	xmid=(xmax-xmin)/2+(xmin);
	ymid=(ymax-ymin)/2+(ymin);
	printf("\n%d\t%d", xmid, ymid);

	while (1)
	{
		printf("\n1. Boundary Filling algo\n2. Edge filling algo\n3. Scanline algo\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter seed point : ");
			scanf("%d %d", &xmid, &ymid);
			setbkcolor(0);
			draw(arr, n);
			b_fill(xmid, ymid);
			getch();
			cleardevice();
			break;
		case 2:
			setbkcolor(0);
			draw(arr, n);
			edge_fill(arr, n, ymin, ymax);
			getch();
			cleardevice();
			break;
		case 3:
			scanline(arr, n);
			getch();
			cleardevice();
			break;
		case 4:
			exit(0);
		}
	}

	closegraph();
	return 0;
}