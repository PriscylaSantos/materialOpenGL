/*
* aim.c
* This program calculates the fovy (field of view angle
* in the y direction), by using trigonometry, given the
* size of an object and its size.
*/
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void myinit (void) {
glShadeModel (GL_FLAT);
}
/* Clear the screen. Set the current color to white.
* Draw the wire frame cube and sphere.
*/
void display (void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 1.0, 1.0);
glLoadIdentity ();
/* glTranslatef() as viewing transformation */
glTranslatef (0.0, 0.0, -5.0);
glutWireCube(2.0);
glutWireSphere(1.0, 10, 10);
glFlush();
}
#define PI 3.1415926535
/* atan2 () is a system math routine which calculates
* the arctangent of an angle, given length of the
* opposite and adjacent sides of a right triangle.
* atan2 () is not an OpenGL routine.
*/
GLdouble calculateAngle (double size, double distance)
{
GLdouble radtheta, degtheta;
radtheta = 2.0 * atan2 (size/2.0, distance);
degtheta = (180.0 * radtheta) / PI;
printf ("degtheta is %lf\n", degtheta);
return ((GLdouble) degtheta);
}
/* Called when the window is first opened and whenever
* the window is reconfigured (moved or resized).
*/
void myReshape(int w, int h)
{
GLdouble theta;
//glViewport(0, 0, w/4, h/2);
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
theta = calculateAngle (2.0, 5.0);
gluPerspective(theta*4, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
//gluPerspective(theta, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
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
return 0; /* ANSI C requires main to return int. */
}
