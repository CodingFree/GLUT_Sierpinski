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

void setColor(float *color, float value) {
	color[0] = value;
	color[1] = value;
	color[2] = value;
}

void drawTriangle(float *a, float *b, float *c, float *color) {
	glBegin(GL_TRIANGLES);

	glColor3f(color[0], color[1], color[2]);glVertex3f(a[0], a[1], 0);
	glColor3f(color[0], color[1], color[2]);glVertex3f(b[0], b[1], 0);
	glColor3f(color[0], color[1], color[2]);glVertex3f(c[0], c[1], 0);

	glFlush();
	glEnd();
}

float getMiddle(float x, float y) {
	return (x + y) / 2;
}

void sierpinski(float *a, float *b, float *c, float degree) {
	float ab[2]; 
	float bc[2]; 
	float ca[2];

	glColor3f(1, 1, 1);
	
	if (degree > 0) {
		degree = degree - 1;

		//Primero obtengo la mitad
		ab[0] = getMiddle(a[0], b[0]);
		ab[1] = getMiddle(a[1], b[1]);

		bc[0] = getMiddle(b[0], c[0]);
		bc[1] = getMiddle(b[1], c[1]);

		ca[0] = getMiddle(c[0], a[0]);
		ca[1] = getMiddle(c[1], a[1]);

		//Repinto
		sierpinski(a, ab, ca, degree);
		sierpinski(b, bc, ab, degree);
		sierpinski(c, ca, bc, degree);

		float color[3];
		setColor(color, 1);
		drawTriangle(ab, bc, ca, color);
	}

}

void drawCanvas() {
	int degree = 5;
	float a[] = { -1, -1 };
	float b[] = { 1, -1 };
	float c[] = { 0, 1 };
	float color[3];

	glClear(GL_COLOR_BUFFER_BIT);

	//Primero dibujo la base negra.
	setColor(color, 0);
	drawTriangle(a, b, c, color);

	sierpinski(a, b, c, degree);

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