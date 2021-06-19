#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<cmath>



using namespace std;



GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat position4 = 0.0f;
GLfloat speed = 0.02f;
GLfloat speed2 = 0.03f;
GLfloat speed3 = 0.04f;
GLfloat speed4 = 0.06f;
float tX, tY;



float X11=-0.8f;
float X12=-0.75f;
float X13=-0.85f;
float Y11=0.85f;
float Y12=1.0f;
float Y13=1.0f;



float X21=-0.25f;
float X22=-0.2f;
float X23=-0.3f;
float Y21=-0.65f;
float Y22=-0.50f;
float Y23=-0.50f;



float X31=0.25f;
float X32=0.3f;
float X33=0.2f;
float Y31=0.0f;
float Y32=0.15f;
float Y33=0.15f;



float X41=0.8f;
float X42=0.85f;
float X43=0.75f;
float Y41=0.85f;
float Y42=1.0f;
float Y43=1.0f;



void update(int value) {



    if(Y12 < -1.0)
    {
        //position = 1.0f;
        Y11=1.0f;
        Y12=1.15f;
        Y13=1.15f;
    }



    if(Y22 < -1.0)
    {
        //position2 = 1.0f;
        Y21=1.0f;
        Y22=1.15f;
        Y23=1.15f;
    }



    if(Y32 < -1.0)
    {

        Y31=1.0f;
        Y32=1.15f;
        Y33=1.15f;
    }



    if(Y42 < -1.0)
    {

        Y41=1.0f;
        Y42=1.15f;
        Y43=1.15f;
    }



    //position -= speed;
        Y11 -= speed;
        Y12 -= speed;
        Y13 -= speed;
    //position2 -= speed2;
        Y21 -= speed2;
        Y22 -= speed2;
        Y23 -= speed2;
    //position3 -= speed3;
        Y31 -= speed3;
        Y32 -= speed3;
        Y33 -= speed3;
    //position4 -= speed4;
        Y41 -= speed4;
        Y42 -= speed4;
        Y43 -= speed4;



    glutPostRedisplay();



    glutTimerFunc(100, update, 0);
}







void handleMouse(int button, int state, int x, int y) {



    tX = ((float(x)/900) - 0.5) * 2;
    tY = -((float(y)/600) - 0.5) * 2;
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            printf("clicked at %f,%f)\n", tX,tY);




        }
    }



    glutPostRedisplay();
}




void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();



    glColor3f(1.0f, 1.0f, 0.0f);




    if(tX>=X13 && tX<=X12 && tY>=Y11 && tY<=Y12)
    {
        X11=-2.8f;
        X12=-2.75f;
        X13=-2.85f;
    }




    glPushMatrix();
    glTranslatef(0.0f,position, 0.0f);



    glBegin(GL_TRIANGLES);



    glVertex2f(X11,Y11);// enemy 1
    glVertex2f(X12,Y12);
    glVertex2f(X13,Y13);



    glEnd();



    glPopMatrix();



    glColor3f(1.0f, 0.0f, 0.0f);




    if(tX>=X23 && tX<=X22 && tY>=Y21 && tY<=Y22)
    {
        X21=-2.25f;
        X22=-2.2f;
        X23=-2.3f;
    }
    else
    glColor3f(1.0f, 1.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f,position2, 0.0f);



    glBegin(GL_TRIANGLES);



    glVertex2f(X21,Y21);// enemy 2
    glVertex2f(X22,Y22);
    glVertex2f(X23,Y23);



    glEnd();



    glPopMatrix();



    glColor3f(1.0f, 1.0f, 0.0f);




    if(tX>=X33 && tX<=X32 && tY>=Y31 && tY<=Y32)
    {
        X31=-2.25f;
        X32=-2.2f;
        X33=-2.3f;
    }



    glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);



    glBegin(GL_TRIANGLES);



    glVertex2f(X31,Y31);// enemy 3
    glVertex2f(X32,Y32);
    glVertex2f(X33,Y33);



    glEnd();



    glPopMatrix();



    glColor3f(1.0f, 1.0f, 0.0f);




    if(tX>=X43 && tX<=X42 && tY>=Y41 && tY<=Y42)
    {
        X41=-2.25f;
        X42=-2.2f;
        X43=-2.3f;
    }



    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);



    glBegin(GL_TRIANGLES);



    glVertex2f(X41,Y41);// enemy 4
    glVertex2f(X42,Y42);
    glVertex2f(X43,Y43);



    glEnd();



    glPopMatrix();



    glFlush();




}




void init() {
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-450 , 450 , -300 , 300);
}




int main(int argc, char** argv) {



   glutInit(&argc, argv);
   glutInitWindowSize(900, 600);
   glutInitWindowPosition(300, 150);
   glutCreateWindow("Enemy destroy");
   glutDisplayFunc(display);
   init();
   glutMouseFunc(handleMouse);
   glutTimerFunc(100, update, 0);
   glutMainLoop();



   return 0;
}
