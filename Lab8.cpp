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
//void draw();
//void init();
//void idle();
//void keyboard(unsigned char key, int x, int y);
//void specialkey(int key, int x, int y);
//
//double zoom = 0; // �� ��, �ƿ� ���� ����
//double temp=0; //��� ������ ���� ���� �񱳸� ���� ������ ����
//double m_RotateAngle = 0; //ȸ����
//double zoom_x = 0, zoom_y = 0, zoom_z = 0; //���� ���� ���� 
//
//bool CW_mode = true; //�׸��� ���� ����
//bool CULL_FACE_mode = true; //Cull-face on-off
//bool spin_right = true; // �׸��� ����(�¿�) ����
//bool zoom_in = false; // �� �� ����
//bool zoom_out = false; // �� �ƿ� ����
//bool stop_spin = false; // ȸ����� on-off
//
//int main(int argc, char** argv)
//{
//	// ������ �ʱ�ȭ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glClearDepth(1.0f);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutSpecialFunc(specialkey);
//	glutKeyboardFunc(keyboard);
//	glutIdleFunc(idle);
//	init();
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void init()
//{
//	GLfloat ambientLight[] = { 0.2f,0.2f,0.2f,1.0f };
//	GLfloat diffuseLight[] = { 0.7f,0.7f,0.7f,1.0f };
//	GLfloat specularLight[] = { 0.9f,0.9f,0.9f,1.0f };
//	GLfloat specularMaterial[] = { 1.0f,1.0f,1.0f,1.0f };
//
//	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
//
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
//	glMateriali(GL_FRONT, GL_SHININESS, 20);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	//Depth-Test Enable
//	glFrontFace(GL_CW); //CW�� �׸��� ���ΰ� ���̾�, CCW�� �׸��� �ܺΰ� ���̾�
//	glEnable(GL_DEPTH_TEST);
//
//	glPolygonMode(GL_BACK, GL_LINE); //���θ� ���̾�� �׸�
//}
//
//void idle()
//{
//	if (stop_spin == false) //ȸ����� on-off�� ���� �Լ����� �κ�
//	{
//		if (spin_right == true) m_RotateAngle = m_RotateAngle + 0.2; //���� �������� ȸ��
//		else m_RotateAngle = m_RotateAngle - 0.2; //���� �������� ȸ��
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
//}
//
//void draw()
//{
//	//CW_mode ����.
//	if (CW_mode == false) glFrontFace(GL_CCW); 
//	else glFrontFace(GL_CW);
//
//	//CULL_FACE_mode ����
//	if (CULL_FACE_mode == false) glDisable(GL_CULL_FACE); //GL_CULL_FACE ����� ���� �ӿ� ������ �ӿ� ���̾ �׷���.
//	else glEnable(GL_CULL_FACE);
//
//	int up = 1;
//	int r = 20; // ������ǥ�迡�� ����-��P������ �Ÿ�
//	double eye_x = r*sin(E_Radian)*sin(A_Radian), eye_y = r*cos(E_Radian), eye_z = r*sin(E_Radian)*cos(A_Radian); //���� ��ǥ�踦 ��Ÿ���� ����
//
//	//�� ��, �ƿ� �Լ� �����κ�
//	if (zoom_in == true)
//	{
//		zoom_x = eye_x - zoom;
//		zoom_y = eye_y - zoom;
//		zoom_z = eye_z - zoom;
//		if (zoom_x <= 0) zoom_x = 0;
//		if (zoom_y <= 0) zoom_y = 0;
//		if (zoom_z <= 0) zoom_z = 0;
//	}
//	else if (zoom_out == true)
//	{
//		zoom_x = eye_x - zoom;
//		zoom_y = eye_y - zoom;
//		zoom_z = eye_z - zoom;
//	}
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	if (zoom_in == true || zoom_out == true)
//	{
//		if (E_angle > 180 || E_angle <= -180) up = -1;  // Ư�� ������ �Ǹ� ī�޶��� ������ �ٲ�µ� �̸� ó���ϱ� ���� ���ǹ�
//		gluLookAt(zoom_x, zoom_y, zoom_z, 0, 0, 0, 0, up, 0); //�� ���� ���� �������� ���ƶ�.
//	}
//	else
//	{
//		if (E_angle > 180 || E_angle <= -180 || E_angle==0) up = -1;  // Ư�� ������ �Ǹ� ī�޶��� ������ �ٲ�µ� �̸� ó���ϱ� ���� ���ǹ�
//		gluLookAt(eye_x, eye_y, eye_z, 0, 0, 0, 0, up, 0); //�� ��尡 �ƴϸ� ������ �������� ���ƶ�.
//	}
//
//	glPushMatrix();
//	glRotatef(m_RotateAngle, 0, 1, 0);
//	GLdouble eq[4] = { 1.0, 0.0, 0.0, 0.0 };
//	glClipPlane(GL_CLIP_PLANE0, eq);
//	glEnable(GL_CLIP_PLANE0);
//	glPopMatrix();
//
//	glColor3f(1, 1, 0);
//	glutSolidTeapot(4);
//
//	glFlush();
//	glutSwapBuffers();
//}
//
//void specialkey(int key, int x, int y)
//{
//	//����Ű�� ���� ������ �浵�� ������Ų��.
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
//	else if (key == GLUT_KEY_F3) //��� ���� �ʱ�ȭ
//	{
//		E_angle = 90;
//		A_angle = 0;
//		zoom = 0;
//		zoom_in = false;
//		zoom_out = false;
//	}
//
//	glutPostRedisplay();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	//Ű���� ��ư�� ���� �� ���۱�ɵ� ����
//	if (key == '1') //CW_mode ����
//	{
//		if (CW_mode == true) CW_mode = false; 
//		else CW_mode = true; 
//	}
//	else if (key == '2') //CULL_FACE_mode ����
//	{
//		if (CULL_FACE_mode == true) CULL_FACE_mode = false;
//		else CULL_FACE_mode = true;
//	}
//	else if (key == '3') //ȸ�� ���� ����
//	{
//		if (spin_right == true) spin_right = false;
//		else spin_right = true;
//	}
//	else if (key == 'z') //�� ��
//	{
//		if (zoom_out == true)	zoom_out = false;
//		zoom_in = true;
//		zoom = zoom + 0.1;
//	}
//	else if (key == 'x') //�� �ƿ�
//	{
//		if (zoom_in == true)	zoom_in = false;
//		zoom_out = true;
//		zoom = zoom - 0.1;
//	}
//	else if (key == 'c') //�� ��� ��� off
//	{
//		zoom_in = false;
//		zoom_out = false;
//	}
//	else if (key == 's') //ȸ����� on-off
//	{
//		if (stop_spin == false) stop_spin = true;
//		else stop_spin = false;
//	}
//	glutPostRedisplay();
//}