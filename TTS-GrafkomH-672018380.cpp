#include <iostream>
#include <GL/freeglut.h>

void printCircleHorizontal(float x, float y, float radius) {
	int triangleAmount = 20;
	float twicePI = 2.0f * 3.14;
	float k = 0.0;

	for (int j = 0; j < 2; ++j, k += 3.0) {
		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(199, 183, 114);
		glVertex2f(x + k, y);
		for (int i = 0; i <= triangleAmount; ++i) {
			glVertex2f(
				x + k + (radius * cos(i * twicePI / triangleAmount)),
				y + (radius * sin(i * twicePI / triangleAmount))
			);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(61, 43, 31);
		glVertex2f(x + k, y);
		for (int i = 0; i <= triangleAmount; ++i) {
			glVertex2f(
				x + k + ((radius - 0.15) * cos(i * twicePI / triangleAmount)),
				y + ((radius - 0.15) * sin(i * twicePI / triangleAmount))
			);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(255, 255, 255);
		glVertex2f(x + k, y);
		for (int i = 0; i <= triangleAmount; ++i) {
			glVertex2f(
				x + k + ((radius - 0.3) * cos(i * twicePI / triangleAmount)),
				y + ((radius - 0.3) * sin(i * twicePI / triangleAmount))
			);
		}
		glEnd();
	}
}

void printSquare() {
	float l = 0.0;

	for (int i = 0; i < 2; ++i, l -= 3.5) {
		for (int j = 0, k=0; j < 3; ++j, k+=3) {
			glBegin(GL_POLYGON);
			glColor3ub(255, 255, 255);
			glVertex2f(1.0 + k, 6.9 + l);
			glVertex2f(0.0 + k, 5.75 + l);
			glVertex2f(1.0 + k, 4.6 + l);
			glVertex2f(2.0 + k, 5.75 + l);
			glEnd();

			glLineWidth(7.0);
			glBegin(GL_LINE_LOOP);
			glColor3ub(199, 183, 114);
			glVertex2f(1.0 + k, 6.625 + l);
			glVertex2f(0.25 + k, 5.75 + l);
			glVertex2f(1.0 + k, 4.875 + l);
			glVertex2f(1.775 + k, 5.75 + l);
			glEnd();

			glBegin(GL_POLYGON);
			glColor3ub(199, 183, 114);
			glVertex2f(1.0 + k, 6.3 + l);
			glVertex2f(0.55 + k, 5.75 + l);
			glVertex2f(1.0 + k, 5.20 + l);
			glVertex2f(1.5 + k, 5.75 + l);
			glEnd();
		}
	}
}

void printDoubleXVertical(float x1, float x2, float x3) {
	glLineWidth(15.0);
	glPointSize(13.0);

	float j = 0.0;

	for (int i = 0; i < 2; ++i, j += 3.5) {
		glBegin(GL_LINE_LOOP);
		glColor3ub(199, 183, 114);
		glVertex2f(x1, 6.75 - j);
		glVertex2f(x2, 5.75 - j);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3ub(199, 183, 114);
		glVertex2f(x1, 5.75 - j);
		glVertex2f(x2, 6.75 - j);
		glEnd();

		glBegin(GL_POINTS);
		glColor3ub(255, 255, 255);
		glVertex2f(x3, 6.25 - j);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3ub(199, 183, 114);
		glVertex2f(x1, 5.75 - j);
		glVertex2f(x2, 4.75 - j);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3ub(199, 183, 114);
		glVertex2f(x1, 4.75 - j);
		glVertex2f(x2, 5.75 - j);
		glEnd();

		glBegin(GL_POINTS);
		glColor3ub(255, 255, 255);
		glVertex2f(x3, 5.25 - j);
		glEnd();
	}
}

void printDoubleXHorizontal(float y1, float y2, float y3) {
	glLineWidth(15.0);
	glPointSize(13.0);

	for (int i = 0, j = 0; i < 3; ++i, j+=3) {
		glBegin(GL_LINE_LOOP);
		glColor3ub(199, 183, 114);
		glVertex2f(0.0 + j, y1);
		glVertex2f(1.0 + j, y2);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3ub(199, 183, 114);
		glVertex2f(0.0 + j, y2);
		glVertex2f(1.0 + j, y1);
		glEnd();

		glBegin(GL_POINTS);
		glColor3ub(255, 255, 255);
		glVertex2f(0.5 + j, y3);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3ub(199, 183, 114);
		glVertex2f(1.0 + j, y1);
		glVertex2f(2.0 + j, y2);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3ub(199, 183, 114);
		glVertex2f(2.0 + j, y1);
		glVertex2f(1.0 + j, y2);
		glEnd();

		glBegin(GL_POINTS);
		glColor3ub(255, 255, 255);
		glVertex2f(1.5 + j, y3);
		glEnd();
	}
}

void wrappingComponent() {
	glBegin(GL_QUADS);
	glColor3ub(61, 43, 31);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 8.0);
	glVertex2f(8.0, 8.0);
	glVertex2f(8.0, 0.0);
	glEnd();

	printDoubleXHorizontal(8.0, 7.0, 7.5);
	printDoubleXHorizontal(4.5, 3.5, 4.0);
	printDoubleXHorizontal(1.0, 0.0, 0.5);

	printDoubleXVertical(2.0, 3.0, 2.5);
	printDoubleXVertical(5.0, 6.0, 5.5);

	printSquare();

	printCircleHorizontal(2.5, 7.5, 0.5);
	printCircleHorizontal(2.5, 4.0, 0.5);
	printCircleHorizontal(2.5, 0.5, 0.5);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	wrappingComponent();

	glFlush();
}

void initGL() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 8.0f, 0.0f, 8.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TTS DOSEN GRAFKOM H - 672018380");
	glutDisplayFunc(display);

	initGL();

	glutMainLoop();

	return 0;
}