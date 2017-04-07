
// #include <windows.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <stdio.h>
/*GL Includes */
#include <GL/gl.h>
#include <GL/glut.h>
static int shoulder = -45, elbow = 60;
void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glPushMatrix();
//Bra�o direito
glTranslatef (-1.0, 0.0, 0.0);
//glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
glRotatef ((GLfloat) -45.0, 0.0, 0.0, 1.0);
glTranslatef (1.0, 0.0, 0.0);
glPushMatrix();
glColor3f(0.0,0.0,1.0);
glScalef (2.0, 0.4, 1.0);
glutSolidCube (1.0);
glPopMatrix();
glTranslatef (1.0, 0.0, 0.0);
glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
glTranslatef (1.0, 0.0, 0.0);
glPushMatrix();
glScalef (2.0, 0.4, 1.0);
glutSolidCube (1.0);
glPopMatrix();
glPopMatrix();
//Bra�o esquerdo
glPushMatrix();
glTranslatef (1.6, 0.0, 0.0);
glTranslatef (-1.0, 0.0, 0.0);
//glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
glRotatef ((GLfloat) 270.0, 0.0, 0.0, 1.0);
glTranslatef (1.0, -4.0, 0.0);
glPushMatrix();
glColor3f(0.0,0.0,1.0);
glScalef (2.0, 0.4, 1.0);
glutSolidCube (1.0);
glPopMatrix();
glTranslatef (1.0, 0.0, 0.0);
glRotatef ((GLfloat) 90, 0.0, 0.0, 1.0);
glTranslatef (1.0, 0.0, 0.0);
glPushMatrix();
glScalef (2.0, 0.4, 1.0);
glutSolidCube (1.0);
glPopMatrix();
glPopMatrix();

//Ombros
glPushMatrix();
glColor3f(1.0,1.0,0.0);
glTranslatef (-2.0, 0.15, 0.0);
glScalef (2.0, 0.2, 1.0);
glutSolidCube (1.0);
glPopMatrix();
//Cabe�a
glPushMatrix();
glColor3f(0.0,0.0,1.0);
glTranslatef (-2.0, 1.0, 0.0);
glutSolidCube (1.0);
glPopMatrix();
//Coluna Vertebral
glPushMatrix();
glColor3f(0.0,0.0,1.0);
glTranslatef (-2.0, -2.1, 0.0);
glScalef (0.2, 4.0, 1.0);
glutSolidCube (1.0);
glPopMatrix();
//Bacia
glPushMatrix();
glColor3f(1.0,1.0,0.0);
glTranslatef (-2.0, -4, 0.0);
glScalef (2.0, 0.2, 1.0);
glutSolidCube (1.0);
glPopMatrix();
//Perna direita
glPushMatrix();
glTranslatef (-1.0, -4.0, 0.0);
//glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
glRotatef ((GLfloat) -85.0, 0.0, 0.0, 1.0);
glTranslatef (1.0, 0.0, 0.0);
glPushMatrix();
glColor3f(0.0,0.0,1.0);
glScalef (2.0, 0.4, 1.0);
glutSolidCube (1.0);
glPopMatrix();
glTranslatef (1.0, 0.0, 0.0);
glRotatef ((GLfloat) 5.0, 0.0, 0.0, 1.0);
glTranslatef (1.0, 0.0, 0.0);
glPushMatrix();
glColor3f(1.0,0.0,0.0);
glScalef (2.0, 0.4, 1.0);
glutSolidCube (1.0);
glPopMatrix();
glPopMatrix();
//Perna esquerda
glPushMatrix();
glTranslatef (-3.0, -4.0, 0.0);
//glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
glRotatef ((GLfloat) -85.0, 0.0, 0.0, 1.0);
glTranslatef (1.0, 0.0, 0.0);
glPushMatrix();
glColor3f(0.0,0.0,1.0);
glScalef (2.0, 0.4, 1.0);
glutSolidCube (1.0);
glPopMatrix();
glTranslatef (1.0, 0.0, 0.0);
glRotatef ((GLfloat) 5.0, 0.0, 0.0, 1.0);
glTranslatef (1.0, 0.0, 0.0);
glPushMatrix();

glColor3f(1.0,0.0,0.0);
glScalef (2.0, 0.4, 1.0);
glutSolidCube (1.0);
glPopMatrix();
glPopMatrix();
glutSwapBuffers();
}
void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt (0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
glTranslatef (0.0, 0.0, -5.0);
}
void keyboard (unsigned char key, int x, int y)
{
switch (key) {
case 'e': /* e key rotates at elbow */
elbow = (elbow + 5) % 360;
glutPostRedisplay();
break;
default:
break;
}
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow (argv[0]);
init ();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}
