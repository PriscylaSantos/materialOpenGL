
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
           
  //  glScalef(4.0,4.0,4.0);//aumenta o tamanho do desenho
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      glBegin(GL_LINES);
       glColor3f(1.0,1.0,1.0);
       glVertex2f(0,0);
       glVertex2f(0,175);
       glVertex2f(0,0);
       glVertex2f(0,-175);
       glVertex2f(150,0);
       glVertex2f(-150,0);     
    glEnd();
    /*Primeiro quadrante*/
    glBegin(GL_TRIANGLE_STRIP);    
       glColor3f(1.0,0.0,0.0);
       glVertex3f(40,80,0);
       glColor3f(1.0,0.0,1.0);
       glVertex3f(80,80,0);
       glColor3f(1.0,1.0,0.0);       
       glVertex3f(80,40,0); 
       //
        glColor3f(1.0,0.0,0.0);
       glVertex3f(40,80,0);
       glColor3f(1.0,0.0,1.0);
       glVertex3f(40,40,0);
       glColor3f(1.0,1.0,0.0);       
       glVertex3f(80,40,0);
             glEnd();   
  
       /*Segundo Quadrante*/
       //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);      
       glBegin(GL_TRIANGLES);
       glColor3f(0.8,0.0,0.0);
       glVertex2f(-40,40);
       glColor3f(1.0,1.0,0.0);
       glVertex2f(-80,80);  
       glColor3f(1.0,0.4,0.6);     
       glVertex2f(-100,75);
          glEnd();   

       /*terceiro quadrante*/
      // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
       glBegin(GL_QUADS);    
       glColor3f(1.0,0.0,0.0);
       glVertex3f(-10,-90,0);
       glColor3f(1.0,0.5,0.7);
       glVertex3f(-10,-10,0);
       glColor3f(0.0,0.0,0.0); 
       glVertex3f(-40,-20,0); 
       glColor3f(1.0,6.0,5.0);     
       glVertex3f(-35,-75,0);
       //
       glColor3f(1.0,1.0,0.0);
       glVertex3f(-15,-80,0);
       glColor3f(1.0,0.5,0.7);
       glVertex3f(-20,-10,0);
       glColor3f(0.0,0.8,0.0);
       glVertex3f(-90,-20,0);
       glColor3f(1.0,1.0,5.0);
       glVertex3f(-90,-75,0);
       glEnd();  
       
       /*quarto quadrante*/
       //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  
       glBegin(GL_POLYGON);    
       glColor3f(1.0,1.0,1.0);
       glVertex3f(20,-20,0);
        glColor3f(1.0,1.0,0.0);
       glVertex3f(50,-20,0); 
        glColor3f(1.0,0.0,0.0);
       glVertex3f(80,-50,0);  
        glColor3f(0.0,0.6,0.0);    
       glVertex3f(80,-80,0);
        glColor3f(0.0,0.8,1.0);
       glVertex3f(20,-80,0);
                    
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
    gluOrtho2D (-175, 175, -150, 150);  
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



