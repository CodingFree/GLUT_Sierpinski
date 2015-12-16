#include <windows.h> 
#define GLUT_DISABLE_ATEXIT_HACK  
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/gl.h>
#include "Source.h"

#define DEEP 2;

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glPointSize(10.0);
}

void drawSierpinski() {
	float a[] = { -1, -1 };
	float b[] = {  1, -1 };
	float c[] = { 0, 1 };
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);glVertex3f(a[0], a[1], 0);
	glColor3f(0, 0, 0);glVertex3f(b[0], b[1], 0);
	glColor3f(0, 0, 0);glVertex3f(c[0], c[1], 0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sierpinski Gasket");
	myinit();
	glutDisplayFunc(drawSierpinski);
	glutMainLoop();

}