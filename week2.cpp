//#include <gl/glut.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//void init(void);
//void draw(void);
//
//
//int main(int argc, char** argv)
//{
//
//	// ������ �ʱ�ȭ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//	init(); // ����� �ʱ�ȭ �Լ�
//
//
//	// Callback �Լ� ����
//	glutDisplayFunc(draw); // draw() -> ���� �׸��� �Լ�
//
//	// Looping ����
//	glutMainLoop();
//
//	return 0;
//}
//
//void init(void)
//{
//	// ȭ���� �⺻������ blue ����
//	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
//	
//	// ȭ�� ��ǥ ���� ����
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
//}
//
//void draw_point(void)
//{
//	// ���� ���� RED
//	glColor3f(1.0f, 0.0f, 0.0f);
//
//	// ���� ũ�� ���� ( �ʱⰪ�� 1.0)
//	glPointSize(4.0f);
//
//	glBegin(GL_POINTS);
//	glVertex2i(50, 50);
//	glVertex2i(100, 150);
//	glVertex2i(200, 200);
//	glVertex2i(350, 300);
//	glVertex2i(450, 300);
//	glEnd();
//}
//
//void draw_line(void)
//{
//	/*glLineWidth(2.0f);
//	glEnable(GL_LINE_STIPPLE);
//	glLineStipple(3, 0xAAAA);*/
//
//	// ���� ������ ���������
//	glColor3f(1.0f, 1.0f, 0.0f);
//	glBegin(GL_LINE_LOOP);
//	glVertex2i(50, 50);
//	glVertex2i(250, 450);
//	glVertex2i(300, 450);
//	glVertex2i(400, 100);
//	glEnd();
//}
//
//void draw_Left_triangle(void)
//{
//	/*glPolygonMode(GL_FRONT, GL_LINE);
//	glFrontFace(GL_CCW);*/
//	/*glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);*/
//
//	// ���� ������ ���������
//	//glEnable(GL_BLEND); // ���� ���� on
//	glDisable(GL_BLEND); // ���� ���� off
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glColor4f(1.0f, 1.0f, 0.0f,0.75);
//	glBegin(GL_TRIANGLES);
//	glVertex2i(100, 300);
//	glVertex2i(300, 200);
//	glVertex2i(100, 100);
//	glEnd();
//}
//
//void draw_Right_triangle(void)
//{
//	// ���� ������ û�ϻ�����
//	//glEnable(GL_BLEND);
//	glDisable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glColor4f(0.0f, 1.0f, 1.0f, 0.75);
//	glBegin(GL_TRIANGLES);
//	glVertex2i(400, 300);
//	glVertex2i(200, 200);
//	glVertex2i(400, 100);
//	glEnd();
//}
//
//void draw(void)
//{
//	// ȭ���� �����ϰ� �����
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//draw_point();
//	//draw_line();
//	draw_Left_triangle();
//	draw_Right_triangle();
//	
//	glFlush();
//}
