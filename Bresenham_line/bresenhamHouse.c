#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
void bresenham(int x1, int y1, int x2, int y2)
{
    int dx, dy, sx = 1, sy = 1, pk, i, temp, flag1 = 0;
    dx = x2 - x1;
    dy = y2 - y1;
    if(dx < 0)
    {
        sx = -1;
    }
    if(dy < 0)
    {
        sy = -1;
    }
    if(abs(dx) < abs(dy))
    {
        temp = dx;
        dx = dy;
        dy = temp;
        flag1 = 1;
    }

    pk = 2 * abs(dy) - abs(dx);
    putpixel(x1, y1, WHITE);
    for(i = 1; i <= abs(dx); i++)
    {
        if(pk < 0)
        {   if(flag1 == 0){x1 = x1 + sx; }
        else {y1 = y1 + sy; }
        putpixel(x1, y1, WHITE);
        pk = pk + 2*abs(dy);
    }
    else
    {
        x1 = x1+sx;
        y1 = y1+sy;
        putpixel(x1, y1, WHITE);
        pk = pk + 2*abs(dy) - 2*abs(dx);
    }
}
}

int main()
{
    int x[5] = {100,0  ,0  ,200,200};
    int y[5] = {0,  100,200,200,100};
    int i, j;
    int matcher[5][5];
    int count = 0;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    //clrscr();
    matcher[0][1] = 1;
    matcher[0][4] = 1;
    matcher[1][4] = 1;
    matcher[1][2] = 1;
    matcher[2][3] = 1;
    matcher[3][4] = 1;
    for(i = 0; i < 5; i++)
    {
        for(j = i+1; j < 5; j++)
        {
            if(matcher[i][j] == 1)
            {
                bresenham(x[i], y[i], x[j], y[j]);
                count++;
            }
        }
    }
    printf("count is %d",count);
    getch();
}
