//#include <gl/glut.h>
//#include <stdio.h>
//#include <math.h> // ����, �ڻ��� �Լ��� ����ϱ� ���� �� �Լ��� ��������� �����Ͽ���.
//
//double E_angle = 90, A_angle = 0; // �������� ��ȯ�ϱ� ���� Degree ���� ����.
//#define PI 3.141592
//#define E_Radian PI*E_angle/180 //C������ ���ȸ� ��밡���ϴ�.
//#define A_Radian PI*A_angle/180
//
//void resize(int width, int height);
//void draw_axis();
//void draw();
//void specialkey(int key, int x, int y);
//
//double Cam_dis=0; // ī�޶� ��ü�κ��� �־����ų� ����������� �ϱ����� ������ ����
//double temp=0; //��� ������ ���� ���� �񱳸� ���� ������ ����
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
//	glutReshapeFunc(resize);
//	glutSpecialFunc(specialkey);
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void resize(int width, int height)
//{
//	glViewport(0, 0, width, height); // width�� height�� ����������� �� ���� , viewport�� Ortho2D�� ����(=���)
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / (float) height, 1, 500);
//	glMatrixMode(GL_MODELVIEW);
//}
//
// //x, y, z �� ����
//void draw_axis() 
//{
//	glLineWidth(3);
//	
//	glBegin(GL_LINES);
//	
//	glColor3f(1, 0, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(4, 0, 0);
//
//	glColor3f(0, 1, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 4, 0);
//
//	glColor3f(0, 0, 1);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 4);
//	
//	glEnd();
//	glLineWidth(1);
//}
//
//void draw()
//{
//	int up = 1;
//	int r = 20; // ������ǥ�迡�� ����-��P������ �Ÿ�
//	double eye_x = r*sin(E_Radian)*sin(A_Radian), eye_y = r*cos(E_Radian), eye_z = r*sin(E_Radian)*cos(A_Radian); //���� ��ǥ�踦 ��Ÿ���� ����
//
//	if (E_angle > 180 || E_angle <= -180 ) up = -1;  // Ư�� ������ �Ǹ� ī�޶��� ������ �ٲ�µ� �̸� ó���ϱ� ���� ���ǹ�
//
//	if (Cam_dis > temp) // ���� �־���
//	{
//		eye_x = eye_x + Cam_dis;
//		eye_y = eye_y + Cam_dis;
//		eye_y = eye_z + Cam_dis;
//		temp = Cam_dis;
//	}
//	else if (Cam_dis < temp) //�Ʒ��� �־���
//	{
//		eye_x = eye_x + Cam_dis;
//		eye_y = eye_y + Cam_dis;
//		eye_y = eye_z + Cam_dis;
//		temp = Cam_dis;
//	}
//	
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(eye_x, eye_y, eye_z, 0, 0, 0, 0, up, 0);
//
//	glColor3f(1, 1, 0);
//	glutWireTeapot(4);
//	draw_axis();
//
//	glFlush();
//	glutSwapBuffers();
//}
//
//void specialkey(int key, int x, int y)
//{
//	if (key == GLUT_KEY_LEFT)
//	{
//		A_angle--;
//		printf("E_angle : %f  A_angle : %f\n", E_angle, A_angle);
//	}
//	else if (key == GLUT_KEY_RIGHT)
//	{
//		printf("E_angle : %f  A_angle : %f\n", E_angle, A_angle);
//		A_angle++;
//	}
//	else if (key == GLUT_KEY_UP)
//	{
//		printf("E_angle : %f  A_angle : %f\n", E_angle, A_angle);
//		E_angle--;
//		if (E_angle < 0)  E_angle = 360 + E_angle;
//		if (E_angle > 360) E_angle = E_angle - 360;  // -1 = 359���� �����Ƿ� ������ ���������� �۾����� �� ����
//	}
//	else if (key == GLUT_KEY_DOWN)
//	{
//		E_angle++;
//		if (E_angle == 360) E_angle = 0;  //360�� = 0�� �̹Ƿ� ������ ���������� Ŀ���� �� ����
//		printf("E_angle : %f  A_angle : %f\n", E_angle, A_angle);
//	}
//	else if (key == GLUT_KEY_F1) //���� �־����� Ű 
//	{
//		Cam_dis++;
//	}
//	else if (key == GLUT_KEY_F2) //�Ʒ��� �־����� Ű
//	{
//		Cam_dis--;
//	}
//	else if (key == GLUT_KEY_F3) //���� �ʱ�ȭ
//	{
//		E_angle = 90;
//		A_angle = 0;
//	}
//
//	glutPostRedisplay();
//}