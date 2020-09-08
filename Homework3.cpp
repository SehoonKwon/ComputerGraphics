//#include <gl/glut.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// �Լ� ������Ÿ��
//void init(void);
//void idle(void);
//void draw_point(void);
//void draw_line(void);
//void draw_triangle(void);
//void draw_quadrangle(void);
//void draw(void);
//void mouse(int botton, int state, int x, int y);
//void keyboard(unsigned char key, int x, int y);
//void sub_menu_function(int option);
//void main_menu_function(int option);
//
////�������� ����
//enum shape { point = 1, line, triangle, quadrangle, clear }; // ��� ���ý� �˱� ���� ���������� ����
//enum Color_mode { Red = 1, Green, Blue };
//
//int count = 0, draw_mode, Color_mode = Red; // ���� ����, �׸�����, ��(�ʱ� �� ����);
//int x_point[10], y_point[10]; //��ǥ ����� ���� �迭
//
//// ��� On-Off�� ���� boolŸ�� ����
//bool antialiase_on = false; 
//bool StudentName_on = false;
//bool Rotate_on = false;
//
//double spin = 0.01;  // ȸ���� ���� ����
//
//
//int main(int argc, char** argv)
//{
//	int submenu1;
//
//	// ������ �ʱ�ȭ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//	init(); // ����� �ʱ�ȭ �Լ�
//
//	submenu1 = glutCreateMenu(sub_menu_function); //����޴� ����
//	glutAddMenuEntry("��", 1);
//	glutAddMenuEntry("��", 2);
//	glutAddMenuEntry("�ﰢ��", 3);
//	glutAddMenuEntry("�簢��", 4);
//	glutAddMenuEntry("�ʱ�ȭ", 5); // 5���� �׸��� �ִ� �޴� ����
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddSubMenu("list", submenu1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	//// Callback �Լ� ����
//	glutDisplayFunc(draw); // draw() -> ���� �׸��� �Լ�
//	glutMouseFunc(mouse);  // mouse -> ���콺 Ŭ�� �� ��ǥ���� ��Ÿ���� �Լ�
//	glutIdleFunc(idle);	// 
//	glutKeyboardFunc(keyboard); // Ű���� �ݹ� �Լ�
//
//								// Looping ����
//	glutMainLoop();
//
//	return 0;
//}
//
//void init(void)
//{
//	// ȭ���� �⺻������ blue ����
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	// ȭ�� ��ǥ ���� ����
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
//}
//
//void idle(void)
//{
//	//ȸ���϶�� ����� on�϶��� �۵�
//	if (Rotate_on == true)
//	{
//		spin = spin + 0.1;
//		if (spin > 360) spin -= 360;
//	}
//	glutPostRedisplay(); // ȭ�� �ٽ� ����
//}
//
//// ���� �׸��� �Լ�
//void draw_point()
//{
//	
//	glPointSize(30.0f); //���� ũ�� 30, �ʱ� ���� 1.0
//
//	glBegin(GL_POINTS);
//	for (int i = 0; i < count; i++)
//	{
//		glVertex2i(x_point[i], y_point[i]);
//	}
//	glEnd();
//
//	glFlush();
//}
//
//// ���� �׸��� �Լ�
//void draw_line()
//{
//	glBegin(GL_LINES);
//	for (int i = 0; i<count; i++)
//	{
//		glVertex2i(x_point[i], y_point[i]);
//	}
//	glEnd();
//
//	glFlush();
//}
//
//// �ﰢ���� �׸��� �Լ�
//void draw_triangle()
//{
//	glBegin(GL_TRIANGLES);
//	for (int i = 0; i<count; i++)
//	{
//		glVertex2i(x_point[i], y_point[i]);
//	}
//	glEnd();
//	
//	glFlush();
//}
//
//// �簢���� �׸��� �Լ�
//void draw_quadrangle()
//{
//	glBegin(GL_QUADS);
//	for (int i = 0; i<count; i++)
//	{
//		glVertex2i(x_point[i], y_point[i]);
//	}
//	glEnd();
//
//	glFlush();
//}
//
////���ڿ��� �����ϴ� �Լ�
//void draw_string(void *font, const char* str, int x, int y)
//{
//	unsigned int i;
//	glRasterPos2i(x, y);
//	for (i = 0; i < strlen(str); i++)
//	{
//		glutBitmapCharacter(font, str[i]);
//	}
//}
//
////����� ���� ��ο� �Լ�. �Լ����� �̿��� ���� �׸��� �׸����� �۵�
//void draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT); // ȭ�� �ʱ�ȭ
//
//	//�� ��忡 ���� �� ����
//	if (Color_mode == Red) glColor3f(1.0f, 0.0f, 0.0f);
//	else if (Color_mode == Green) glColor3f(0.0f, 1.0f, 0.0f);
//	else if (Color_mode == Blue) glColor3f(0.0f, 0.0f, 1.0f);
//
//	glMatrixMode(GL_MODELVIEW); //��� ����
//	glLoadIdentity(); //��� �ʱ�ȭ
//
//	//ȸ���� ���� ���
//	glPushMatrix();
//	glTranslatef(250, 250, 0); 
//	glRotatef(spin, 0, 0, 1); // ȸ��
//	glTranslatef(-250, -250, 0);
//
//	//��ο� ��忡 ���� ��� �׸��� �����ϴ� ����ġ��
//	switch (draw_mode)
//	{
//
//	case point:
//		draw_point();
//		break;
//
//	case line:
//		draw_line();
//		break;
//
//	case triangle:
//		draw_triangle();
//		break;
//
//	case quadrangle:
//		draw_quadrangle();
//		break;
//
//	default:
//		break;
//
//	}
//	glPopMatrix(); // push�� pop�� ¦. ȸ���� �������� �����ϱ� ���� ��Ʈ������ ��ο츸 ���Խ�Ŵ.
//
//	//�̸��� ���� �۾� on�϶� ȭ�鿡 ���ڿ� ����
//	if (StudentName_on == true)
//	{
//		glColor3f(1.0f, 1.0f, 0.0f);
//		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "12131649 Kwon-Sehoon", 10, 30);
//	}
//
//	//��Ƽ�ٸ��ֽ� �۾��� on�϶� ȭ�鿡 ��Ƽ�ٸ��ֽ��� �Ѵٴ� ���ڿ� ����
//	if (antialiase_on == true)
//	{
//		glColor3f(1.0f, 0.0f, 1.0f);
//		draw_string(GLUT_BITMAP_HELVETICA_18, "Antialiasing", 400, 475);
//	}
//
//	//ȸ�� �۾��� on�϶� ȸ���ϴ� ���̶�� ���ڿ� ����
//	if (Rotate_on == true)
//	{
//		glColor3f(1.0f, 1.0f, 1.0f);
//		draw_string(GLUT_BITMAP_HELVETICA_18, "Rotate", 400, 30);
//	}
//
//	glFlush(); // ��ɾ�� ��� ���� �� ���
//	glutSwapBuffers(); // ����Ʈ ���ۿ� ����۸� ��������.
//}
//
////���콺 Ŭ���� �۵��ϴ� �ݹ��Լ�
//void mouse(int button, int state, int x, int y)
//{
//	//���� ��ư�� ������ ���� �۾�
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		printf("%d %d\n", x, 500 - y);
//		x_point[count] = x;
//		y_point[count] = 500 - y; // ������ ���� ���� ��ǥ 0.0 �̱⿡ �Ʒ����� 0.0���� �����ϸ� ���콺�� ��ǥ�޴� �Լ��� �ٲ��־�� ��.
//		count++; // ���� ���� ����
//	}
//	glutPostRedisplay(); // ȭ�� �����
//}
//
////Ű���� �ݹ� �Լ�
//void keyboard(unsigned char key, int x, int y)
//{
//	printf("Pressed %c\n", key); //���� Ű ǥ��
//
//	//'a'Ű�� ������ �� �۵�
//	if (key == 'a')
//	{
//		if (antialiase_on == false) antialiase_on = true; // ��Ƽ�ٸ��ֽ� on , �ʱ� ���� off�� ù aŰ ������ ��.
//		else antialiase_on = false; //��Ƽ�ٸ��ֽ��� off���¿��� aŰ�� ������ ������ �ٲ�.
//
//		//��Ƽ�ٸ��ֽ� �۾��� on�� �� ��Ƽ�ٸ��ֽ� ��� ����
//		if (antialiase_on == true)
//		{
//			glEnable(GL_BLEND);
//			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//			glEnable(GL_POINT_SMOOTH);
//			glEnable(GL_LINE_SMOOTH);
//			glEnable(GL_POLYGON_SMOOTH);
//		}
//		//��Ƽ�ٸ��ֽ� �۾��� off�� �� ��Ƽ�ٸ��ֽ� ��� ����
//		else
//		{
//			glDisable(GL_BLEND);
//			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//			glDisable(GL_POINT_SMOOTH);
//			glDisable(GL_LINE_SMOOTH);
//			glDisable(GL_POLYGON_SMOOTH);
//		}
//	}
//
//	//'n'Ű�� ������ �� �۵�
//	if (key == 'n')
//	{
//		if (StudentName_on == false) StudentName_on = true; // �̸� ���� ��� on. �ʱ� ���� off�� ù nŰ ���� �� ��
//		else StudentName_on = false; // �̸� ���� ����� �� ������ �� nŰ�� ������ ����
//	}
//
//	//'s'Ű�� ������ �� �۵�
//	if (key == 's')
//	{
//		if (Rotate_on == false) Rotate_on = true; //ȸ�� ��� on. �ʱ� ���� off�� ù sŰ ������ ��
//		else Rotate_on = false; // ȸ������� �� ���¿��� sŰ�� ������ ȸ�� ��� ����
//	}
//
//	//������ Ű�� ���� �� ��ȭ
//	if (key == 'r') Color_mode = Red;
//	else if (key == 'g') Color_mode = Green;
//	else if (key == 'b') Color_mode = Blue;
//
//	glutPostRedisplay();
//}
//
////����޴� �ɼǿ� ���� ���
//void sub_menu_function(int option)
//{
//	//����޴����� �� �޴��� ���� �׸��� ��带 ������.
//	switch (option)
//	{
//	case point:
//		printf("you select point\n");
//		draw_mode = point;
//		break;
//
//	case line:
//		printf("you slect line\n");
//		draw_mode = line;
//		break;
//
//	case triangle:
//		printf("you select triangle\n");
//		draw_mode = triangle;
//		break;
//
//	case quadrangle:
//		draw_mode = quadrangle;
//		printf("you select quadrangle\n");
//		break;
//
//	case clear:
//		count = 0;
//		break;
//
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//
////���θ޴��� ���� ���. Quit�� ������ ���α׷� ����.
//void main_menu_function(int option)
//{
//	printf("Submenu %d has been selected\n", option);
//	if (option == 999) exit(0);
//}