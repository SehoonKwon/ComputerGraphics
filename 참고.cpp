//#include <stdlib.h> 
//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h> //idle func ����
//#include <string.h>
//
//
//int iDrawMode = 0; //��������, �׸��� ��带 ���� ����
//int iNumPoints = 0;//���° ���콺 Ŭ���� �ִ����� ������ ����
//int xaxis[100];
//int yaxis[100];
//int color = 0;// RGB���� ��ȯ�� ���� ����
//int The_Num;//������ � �׷������� ������ ������ ���´�.
//int Change_color[100];
//double Change_alpha[100];
//
//double spin = 0;
//double distance = 0;
//
//bool Antialiase_on = false;// ��Ƽ���ϸ������ ON_OFF�� ���� ����
//bool Character_on = false; // ���� ��� ON_OFF�� ���� ����
//
//bool Rotation_on = false;// ȸ���� ON_OFF �� ���� ����
//bool Translation_on = false;//�����̵��� ON_OFF �� ���� ����
//
//
//void Init(void);
//void idle(void);
//void drawString(void * font, const char* str, int x, int y);
//void drawPoint(void);
//void drawLine(void);
//void drawPolygon(void);
//void drawTriangle(void);
//void drawQuad(void);
//void draw(void);
//void mouse(int button, int state, int x, int y);
//void motion(int x, int y);
//void keyboard(unsigned char key, int x, int y);
//void subsub_menu_function1(int option);
//void subsub_menu_function2(int option);
//void sub_menu_function1(int option);
//void main_menu_function(int option);
//
//
//int main(int argc, char** argv)
//{
//
//	int subsubmenu1;
//	int subsubmenu2;
//	int submenu1;
//
//	////////////////// ��ǥ�� ���� ��ȯ, ���ĺ����� �ϱ� ���� �迭�� �ʱ�ȭ �����ش�./////////////////////
//	for (int i = 0; i<100; i++)
//	{
//		Change_alpha[i] = 1;
//		Change_color[i] = 0;
//		xaxis[i] = 0;
//		yaxis[i] = 0;
//	}
//
//	///////////////// window �ʱ�ȭ /////////////////
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First Gl Program");
//	Init(); //����� �ʱ�ȭ �Լ�
//
//			////////////////////// �˾��޴� ���� �� �߰� ///////////////////////////
//	subsubmenu1 = glutCreateMenu(subsub_menu_function1);
//	glutAddMenuEntry("GL_LINES", 21);
//	glutAddMenuEntry("GL_LINE_STRIP", 22);
//	glutAddMenuEntry("GL_LINE_LOOP", 23); //3���� �׸��� �ִ� �޴� ����
//
//	subsubmenu2 = glutCreateMenu(subsub_menu_function2);
//	glutAddMenuEntry("GL_TRIANGLES", 31);
//	glutAddMenuEntry("GL_TRIANGLE_STRIP", 32);
//	glutAddMenuEntry("GL_QUADS", 33);
//	glutAddMenuEntry("GL_POLYGON", 34);
//
//	submenu1 = glutCreateMenu(sub_menu_function1);
//	glutAddMenuEntry("Point Draw", 1);
//	glutAddSubMenu("Line Draw", subsubmenu1);
//	glutAddSubMenu("Polygon Draw", subsubmenu2);
//
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Clear", 41);
//	glutAddMenuEntry("Antialiasing", 42);
//	glutAddMenuEntry("Character Print", 43);
//	glutAddSubMenu("Draw mode", submenu1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	//////////////////Call back �Լ� ����//////////////////
//
//	glutDisplayFunc(draw); //draw() ���� �׸����Լ�
//	glutMouseFunc(mouse); //���콺 �Է�ó��
//	glutMotionFunc(motion); //���콺 ������ ó��
//	glutKeyboardFunc(keyboard); //Ű���� �Է�ó��
//
//	glutIdleFunc(idle); //idle function ó��
//
//
//						//////////////////// Looping ���� ///////////////////////
//	glutMainLoop();
//
//	return 0;
//}
//
//void Init(void)
//{
//	///////////////////// ȭ���� �⺻�� ���� (RGB, alpha) //////////////////////////
//	glClearColor(0.0f, 0.0f, 0.5f, 0.0f);
//	//ȭ�� ��ǥ���� ����
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
//}
//
//void idle(void)
//{
//	///////////////////////////��ü�� ������ animation ������ �̿�///////////////////////////
//	//printf("%d second has elapsed since the system was started \n", GetTickCount()/1000); //���� ���������
//
//	if (Rotation_on == true)
//	{
//		spin = spin + 0.5;
//		if (spin > 360)
//		{
//			spin -= 360; // 360�� ���� spin�� �������ְڴ�
//		}
//	}
//	if (Translation_on == true)
//	{
//		distance = distance + 0.5;
//		if (distance>500)
//		{
//			distance -= 1000; // ������ ȭ�� ������ �� �Ŀ� �ٽ� ����ȭ�鿡�� ��Ÿ���� �ϹǷ�.
//		}
//	}
//	glutPostRedisplay();
//}
/////////////// character ����� ���� �Լ� ///////////////////////////
//void drawString(void * font, const char* str, int x, int y)
//{
//	unsigned int i;
//	glRasterPos2i(x, y);
//	for (i = 0; i<strlen(str); i++)
//	{
//		glutBitmapCharacter(font, str[i]);
//	}
//
//}
//
//void drawPoint(void)
//{
//	//���� ����
//	//glColor3f(1.0f, 1.0f, 0.0f);
//	//���� ũ�� (�ʱⰪ 1.0)
//	glPointSize(20.0f);
//	switch (iDrawMode)
//	{
//	case 1:
//
//		glBegin(GL_POINTS); //�׸��� ��ǥ�� ������ â���� ������� ��ǥ�� y ���� �ٸ�
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//	}
//	glutPostRedisplay();
//}
//
//void drawLine(void)
//{
//	glLineWidth(10.0f); //�� ����
//	glEnable(GL_LINE_STIPPLE);//�ٸ�� ���� ���
//	glLineStipple(3, 0xAAAA); //�� ��� ����
//	switch (iDrawMode)
//	{
//	case 21:
//	{
//		glBegin(GL_LINES);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	case 22:
//	{
//		glBegin(GL_LINE_STRIP);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	case 23:
//	{
//		glBegin(GL_LINE_LOOP);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	}
//	glutPostRedisplay();
//}
//
//void drawTriangle(void)
//{
//	//////glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // �׸��� ��� ����, ȿ���ٸ�� point���� line���� ��fill����
//	//////glFrontFace(GL_CCW); //������� �ո����� ���ϴ� default �� CCW
//	//////glCullFace(GL_FRONT);//�ո��� �������� �޸��� �������� �յ� ��� ���� ����
//	//�ٷ� ������ �Լ��� ����Ҷ�, glEnable(GL_CULL_FACE);�� ���¸� on�ؾ���
//
//	glColor3f(1.0f, 1.0f, 0.0f); //�����
//	if (Antialiase_on == false)
//	{
//		glDisable(GL_BLEND);//alpha blending OFF
//	}
//	else if (Antialiase_on == true)
//	{
//		glEnable(GL_BLEND);   //alpha blending ON
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	}
//	switch (iDrawMode)
//	{
//	case 31:
//	{
//		glBegin(GL_TRIANGLES);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			if (Change_color[t / 3] == 0)
//			{
//				glColor4f(1.0f, 1.0f, 0.0f, Change_alpha[t / 3]);
//			}
//			else if (Change_color[t / 3] == 1)
//			{
//				glColor4f(1.0f, 0.0f, 0.0f, Change_alpha[t / 3]);
//			}
//			else if (Change_color[t / 3] == 2)
//			{
//				glColor4f(0.0f, 1.0f, 0.0f, Change_alpha[t / 3]);
//			}
//			else if (Change_color[t / 3] == 3)
//			{
//				glColor4f(0.0f, 0.0f, 1.0f, Change_alpha[t / 3]);
//			}
//			else if (Change_color[t / 3] == 4)
//			{
//				glColor4f(0.0f, 1.0f, 1.0f, Change_alpha[t / 3]);
//			}
//			else if (Change_color[t / 3] == 5)
//			{
//				glColor4f(1.0f, 0.0f, 1.0f, Change_alpha[t / 3]);
//			}
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	case 32:
//	{
//		glBegin(GL_TRIANGLE_STRIP);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			if (Change_color[t / 3] == 0)
//			{
//				glColor3f(1.0f, 1.0f, 0.0f);
//			}
//			else if (Change_color[t / 3] == 1)
//			{
//				glColor3f(1.0f, 0.0f, 0.0f);
//			}
//			else if (Change_color[t / 3] == 2)
//			{
//				glColor3f(0.0f, 1.0f, 0.0f);
//			}
//			else if (Change_color[t / 3] == 3)
//			{
//				glColor3f(0.0f, 0.0f, 1.0f);
//			}
//			else if (Change_color[t / 3] == 4)
//			{
//				glColor3f(0.0f, 1.0f, 1.0f);
//			}
//			else if (Change_color[t / 3 == 5])
//			{
//				glColor3f(1.0f, 0.0f, 1.0f);
//			}
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	}
//	glutPostRedisplay();
//}
//
//void drawQuad(void)
//{
//	if (Antialiase_on == false)
//	{
//		glDisable(GL_BLEND);//alpha blending OFF
//
//	}
//	if (Antialiase_on == true)
//	{
//		glEnable(GL_BLEND);   //alpha blending ON
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	}
//
//	glColor3f(1.0f, 1.0f, 0.0f); //�̰Ŵ� �� ���ذ���??
//	switch (iDrawMode)
//	{
//	case 33:
//	{
//		glBegin(GL_QUADS);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			if (Change_color[t / 4] == 0)
//			{
//				glColor4f(1.0f, 1.0f, 0.0f, Change_alpha[t / 4]);
//			}
//			else if (Change_color[t / 4] == 1)
//			{
//				glColor4f(1.0f, 0.0f, 0.0f, Change_alpha[t / 4]);
//			}
//			else if (Change_color[t / 4] == 2)
//			{
//				glColor4f(0.0f, 1.0f, 0.0f, Change_alpha[t / 4]);
//			}
//			else if (Change_color[t / 4] == 3)
//			{
//				glColor4f(0.0f, 0.0f, 1.0f, Change_alpha[t / 4]);
//			}
//			else if (Change_color[t / 4] == 4)
//			{
//				glColor4f(0.0f, 1.0f, 1.0f, Change_alpha[t / 4]);
//			}
//			else if (Change_color[t / 4] == 5)
//			{
//				glColor4f(1.0f, 0.0f, 1.0f, Change_alpha[t / 4]);
//			}
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	}
//	glutPostRedisplay();
//
//}
//
//void drawPolygon(void)
//{
//	glColor3f(1.0f, 1.0f, 0.0f);
//	switch (iDrawMode)
//	{
//	case 34:
//	{
//		glBegin(GL_POLYGON);
//		for (int t = 0; t < iNumPoints; t++)
//		{
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//
//	}
//	glutPostRedisplay();
//}
//
//void draw(void)
//{
//	//glColor3f (0.0f, 0.0f, 0.5f);
//	//glutWireTeapot(0.5f); //������ �׸���
//
//	glMatrixMode(GL_MODELVIEW);//��ǥ�迡�� ��ü�� ��ȯ, ������ �̵� �� �ݿ�
//							   //glMatrixMode(GL_PROJECTION); //ī�޶��� projection Ư�� �ݿ�
//	glLoadIdentity();//���� Ȱ��ȭ�� ����� ���� ��ķ� �ʱ�ȭ
//
//
//	glClear(GL_COLOR_BUFFER_BIT); //ȭ�������
//
//								  ////////////////// Rotation _ON , OFF ���� /////////////////
//	if (Rotation_on == true)
//	{
//		glTranslatef(250 + distance, 250, 0); // ȸ�� �߽�(pivot point )�� ���Ͽ� ������ ��ǥ���� ������ �̵���Ų��.
//		glRotatef(spin, 0, 0, 1); // ���ϴ� ȸ�� ���� spin, x,y,z �߽���
//		glTranslatef(-250 - distance, -250, 0);//ȸ���ϸ鼭 �����̵� �� ������ �����̵� �� ��ŭ Povot point �� �̵��ϱ� ������ �̵��� ��ǥ���� �߽��� �����̵� �� ��ŭ �Ű� �־�� �Ѵ�.
//											   //���� ������ ����, �ؿ������� �����
//	}
//
//	/////////////////// Translation_ON,OFF ���� ////////////////////////////////////
//	if (Translation_on == true)
//	{
//		glTranslatef(distance, 0, 0);
//	}
//
//	//////////////////////// Ű������ �Է��� �޾Ƽ� ������ ���� �ٲٱ� /////////////////////////////
//
//	if (iDrawMode == 1 || iDrawMode == 21 || iDrawMode == 22 || iDrawMode == 23 || iDrawMode == 34)
//	{
//		if (color == 1)
//		{
//			glColor3f(1.0f, 0.0f, 0.0f);//Red ����
//		}
//		else if (color == 2)
//		{
//			glColor3f(0.0f, 1.0f, 0.0f);//Green ����
//		}
//		else if (color == 3)
//		{
//			glColor3f(0.0f, 0.0f, 1.0f);//Blue ����
//		}
//		else if (color == 4)
//		{
//			glColor3f(0.0f, 1.0f, 1.0f);//Cyan ����
//		}
//		else if (color == 5)
//		{
//			glColor3f(1.0f, 0.0f, 1.0f);//Magenta ����
//		}
//		else if (color == 0)
//		{
//			glColor3f(1.0f, 1.0f, 0.0f);//��������� �ʱ�ȭ
//		}
//	}
//	/////////////////////////// AntiAliasing  ��  Alpha Blending  ���� ///////////////////////////
//
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); //antialiasing ǰ�� ����
//	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
//	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
//
//	if (Antialiase_on == false)
//	{
//		glDisable(GL_BLEND);
//		glDisable(GL_POINT_SMOOTH);
//		glDisable(GL_LINE_SMOOTH);
//		glDisable(GL_POLYGON_SMOOTH);
//	}
//
//	else if (Antialiase_on == true)
//	{
//		glEnable(GL_BLEND); //antialiasing ��� , alpha �����ϰ� ����
//		glEnable(GL_POINT_SMOOTH);
//		glEnable(GL_LINE_SMOOTH);
//		glEnable(GL_POLYGON_SMOOTH);
//	}
//
//	/////////////////////////// ������ �׸��� ��带 ���� /////////////////////////////
//
//	if (iDrawMode == 1)
//	{
//		drawPoint();
//	}
//	else if (iDrawMode == 21 || iDrawMode == 22 || iDrawMode == 23)
//	{
//		drawLine();
//	}
//	else if (iDrawMode == 31 || iDrawMode == 32)
//	{
//		drawTriangle();
//	}
//	else if (iDrawMode == 33)
//	{
//		drawQuad();
//	}
//	else if (iDrawMode == 34)
//	{
//		drawPolygon();
//	}
//	glLoadIdentity();
//	//���ڿ� ����� ���� �������� ���־�� ����� ���۵� (��draw�Լ� �ڿ�)
//	if (Character_on == true)
//	{
//		glColor3f(0.0f, 1.0f, 1.0f);
//		drawString(GLUT_BITMAP_TIMES_ROMAN_24, "12131668 YURI KIM", 5, 475);
//		if (Antialiase_on == false)
//			drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Antialiasing OFF!", 300, 5);
//		else if (Antialiase_on == true)
//			drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Antialiasing ON!", 300, 5);
//	}
//
//	glutSwapBuffers();
//	glutPostRedisplay();
//}
//
//void mouse(int button, int state, int x, int y)
//{
//	printf("Mouse button is clicked! (%d,%d,%d,%d)\n", button, state, x, y);
//	//���ʹ�ư0, �߰���ư1, �����ʹ�ư2
//	//���� 0, �� 1
//	if (button == 0 && state == 0) // ���� �����ָ� x,y�� ��ư�� ������ ���� ��� ���� �ɼ��� ����
//	{
//		xaxis[iNumPoints] = x;
//		yaxis[iNumPoints] = 500 - y; // window�� opengl�� y���� ���߾���
//		iNumPoints++;
//	}
//	glutPostRedisplay();
//}
//
//void motion(int x, int y)
//{
//	printf("Mouse is moving! (%d, %d)\n", x, y);
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//
//	printf("You pressed %c \n", key);
//	/////////////////////// Ű����� ���ڸ� �Է� �޾� ������ ���� �ٲ۴�./////////////////////////
//	if ((key >= 48) && (key <= 57))//Ű������ ���� 1���� 5 �̿��� ���ڸ� �Է¹����� ��������� �ʱ�ȭ �����ֱ� ���ؼ� 1���� 5������ �ƽ�Ű �ڵ�� �޾Ҵ�.
//	{
//		if (iDrawMode == 1 || iDrawMode == 21 || iDrawMode == 22 || iDrawMode == 23 || iDrawMode == 34)
//		{
//			switch (key)
//			{
//
//			case '1':
//			{
//				color = 1;
//				printf("RED\n");
//				break;
//			}
//			case '2':
//			{
//				color = 2;
//				printf("GREEN\n");
//				break;
//			}
//			case '3':
//			{
//				color = 3;
//				printf("BLUE\n");
//				break;
//			}
//			case '4':
//			{
//				color = 4;
//				printf("CYAN\n");
//				break;
//			}
//			case '5':
//			{
//				color = 5;
//				printf("Magenta\n");
//				break;
//			}
//
//			default://1~5 �̿��� ���ڸ� �Է����� �ÿ��� ��������� �ʱ�ȭ ��Ų��.
//			{
//				color = 0;
//				printf("color reset\n");
//				break;
//			}
//
//			}
//			glutPostRedisplay();
//		}
//		//////////////////////// �ﰢ�� �׸��� ////////////////////
//		////////////// �ﰢ���� �������� �׸� ������ ������ �ٲ��� �ϹǷ� �ٸ� �������� �ٸ� ������ �ش� //////////////////
//		if (iDrawMode == 31 || iDrawMode == 32)
//		{
//			The_Num = iNumPoints / 3;
//
//			switch (key)
//			{
//
//			case '1':
//			{
//				Change_color[The_Num - 1] = 1;
//				printf("RED\n");
//				break;
//			}
//			case '2':
//			{
//				Change_color[The_Num - 1] = 2;
//				printf("GREEN\n");
//				break;
//			}
//			case '3':
//			{
//				Change_color[The_Num - 1] = 3;
//				printf("BLUE\n");
//				break;
//			}
//			case '4':
//			{
//				Change_color[The_Num - 1] = 4;
//				printf("CYAN\n");
//				break;
//			}
//			case '5':
//			{
//				Change_color[The_Num - 1] = 5;
//				printf("Magenta\n");
//				break;
//			}
//
//			default:
//			{
//				Change_color[The_Num - 1] = 0;
//				printf("color reset\n");
//				break;
//			}
//
//			}
//			glutPostRedisplay();
//
//		}
//
//		if (iDrawMode == 33)
//		{
//
//			The_Num = iNumPoints / 4;
//
//
//			switch (key)
//			{
//
//			case '1':
//			{
//				Change_color[The_Num - 1] = 1;
//				printf("RED\n");
//				break;
//			}
//			case '2':
//			{
//				Change_color[The_Num - 1] = 2;
//				printf("GREEN\n");
//				break;
//			}
//			case '3':
//			{
//				Change_color[The_Num - 1] = 3;
//				printf("BLUE\n");
//				break;
//			}
//			case '4':
//			{
//				Change_color[The_Num - 1] = 4;
//				printf("CYAN\n");
//				break;
//			}
//			case'5':
//			{
//				Change_color[The_Num - 1] = 5;
//				printf("Magenta\n");
//				break;
//			}
//			default:
//			{
//				Change_color[The_Num - 1] = 0;
//				printf("color reset\n");
//				break;
//			}
//
//			}
//		}
//		glutPostRedisplay();
//	}
//
//	if (iDrawMode == 31 || iDrawMode == 32)
//	{
//		The_Num = iNumPoints / 3;
//		if (Antialiase_on == true)    //alpha���� �����Ѵ�
//		{
//			switch (key)
//
//			{
//			case'q':
//			{
//				Change_alpha[The_Num - 1] = 0.0f;
//				printf("alpha value : 0.0\n");
//				break;
//			}
//			case 'w':
//			{
//				Change_alpha[The_Num - 1] = 0.25f;
//				printf("alpha value : 0.25\n");
//				break;
//			}
//			case 'e':
//			{
//				Change_alpha[The_Num - 1] = 0.5f;
//				printf("alpha value : 0.5\n");
//				break;
//			}
//			case 'r':
//			{
//				Change_alpha[The_Num - 1] = 0.75f;
//				printf("alpha value : 0.75\n");
//				break;
//			}
//			case 't':
//			{
//				Change_alpha[The_Num - 1] = 1.0f;
//				printf("alpha value : 1.0\n");
//				break;
//			}
//			}
//		}
//		glutPostRedisplay();
//	}
//	if (iDrawMode == 33)
//	{
//		The_Num = iNumPoints / 4;
//
//		if (Antialiase_on == true)    //alpha���� �����Ѵ�
//		{
//			switch (key)
//
//			{
//			case'q':
//			{
//				Change_alpha[The_Num - 1] = 0.0f;
//				printf("alpha value : 0.0\n");
//				break;
//			}
//			case 'w':
//			{
//				Change_alpha[The_Num - 1] = 0.25f;
//				printf("alpha value : 0.25\n");
//				break;
//			}
//			case 'e':
//			{
//				Change_alpha[The_Num - 1] = 0.5f;
//				printf("alpha value : 0.5\n");
//				break;
//			}
//			case 'r':
//			{
//				Change_alpha[The_Num - 1] = 0.75f;
//				printf("alpha value : 0.75\n");
//				break;
//			}
//			case 't':
//			{
//				Change_alpha[The_Num - 1] = 1.0f;
//				printf("alpha value : 1.0\n");
//				break;
//			}
//			}
//		}
//		glutPostRedisplay();
//	}
//	if (Antialiase_on == false)
//	{
//		if (key == 'a')
//		{
//			Antialiase_on = true;
//				printf("Antialiasing ON\n");
//		}
//	}
//	else if (Antialiase_on == true)
//	{
//		if (key == 'a')
//		{
//			Antialiase_on = false;
//				printf("Antialiasing OFF\n");
//		}
//	}
//	if (Character_on == false)
//	{
//		if (key == 'c')
//		{
//			Character_on = true;
//				printf("Character ON\n");
//		}
//		glutPostRedisplay();
//	}
//
//	else if (Character_on == true)
//	{
//		if (key == 'c')
//		{
//			Character_on = false;
//				printf("Character OFF\n");
//		}
//		glutPostRedisplay();
//	}
//	if (Translation_on == false)
//	{
//		if (key == 'T')
//		{
//			Translation_on = true;
//				printf("Translation_ON\n");
//		}
//		glutPostRedisplay();
//	}
//	else if (Translation_on == true)
//	{
//		if (key == 'T')
//		{
//			Translation_on = false;
//				printf("Translation_OFF\n");
//		}
//		glutPostRedisplay();
//	}
//	if (Rotation_on == false)
//	{
//		if (key == 'R')
//		{
//			Rotation_on = true;
//				printf("Rotaion_ON\n");
//		}
//		glutPostRedisplay();
//	}
//	else if (Rotation_on == true)
//	{
//		if (key == 'R')
//		{
//			Rotation_on = false;
//				printf("Rotation_OFF\n");
//		}
//		glutPostRedisplay();
//	}
//
//
//
//	glutPostRedisplay();
//}
//
//void subsub_menu_function1(int option)
//
//{
//	printf("SubSubmenu %d has been selected \n", option);
//
//	switch (option)
//	{
//	case 21:
//	{
//		iDrawMode = option;
//		printf("GL_LINES\n");
//		break;
//	}
//	case 22:
//	{
//		iDrawMode = option;
//		printf("GL_LINE_STRIP\n");
//		break;
//	}
//	case 23:
//	{
//		iDrawMode = option;
//		printf("GL_LINE_LOOP\n");
//		break;
//	}
//	}
//	glutPostRedisplay();
//}
//
//void subsub_menu_function2(int option)
//
//{
//	printf("SubSubmenu %d has been selected \n", option);
//
//	switch (option)
//	{
//	case 31:
//	{
//		iDrawMode = option;
//		printf("GL_TRIANGLES\n");
//		break;
//	}
//	case 32:
//	{
//		iDrawMode = option;
//		printf("GL_TRIANGLE_STRIP\n");
//		break;
//	}
//	case 33:
//	{
//		iDrawMode = option;
//		printf("GL_QUADS\n");
//		break;;
//	}
//	case 34:
//	{
//		iDrawMode = option;
//		printf("GL_POLYGON\n");
//		break;
//	}
//	}
//	glutPostRedisplay();
//}
//
//void sub_menu_function1(int option)
//
//{
//	printf("Submenu %d has beed selected \n", option);
//	if (option == 1)
//	{
//		iDrawMode = option;
//		printf("Point Draw\n");
//		glutPostRedisplay();
//	}
//}
//
//void main_menu_function(int option)
//{
//	printf("Mainmenu %d has beed selected \n", option);
//	if (option == 999)
//	{
//		exit(0);
//	}
//
//	if (option == 41)
//	{
//		printf("Clear\n");
//		iNumPoints = 0;
//		color = 0;
//
//		for (int i = 0; i<The_Num; i++)
//		{
//			Change_color[i] = 0;
//			Change_alpha[i] = 1;
//		}
//		glutPostRedisplay();
//	}
//
//	if (option == 42)
//	{
//		if (Antialiase_on == false)
//		{
//			Antialiase_on = true;
//				printf("Antialiasing ON\n");
//			glutPostRedisplay();
//		}
//
//		else if (Antialiase_on == true)
//		{
//			Antialiase_on = false;
//				printf("Antialiasing OFF\n");
//			glutPostRedisplay();
//		}
//	}
//
//	/*if (option == 43)
//	{
//		if (Character_on == false)
//		{
//			Character_on = true;
//				printf("Character ON\n");
//			glutPostRedisplay();
//		}
//		else if (Character_on == true)
//		{
//			Character_on = false;
//				printf("Character OFF\n");
//			glutPostRedisplay();
//		}
//	}*/
//}