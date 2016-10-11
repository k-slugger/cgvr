#include<stdio.h>
#include<graphics.h>

int main()
{
    int xmin,ymin,xmax,ymax,x1,y1,x2,y2;
    int pt1[4]={0,0,0,0}, pt2[4]={0,0,0,0};
    int i;
    float m;
    int gd=DETECT, gm;

    printf("Enter coordinates of clipping window:\nxmin,ymin: ");
    scanf("%d %d",&xmin,&ymin);
    printf("xmax,ymax: ");
    scanf("%d %d",&xmax,&ymax);
    printf("Enter starting and ending points of line:\nx1,y1: ");
    scanf("%d %d",&x1,&y1);
    printf("x2,y2: ");
    scanf("%d %d",&x2,&y2);

    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    setbkcolor(15);
    cleardevice();
    setcolor(0);
    rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	getch();
	m = (float)(y2-y1)/(x2-x1);
	if(y1>ymax) pt1[0] = 1;
	if(y1<ymin) pt1[1] = 1;
	if(x1>xmax) pt1[2] = 1;
	if(x1<xmin) pt1[3] = 1;
	if(y2>ymax) pt2[0] = 1;
	if(y2<ymin) pt2[1] = 1;
	if(x2>xmax) pt2[2] = 1;
	if(x2<xmin) pt2[3] = 1;
	for(i = 0; i < 4; i++)
        if(pt1[i] && pt2[i])
        {
            printf("Line outside clipping window");
            getch();
            return 0;
        }
    //clipping on top boundary
    if(pt1[0])
    {
        x1 = x1 + (ymax-y1)/m;
        y1 = ymax;
    }
    if(pt2[0])
    {
        x2 = x2 + (ymax-y2)/m;
        y2 = ymax;
    }
    //clipping for bottom boundary
    if(pt1[1])
    {
        x1 = x1 + (ymin-y1)/m;
        y1 = ymin;
    }
    if(pt2[1])
    {
        x2 = x2 + (ymin-y2)/m;
        y2 = ymin;
    }
    //clipping on right boundary
    if(pt1[2])
    {
        y1 = y1 + m*(xmax-x1);
        x1 = xmax;
    }
    if(pt2[2])
    {
        y2 = y2 + m*(xmax-x2);
        x2 = xmax;
    }
    //clipping for left boundary
    if(pt1[3])
    {
        y1 = y1 + m*(xmin-x1);
        x1 = xmin;
    }
    if(pt2[3])
    {
        y1 = y1 + m*(xmin-x1);
        x1 = xmin;
    }
    printf("\nDone dana done.\n");
    printf("x1: %d, y1: %d\nx2: %d, y2: %d",x1,y1,x2,y2);
    cleardevice();
    rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	getch();
	closegraph();
    return 0;
}
