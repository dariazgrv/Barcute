#include <windows.h>  // sunt mentionate fisiere (biblioteci) care urmeaza sa fie incluse
#include <gl/freeglut.h> // nu trebuie uitat freeglut.h (sau glut.h sau gl.h & glu.h)
#include <math.h>
#include <iostream>
using namespace std;
double i = 0.0;
double j = 0.0;
double iSoare = 0.0;
double alpha = 1.0;
double alphaSoare = 0.018, unSoare = 0;
double alphaRaza = 0.001;
double angle = 0;

const double TWO_PI = 6.2831853;

GLsizei winWidth = 500, winHeight = 500;
GLuint regHex;
static GLfloat rotTheta = 0.0;


double raza = 1;
bool temporizator = true, translatie1 = false, translatie2 = false;
int stop = 200;
class scrPt
{
public:
	GLint x, y;
};

void fish2();


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
	
	
	glBegin(GL_POLYGON);
	for (k = 0; k < 80; k++)
	{
		hexTheta = TWO_PI * k / 80;
		
		hexVertex.x = 0 + 30 * cos(hexTheta);
		hexVertex.y = 250 + 30 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
	}
	glEnd();
	glEndList();
}
void desen(void) // procedura desenare  
{




	// segmentele
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2i(-20, 250);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(1920, 250);
	glVertex2i(1920, 1080);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	glVertex2i(-20, 1080);
	glColor3f(1.0, 1.0, 1.0);
	glEnd();



	glPushMatrix();
	////glScalef(raza, raza, 1);
	//glTranslated(iSoare, 100.0, 0.0);
	//
	////glRotated(j, 0.0, 0.0, 1.0);
	//glTranslated(iSoare, -100.0, 0.0);
	//
	//glColor3f(1.0, 1.0, 0.0);
	//if()
	//iSoare = iSoare + 1;
	//glTranslated(300, 300, 0);

	//glTranslated(-iSoare, -iSoare, 0);



	glRotated(angle, 0, 0, 1);
	glTranslated(iSoare * 3, iSoare * 3, 0);
	if (angle>-65)
		angle = angle - 0.005;
	glColor3f(1.0, 1.0, 0.0);
	
	//glTranslated(-300, -300, 0);
	//glTranslated(-iSoare, -iSoare, 0);
	glCallList(regHex);
	glPopMatrix();

//avion

	glBegin(GL_POLYGON);
	glColor3f(1.000, 0.973, 0.863);
	glVertex2i(100,500);
	
	glVertex2i(220,500);
	glColor3f(0.961, 0.871, 0.702);
	glVertex2i(220,550);
	glVertex2i(100,550);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.863, 0.078, 0.235);
	glVertex2i(130,450);

	glVertex2i(170,450);
	glColor3f(0.545, 0.000, 0.000);
	glVertex2i(190,510);
	glVertex2i(150,510);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.863, 0.078, 0.235);
	glVertex2i(100,550);

	glVertex2i(130, 550);
	glColor3f(0.545, 0.000, 0.000);
	glVertex2i(110,580);
	glColor3f(0.545, 0.000, 0.000);
	glVertex2i(100, 580);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.863, 0.078, 0.235);
	glVertex2i(150,550);

	glVertex2i(180, 550);
	glColor3f(0.545, 0.000, 0.000);
	glVertex2i(160,570);
	glVertex2i(130,570);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.000, 0.973, 0.863);
	glVertex2i(220,525);

	glVertex2i(250,525);
	glVertex2i(250,530);

	glVertex2i(220,550);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.863, 0.078, 0.235);
	glVertex2i(220, 525);

	glVertex2i(250, 525);
	glVertex2i(250, 510);
	glColor3f(0.545, 0.000, 0.000);
	glVertex2i(220, 500);
	glEnd();//end avion

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
	glColor3f(0.545, 0.271, 0.075);//Brown
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
	glColor3f(0.961, 0.871, 0.702);
	glVertex2i(80, 80);
	glVertex2i(115, 80);
	glVertex2i(80, 130);
	glEnd();



	glPushMatrix();
	glTranslatef(i, 100, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.545, 0.271, 0.075);
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
	glColor3f(0.961, 0.871, 0.702);
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
	if (translatie2)
		unSoare -= alphaSoare;
	raza = raza + 0.001;
	if (i > 750.0)
		alpha = 0.1;
	else if (i <= 0.0)
		alpha = 0.1;
	

	/*if (iSoare > 250)
	alphaSoare = -0.05;

	else
	if (iSoare <= 0.0)
	alphaSoare = 0.05;*/

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
		{
			alpha = -1.0; glutIdleFunc(miscad);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{
			alpha = 1.0; glutIdleFunc(miscad);
		}
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