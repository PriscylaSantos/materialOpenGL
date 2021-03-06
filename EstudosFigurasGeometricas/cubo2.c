

#include <GL/glut.h>

GLfloat angle, fAspect;

// Fun��o callback chamada para fazer o desenho

void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.1f, 1.0f, 1.0f);

	// Desenha um cubo

	glBegin(GL_POLYGON);			// Face posterior
		glNormal3f(0.0, 0.0, 1.0);	// Normal da face
		glVertex3f(40.0, 40.0, 40.0);
		glVertex3f(-40.0, 40.0, 40.0);
		glVertex3f(-40.0, -40.0, 40.0);
		glVertex3f(40.0, -40.0, 40.0);
		// Face frontal
		glNormal3f(0.0, 0.0, -1.0); 	// Normal da face
		glVertex3f(40.0, 40.0, -40.0);
		glVertex3f(40.0, -40.0, -40.0);
		glVertex3f(-40.0, -40.0, -40.0);
		glVertex3f(-40.0, 40.0, -40.0);
		// Face lateral esquerda
		glNormal3f(-1.0, 0.0, 0.0); 	// Normal da face
		glVertex3f(-40.0, 40.0, 40.0);
		glVertex3f(-40.0, 40.0, -40.0);
		glVertex3f(-40.0, -40.0, -40.0);
		glVertex3f(-40.0, -40.0, 40.0);
		// Face lateral direita
		glNormal3f(1.0, 0.0, 0.0);	// Normal da face
		glVertex3f(40.0, 40.0, 40.0);
		glVertex3f(40.0, -40.0, 40.0);
		glVertex3f(40.0, -40.0, -40.0);
		glVertex3f(40.0, 40.0, -40.0);
		// Face superior
		glNormal3f(0.0, 1.0, 0.0);  	// Normal da face
		glVertex3f(-40.0, 40.0, -40.0);
		glVertex3f(-40.0, 40.0, 40.0);
		glVertex3f(40.0, 40.0, 40.0);
		glVertex3f(40.0, 40.0, -40.0);
		// Face inferior
		glNormal3f(0.0, -1.0, 0.0); 	// Normal da face
		glVertex3f(-40.0, -40.0, -40.0);
		glVertex3f(40.0, -40.0, -40.0);
		glVertex3f(40.0, -40.0, 40.0);
		glVertex3f(-40.0, -40.0, 40.0);
	glEnd();
	glutSwapBuffers();
}

// Inicializa par�metros de rendering
void Inicializa (void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    angle=45;
}

// Fun��o usada para especificar o volume de visualiza��o
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// Especifica a proje��o perspectiva
	gluPerspective(angle,fAspect,0.1,500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posi��o do observado e do alvo
    //posi��o c�mera, 1 gira horizontal 2 giro vertical 3 zoom
	//posi��o alvo, 1 transla��o de c�mera eixo x esquerda 2 transla��o de c�mera eixo y 3 transla��o de c�mera eixo x esquerda
    //vista de cima, 1 rota��o anti-hor�ria 2  2 inclina��o 3d
    gluLookAt(50,80,200, 0,0,0, 0,1,0);
}

// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divis�o por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a corre��o de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Programa Principal
int main(void)
{
  char** argv_ = 0;
  int argc_ = 0;
  glutInit(&argc_,argv_);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(350,300);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);

	Inicializa();
	glutMainLoop();
}
