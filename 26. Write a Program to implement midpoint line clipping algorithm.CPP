//26. Write a Program to implement midpoint line clipping algorithm.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#define TOP 1
#define BOTTOM 2
#define RIGHT 4
#define LEFT 8
void drawwindow(int x1, int y1, int x2, int y2);
void drawline (int x1, int y1, int x2, int y2, int cl);
int setcode(int x, int y, int x1, int y1, int x2, int y2);
int visibility (int code1, int code2);
void midsub(int x1, int y1, int x2, int y2, int win_x1, int win_y1, int
win_x2, int win_y2);
int main()
{
 int gd=DETECT, gm, v, x1, y1, x2, y2, win_x1, win_y1, win_x2,
win_y2;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 cleardevice();
 printf("\n\n\t\tENTER WINDOW COORDINATES (x1, y1, x2, y2):");
 scanf("%d %d %d %d", &win_x1, &win_y1, &win_x2, &win_y2);
 drawwindow(win_x1, win_y1, win_x2, win_y2);
 getch();
 printf("\n\n\t\tENTER END-POINT 1 (x,y): ");
 scanf("%d %d",&x1, &y1);
 printf("\n\n\t\tENTER END-POINT 2 (x,y): ");
 scanf("%d %d",&x2, &y2);
 cleardevice();
 drawwindow(win_x1, win_y1, win_x2, win_y2);
 getch();
 drawline(x1, y1, x2, y2, 15);
 getch();
 cleardevice();
 drawwindow(win_x1, win_y1, win_x2, win_y2);
midsub(x1, y1, x2, y2, win_x1, win_y1, win_x2, win_y2);
 getch();
 closegraph();
 return(0);
}
void midsub(int x1, int y1, int x2, int y2, int win_x1, int win_y1, int
win_x2, int win_y2)
{
 int code1, code2, v;
 code1 = setcode(x1, y1, win_x1, win_y1, win_x2, win_y2);
 code2 = setcode(x2, y2, win_x1, win_y1, win_x2, win_y2);
 v = visibility(code1, code2);
 switch(v)
 {
 case 0: /* Line completely visible */
 drawline(x1, y1, x2, y2, 15);
 break;
 case 1: /* Line completely invisible */
 break;
 case 2: /* Line partly visible */
{
 int midx = (x1 + x2) / 2;
 int midy = (y1 + y2) / 2;
 if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) < 2) {
 // Stop recursion if the line segment is very small
 break;
 }
 midsub(x1, y1, midx, midy, win_x1, win_y1, win_x2,
win_y2);
 midx++;
 midy++;
 midsub(midx, midy, x2, y2, win_x1, win_y1, win_x2,
win_y2);
 break;
 }
 }
}
void drawwindow(int x1, int y1, int x2, int y2)
{
 setcolor(RED);
 line(x1, y1, x2, y1);
 line(x2, y1, x2, y2);
 line(x2, y2, x1, y2);
 line(x1, y2, x1, y1);
}
void drawline (int x1, int y1, int x2, int y2, int cl)
{
 setcolor(cl);
 line(x1, y1, x2, y2);
}
int setcode(int x, int y, int x1, int y1, int x2, int y2)
{
 int code = 0;
 if(y <= y1)
 code |= TOP;
 if(y >= y2)
 code |= BOTTOM;
 if(x >= x2)
 code |= RIGHT;
if(x <= x1)
 code |= LEFT;
 return code;
}
int visibility (int code1, int code2)
{
 if((code1 & code2) != 0)
 return 1; // Line completely invisible
 else if((code1 | code2) == 0)
 return 0; // Line completely visible
 else
 return 2; // Line partly visible
}
