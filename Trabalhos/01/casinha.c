#include <stdlib.h>
#include<GL/glut.h>

#include <GL/glut.h>
#include <stdlib.h>

GLfloat X = 0.0f; //  movimentação ma tela, setas esq, dir, p/ cima, p/ baixo
GLfloat Y = 0.0f; 

void desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
 	
    glTranslatef(X, Y, 0.0f);    //para movimentação da tela			
    glutPostRedisplay();                   
   
   glLineWidth(5.0);
   glBegin(GL_LINES);
     glColor3f(1.0,1.0,0.0);
     glVertex3f(-40.0,-40.0,0.0);
     glColor3f(0.1,0.8,0.7);
     glVertex3f(40.0,-40.0,0.0);
     
  glColor3f(1.0,1.0,0.0);
     glVertex3f(-40,40.0,0.0);
   glColor3f(0.1,0.6,0.5);
     glVertex3f(40,40.0,0.0);
     //
     glColor3f(1.0,1.0,0.0);
     glVertex3f(40,40.0,0.0);
    glColor3f(0.1,0.4,0.4);
     glVertex3f(40.0,-40.0,0.0);
     //
   glColor3f(1.0,1.0,0.0);
     glVertex3f(-40.0,40.0,0.0);
     glColor3f(0.1,0.2,0.1);
     glVertex3f(-40.0,-40.0,0.0);
     glEnd();
     //
      glBegin(GL_TRIANGLES);
       glColor3f(1.0,0.0,1.0);
       glVertex3f(-40,42,0);
       glColor3f(0.0,0.0,1.0);
       glVertex3f(40,42,0);    
       glColor3f(0.0,1.0,0.0);   
       glVertex3f(0,90,0);
       glEnd();
       //porta
      glBegin(GL_QUADS);
       glColor3f(0.0,0.0,1.0);
        glVertex2f(15,-39);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-15, -39);
         glColor3f(0.0,1.0,1.0);
        glVertex2f(-15, -15);        
         glColor3f(1.0,0.0,0);
       glVertex2f(15, -15);
       //janela
    glColor3f (0.8, 1.0, 0.0);
    glPointSize(30);
    glBegin(GL_POINTS);
      glVertex3f(-25,10,0);
      glEnd();
      //janela
    glColor3f (0.8, 1.0, 0.0);
    glPointSize(30);
    glBegin(GL_POINTS);
      glVertex3f(25,10,0);
      glEnd();
      //fechadura
      glColor3f (0.0, 0.0, 0.0);
    glPointSize(12);
    glBegin(GL_POINTS);
      glVertex3f(10,-30,0);
   
      
       
    glEnd();
    glFlush();
}

void key(unsigned char key, int x, int y)
{
    if( key == 'q' || key == 'Q') 
        exit(0);                
}


// movimentar a tela
void specialKey(int key, int x, int y) { 
    switch(key) {
        case GLUT_KEY_LEFT : 	
            X -= 0.1f;
          break;
        case GLUT_KEY_RIGHT :    	
            X +=  0.1f;
          break;
        case GLUT_KEY_UP :        	
            Y += 0.1f;
          break;
        case GLUT_KEY_DOWN :    	
            Y -= 0.1f;
          break;    
    }
}

void resize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
   // gluOrtho2D (-1.1, 1.1 , -1.1 , 1.1);
    gluOrtho2D (-100.0, 100.0, -100.0,100.0);  
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);  	
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Introdução a OPENGL - Computação Gráfica - março/2013");  
    glutDisplayFunc(desenha);               	
    glutSpecialFunc(specialKey); 
    glutReshapeFunc(resize); 
    glutKeyboardFunc(key);    	
    glutMainLoop();

    return 0;
}



