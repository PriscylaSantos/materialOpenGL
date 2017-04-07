#include <GL/glut.h>


GLdouble obsX=0, obsY=0, obsZ=200;
GLfloat angle, fAspect;

// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);

	// Desenha o teapot com a cor corrente (wire-frame)
	glutWireTeapot(50.0f);
	glTranslatef(-50.0f, -30.0f, 10.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutWireCube(50.0f);


	// Executa os comandos OpenGL
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

	// Especifica posi��o do observador e do alvo
	gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
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

// Fun��o callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Callback para gerenciar eventos do teclado para teclas especiais (F1, PgDn, entre outras)
void SpecialKeys(int key, int x, int y)
        {
		switch (key) {
			case GLUT_KEY_LEFT :
							obsX -=100;
							break;
			case GLUT_KEY_RIGHT :
							obsX +=100;
							break;
			case GLUT_KEY_UP :
							obsY +=100;
							break;
			case GLUT_KEY_DOWN :
							obsY -=100;
							break;

			case GLUT_KEY_HOME :
							obsZ +=100;
							break;
			case GLUT_KEY_END :
							obsZ -=100;
							break;
		}
		glLoadIdentity();
		gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
        	glutPostRedisplay();
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
	glutMouseFunc(GerenciaMouse);
	glutSpecialFunc(SpecialKeys);
	Inicializa();
	glutMainLoop();


}
