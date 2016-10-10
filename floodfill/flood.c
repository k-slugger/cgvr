#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void flood(int,int,int,int);

int main()
{
int gd,gm=DETECT;
//clrscr();
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"c:\\tc\\bgi");
rectangle(10,10,100,200);
rectangle(15,15,95,150);
rectangle(15,155,53,195);
rectangle(57,155,95,195);
flood(16,16,0,12);
flood(16,156,0,12);
flood(66,156,0,12);
getch();
return 0;
}

void flood(int x,int y, int old_color, int new_color)
{
if(getpixel(x,y)==old_color)
{
delay(0.1);
putpixel(x,y,new_color);

flood(x+1, y, old_color, new_color);

flood(x-1, y, old_color, new_color);

flood(x, y+1, old_color, new_color);

flood(x, y-1, old_color, new_color);

flood(x+1, y+1, old_color, new_color);

flood(x-1, y-1, old_color, new_color);

flood(x+1, y-1, old_color, new_color);

flood(x-1, y+1, old_color, new_color);
}
}
