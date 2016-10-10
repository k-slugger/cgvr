#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#define PI 3.14159
void translate(int Tx, int Ty);
void rotate(int angle);
void multiply(float m[3][3]);
float multiplymat[3][8];
void move();
int p[8][8];

int main(){
   int gd = DETECT,gm;
   int x ,y;
   initgraph(&gd, &gm, "X:\\TC\\BGI");
   /* Initialize center of ellipse with center of screen */
  // int stangle,endangle;
   //outtextxy(x-100, 50, "ELLIPSE Using Graphics in C");
   /* Draw ellipse on screen */
   //for(int i=0;i<=400;i++)
   //{

   //ellipse(x, y, 0, 360, 10, 2);
   for(int i=0;i<=10;i++)
    {
        x = getmaxx()/2;
   y = getmaxy()/2;

     p={{x-45,x+45,x-45,x+45,x-10,x+10,x-5,x+5},{y,y,y+15,y+15,y,y,y,y},{1,1,1,1,1,1,1,1}};

       arc(x,y,180,0,10);
   line(x-10,y,x+10,y);
   arc(x,y,0,180,5);
   ellipse(x+1,y+1,0,360,45,25);
   line(45+x,y+1,45+x,y+15);
   line(-45+x,y+1,-45+x,y+15);
   ellipse(x+1,y+15,180,0,45,25);
   translate(2,2);
   rotate(45);
   translate(-2,-2);
   }

   getch();
   closegraph();
   return 0;
}

void translate(int Tx, int Ty)
{
    float T[3][3] = {{1, 0, Tx}, {0, 1, Ty}, {0, 0, 1}};
    multiply(T);

}

void rotate(int angle)
{
    float angrad = angle*(PI/180);
    float R[3][3] = {{cos(angrad), -sin(angrad), 0}, {sin(angrad), cos(angrad), 0}, {0, 0, 1}};
    multiply(R);
    delay(0);
}

void multiply(float m[3][3])
{
    int c,d,k;
    float sum=0;

    for (c = 0; c < 3; c++)
    {
        for (d = 0; d < 8; d++)
        {
            for (k = 0; k < 3; k++)
            {
                sum = sum + m[c][k]*p[k][d];
            }

            multiplymat[c][d] = sum;
            sum = 0;
        }
    }
    move();
}

void move()
{
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<8; j++)
        {
            p[i][j] = multiplymat[i][j];
        }
}
