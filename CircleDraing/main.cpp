#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>


int pntX1, pntY1, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}


void myInit (void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}



void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3ub (128, 128, 128);
	glPointSize(3.0);


	int x = 0;
	int y = r;
	int decision = 5/4 - r;
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



	glFlush ();
}

}

int main(int argc, char** argv)
{


    //pntX1, pntY1, r;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

	printf( "Enter the coordinates of the center\n");

	printf( "X-coordinate   : ");
	scanf("%d",&pntX1);
	printf( "\nY-coordinate : ");
	scanf("%d",&pntY1);
	printf ("\nEnter radius : ");
	scanf("%d",&r);

	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Circle Drawing Alogrithms");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
 return 0;
}
