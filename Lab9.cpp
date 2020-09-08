//#include <gl/glut.h>
//#include <stdio.h>
//
//void resize(int width, int height);
//void idle();
//void init();
//void draw(); 
//void keyboard(unsigned char key, int x, int y);
//
//float angle1 = 0; //���� ����
//float angle2 = 0; //���� ����
//float angle3 = 0; //ȭ�� ����
//float angle4 = 0; //ȭ�� ����
//float angle5 = 0; //�� ����
//float angle6 = 0; //�� ����
//float angle7 = 0; //�¾� ����
//
//double temp = 0; //��� ������ ���� ���� �񱳸� ���� ������ ����
//double p_x = 15, p_y = 15, p_z = 15; //light_position�� ��ġ�� �����ϱ� ���� ����, �ʱⰪ�� ī�޶��� ��ġ�� ����.
//
//enum light_position { Sun = 1, Earth, Moon, Mars, Init}; // �������� ���� intŸ���� enumŸ�� ǥ��
//int light_position_case = 0; // ������ ��ġ case �ʱ� �� ����
//bool second_light = false; // �� 2���� on-off�뵵
//
//int main(int argc, char** argv)
//{
//	// ������ �ʱ�ȭ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//	init();
//
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutKeyboardFunc(keyboard);
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
//	angle1 = angle1 + 0.05;
//	if (angle1 > 360) angle1 -= 360; 
//	angle2 = angle2 + 0.1;
//	if (angle2 > 360)	angle2 -= 360;
//
//	//�༺���� ����, ���� �߰� 
//	//ȭ���� �������� ������ ������ ������.
//	angle3 = angle3 + 0.025;
//	if (angle3 > 360) angle3 -= 360;
//	angle4 = angle4 + 0.06;
//	if (angle4 > 360)	angle4 -= 360;
//
//	//��, ���� ������ ������ ���� ���� ������ ������ �ణ �۴�.
//	angle5 = angle5 + 0.1;
//	if (angle5 > 360) angle5 -= 360;
//	angle6 = angle6 + 0.1;
//	if (angle6 > 360)	angle6 -= 360;
//
//	//�¾��� ����, �¾��� ������ �ſ������.
//	angle7 = angle7 + 0.005;
//	if (angle7 > 360)	angle7 -= 360;
//	glutPostRedisplay();
//}
//
//void init()
//{
//	//������ ������ �� ����
//	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
//
//	GLfloat ambient_Sun[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//	GLfloat diffuse_Sun[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	GLfloat specular_Sun[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//
//	//������ ����
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//
//	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
//
//	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_Sun);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_Sun);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_Sun);
//	glMateriali(GL_FRONT, GL_SHININESS, 20);
//
//	glEnable(GL_COLOR_MATERIAL);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//
//	//�� 1������ Ų��(����Ѵ�)
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
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
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glEnable(GL_DEPTH_TEST);
//	if (second_light == true) glEnable(GL_LIGHT1); //�� 2������ Ű�� �����̸� ��2���� on
//	else glDisable(GL_LIGHT1); //�׷��� ������ off
//	gluLookAt(15, 15, 15, 0, 0, 0, 0, 1, 0); //ī�޶��� ����
//
//	GLfloat light_position1[] = { p_x, p_y, p_z, 1 }; //��1������ ��ġ�� �����ϱ����� ������ ���� �־��ش�.
//	GLfloat light_position2[] = { -15, 15, 15, 1 }; //�� 2������ ��ġ
//	glLightfv(GL_LIGHT1, GL_POSITION, light_position2); // �� 2������ ��ġ����. ī�޶��� x��ǥ �ݴ�
//
//	//case�� ���� �� 1������ ��ġ ����
//	if (light_position_case == Sun)
//	{
//		p_x = 0;
//		p_y = 0;
//		p_z = 0;
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//	}
//
//	else if (light_position_case == Earth)
//	{
//		glPushMatrix();
//		glRotatef(angle1, 0, 1, 0);
//		glTranslatef(5, 0, 0);
//		p_x = 0;
//		p_y = 0;
//		p_z = 0;
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//		glPopMatrix();
//	}
//
//	else if (light_position_case == Moon)
//	{
//		glPushMatrix();
//		glRotatef(angle1, 0, 1, 0);
//		glTranslatef(5, 0, 0);
//		glRotatef(-angle1, 0, 1, 0);
//		glRotatef(angle5, 0, 1, 0);
//		glTranslatef(3, 0, 0);
//		p_x = 0;
//		p_y = 0;
//		p_z = 0;
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//		glPopMatrix();
//	}
//
//	else if (light_position_case == Mars)
//	{
//		glPushMatrix();
//		glRotatef(angle3, 0, 1, 0);
//		glTranslatef(8, 0, 0);
//		p_x = 0;
//		p_y = 0;
//		p_z = 0;
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//		glPopMatrix();
//	}
//
//	else
//	{
//		p_x = 15;
//		p_y = 15;
//		p_z = 15;
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//	}
//
//	GLfloat emission[] = { 1.0f, 0.0f, 0.0f, 1.0f }; //�¾��� �߻걤�� ������ֱ� ���� ����
//
//	//�¾�, ������ǥ
//	glMaterialfv(GL_FRONT, GL_EMISSION, emission); //�¾��� �߻걤�� ������ֱ� ���� ����
//	glColor3f(1, 0, 0); //�¾��� ���� Red
//	glPushMatrix(); //push - pop �� �������� : ���� push-pop�� ���ٸ� ����� ȸ�� �� �̵��� �� �ؿ� �ڵ�� ��ο� ������ ���ļ� ���ϴ� ����� ���� �� ����. 
//	glRotatef(angle7, 0, 1, 0);
//	glutSolidSphere(1, 30, 30);
//	glPopMatrix();
//	emission[0] = 0.0f; //�¾��� �߻걤�� ������ֱ� ���� ����
//	glMaterialfv(GL_FRONT, GL_EMISSION, emission); //�¾��� �߻걤�� ������ֱ� ���� ����
//	
//	//����
//	glPushMatrix();
//	glRotatef(angle1, 0, 1, 0);
//	glTranslatef(5, 0, 0);
//	glRotatef(angle2, 0, 1, 0);
//
//	glColor3f(0, 0, 1); //������ ���� blue
//	glutSolidSphere(0.5, 30, 30);
//	glRotatef(-angle2, 0, 1, 0); //���� ���� ������ ��������� �ȵǹǷ� ���� ��ŭ �ݴ�� ��ǥ�踦 ������
//	glRotatef(-angle1, 0, 1, 0); //���� ���� ������ ��������� �ȵǹǷ� ���� ��ŭ �ݴ�� ��ǥ�踦 ������
//	
//	//��
//	glRotatef(angle5, 0, 1, 0);
//	glTranslatef(3, 0, 0);
//	glRotatef(angle6, 0, 1, 0);
//
//	glColor3f(1, 0.9, 0); //���� ���� Yellow
//	glutSolidSphere(0.35, 30, 30);
//	glPopMatrix();
//
//	//ȭ��
//	glPushMatrix();
//	glRotatef(angle3, 0, 1, 0);
//	glTranslatef(8, 0, 0);
//	glRotatef(angle4, 0, 1, 0);
//
//	glColor3f(1.5, 0.5, 0); //ȭ���� ���� Brown
//	glutSolidSphere(0.7, 30, 30);
//	glPopMatrix();
//
//	glFlush();
//	glutSwapBuffers();
//}
//
// //Ű�� �Է¹޾� ������ ��ġ�� �ٲ۴�
//void keyboard(unsigned char key, int x, int y)
//{
//	//������ Ű�� ���� ������ ��ġ�� �ٲ�� ����
//	if (key == '1')
//	{
//		light_position_case = Sun;
//	}
//
//	if (key == '2')
//	{
//		light_position_case = Earth;
//	}
//
//	if (key == '3')
//	{
//		light_position_case = Moon;
//	}
//
//	if (key == '4')
//	{
//		light_position_case = Mars;
//	}
//
//	if (key == '5') //���� ��ġ �ʱ�ȭ
//	{
//		light_position_case = Init;
//	}
//
//	//'o' Ű�� ������ ��2 ���� ��-���� ���
//	if (key == 'o')
//	{
//		if (second_light == false)  second_light = true;
//		else second_light = false;
//	}
//
//	glutPostRedisplay();
//}