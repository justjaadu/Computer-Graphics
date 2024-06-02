#include <stdio.h>
#include <math.h>
#include <graphics.h>

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

void rotation(int a[5][2], int n, float angle, int mul[5][2])
{
    float c, s;
    int i, j, k;
    int b[2][2];
    int as[5][2];
    c = cos(angle * 0.017453);
    s = sin(angle * 0.017453);
    // printf("%f",c);
    // printf(" %f",s);
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

    // printMatrix(b,n);

    for (i = 0; i < n; i++)
    {
        mul[i][0] += 320;
        mul[i][1] = 240 - mul[i][1];
    }
    // printMatrix(mul, n);
    // line(320, 0, 320, 479);
    // line(0, 240, 679, 240);
    setcolor(RED);
    draw(mul, n);
    // return mul2;
}

void rotation2(int a[5][2], int n, float angle, int mul[5][2])
{
    float c, s;
    int i, j, k;
    int b[2][2];
    int as[5][2];
    c = cos(angle * 0.017453);
    s = sin(angle * 0.017453);

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

    setcolor(BLUE);
    draw(mul, n);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    float angle1, angle2, angle3;
    int i, j, n, a[5][2], b[5][2], c[5][2], mul[5][2], mul2[5][2];
    int ch;
    cleardevice();

    printf("\nEnter number of vertices : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter x%d and y%d : ", i + 1, i + 1);
        scanf("%d%d", &a[i][0], &a[i][1]);
        a[i][0] += 320;
        a[i][1] = 240 - a[i][1];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j];
        }
    }
    
    do
    {
        printf("Enter\n1. Additive Nature\n2. Commutative Nature\n3. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {

            case 1: printf("Enter the 1st angle of rotation: ");
                    scanf("%f", &angle1);
                    printf("Enter the 2nd angle of rotation: ");
                    scanf("%f", &angle2);
                    cleardevice();

                    draw(a, n);
                    line(320, 0, 320, 479);
                    line(0, 240, 679, 240);

                    printf("For LHS\nRotating for angle %.2f", angle1);
                    rotation(a, n, angle1, mul);
                    getch();

                    printf("\nRotating for angle %.2f\n", angle2);
                    rotation(mul, n, angle2, mul2);
                    printMatrix(mul, n);
                    getch();
               



                    draw(c, n);
                    line(320, 0, 320, 479);
                    line(0, 240, 679, 240);

                    angle3 = angle1 + angle2;
                    printf("\nFor RHS\nRotating for angle %.2f\n", angle3);
                    rotation2(a, n, angle3, mul);
                    printMatrix(a, n);
                    getch();

                    printf("We saw that the final matrices for LHS and RHS are same.\nTherefore, Rotation of object is Additive in nature.");
                    getch();
                    break;

            case 2: printf("Enter the 1st angle of rotation: ");
                    scanf("%f", &angle1);
                    printf("Enter the 2nd angle of rotation: ");
                    scanf("%f", &angle2);


                    draw(a, n);
                    line(320, 0, 320, 479);
                    line(0, 240, 679, 240);

                    printf("For LHS\nRotating for angle %.2f", angle1);
                    rotation(a, n, angle1, mul);
                    getch();

                    printf("\nRotating for angle %.2f\n", angle2);
                    rotation(mul, n, angle2, mul);
                    printMatrix(mul, n);
                    getch();
                

                     cleardevice();
                    draw(c, n);
                    line(320, 0, 320, 479);
                    line(0, 240, 679, 240);

                    printf("For RHS\nRotating for angle %.2f", angle2);
                    rotation2(c, n, angle2, mul);
                    getch();

                    printf("\nRotating for angle %.2f\n", angle1);
                    rotation2(mul, n, angle1, mul);
                    printMatrix(mul, n);
                    getch();
                   

                    printf("We saw that the final matrices for LHS and RHS are same.\nTherefore, Rotation of object is Commutative in nature.");
                    getch();
                    break;

            case 3: exit(0);

            default:printf("Invalid input");
                    break;
        }
    }
    while(ch!=3);

     closegraph();
     return 0;
}