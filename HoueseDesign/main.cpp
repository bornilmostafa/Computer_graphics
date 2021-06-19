
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>




void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);




glColor3ub (0, 0,0);
glPointSize(1.0);
glBegin(GL_POLYGON);
glVertex2i(11,4);
glVertex2i(11,15);
glVertex2i(1524,15);
glVertex2i(1524,0);
glEnd();
glFlush ();

glColor3ub (211, 211,211);
glPointSize(3.0);
glBegin(GL_POLYGON);
glVertex2i(99,15);
glVertex2i(99,352);
glVertex2i(1414,352);
glVertex2i(1414,15);
glEnd();
glFlush ();



glColor3ub (119, 136,153);
glPointSize(1.0);
glBegin(GL_POLYGON);
glVertex2i(171,24);
glVertex2i(171,304);
glVertex2i(766,304);
glVertex2i(766,24);
glEnd();
glFlush ();


glColor3ub (1, 1,1);
glPointSize(3.0);
glBegin(GL_LINES);
glVertex2i(814,14);
glVertex2i(814,353);
glEnd();
glFlush ();




glColor3ub (119, 136,153);
glPointSize(1.0);
glBegin(GL_POLYGON);
glVertex2i(850,24);
glVertex2i(850,331);
glVertex2i(1013,331);
glVertex2i(1014,24);
glEnd();
glFlush ();



glColor3ub (0, 255,255);
glPointSize(1.0);
glBegin(GL_POLYGON);
glVertex2i(1103,83);
glVertex2i(1103,306);
glVertex2i(1319,306);
glVertex2i(1319,83);
glEnd();
glFlush ();

glColor3ub (0, 255,255);
glPointSize(1.0);
glBegin(GL_TRIANGLES);
glVertex2i(26,377);
glVertex2i(753,643);
glVertex2i(1483,377);

glEnd();
glFlush ();

glColor3ub (1, 1,1);
glPointSize(3.0);
glBegin(GL_LINES);
glVertex2i(1211,97);
glVertex2i(1211,297);
glEnd();
glFlush ();



glColor3ub (1, 1,1);
glPointSize(3.0);
glBegin(GL_LINES);
glVertex2i(1111,164);
glVertex2i(1321,164);
glEnd();
glFlush ();


glColor3ub (32, 178,170);
glPointSize(3.0);
glBegin(GL_TRIANGLES);
glVertex2i(493,526);
glVertex2i(753,618);
glVertex2i(1011,526);

glEnd();
glFlush ();



glColor3ub (0, 1,1);
glPointSize(1.0);
glBegin(GL_POLYGON);
glVertex2i(854,46);
glVertex2i(854,304);
glVertex2i(1000,304);
glVertex2i(1000,46);
glEnd();
glFlush ();




glColor3ub (0, 1,1);
glPointSize(1.0);
glBegin(GL_POLYGON);
glVertex2i(24,352);
glVertex2i(10,375);
glVertex2i(1502,374);
glVertex2i(1488,352);
glEnd();
glFlush ();

}





void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1557.0, 0.0, 732.0);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1557, 732);
glutInitWindowPosition (100, 150);
glutCreateWindow ("House ");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
