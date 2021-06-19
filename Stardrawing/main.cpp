/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<cstdio>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include<GL/gl.h>
#include <GL/glut.h>

#endif

#include <stdlib.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (1, 1,1);
glPointSize(5.0);



 glBegin(GL_TRIANGLES);

  glVertex2i(173,27);//4
  glVertex2i(403,193);//5
  glVertex2i(262,298);//10

  glVertex2i(635,27);//4
  glVertex2i(403,193);//5
  glVertex2i(546,298);//4

glVertex2i(262,298);//10
glVertex2i(403,193);//5
glVertex2i(546,298);//4
glEnd();



glBegin(GL_TRIANGLE_FAN);
  glVertex2i(546,298);//4
  glVertex2i(780,465);//5
  glVertex2i(490,465);//6
  glVertex2i(405,737);//7
  glVertex2i(315,465);//8
  glVertex2i(28,465);//9
  glVertex2i(262,298);//10
  glEnd();

  //glBegin(GL_LINES);

   //glVertex2i(549,586);//4
//glVertex2i(575,586);//5
  //glVertex2i(575,615);//6
 //glEnd();




glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,815.0, 0.0, 768.0);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (815, 768);
glutInitWindowPosition (100, 150);
glutCreateWindow ("THE STAR");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}



