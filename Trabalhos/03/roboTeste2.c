#include <GL/glut.h>
#include <stdlib.h>

static int ombro = 0, cotovelo = 0,girar=0, corpo = 0,  ombro1 = 0, cotovelo1 = 0;

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void desenha(void){
  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  /* origem posicionada no ombro */
  glColor3f(0.0,0.0,1.0);
  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) ombro, 0.0, 0.0, 1.0);

  /* origem posicionada no centro do braço */
  glTranslatef (0.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (0.5);
  glPopMatrix();
  
  /* origem posicionada no cotovelo */
  glTranslatef (0.0, 0.0, 0.0); 
  glRotatef ((GLfloat) cotovelo, 0.0, 0.0, 1.0);
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (0.5);
  glPopMatrix();
  
   //braço esquerdo
  glColor3f(0.0,0.0,1.0);
  glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) ombro1, 0.0, 0.0, 1.0);
  glTranslatef (-2.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (0.5);
  glPopMatrix();
  
  glTranslatef (0.0, 0.0, 0.0); 
  glRotatef ((GLfloat) cotovelo1, 0.0, 0.0, 1.0);
  glTranslatef (-1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (0.5);
  glPopMatrix();
 

  //  corpo
  glTranslatef (1.0, 0.6, 1.0);
  glRotatef ((GLfloat) corpo, 0.0, 0.0, 1.0);
  glTranslatef (1.0, -1.0, 0.0);
  glPushMatrix();
  glScalef (0.5, 0.8, 1.0);
  glutWireCube (1.3);
  glPopMatrix();
  
  //cabeça
  glPushMatrix();
  glTranslatef (0.0, 0.9, 0.0);
   glColor3f(0.0,0.0,1.0);
   glRotatef ((GLfloat) girar, 0.0, 0.0, 0.0);
   glutSolidSphere(1.0, 1, 6);
   glColor3f(0.0,0.0,1.0);
   glutWireSphere(0.3, 20, 16);  
 glPopMatrix();
 
  //coxa esquerda
  glTranslatef (-1.3, -0.9, 0.0);
  glRotatef ((GLfloat) corpo, 0.0, 0.0, 0.0);
  glTranslatef (1, 0.0, 0.0);
  glPushMatrix();
  glScalef (0.5, 1, 1.0);
  glutWireCube (0.4);
  glPopMatrix();
  
  //coxa direita  
  glTranslatef (-0.4, 0, 0.0);
  glRotatef ((GLfloat) corpo, 0.0, 0.0, 0.0);
  glTranslatef (1, 0.0, 0.0);
  glPushMatrix();
  glScalef (0.5, 1, 1.0);
  glutWireCube (0.4);
  glPopMatrix();
  
  // perna esquerda
  glTranslatef (0.0, -0.5, 0.0);
  glRotatef ((GLfloat) corpo, 0.0, 0.0, 0.0);
  glTranslatef (0, 0, 0.0);
  glPushMatrix();
  glScalef (0.5, 2.5, 1.0);
  glutWireCube (0.4);
  glPopMatrix();
  
  // perna direita
  glTranslatef (0.0, -0.5, 0.0);
  glRotatef ((GLfloat) corpo, 0.0, 0.0, 0.0);
  glTranslatef (-0.6, 0.5, 0.0);
  glPushMatrix();
  glScalef (0.5, 2.5, 1.0);
  glutWireCube (0.4);
  glPopMatrix();

 


  /* origem volta para o sistema de coordenadas original */

  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 'o':
    ombro = (ombro + 5) % 360;
    glutPostRedisplay();
    break;
  case 'O':
    ombro = (ombro - 5) % 360;
    glutPostRedisplay();
    break;
  case 'c':
    cotovelo = (cotovelo + 5) % 360;
    glutPostRedisplay();
    break;
  case 'C':
    cotovelo = (cotovelo - 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (800, 800);
  glutInitWindowPosition (100, 100);
   glutCreateWindow("Computação Gráfica 2013 - Movimento");
  init ();
  glutDisplayFunc(desenha);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}