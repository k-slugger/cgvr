#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

int fig[3][5] = {{100, 50, 50,150,150},
                 {160,110, 50, 50,110},
                 {  1,  1,  1,  1,  1}};

void multiply(float[3][3]);
void createFig();

void translation(float tx, float ty)
{
    float trans[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}};
    trans[0][2] = tx;
    trans[1][2] = ty;
    multiply(trans);
}

void scaling(float sx, float sy)
{
    float scal[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}};
    scal[0][0] = sx;
    scal[1][1] = sy;
    multiply(scal);
}

void multiply(float transformer[3][3])
{
    int i, j, k;
    float sum = 0;
    int newFig[3][5];
    for(i=0; i<3; i++)
    {
        for(k=0; k<5; k++)
        {
            sum = 0;
            for(j=0; j<3; j++)
            {
                sum = sum + transformer[i][j] * fig[j][k];
            }
            newFig[i][k] = (int)sum;
        }
    }
    for(i=0; i<3; i++)
        for(j=0; j<5; j++)
            fig[i][j] = newFig[i][j];
}

void createFig()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    int a,b;
    a = getmaxx()/2;
    b = getmaxy()/2;
    setcolor(8);
    line(a,0,a,b*2);
    line(0,b,a*2,b);
    setcolor(15);
    line(a+fig[0][0], b-fig[1][0], a+fig[0][1], b-fig[1][1]);
    line(a+fig[0][1], b-fig[1][1], a+fig[0][2], b-fig[1][2]);
    line(a+fig[0][2], b-fig[1][2], a+fig[0][3], b-fig[1][3]);
    line(a+fig[0][3], b-fig[1][3], a+fig[0][4], b-fig[1][4]);
    line(a+fig[0][4], b-fig[1][4], a+fig[0][0], b-fig[1][0]);
    line(a+fig[0][1], b-fig[1][1], a+fig[0][4], b-fig[1][4]);
    getch();
    //closegraph();
}

int main()
{
    float cx, cy, sx, sy;
    //system("cls");
    createFig();
    printf("Enter coordinates about which object is to be scaled:\n");
    scanf("%f %f",&cx,&cy);
    translation((-1*cx),(-1*cy));
    printf("Enter sx and sy for scaling:");
    scanf("%f %f",&sx,&sy);
    scaling(sx,sy);
    translation(cx,cy);
    createFig();
    getch();
    return 0;
}

