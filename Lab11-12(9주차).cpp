//#include <gl/glut.h>
//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//using namespace std;
//
//void resize(int width, int height);
//void draw_axis(); // ���� �׸��� �Լ�.
//void draw(); // ��ü���� draw�Լ�
//void draw_can(); //can�� �׸��� �Լ�
//void draw_disk(); //disk�� �׸��� �Լ�
//void draw_teapot(); //�����ڸ� �׸��� �Լ�
//void draw_text(); //���ڿ��� ����ϴ� �Լ�
//void idle(); 
//void keyboard(unsigned char key, int x, int y);
//void draw_string(void *font, const char* str, float x, float y, float red, float green, float blue); //���ڿ��� ȭ�鿡 ǥ���ϴ� �Լ�
//
//int current_width = 0, current_height = 0; //������ ������ ���� �޾ƿ��� ���� �������� ����
//
//char my_string[255]; // ���ڿ� ������ ���� char�迭 ����
//
//char* Test = "Hi";
//
////�� ��ü���� ȸ������ �ٸ��� �ϱ� ���� ��� �ٸ� ���� ����
//double spin_disk = 0.01;
//double spin_teapot = 0.01;
//double spin_can = 0.01;
//
//GLUquadric *q;
//
//bool String_on = false; //�̸� ���� �¿��� ���
//bool Rotate_on = true;//ȸ�� �¿��� ���
//
//int main(int argc, char** argv)
//{
//	// ������ �ʱ�ȭ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//
//	glutDisplayFunc(draw);
//	glutKeyboardFunc(keyboard);
//	glutReshapeFunc(resize);
//	glutIdleFunc(idle);
//	
//	glutMainLoop();
//
//	return 0;
//}
//
//void idle()
//{
//	//ȸ�� ��尡 on�� ���� ȸ���Ѵ�
//	if (Rotate_on == true)
//	{
//		spin_disk = spin_disk + 0.8;
//		spin_can = spin_can + 0.4;
//		spin_teapot = spin_teapot + 0.1;
//		if (spin_disk > 360) spin_disk -= 360;
//		if (spin_can > 360) spin_can -= 360;
//		if (spin_teapot > 360) spin_teapot -= 360;
//	}
//	glutPostRedisplay();
//}
//
//void resize(int width, int height)
//{
//	glViewport(0, 0, width, height); // width�� height�� ����������� �� ���� , viewport�� Ortho2D�� ����(=���)
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / (float) height, 1, 500);
//	glMatrixMode(GL_MODELVIEW);
//
//	current_width = width; //������ ����� �̿��ϱ� ���� ���������� �̿��� ���� �����Ѵ�.
//	current_height = height; //width�� ���� �뵵
//}
//
//  //x, y, z �� ����
//void draw_axis() 
//{
//	glLineWidth(3);
//	
//	glBegin(GL_LINES);
//	
//	glColor3f(1, 0, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(7, 0, 0);
//
//	glColor3f(0, 1, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 7, 0);
//
//	glColor3f(0, 0, 1);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 7);
//	
//	glEnd();
//
//	glLineWidth(1); // ���̾� Ƽ�� ���� ���� �̿��� ��ü�� ������ �����ʱ� ���� �ʱⰪ���� �ʱ�ȭ
//}
//
//void draw_can()
//{
//	glViewport(0, 0, current_width / 2, current_height / 2); //�������� (0,0) ũ��� �������� 1/4
//	draw_axis();
//	glPushMatrix(); //�ٸ� ��ü�� ȸ���� ������ ���� �ʵ��� push-pop���� �����ش�
//	glRotatef(spin_can, 1, 0, 0);
//	q = gluNewQuadric();
//	glColor3f(0, 1, 1);
//	gluQuadricNormals(q, GLU_NONE);
//	gluCylinder(q, 0, 2, 5, 50, 50); // �Ǹ����� �׸���. Base ���� 0 �̹Ƿ� �������°� �׷�����.
//	glPopMatrix();
//	glFlush();
//	gluDeleteQuadric(q);
//}
//
//void draw_teapot()
//{
//	glViewport(current_width / 2, 0, current_width / 2, current_height / 2); //�������� (width/2 , 0) ũ��� �������� 1/4
//	draw_axis();
//	glPushMatrix(); //�ٸ� ��ü�� ȸ���� ������ ���� �ʵ��� push-pop���� �����ش�
//	glRotatef(spin_teapot, 0, 0, 1);
//	glColor3f(1, 1, 0);
//	glutWireTeapot(2);
//	glPopMatrix();
//	glFlush();
//}
//
//void draw_disk()
//{
//	glViewport(current_width / 2, current_height / 2, current_width /2, current_height/2); //�������� (width / 2 , height / 2) ũ��� �������� 1/4
//	gluLookAt(10, 10, 10, 0, 0, 0, 0, 1, 0); // ���� ó�� �׸��� Disk�� glLookAt�Լ� ����
//	draw_axis();
//	glPushMatrix(); //�ٸ� ��ü�� ȸ���� ������ ���� �ʵ��� push-pop���� �����ش�
//	glRotatef(spin_disk, 0, 1, 0);
//	glColor3f(1, 0, 0);
//	q = gluNewQuadric();
//	gluDisk(q, 1, 3, 30, 30);
//	glPopMatrix();
//	glFlush();
//	gluDeleteQuadric(q);
//}
//
////���ڿ��� �����ϴ� �Լ�
//void draw_string(void *font, const char* str, float x, float y, float red, float green, float blue)
//{
//	glPushAttrib(GL_LIGHTING_BIT);
//	glDisable(GL_LIGHTING);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity(); // ���� ��� �ʱ�ȭ
//	gluOrtho2D(-5, 5, -5, 5); // ���� ȭ���� ��ǥ�� (-5,-5) ~ (5, 5);
//	
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//	glColor3f(red, green, blue);
//	glRasterPos3f(x, y,0);
//	for (unsigned int i = 0; i < strlen(str); i++)	glutBitmapCharacter(font, str[i]);
//	glPopMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glMatrixMode(GL_MODELVIEW);
//	glPopAttrib();
//}
//
//void draw_text()
//{
//	glViewport(0, current_height / 2, current_width / 2, current_height / 2); //�������� (0,height / 2) ũ��� �������� 1/4
//	glLoadIdentity(); // ������ ȸ�� ��ȯ�� ����
//
//	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "12131649 Kwon-Sehoon", -5, 0, 1, 0, 0);
//
////	draw_string(GLUT_BITMAP_HELVETICA_18, "Multi-Viewprot Example!!", -5, 1, 0, 1, 5);
//
//	draw_string(GLUT_BITMAP_TIMES_ROMAN_10, Test, -5, 1, 0, 1, 5);
//
//	if (String_on == true)	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, my_string, -5, 2, 50, 30, 10);
//
//	glFlush();
//}
//
//void draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	draw_text();
//	draw_disk();
//	draw_can();
//	draw_teapot();
//
//	glutSwapBuffers();
//}
//
//
//void keyboard(unsigned char key, int x, int y)
//{
//	//'n'Ű�� ������ �� �۵�
//	if (key == 'i')
//	{
//		printf("Input your string\n");
//		gets_s(my_string);
//	}
//
//	//'n'Ű�� ������ �� �۵�
//	if (key == 'n')
//	{
//		if (String_on == false)
//		{
//			printf("String_on\n");
//			String_on = true; // ���ڿ� ��� ��� on. �ʱ� ���� off�̹Ƿ� ó�� nŰ ������ on
//		}
//		else
//		{
//			printf("StudentName_off\n");
//			String_on = false; 
//		}
//	}
//	//'s'Ű�� ������ �� �۵�
//	if (key == 's')
//	{
//		if (Rotate_on == false)
//		{
//			printf("Rotate_on\n");
//			Rotate_on = true; //ȸ�� ��� on. �ʱ� ���� on�� ù sŰ ������ off
//		}
//		else
//		{
//			printf("Rotate_off\n");
//			Rotate_on = false; // ȸ������� �� ���¿��� sŰ�� ������ ȸ�� ��� ����
//		}
//	}
//	glutPostRedisplay();
//}