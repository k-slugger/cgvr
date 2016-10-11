#include<stdio.h>
#include<graphics.h>
#define MAX 6

int xmin=0,xmax=0,ymin=0,ymax=0;
float m;
/*int fig[3][MAX+10] = {{-100,   0, 100,-100, 100, 100,-100,-100},
                      {   0, 100,   0,   0,   0,-100,-100,   0},
                      {   1,   1,   1,   1,   1,   1,   1,   1}};*/
int fig[3][MAX+10] = {{-100,   0, 100, 100,-100,-100},
                      {   0, 100,   0,-100,-100,   0},
                      {   1,   1,   1,   1,   1,   1}};
/*int fig[3][MAX] = {{-100, 100, 100,  25,  25, -25, -25,-100,-100},
                   { 100, 100,  50,  50,-100,-100,  50,  50, 100},
                   {   1,   1,   1,   1,   1,   1,   1,   1,   1}};*/
int clipFig[2][20];
int arr[20],k;

void clipL(int i)
{
    int x1=fig[0][i], y1=fig[1][i], x2=fig[0][i+1], y2=fig[1][i+1];
    if(x2-x1)
        m = (float)(y2-y1)/(x2-x1);
    else
        m = 1000000;
    if(x1 >= xmin && x2 >= xmin)
    {
        clipFig[0][k]=x2;
        clipFig[1][k]=y2;
        k++;
    }
    if(x1 < xmin && x2 >= xmin)
    {
        clipFig[0][k]=xmin;
        clipFig[1][k]=y1+m*(xmin-x1);
        clipFig[0][k+1]=x2;
        clipFig[1][k+1]=y2;
        k+=2;
    }
    if(x1 >= xmin && x2 < xmin)
    {
        clipFig[0][k]=xmin;
        clipFig[1][k]=y1+m*(xmin-x1);
        k++;
    }
}

void clipT(int i)
{
    int x1=fig[0][i], y1=fig[1][i], x2=fig[0][i+1], y2=fig[1][i+1];
    if(x2-x1)
        m = (float)(y2-y1)/(x2-x1);
    else
        m = 1000000;
    if(y1 <= ymax && y2 <= ymax)
    {
        clipFig[0][k]=x2;
        clipFig[1][k]=y2;
        k++;
    }
    if(y1 > ymax && y2 <= ymax)
    {
        clipFig[0][k]=x1+(ymax-y1)/m;
        clipFig[1][k]=ymax;
        clipFig[0][k+1]=x2;
        clipFig[1][k+1]=y2;
        k+=2;
    }
    if(y1 <= ymax && y2 > ymax)
    {
        clipFig[0][k]=x1+(ymax-y1)/m;
        clipFig[1][k]=ymax;
        k++;
    }
}

void clipR(int i)
{
    int x1=fig[0][i], y1=fig[1][i], x2=fig[0][i+1], y2=fig[1][i+1];
    if(x2-x1)
        m = (float)(y2-y1)/(x2-x1);
    else
        m = 1000000;
    if(x1 <= xmax && x2 <= xmax)
    {
        clipFig[0][k]=x2;
        clipFig[1][k]=y2;
        k++;
    }
    if(x1 > xmax && x2 <= xmax)
    {
        clipFig[0][k]=xmax;
        clipFig[1][k]=y1+m*(xmax-x1);
        clipFig[0][k+1]=x2;
        clipFig[1][k+1]=y2;
        k+=2;
    }
    if(x1 <= xmax && x2 > xmax)
    {
        clipFig[0][k]=xmax;
        clipFig[1][k]=y1+m*(xmax-x1);
        k++;
    }
}

void clipB(int i)
{
    int x1=fig[0][i], y1=fig[1][i], x2=fig[0][i+1], y2=fig[1][i+1];
    if(x2-x1)
        m = (float)(y2-y1)/(x2-x1);
    else
        m = 1000000;
    if(y1 >= ymin && y2 >= ymin)
    {
        clipFig[0][k]=x2;
        clipFig[1][k]=y2;
        k++;
    }
    if(y1 < ymin && y2 >= ymin)
    {
        clipFig[0][k]=x1+(ymin-y1)/m;
        clipFig[1][k]=ymin;
        clipFig[0][k+1]=x2;
        clipFig[1][k+1]=y2;
        k+=2;
    }
    if(y1 >= ymin && y2 < ymin)
    {
        clipFig[0][k]=x1+(ymin-y1)/m;
        clipFig[1][k]=ymin;
        k++;
    }
}

void createFig(int n)
{
    int i,a,b;
    cleardevice();
    a = getmaxx()/2;
    b = getmaxy()/2;
    setcolor(0);
    for(i = 0; i < n; i++)
    {
        line(a+fig[0][i], b-fig[1][i], a+fig[0][i+1], b-fig[1][i+1]);
    }
    setfillstyle(SOLID_FILL, COLOR(255,255,0));
    floodfill(a+0,b-20, 0);
    setcolor(12);
    rectangle(a+xmin, b-ymax, a+xmax, b-ymin);
    getch();
}

void refresh()
{
    int i;
    for(i = 0; i < k; i++)
    {
        fig[0][i] = clipFig[0][i];
        fig[1][i] = clipFig[1][i];
    }
    fig[0][i] = fig[0][0];
    fig[1][i] = fig[1][0];
    k = 0;
}

int main()
{
    int i,n;
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    setbkcolor(15);
    n = MAX-1;
    createFig(n);
    printf("Enter clipping window coordinates:\nxmin ymin: ");
    scanf("%d %d",&xmin,&ymin);
    printf("\nxmax ymax: ");
    scanf("%d %d",&xmax,&ymax);
    createFig(n);
    k = 0;
    n = MAX-1;
    for(i = 0; i < n; i++)
        clipL(i);
    n = k;
    refresh();
    for(i = 0; i < n; i++)
        clipT(i);
    n = k;
    refresh();
    for(i = 0; i < n; i++)
        clipR(i);
    n = k;
    refresh();
    for(i = 0; i < n; i++)
        clipB(i);
    n = k;
    refresh();
    for(i = 0; i < n; i++)
        printf("\nP%d ( %d,%d )",i+1,fig[0][i],fig[1][i]);
    createFig(n);
    getch();
    return 0;
}
