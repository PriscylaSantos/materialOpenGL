/*
* smooth.c
* This program demonstrates smooth shading.
* A smooth shaded polygon is drawn in a 2-D projection.
*/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
/* GL_SMOOTH is actually the default shading model. */
void myinit (void)
{
     glShadeModel (GL_SMOOTH);
}

void triangle(void)
{
     glBegin (GL_TRIANGLES);
     glColor3f (1.0, 0.0, 0.0);
     glVertex2f (5.0, 5.0);
     glColor3f (0.0, 1.0, 0.0);
     glVertex2f (25.0, 5.0);
     glColor3f (0.0, 0.0, 1.0);
     glVertex2f (5.0, 25.0);
     glEnd ();
}

void display(void)
{
     glClear (GL_COLOR_BUFFER_BIT);
     triangle ();
     glFlush ();
}

void myReshape(int w, int h)
{
     glViewport(0, 0, w, h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     if (w <= h)
         gluOrtho2D (0.0, 30.0, 0.0, 30.0 * (GLfloat) h/(GLfloat) w);
     else
         gluOrtho2D (0.0, 30.0 * (GLfloat) w/(GLfloat) h, 0.0, 30.0);
         glMatrixMode(GL_MODELVIEW);
}

/* Main Loop
* Open window with initial window size, title bar,
* RGBA display mode, and handle input events.
*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
