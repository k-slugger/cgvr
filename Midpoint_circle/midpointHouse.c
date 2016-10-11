#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void cir(int,int,int,int);
int flag=0;
int main()
{
    int gd=DETECT,gm;
    int i,r,x,y,xc,yc,pk,or1;
    float d;
    //clrscr();
    initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
    printf("Enter the inner radius = ");
    scanf("%d",&r);
    printf("Enter the outer radius = ");
    scanf("%d",&or1);
    printf("Enter the center point in x and y= ");
    scanf("%d",&xc);
    scanf("%d",&yc);
    cir(xc,yc,r,flag);
    flag=1;
    cir(xc,yc,or1,flag);
    getch();
 }

void cir(int x1,int y1,int r1,int flag)
{
    int i,r,x,y,xc,yc,pk;xc=x1;
    yc=y1;
    r=r1;
//if
// printf("Enter the radius for innner circle= ");
//scanf("%d",&r);
// printf("Enter the center point in x and y= ");
// scanf("%d",&xc);
//scanf("%d",&yc);
    pk=1-r;
    x=0;
    y=r;
    while(y>=x)
    {
        if(pk<0)
        {
            x=x+1;
            y=y;
            pk=pk+2*x+3;
        }
        else
        {
            x=x+1;
            y=y-1;
            pk=pk+2*x-2*y+5;
        }
        putpixel(y+xc,x+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
        putpixel(x+xc,-y+yc,WHITE);
        putpixel(-y+xc,-x+yc,WHITE);
        if(flag==0)
        {
            putpixel(x+xc,y+yc,WHITE);
            putpixel(-y+xc,x+yc,WHITE);
            putpixel(y+xc,-x+yc,WHITE);
            putpixel(-x+xc,-y+yc,WHITE);
        }
    }
}
