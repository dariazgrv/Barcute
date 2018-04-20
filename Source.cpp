#include <windows.h>  // sunt mentionate fisiere (biblioteci) care urmeaza sa fie incluse
#include <gl/freeglut.h> // nu trebuie uitat freeglut.h (sau glut.h sau gl.h & glu.h)
#include <math.h>

double i = 0.0;
double j = 0.0;
double iSoare = 0.0;
double alpha = 1.0;
double alphaSoare = 0.001;
double alphaRaza = 0.001;

const double TWO_PI = 6.2831853;

GLsizei winWidth = 500, winHeight = 500;
GLuint regHex, regHex2;
static GLfloat rotTheta = 0.0;

double raza = 1;
bool temporizator = true;

class scrPt
{
public:
	GLint x, y;
};



void init(void)  // initializare fereastra de vizualizare
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // precizeaza culoarea de fond a ferestrei de vizualizare

	glMatrixMode(GL_PROJECTION);  // se precizeaza este vorba de o reprezentare 2D, realizata prin proiectie ortogonala
	gluOrtho2D(0.0, 800.0, 0.0, 600.0); // sunt indicate coordonatele extreme ale ferestrei de vizualizare

	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	regHex = glGenLists(1);
	
	glNewList(regHex, GL_COMPILE);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (k = 0; k < 80; k++)
	{
		hexTheta = TWO_PI * k / 80;
		hexVertex.x = 300 + 50 * cos(hexTheta);
		hexVertex.y = 300 + 50 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
	}
	glEnd();
	glEndList();
}
void desen(void) // procedura desenare  
{

	// segmentele
	glClear(GL_COLOR_BUFFER_BIT);

	
	glPushMatrix();
	glScalef(raza, raza, 1);
	glTranslated(iSoare, 100.0, 0.0);
	
	glRotated(j, 0.0, 0.0, 1.0);
	glTranslated(-iSoare, -100.0, 0.0);
	
	glColor3f(1.0, 1.0, 0.0);
	glCallList(regHex);
	glPopMatrix();
	

	
	

	
	//glCallList(regHex); 

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(-20, 0);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2i(1920, 0);
	glVertex2i(1920, 250);
	glVertex2i(-20, 250);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(25, 25);
	glVertex2i(100, 25);
	glVertex2i(125, 50);
	glVertex2f(12.2, 50);
	glVertex2i(25, 25);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 50);
	glVertex2i(80, 130);

	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 80);
	glVertex2i(115, 80);
	glVertex2i(80, 130);
	glEnd();



	glPushMatrix();
	glTranslatef(i, 100, 0);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(25, 25);
	glVertex2i(100, 25);
	glVertex2i(125, 50);
	glVertex2f(12.2, 50);
	glVertex2i(25, 25);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 50);
	glVertex2i(80, 130);

	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 80);
	glVertex2i(115, 80);
	glVertex2i(80, 130);
	glEnd();
	glPopMatrix();

	glFlush();



	/*glPushMatrix();
	glTranslated(i, 100.0, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(25, 25);
	glVertex2i(100, 25);
	glVertex2i(125, 50);
	glVertex2f(12.2, 50);
	glVertex2i(25, 25);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 50);
	glVertex2i(80, 130);

	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(80, 80);
	glVertex2i(115, 80);
	glVertex2i(80, 130);
	glEnd();


	glPopMatrix();*/


	glutSwapBuffers();


	glFlush(); // proceseaza procedurile OpenGL cat mai rapid
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20.0, 780.0, 0.0, 600.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void miscad(void)
{
	i = i + alpha;
	iSoare = iSoare + alphaSoare;
	raza = raza +0.001;
	if (i > 750.0 )
		alpha = 0.1;
	else if (i < 0.0 )
		alpha = 0.1;

	if (iSoare > 750.0)
		alphaSoare = -1.0;
	   
	else
		if (iSoare < 0.0)
			alphaSoare = -1.0;

	if (raza > 1.3 && temporizator) {
		alphaRaza = 0;
		raza = 1;
		temporizator = !temporizator;
	}

	j = j + 0.5;

	glutPostRedisplay();
}


void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			alpha = -1.0; glutIdleFunc(miscad);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			alpha = 1.0; glutIdleFunc(miscad);
		break;
	default:
		break;
	}
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv); // initializare GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // se utilizeaza un singur buffer | modul de colorare RedGreenBlue  default)
	glutInitWindowPosition(0, 0); // pozitia initiala a ferestrei de vizualizare (in coordonate ecran)
	glutInitWindowSize(1920, 800); // dimensiunile ferestrei
	glutCreateWindow("Puncte & Segmente"); // creeaza fereastra, indicand numele ferestrei de vizualizare - apare in partea superioara

	init(); // executa procedura de initializare
	glClear(GL_COLOR_BUFFER_BIT); // reprezentare si colorare fereastra de vizualizare
	glutDisplayFunc(desen); // procedura desen este invocata ori de cate ori este nevoie
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glutMainLoop(); // ultima instructiune a programului, asteapta (eventuale) noi date de intrare
}