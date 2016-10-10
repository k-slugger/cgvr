#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define PI 3.14159265

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

void rotation(float deg)
{
    float rot[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}};
    float val = PI / 180;
    rot[0][0] = cos(deg * val);
    rot[0][1] = -1*sin(deg * val);
    rot[1][0] = sin(deg * val);
    rot[1][1] = cos(deg * val);
    multiply(rot);
}

void shearing(float shrX, float shrY)
{
    float shear[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}};
    shear[0][1] = shrX;
    shear[1][0] = shrY;
    multiply(shear);
}

void reflection(int axis)
{
    float reflect[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}};
    if(axis == 1)
    {
        reflect[1][1] = -1;
    }
    else if(axis == 2)
    {
        reflect[0][0] = -1;
    }
    else
    {
        reflect[0][0] = 0;
        reflect[0][1] = 1;
        reflect[1][0] = 1;
        reflect[1][1] = 0;
    }
    multiply(reflect);
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
    createFig();
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
    closegraph();
}

int main()
{
    int slt;
    float x,y;
    //system("cls");
    createFig();
    while(slt != 6)
    {
        printf("Select transformation:\n");
        printf("1.Translation\n2.Scaling\n3.Rotation\n4.Shearing\n5.Reflection\n6.Exit\n");
        scanf("%d",&slt);
        switch(slt)
        {
            case 1:
                printf("Enter tx and ty: ");
                scanf("%f %f",&x,&y);
                translation(x,y);
                break;
            case 2:
                printf("Enter sx and sy: ");
                scanf("%f %f",&x,&y);
                scaling(x,y);
                break;
            case 3:
                printf("Enter degree: ");
                scanf("%f",&x);
                rotation(x);
                break;
            case 4:
                printf("Select shearing:\n1.X-Shear 2.Y-Shear\n");
                scanf("%f",&x);
                if(x == 1)
                {
                    printf("Enter X-Shear: ");
                    scanf("%f",&x);
                    y = 0;
                }
                else if(x == 2)
                {
                    printf("Enter Y-Shear: ");
                    scanf("%f",&y);
                    x = 0;
                }
                shearing(x,y);
                break;
            case 5:
                printf("Select reflection axis:\n1.x=0 2.y=0 3.x=y\n");
                scanf("%f",&x);
                reflection(x);
                break;
            case 6:
                exit(0);
            default:
                printf("Enter valid selection");
        }
        printf("\n");
    }
    getch();
    return 0;
}
