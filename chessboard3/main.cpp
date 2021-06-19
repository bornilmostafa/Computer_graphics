#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
int c = 0;

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
int x, y;
for (x = 0; x <= 900; x += 100)
{
for (y = 0; y <= 600; y += 75)
{

if (c == 0)
{
glColor3f(1, 1, 1); //This for white colour
c = 1;
}

else
{
glColor3f(0, 0, 0); //This for black colour
c = 0;
}

// Squre drawing
glBegin(GL_POLYGON);
glVertex2i(x, y+75);
glVertex2i(x+100,y+75);
glVertex2i(x+100, y);
glVertex2i(x,y);
glEnd();

}
}

glFlush();
}

void myInit()
{

glClearColor(0, 0,0 , 0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0, 900, 0,600);
}

int main(int agrc, char ** argv)
{
glutInit(&agrc, argv);

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(500, 100);
glutInitWindowSize(900, 600);
glutCreateWindow("ChessBoard");
myInit();
glutDisplayFunc(display);
glutMainLoop();
}

