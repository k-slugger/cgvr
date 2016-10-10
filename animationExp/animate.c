#include<stdio.h>
#include<graphics.h>
#define PTS 5

int fig[3][PTS] = {{  0,-50,-50, 50, 50},
                   { 50,  0,-50,-50,  0},
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
    int newFig[3][PTS];
    for(i=0; i<3; i++)
    {
        for(k=0; k<PTS; k++)
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
        for(j=0; j<PTS; j++)
            fig[i][j] = newFig[i][j];
}

void createFig()
{
    int a,b;
    cleardevice();
    a = getmaxx()/2;
    b = getmaxy()/2;
    //house
    setcolor(0);
    line(a+fig[0][0], b-fig[1][0], a+fig[0][1], b-fig[1][1]);
    line(a+fig[0][1], b-fig[1][1], a+fig[0][2], b-fig[1][2]);
    line(a+fig[0][2], b-fig[1][2], a+fig[0][3], b-fig[1][3]);
    line(a+fig[0][3], b-fig[1][3], a+fig[0][4], b-fig[1][4]);
    line(a+fig[0][4], b-fig[1][4], a+fig[0][0], b-fig[1][0]);
    line(a+fig[0][1], b-fig[1][1], a+fig[0][4], b-fig[1][4]);
    //setfillstyle(SOLID_FILL, COLOR(139,69,19));
    //floodfill(a+0,b-20, 0);
    //setfillstyle(SOLID_FILL, COLOR(255,255,0));
    //floodfill(a+0,b+10, 0);;
    //getch();
}

int main()
{
    int a,b,i,k=5,l=10,flag=0;
    char slt;
    int gd=DETECT,gm;
    //initwindow(1280,720);
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    setbkcolor(15);
    a = getmaxx()/2;
    b = getmaxy()/2;
    createFig();
    while(l)
    {
        if(flag == 0)
        {
            while(fig[0][4] < a-10 && fig[1][0] < b-10)
            {
                createFig();
                scaling(1.02,1.02);
                delay(20);
            }
            while(fig[0][4] > 51  && fig[1][0] > 51 )
            {
                createFig();
                scaling(0.98,0.98);
                delay(20);
            }
            flag = 0;
        }
    }
    /*while(fig[0][4] < a-10 && fig[1][0] < b-10)
    {
        createFig();
        scaling(1.02,1.02);
        if(l == 0)
        {
            translation(0,-k);
            createFig();
            delay(150);
            translation(0,k);
            createFig();
            delay(150);
            l = 10;
        }
        else
        {
            l--;
            delay(20);
        }
        //delay(20);
        flag = 1;
    }*/
    getch();
    return 0;
}
