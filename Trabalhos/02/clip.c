
#include <GL/glut.h>
#include <stdlib.h>
void display(void)
{
GLdouble eqn[4] = {1.0, 1.0, 1.0, 1.0};
GLdouble eqn2[4] = {1.0, 1.0, 1.0, 0.0};
/* 
GLdouble eqn[4] = {0.0, 1.0, 0.0, 0.0};
GLdouble eqn2[4] = {1.0, 0.0, 0.0, 0.0};
*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 1.0, 1.0);
glPushMatrix();
glTranslatef (0.0, 0.0, -5.0);
/* clip lower half -- y < 0 */
glClipPlane (GL_CLIP_PLANE0, eqn);
glEnable (GL_CLIP_PLANE0);
/* clip left half -- x < 0 */
glClipPlane (GL_CLIP_PLANE1, eqn2);
glEnable (GL_CLIP_PLANE1);
glRotatef (90.0, 1.0, 0.0, 0.0);
glutWireSphere(1.0, 20, 20);
glPopMatrix();
glFlush();
}
void myinit (void) {
glShadeModel (GL_FLAT);
}
void myReshape(int w, int h)
{
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
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
return 0; /* ANSI C requires main to return int. */
}
