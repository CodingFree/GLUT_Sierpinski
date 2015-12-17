#include <windows.h> 
#define GLUT_DISABLE_ATEXIT_HACK  
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/gl.h>
#include "Source.h"

void myinit()
{
	glClearColor(0.5, 0.7, 1.0, 1.0);
	glPointSize(10.0);
}

void drawTriangle(float *a, float *b, float *c, int degree) {
	glBegin(GL_TRIANGLES);
	GLfloat color[] = { 1, 1, 1 };
	if (degree % 2) {
			color[0] = 0;
			color[1] = 0;
			color[2] = 0;
	}

	glColor3f(color[0], color[1], color[2]);glVertex3f(a[0], a[1], 0);
	glColor3f(color[0], color[1], color[2]);glVertex3f(b[0], b[1], 0);
	glColor3f(color[0], color[1], color[2]);glVertex3f(c[0], c[1], 0);

	glEnd();
}

float getMiddle(float x, float y) {
	return (x + y) / 2;
}

void updateArray(float *a, float *b, float *c, int degree) {
	float a2[2]; 
	float b2[2]; 
	float c2[2];
	drawTriangle(a, b, c, degree);
	if (degree > 0) {
		degree = degree - 1;
		//Primero obtengo la mitad
		a2[0] = getMiddle(a[0], b[0]);
		a2[1] = getMiddle(a[1], b[1]);

		b2[0] = getMiddle(b[0], c[0]);
		b2[1] = getMiddle(b[1], c[1]);

		c2[0] = getMiddle(c[0], a[0]);
		c2[1] = getMiddle(c[1], a[1]);

		//Repinto
		updateArray(a2, b2, c2, degree);
	}

}

void drawCanvas() {
	int degree = 1;
	float a[] = { -1, -1 };
	float b[] = { 1, -1 };
	float c[] = { 0, 1 };

	glClear(GL_COLOR_BUFFER_BIT);

	//drawTriangle(a, b, c, degree);
	updateArray(a, b, c, degree);

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sierpinski Gasket");
	myinit();
	glutDisplayFunc(drawCanvas);
	glutMainLoop();

}