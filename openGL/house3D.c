#include <stdio.h>
#include <GL/glut.h>

GLfloat fig[3][10] = { // a  b  c  d  e  f  g  h  i  j
                        { 0.2, 0.0, 0.0, 0.4, 0.4, 0.2, 0.0, 0.0, 0.4, 0.4},
                        { 0.4, 0.2, 0.0, 0.0, 0.2, 0.4, 0.2, 0.0, 0.0, 0.2},
                        { 0.5, 0.5, 0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0}};

void initGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -4.0f);
    glRotatef(10, 1.0, 0.0, 0.0);
    glRotatef(-30, 0.0, 1.0, 0.0);
    glRotatef(0, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(20.0f,0.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 20.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 20.0f);
    glEnd();

    glBegin(GL_POLYGON);
        //abcde 01234
        glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
        glVertex3f(fig[0][0], fig[1][0], fig[2][0]);
        glVertex3f(fig[0][1], fig[1][1], fig[2][1]);
        glVertex3f(fig[0][2], fig[1][2], fig[2][2]);
        glVertex3f(fig[0][3], fig[1][3], fig[2][3]);
        glVertex3f(fig[0][4], fig[1][4], fig[2][4]);
    glEnd();

    glBegin(GL_POLYGON);
        //fghij 56789
        glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
        glVertex3f(fig[0][5], fig[1][5], fig[2][5]);
        glVertex3f(fig[0][6], fig[1][6], fig[2][6]);
        glVertex3f(fig[0][7], fig[1][7], fig[2][7]);
        glVertex3f(fig[0][8], fig[1][8], fig[2][8]);
        glVertex3f(fig[0][9], fig[1][9], fig[2][9]);
    glEnd();

    glBegin(GL_QUADS);
        //abgf 0165
        glColor3f(0.60f, 0.25f, 0.25f);  // Brown
        glVertex3f(fig[0][0], fig[1][0], fig[2][0]);
        glVertex3f(fig[0][1], fig[1][1], fig[2][1]);
        glVertex3f(fig[0][6], fig[1][6], fig[2][6]);
        glVertex3f(fig[0][5], fig[1][5], fig[2][5]);

        //bchg 1276
        glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
        glVertex3f(fig[0][1], fig[1][1], fig[2][1]);
        glVertex3f(fig[0][2], fig[1][2], fig[2][2]);
        glVertex3f(fig[0][7], fig[1][7], fig[2][7]);
        glVertex3f(fig[0][6], fig[1][6], fig[2][6]);

        //cdih 2387
        glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
        glVertex3f(fig[0][2], fig[1][2], fig[2][2]);
        glVertex3f(fig[0][3], fig[1][3], fig[2][3]);
        glVertex3f(fig[0][8], fig[1][8], fig[2][8]);
        glVertex3f(fig[0][7], fig[1][7], fig[2][7]);

        //deji 3498
        glColor3f(0.8f, 0.8f, 0.0f);     // Yellow
        glVertex3f(fig[0][3], fig[1][3], fig[2][3]);
        glVertex3f(fig[0][4], fig[1][4], fig[2][4]);
        glVertex3f(fig[0][9], fig[1][9], fig[2][9]);
        glVertex3f(fig[0][8], fig[1][8], fig[2][8]);

        //eafj 4059
        glColor3f(0.60f, 0.25f, 0.25f);  // Brown
        glVertex3f(fig[0][4], fig[1][4], fig[2][4]);
        glVertex3f(fig[0][0], fig[1][0], fig[2][0]);
        glVertex3f(fig[0][5], fig[1][5], fig[2][5]);
        glVertex3f(fig[0][9], fig[1][9], fig[2][9]);

    glEnd();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1000, 900);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Home Sweet Home");
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}
