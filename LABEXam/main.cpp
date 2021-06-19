#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>


int pntX1=146, pntY1=107, r=44;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}



void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glColor3ub (255, 250,250);




glColor3ub (0, 0,205 );
glPointSize(5.0);
glBegin(GL_POLYGON);
glVertex2i(0,216);
glVertex2i(432, 216);
glVertex2i(432, 180);
glVertex2i(0, 180);
glEnd();
glFlush ();

glColor3ub (255, 0,0);
glPointSize(5.0);

glBegin(GL_POLYGON);
glVertex2i(0,170);
glVertex2i(432, 170);
glVertex2i(432, 43);
glVertex2i(0, 43);
glEnd();
glFlush ();

glColor3ub (0,0,205);
glPointSize(5.0);

glBegin(GL_POLYGON);
glVertex2i(0,33);
glVertex2i(432, 33);
glVertex2i(432, 0);
glVertex2i(0,0);
glEnd();
glFlush ();





	glColor3f (255.0, 250.0, 250.0);
	glPointSize(15.0);



int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++;
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
 glFlush ();

 glBegin(GL_TRIANGLES);
glColor3ub (255,0 ,0);
glPointSize(1.0);


  glVertex2i(143,64);//4
  glVertex2i(133,92);//5
  glVertex2i(125,113);//10

  glVertex2i(144,125);//4
  glVertex2i(172,146);//5
  glVertex2i(161,111);//4


glEnd();


glColor3ub (0, 0,205 );
glPointSize(5.0);

glFlush ();
}


void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("North korea");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}

