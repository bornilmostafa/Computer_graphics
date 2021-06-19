#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>


GLfloat positionRoctet = 0.0f;
GLfloat Rspeed = 0.1f;

GLfloat positionEnemy = 0.0f;
GLfloat Espeed = 0.1f;

GLfloat positionGun= 0.0f;
GLfloat Gspeed = 0.1f;


void update(int value) {

    if(positionRoctet >1.0)
        positionRoctet=-1.2f;

    positionRoctet += Rspeed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{


			Gspeed += 0.1f;
			positionGun+=0.1f;
			printf("clicked at (%d, %d)\n", x, y);
			 glutPostRedisplay();
		}

    }



	   else if(button==GLUT_RIGHT_BUTTON)
    {
     Gspeed -= 0.1f;
    positionGun-=0.1f;
    printf("clicked at (%d, %d)\n", x, y);
   glutPostRedisplay();

    }

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {
if(key=='a')
    {Rspeed -= 0.1f;
     Espeed+=0.1f;
       positionEnemy-=0.1;

    glutPostRedisplay();
    }
else if(key=='d')
    {Rspeed += 0.1f;
     Espeed+=0.1f;
     positionEnemy-=0.1;
    glutPostRedisplay();
}
else if(key=='s')
{
    Rspeed=0.0f;
    Espeed+=0.1f;
    positionEnemy-=0.1;
    glutPostRedisplay();
}
}





void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

glPushMatrix();
glTranslatef(positionRoctet,0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.1f,-0.3f);
      glVertex2f(-0.1f,-0.5f);
      glVertex2f( 0.1f,-0.5f);
      glVertex2f(0.1f,-0.3f);
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.1f,-0.3f);
   glVertex2f(0.1f,-0.3f);
   glVertex2f(0.0f, 0.03f);
   glEnd();
glTranslatef(0.0f,positionGun, 0.0f);

    glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.1f,-0.03f);
   glVertex2f(0.1f,-0.03f);
   glVertex2f(0.0f, 0.0f);
   glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,positionEnemy, 0.0f);
    glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.9f,0.5f);
   glVertex2f(-0.7f, 0.5f);
   glVertex2f(-0.7f, 0.3f);
   glEnd();


    glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.6f,0.4f);
   glVertex2f(-0.4f, 0.4f);
   glVertex2f(-0.4f, 0.2f);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex2f(0.9f,0.5f);
   glVertex2f(0.7f, 0.5f);
   glVertex2f(0.7f, 0.3f);
  glEnd();

  glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(0.6f,0.4f);
   glVertex2f(0.4f, 0.4f);
   glVertex2f(0.4f, 0.2f);
   glEnd();

glPopMatrix();



   glFlush();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(800, 800);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Rocket Fire Game");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
  glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
