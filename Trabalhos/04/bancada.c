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
     
    glScalef(1.0,1.0,0.0);//aumenta o tamanho do desenho
     // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      
      //PAREDES - AREA DE DESENHO
       glBegin(GL_QUAD_STRIP);
       glColor3f(0.9,0.9,0.9);      
       glVertex2f(2,2);
       glVertex2f(2,249);          
       glVertex2f(32,2);
       glVertex2f(32,249);
       glVertex2f(219,2); 
       glVertex2f(219,249); 
       glVertex2f(249,2); 
       glVertex2f(249,249);              
     glEnd(); 
     
     //AZULEIJO DA PIA - ratengulo
     glBegin(GL_QUADS);
       glColor3f(1.0,1.0,1.0);      
       glVertex2f(50,120);
       glVertex2f(50,180);
       glVertex2f(200,180); 
       glVertex2f(200,120);             
     glEnd();
     
     //AZULEIJO DA PIA - linhas
      glLineWidth(2.0);
     glBegin(GL_LINES);//_LOOP);
       glColor3f(0.9,0.9,0.9);  
       float x = 50;
       float y = 120;
       float x1 = 50;
       float y1 = 120;
       while (x < 210) 
       {
             glVertex2f(x,y);
             glVertex2f(x,(y+60));//linha vertival
             x = x + 30;                           
       }
       while (y1 < 200)
       {
           glVertex2f(x1,y1);
           glVertex2f((x1+150),y1);//linha horizontal  
           y1 = y1 + 20; 
       }
     glEnd();
      
     // PIA E BALCÃO - retângulo
     glBegin(GL_QUAD_STRIP);
        glColor3f(0.6,0.6,0.6);
        glVertex2f(50,120);
        glVertex2f(40,100);
        glVertex2f(200,120);
        glVertex2f(210,100);
     glEnd();
     
     glBegin(GL_QUAD_STRIP);
     
     glEnd();
     
     
     
       // ARMARIO DA PIA  - retangulo
       //glLineWidth(3.0);   
     glBegin(GL_QUADS);
       glColor3f(0.9, 0.9,0.5);
       glVertex2f(40,100);
       glVertex2f(40,30);
       glVertex2f(210,30); 
       glVertex2f(210,100);             
     glEnd();  
     
       //ARMARIO - menor
     glBegin(GL_QUAD_STRIP);
        glColor3f(0.1,0.1,0.1);
        glVertex2f(45,35);
        glVertex2f(45,95);
        glVertex2f(100,35);
        glVertex2f(100,95);        
     glEnd();     
     glLineWidth(8.0);
     glBegin(GL_LINES);//_LOOP);
       glColor3f(0.6,0.6,0.6);
       glVertex2f(73,35);//linha vertical 
       glVertex2f(73,95);
       glVertex2f(45,80);  //linha horizontal
       glVertex2f(100,80);
     glEnd();     
     glPointSize(8);
     //glBegin(GL_POINTS);   
       glColor3f(0.0,0.0,0.2);
       glVertex2f(47,80);
       glVertex2f(98,80);
     glEnd();
      
      
     //ARMARIO - maior
     glBegin(GL_QUAD_STRIP);
        glColor3f(0.1,0.1,0.1);
        glVertex2f(110,35);
        glVertex2f(110,95);
        glVertex2f(205,35);
        glVertex2f(205,95);        
     glEnd();
      glLineWidth(8.0);
     glBegin(GL_LINES);//_LOOP);
       glColor3f(0.6,0.6,0.6);
       glVertex2f(155,35);//linha vertical 
       glVertex2f(155,95);
       glVertex2f(110,80);  //linha horizontal
       glVertex2f(205,80);
     glEnd(); 
     
     glPointSize(8);
    // glBegin(GL_POINTS);   
       glColor3f(0.0,0.0,0.2);
       glVertex2f(115,80);
       glVertex2f(200,80);
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
    gluOrtho2D (0.0, 250.0, 0.0, 250.0);  
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);  	
    glutInitWindowPosition(200, 200); 
    glutCreateWindow("Introdução a OPENGL - Computação Gráfica - março/2013");  
    glutDisplayFunc(desenha);               	
    glutSpecialFunc(specialKey); 
    glutReshapeFunc(resize); 
    glutKeyboardFunc(key);    	
    glutMainLoop();

    return 0;
}



