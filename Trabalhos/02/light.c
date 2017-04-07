
#include <GL/glut.h>
#include <stdlib.h>
/* Initialize material property, light source, lighting model,
* and depth buffer.
*/
void myinit(void)
{
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
glShadeModel(GL_SMOOTH);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glDepthFunc(GL_LESS);
glEnable(GL_DEPTH_TEST);
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glutSolidSphere(1.0, 40, 40);
glFlush();
}
void myReshape(int w, int h)
{
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (w <= h)
glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
else
glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
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
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow(argv[0]);
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
myinit();
glutMainLoop();
return 0; /* ANSI C requires main to return int. */
}
//-----------------------------------------------------------------------------------------------------------------------------
