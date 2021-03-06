
#include <stdlib.h>
#include<GL/glut.h>
#include <GL/glut.h>
#include <stdlib.h>

GLfloat X = 0.0f; //  movimenta��o ma tela, setas esq, dir, p/ cima, p/ baixo
GLfloat Y = 0.0f; 

void desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
 	glTranslatef(X, Y, 0.0f);    //para movimenta��o da tela			
    glutPostRedisplay();            
           
    glScalef(4.0,4.0,4.0);//aumenta o tamanho do desenho
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glBegin(GL_TRIANGLES);
    glBegin(GL_TRIANGLE_STRIP);
   

    glColor3f(0.0,1.0,0.0);
       glVertex2f(20,60);   
       glVertex2f(20,20);      
       glVertex2f(30,30);        
   
    glColor3f(1.0,0.0,0.0);
       glVertex2f(50,30);   
       glVertex2f(20,20);         
       glVertex2f(60,20);      
              
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
    gluOrtho2D (0.0, 550.0, 0.0, 550.0);  
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);  	
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Introdu��o a OPENGL - Computa��o Gr�fica - mar�o/2013");  
    glutDisplayFunc(desenha);               	
    glutSpecialFunc(specialKey); 
    glutReshapeFunc(resize); 
    glutKeyboardFunc(key);    	
    glutMainLoop();

    return 0;
}



