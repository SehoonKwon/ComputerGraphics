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
//void idle();
//void draw_axis(); // ���� �׸��� �Լ�. �� ���������� ������� ����.
//void draw(); 
//void specialkey(int key, int x, int y); //ī�޶��� ������ �ٲٴ� Ű�� �Է¹ޱ� ���� �Լ�
//
//float angle1 = 0; //���� ����
//float angle2 = 0; //���� ����
//float angle3 = 0; //ȭ�� ����
//float angle4 = 0; //ȭ�� ����
//float angle5 = 0; //�� ����
//float angle6 = 0; //�� ����
//float angle7 = 0; //�¾� ����
//double temp = 0; //��� ������ ���� ���� �񱳸� ���� ������ ����
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
//	glutIdleFunc(idle);
//	
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void idle(void)
//{
//	//������ ������ ���� �߰�
//	angle1 = angle1 + 0.5;
//	if (angle1 > 360) angle1 -= 360; 
//	angle2 = angle2 + 1;
//	if (angle2 > 360)	angle2 -= 360;
//
//	//�༺���� ����, ���� �߰� 
//	//ȭ���� �������� ������ ������ ������.
//	angle3 = angle3 + 0.25;
//	if (angle3 > 360) angle3 -= 360;
//	angle4 = angle4 + 0.6;
//	if (angle4 > 360)	angle4 -= 360;
//
//	//��, ���� ������ ������ ���� ���� ������ ������ �ణ �۴�.
//	angle5 = angle5 + 1;
//	if (angle5 > 360) angle5 -= 360;
//	angle6 = angle6 + 1;
//	if (angle6 > 360)	angle6 -= 360;
//
//	//�¾��� ����, �¾��� ������ �ſ������.
//	angle7 = angle7 + 0.05;
//	if (angle7 > 360)	angle7 -= 360;
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
//	//���� �׸��� �Լ��� �̿�
//	GLUquadric *q;
//	q = gluNewQuadric();
//
//	int up = 1;
//	int r = 20; // ������ǥ�迡�� ����-��P������ �Ÿ�
//	double eye_x = r*sin(E_Radian)*sin(A_Radian), eye_y = r*cos(E_Radian), eye_z = r*sin(E_Radian)*cos(A_Radian); //���� ��ǥ�踦 ��Ÿ���� ����
//	
//	if (E_angle > 180 || E_angle <= -180 ) up = -1; // Ư�� ������ �Ǹ� ī�޶��� ������ �ٲ�µ� �̸� ó���ϱ� ���� ���ǹ�
//
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glEnable(GL_DEPTH_TEST);
//	gluLookAt(eye_x, eye_y, eye_z, 0, 0, 0, 0, up, 0); //ī�޶��� ����
//
//	//�¾�, ������ǥ
//	glColor3f(1, 0, 0); //�¾��� ���� Red
//	glPushMatrix(); //push - pop �� �������� : ���� push-pop�� ���ٸ� ����� ȸ�� �� �̵��� �� �ؿ� �ڵ�� ��ο� ������ ���ļ� ���ϴ� ����� ���� �� ����. 
//	glRotatef(angle7, 0, 1, 0);
//	//glutWireTeapot(1.2);
//	gluQuadricNormals(q, GLU_FLAT);
//	gluSphere(q, 2.0f, 32, 16);
//	glPopMatrix();
//	//draw_axis();
//	
//	//����
//	glPushMatrix();
//	glRotatef(angle1, 0, 1, 0);
//	glTranslatef(5, 0, 0);
//	glRotatef(angle2, 0, 1, 0);
//
//	glColor3f(0, 0, 1); //������ ���� blue
//	glutWireTeapot(1);
//	glRotatef(-angle2, 0, 1, 0);
//	glRotatef(-angle1, 0, 1, 0);
//	
//	//��
//	glRotatef(angle5, 0, 1, 0);
//	glTranslatef(3, 0, 0);
//	glRotatef(angle6, 0, 1, 0);
//
//	glColor3f(1, 0.9, 0); //���� ���� Yellow
//	glutWireTeapot(0.5);  //�۾����� ���� ������ �ӵ��� �ٸ�
//	//gluSphere(q, 0.4f, 32, 16);
//	glPopMatrix();
//
//	//ȭ��
//	glPushMatrix();
//	glRotatef(angle3, 0, 1, 0);
//	glTranslatef(8, 0, 0);
//	glRotatef(angle4, 0, 1, 0);
//
//	glColor3f(1.5, 0.5, 0); //ȭ���� ���� Brown
//	glutWireTeapot(1.2);
//	//gluSphere(q, 1.0f, 32, 16);
//	glPopMatrix();
//
///*	//��
//	glRotatef(angle5, 0, 1, 0);
//	glTranslatef(6.5, 0, 0);
//	glRotatef(angle6, 0, 1, 0);
//
//	glColor3f(1, 0.9, 0); //���� ���� Yellow
//	glutWireTeapot(0.5);  //�۾����� ���� ������ �ӵ��� �ٸ�
//	gluSphere(q, 0.5f, 32, 16);
//	*/
//	glFlush();
//	glutSwapBuffers();
//}
//
// //����Ű�� �Է¹޾� ������ ��ȭ���� ī�޶��� ������ �ٲ۴�.
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
//
//	}
//	else if (key == GLUT_KEY_DOWN)
//	{
//		E_angle++;
//		if (E_angle == 360) E_angle = 0;  //360�� = 0�� �̹Ƿ� ������ ���������� Ŀ���� �� ����
//		printf("E_angle : %f  A_angle : %f\n", E_angle, A_angle);
//
//	}
//	else if (key == GLUT_KEY_F3) //���� �ʱ�ȭ
//	{
//		E_angle = 90;
//		A_angle = 0;
//	}
//
//	glutPostRedisplay();
//}