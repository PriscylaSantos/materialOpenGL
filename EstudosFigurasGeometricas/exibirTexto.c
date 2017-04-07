#include <GL/glut.h>
#include <string.h>


void DesenhaTexto(char *string)
{
  	glPushMatrix();
        // Posi��o no universo onde o texto ser� colocado
        glRasterPos2f(0,0);
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	glPopMatrix();
}
// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
	//Limpa a janela de visualiza��o com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
    DesenhaTexto("Priscyla Santos");
	//Executa os comandos OpenGL
	glFlush();
}

// Inicializa par�metros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualiza��o como preta
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

// Programa Principal
int main(void)
{
  char** argv_ = 0;
int argc_ = 0;
glutInit(&argc_,argv_);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(350,300);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Exemplo de Exibi��o de Caracteres");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
}
