#include<cstdio>
#include<GL/gl.h>
#include<GL/glut.h>
#include<stdlib.h>

float x1,x2,y1,y2,x3,y3,x4,y4;

void draw_points(float x, float y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(float x3, float x4, float y3, float y4) {
	float dx, dy, i, e; //value required for
	float incx, incy, inc1, inc2;
	float x,y;

	dx = x4-x3; //applying bresshm algoritms
	dy = y4-y3;

	if (dx < 0)
    {dx = -dx;}
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x4 < x3) incx = -1;
	incy = 1;
	if (y4 < y3) incy = -1;
	x = x3; y = y3;
	if (dx > dy) {
		draw_points(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_points(x, y);
		}

	} else {
		draw_points(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_points(x, y);
		}
	}
}



void display(void)
{

glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (128, 128, 128);
glPointSize(2.0);
float dy,dx,step,x,y,k,Xin,Yin; //all float inputs
dx=x2-x1;                      //slope for x-axis
dy=y2-y1;                     //slope for y-axis

if(dx> dy)
{
step = dx;
}
else
{step = dy;
}


x= x1;
y=y1;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

for (k=1 ;k<=step;k++) //it will run highest steps count
{
x= x +1;
y= y + 0.5;
glBegin(GL_POINTS);
glVertex2i(x,y);

}
glFlush();

draw_line(x3, x4, y3, y4);
glFlush();
 glEnd();
}

void myinit(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,900,0,700);
}

int main(int argc, char** argv) {
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y1);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);
printf("Enter the value of x3 : ");
scanf("%f",&x3);
printf("Enter the value of y3 : ");
scanf("%f",&y3);
printf("Enter the value of x4 : ");
scanf("%f",&x4);
printf("Enter the value of y4 : ");
scanf("%f",&y4);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (900, 700);
glutInitWindowPosition (500,300);
glutCreateWindow ("DDA AND Bressman algorithms");
myinit();
glutDisplayFunc(display);
glutMainLoop();
}


