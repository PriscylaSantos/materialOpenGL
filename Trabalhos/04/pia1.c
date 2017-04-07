#include <stdlib.h>
#include<GL/glut.h>
#include <GL/glut.h>
#include <stdlib.h>

GLfloat X = 0.0f; 
GLfloat Y = 0.0f; 

void desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
 	glTranslatef(X, Y, 0.0f);    	
    glutPostRedisplay();            
     
    //glScalef(4.0,4.0,4.0);//aumenta o tamanho do desenho
      //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUAD_STRIP);            
       glColor3f(0.3,0.5,0.4);
       glVertex3f(0,0,0);
       glVertex3f(0,500,0);       
       glVertex3f(500,0,0);
       glVertex3f(500,500,0);
    glEnd();
//PAREDE DE FUNDO
    glBegin(GL_QUAD_STRIP);            
       glColor3f(0.9, 0.8,0.3);
       glVertex3f(100,100,0);
       glVertex3f(100,400,0);       
       glVertex3f(410,100,0);
       glVertex3f(410,400,0);
    glEnd(); 
    
//AZULEIJO DA PIA - ratengulo
     glBegin(GL_QUADS);
       glColor3f(1.0,1.0,1.0);      
       glVertex2f(150,242);
       glVertex2f(150,350);
       glVertex2f(400,350); 
       glVertex2f(400,242);             
     glEnd();
     
//AZULEIJO DA PIA - linhas
      glLineWidth(2.0);
      glBegin(GL_LINES);
       //glColor3f(0.9, 0.8,0.3); 
       glColor3f(0.0,1.0,0.0); 
       float x = 150;
       float y = 242;
       float x1 = 150;
       float y1 = 242;
       while (x < 400) 
       {
             glVertex2f(x,y);
             glVertex2f(x,(y+108));//linha vertival
             x = x + 30;                           
       }
       while (y1 < 350)
       {
           glVertex2f(x1,y1);
           glVertex2f((x1+250),y1);//linha horizontal  
           y1 = y1 + 40; 
       }
     glEnd();
     
     //RODAPÉ DO AZULEIJO DA PIA - ratengulo
     glBegin(GL_QUAD_STRIP);
       glColor3f(0.7,0.7,0.7);      
       glVertex2f(150,240); 
       glVertex2f(150,225);
       glVertex2f(399,240);        
       glVertex2f(399,225);           
     glEnd();
      
// PIA E BALCÃO - retângulo   É PRA SER EM 3D PARA APARECER A BEIRADA DO BALCÃO
     glBegin(GL_QUAD_STRIP);
        glColor3f(0.6,0.6,0.6);
        glVertex2f(150,225);
        glVertex2f(140,190);
        glVertex2f(399,225);
        glVertex2f(395,190);
     glEnd();
     
// PIA  
     glBegin(GL_QUAD_STRIP);
       glColor3f(0.3,0.3,0.3);
       glVertex2f(150,195);
       glVertex2f(155,220 );
       glVertex2f(215,195);
       glVertex2f(220,220);
     glEnd();  
     
//BALCÃO 
    glBegin(GL_QUAD_STRIP);
       glColor3f(0.3,0.3,0.3);
       glVertex2f(230,190);
       glVertex2f(235,225);
       glVertex2f(350,190);
       glVertex2f(355,225 );
     glEnd();   
      
// ARMARIO DA PIA  - retangulo  
     glBegin(GL_QUADS);
       glColor3f(0.9, 0.9,0.5);
       glVertex2f(140,100);
       glVertex2f(140,190);
       glVertex2f(395,190); 
       glVertex2f(395,100);             
     glEnd();  
     
//ARMARIO - menor
     glBegin(GL_QUAD_STRIP);
        glColor3f(0.1,0.1,0.1);
        glVertex2f(145,105);
        glVertex2f(145,185);
        glVertex2f(200,105);
        glVertex2f(200,185);        
     glEnd(); 
     
//LINHAS  DO ARMARIO - menor  
     glLineWidth(2.0);
     glBegin(GL_LINES);//_LOOP);
       glColor3f(0.6,0.6,0.6);
       glVertex2f(172,105);//linha vertical 
       glVertex2f(172,185);
       glVertex2f(145,165);  //linha horizontal
       glVertex2f(200,165);
     glEnd();     
     
           
//ARMARIO - maior
glBegin(GL_QUAD_STRIP);
        glColor3f(0.1,0.1,0.1);
        glVertex2f(210,105);
        glVertex2f(210,185);
        glVertex2f(305,105);
        glVertex2f(305,185);        
     glEnd();
     
//LINHAS DO ARMARIO - maior
      glLineWidth(2.0);
     glBegin(GL_LINES);
       glColor3f(0.6,0.6,0.6);
       glVertex2f(255,105);//linha vertical 
       glVertex2f(255,185);
       glVertex2f(210,165);  //linha horizontal
       glVertex2f(305,165);
     glEnd(); 
     
//GAVETAS DO ARMARIO
glBegin(GL_QUAD_STRIP);
        glColor3f(0.1,0.1,0.1);
        glVertex2f(315,105);
        glVertex2f(315,185);
        glVertex2f(390,105);
        glVertex2f(390,185);
                
     glEnd();
     
//LINHAS DO ARMARIO 
      glLineWidth(0.01);
     glBegin(GL_LINES);
       glColor3f(0.6,0.6,0.6);
       glVertex2f(315,165);  //linha horizontal
       glVertex2f(390,165);
       glVertex2f(315,145);  //linha horizontal
       glVertex2f(390,145);
       glVertex2f(315,125);  //linha horizontal
       glVertex2f(390,125);
       glVertex2f(365,105);//linha vertical 
       glVertex2f(365,185);
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
    gluOrtho2D (0.0, 500.0, 0.0, 500.0);  
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



