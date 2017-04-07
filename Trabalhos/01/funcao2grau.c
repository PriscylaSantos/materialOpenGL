#include <stdlib.h>
#include<GL/glut.h>
#include<math.h>
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
    glBegin(GL_LINES);
       glColor3f(1.0,1.0,1.0);
       glVertex2f(0,0);
       glVertex2f(0,10);
       glVertex2f(0,0);
       glVertex2f(0,-10);
       glVertex2f(15,0);
       glVertex2f(-15,0);     
    glEnd();
    //y=3x²+5x -6
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,1.0);
    float x;
    float y;    
    x = -10.0;
    y = 0;
        while(x <= 10.0){
        y = (3*x*x + 5*x - 6);
        glVertex2f(x,y);
        x = x + 0.01;          
    }
    
         
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
    gluOrtho2D (-15.0, 15, -10, 10);  
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



