#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

int fig[3][5] = {{100, 50, 50,150,150},
                 {160,110, 50, 50,110},
                 {  1,  1,  1,  1,  1}};

void boundaryFill(int x, int y, int bc, int fc)
{
    int col = getpixel(x,y);
    if((col != bc) && (col != fc))
    {
        putpixel(x,y,fc);
        boundaryFill(x+1,y  ,bc,fc);
        boundaryFill(x-1,y  ,bc,fc);
        boundaryFill(x  ,y+1,bc,fc);
        boundaryFill(x  ,y-1,bc,fc);
        boundaryFill(x+1,y+1,bc,fc);
        boundaryFill(x-1,y-1,bc,fc);
        boundaryFill(x-1,y+1,bc,fc);
        boundaryFill(x+1,y-1,bc,fc);
    }
}

int main()
{
    int x, y, bc, fc;
    int a,b;
    int gd=DETECT,gm;
    //system("cls");
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    a = getmaxx()/2;
    b = getmaxy()/2;
    setcolor(8);
    line(a,0,a,b*2);
    line(0,b,a*2,b);
    setcolor(15);
    line(a+fig[0][0],   b-fig[1][0],   a+fig[0][1],   b-fig[1][1]);
    line(a+fig[0][0],   b-fig[1][0]-1, a+fig[0][1]-1, b-fig[1][1]);
    line(a+fig[0][4],   b-fig[1][4],   a+fig[0][0],   b-fig[1][0]);
    line(a+fig[0][4]+1, b-fig[1][4],   a+fig[0][0],   b-fig[1][0]-1);

    line(a+fig[0][1], b-fig[1][1], a+fig[0][2], b-fig[1][2]);
    line(a+fig[0][2], b-fig[1][2], a+fig[0][3], b-fig[1][3]);
    line(a+fig[0][3], b-fig[1][3], a+fig[0][4], b-fig[1][4]);
    line(a+fig[0][1], b-fig[1][1], a+fig[0][4], b-fig[1][4]);
    x = a + 60;
    y = b - 60;
    bc = 15;
    fc = 1;
    boundaryFill(x,y,bc,fc);
    x = a + 100;
    y = b - 120;
    fc = 4;
    boundaryFill(x,y,bc,fc);
    getch();
    return 0;
}


