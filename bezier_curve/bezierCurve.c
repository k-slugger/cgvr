#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define MAX 10

int cp[2][MAX] = {{100,300,300,150,100,100,150,225,225,300},
                  { 20, 20,220,220,220,170,170,170,370,370}};

int fact(int a)
{
    if(a < 2)
        return 1;
    else
        return (a * fact(a-1));
}

void bezier(int a, int ncp)
{
    int n,i;
    double u,xu,yu,sum;
    n = ncp-1;
    for(u = 0.0; u < 1.0; u += 0.000005)
    {
        xu = 0;
        for(i = 0; i <= n; i++)
            xu = xu + (fact(n)/(fact(i)*fact(n-i))) * pow(1.0-u,n-i) * pow(u,i) * cp[0][a+i];
        yu = 0;
        for(i = 0; i <= n; i++)
            yu = yu + (fact(n)/(fact(i)*fact(n-i))) * pow(1.0-u,n-i) * pow(u,i) * cp[1][a+i];
        putpixel(xu, yu, BLACK);
    }
    for(i = 0; i < ncp; i++)
        putpixel(cp[0][a+i], cp[1][a+i], 0);
    //setcolor(0);
    //for(i = 0; i < n; i++)
    //    line(cp[0][a+i],cp[1][a+i],cp[0][a+i+1],cp[1][a+i+1]);
}

int main()
{
    int ncp,a=0;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    setbkcolor(15);
    cleardevice();
    ncp = 4;
    bezier(a,ncp);
    a = 3;
    ncp = 4;
    bezier(a,ncp);
    a = 6;
    ncp = 4;
    bezier(a,ncp);
    getch();
    return 0;
}
