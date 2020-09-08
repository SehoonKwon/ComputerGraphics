//#pragma comment(lib, "legacy_stdio_definitions.lib")
//#include <gl/glut.h>
//#include <gl/GLAUX.H>
//#include <stdio.h>
//#include <math.h> // ����, �ڻ��� �Լ��� ����ϱ� ���� �� �Լ��� ��������� �����Ͽ���.
//
//double E_angle = 90, A_angle = 0; // �������� ��ȯ�ϱ� ���� Degree ���� ����.
//#define PI 3.141592
//#define E_Radian PI*E_angle/180 //C������ ���ȸ� ��밡���ϴ�.
//#define A_Radian PI*A_angle/180
//
//
//void resize(int width, int height);
//void idle();
//void init();
//void draw(); 
//void specialkey(int key, int x, int y);
//void keyboard(unsigned char key, int x, int y);
//
//double zoom = 0; // �� ��, �ƿ� ���� ����
//double temp=0; //��� ������ ���� ���� �񱳸� ���� ������ ����
//double m_RotateAngle = 0; //ȸ����
//double zoom_x = 0, zoom_y = 0, zoom_z = 0; //���� ���� ���� 
//
//bool Light = false;
//bool stop_spin = false; // ȸ����� on-off
//bool spin_right = true; // �׸��� ����(�¿�) ����
//
//enum object { Cube = 1, Can, Earth };
//int object = 1; // �ʱ� ���� ť��
//int r = 20;
//
//GLuint texName[6];
//GLuint Cider_t[1];
//GLuint Cider_s[1];
//GLuint Cider_b[1];
//GLuint earth[1];
////GLuint quaname[4];
////GLuint solName1[5];
////GLuint solName2[6];
//
//GLUquadric *m_pQuadric;
//GLUquadric *m_pQuadric2;
//
//int main(int argc, char** argv)
//{
//	// ������ �ʱ�ȭ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 100);
//	glutCreateWindow("My first GL Program");
//	init();
//
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutKeyboardFunc(keyboard);
//	glutSpecialFunc(specialkey);
//	glutIdleFunc(idle);
//	
//	glutMainLoop();
//
//	return 0;
//}
//
//void idle()
//{
//	if (stop_spin == false) //ȸ����� on-off�� ���� �Լ����� �κ�
//	{
//		m_RotateAngle = m_RotateAngle + 0.05; //���� �������� ȸ��
//	}
//	glutPostRedisplay();
//}
//
//void init()
//{
//	glClearColor(0.5, 0.5, 0.5, 1);
//	glClearDepth(1.0);
//	glEnable(GL_DEPTH_TEST);
//
//	m_pQuadric = gluNewQuadric();
//	gluQuadricTexture(m_pQuadric, GL_TRUE);
//	m_pQuadric2 = gluNewQuadric();
//	gluQuadricTexture(m_pQuadric2, GL_TRUE);
//
//	glGenTextures(6, texName);
//	AUX_RGBImageRec *pRGBImage;
//
//	glGenTextures(1, Cider_t);
//	AUX_RGBImageRec *pRGBImage_cider_t;
//
//	glGenTextures(1, Cider_s);
//	AUX_RGBImageRec *pRGBImage_cider_s;
//
//	glGenTextures(1, Cider_b);
//	AUX_RGBImageRec *pRGBImage_cider_b;
//
//	glGenTextures(1, earth);
//	AUX_RGBImageRec *pRGBImage_Earth;
//
//	glBindTexture(GL_TEXTURE_2D, Cider_t[0]);
//	pRGBImage_cider_t = auxDIBImageLoadA("CIDER_T.BMP");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage_cider_t->sizeX, pRGBImage_cider_t->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage_cider_t->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glBindTexture(GL_TEXTURE_2D, Cider_s[0]);
//	pRGBImage_cider_s = auxDIBImageLoadA("CIDER_S.BMP");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage_cider_s->sizeX, pRGBImage_cider_s->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage_cider_s->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glBindTexture(GL_TEXTURE_2D, Cider_b[0]);
//	pRGBImage_cider_b = auxDIBImageLoadA("CIDER_B.BMP");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage_cider_b->sizeX, pRGBImage_cider_b->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage_cider_b->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glBindTexture(GL_TEXTURE_2D, earth[0]);
//	pRGBImage_Earth = auxDIBImageLoadA("Earth.BMP");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage_Earth->sizeX, pRGBImage_Earth->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage_Earth->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glBindTexture(GL_TEXTURE_2D, texName[0]);
//	pRGBImage = auxDIBImageLoadA("TexImage0.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glBindTexture(GL_TEXTURE_2D, texName[1]);
//	pRGBImage = auxDIBImageLoadA("TexImage1.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glBindTexture(GL_TEXTURE_2D, texName[2]);
//	pRGBImage = auxDIBImageLoadA("TexImage2.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glBindTexture(GL_TEXTURE_2D, texName[3]);
//	pRGBImage = auxDIBImageLoadA("TexImage3.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glBindTexture(GL_TEXTURE_2D, texName[4]);
//	pRGBImage = auxDIBImageLoadA("TexImage0.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glBindTexture(GL_TEXTURE_2D, texName[5]);
//	pRGBImage = auxDIBImageLoadA("TexImage5.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//	glEnable(GL_TEXTURE_2D);
//
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
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_Sun);
//	glMateriali(GL_FRONT, GL_SHININESS, 20);
//		
//	glEnable(GL_COLOR_MATERIAL);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//
//	glEnable(GL_LIGHTING);
//
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
//
//	int up = 1;
//	double eye_x = r*sin(E_Radian)*sin(A_Radian), eye_y = r*cos(E_Radian), eye_z = r*sin(E_Radian)*cos(A_Radian); //���� ��ǥ�踦 ��Ÿ���� ����
//	if (E_angle > 180 || E_angle <= -180) up = -1; // Ư�� ������ �Ǹ� ī�޶��� ������ �ٲ�µ� �̸� ó���ϱ� ���� ���ǹ�
//	gluLookAt(eye_x, eye_y, eye_z, 0, 0, 0, 0, up, 0);
//	if (Light == true) glEnable(GL_LIGHT0); 
//	else glDisable(GL_LIGHT0); 
//
//	GLfloat light_position1[] = { 1000, 1000, 1000, 1 }; 
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//
////	draw_axis();
//	glRotatef(m_RotateAngle, 0, 1, 0);
//
//	if (object == Can)
//	{
//		glPushMatrix();
//			glRotatef(90, 1, 0, 0);
//			glTranslatef(0, 0, -1);
//			glBindTexture(GL_TEXTURE_2D, Cider_s[0]);
//			gluQuadricNormals(m_pQuadric2, GL_SMOOTH);
//			gluCylinder(m_pQuadric2, 1, 1, 3, 50, 50);
//			glBindTexture(GL_TEXTURE_2D, Cider_t[0]);
//			gluQuadricOrientation(m_pQuadric2, GLU_INSIDE); // ���̴� ���� �� ���߰� , �Ѳ��� ĵ �ظ��� ���� ������ �������Ͷ� �ȱ׷�������
//			gluDisk(m_pQuadric2, 0, 1, 50, 50);
//			glTranslatef(0, 0, 3);
//			glBindTexture(GL_TEXTURE_2D, Cider_b[0]);
//			gluQuadricOrientation(m_pQuadric2, GLU_OUTSIDE);
//			gluDisk(m_pQuadric2, 0, 1, 50, 50);
//		glPopMatrix();
//	}
//
//	if (object == Earth)
//	{
//		glBindTexture(GL_TEXTURE_2D, earth[0]);
//		gluSphere(m_pQuadric, 3, 50, 50);
//	}
//
//	if (object == Cube)
//	{
//		glBindTexture(GL_TEXTURE_2D, texName[0]);
//		glBegin(GL_QUADS);
//		glTexCoord2f(0, 0);	glNormal3f(-1, 0, 0);	glVertex3f(-1.0f, 1.0f, -1.0f);
//		glTexCoord2f(6, 0);	glNormal3f(-1, 0, 0);	glVertex3f(-1.0f, -1.0f, -1.0f);
//		glTexCoord2f(6, 6);	glNormal3f(-1, 0, 0);	glVertex3f(-1.0f, -1.0f, 1.0f);
//		glTexCoord2f(0, 6);	glNormal3f(-1, 0, 0);	glVertex3f(-1.0f, 1.0f, 1.0f);
//		glEnd();
//
//		glBindTexture(GL_TEXTURE_2D, texName[1]);
//		glBegin(GL_QUADS);
//		glTexCoord2f(0, 0);	glNormal3f(1, 0, 0);	glVertex3f(1.0f, 1.0f, 1.0f);
//		glTexCoord2f(6, 0);	glNormal3f(1, 0, 0);	glVertex3f(1.0f, -1.0f, 1.0f);
//		glTexCoord2f(6, 6);	glNormal3f(1, 0, 0);	glVertex3f(1.0f, -1.0f, -1.0f);
//		glTexCoord2f(0, 6);	glNormal3f(1, 0, 0);	glVertex3f(1.0f, 1.0f, -1.0f);
//		glEnd();
//
//		glBindTexture(GL_TEXTURE_2D, texName[2]);
//		glBegin(GL_QUADS);
//		glTexCoord2f(0, 0);	glNormal3f(0, -1, 0);	glVertex3f(-1.0f, -1.0f, -1.0f);
//		glTexCoord2f(6, 0);	glNormal3f(0, -1, 0);	glVertex3f(1.0f, -1.0f, -1.0f);
//		glTexCoord2f(6, 3);	glNormal3f(0, -1, 0);	glVertex3f(1.0f, -1.0f, 1.0f);
//		glTexCoord2f(0, 6);	glNormal3f(0, -1, 0);	glVertex3f(-1.0f, -1.0f, 1.0f);
//		glEnd();
//
//		glBindTexture(GL_TEXTURE_2D, texName[3]);
//		glBegin(GL_QUADS);
//		glTexCoord2f(0, 0);	glNormal3f(0, 1, 0);	glVertex3f(-1.0f, 1.0f, 1.0f);
//		glTexCoord2f(6, 0);	glNormal3f(0, 1, 0);	glVertex3f(1.0f, 1.0f, 1.0f);
//		glTexCoord2f(6, 6);	glNormal3f(0, 1, 0);	glVertex3f(1.0f, 1.0f, -1.0f);
//		glTexCoord2f(0, 6);	glNormal3f(0, 1, 0);	glVertex3f(-1.0f, 1.0f, -1.0f);
//		glEnd();
//
//		glBindTexture(GL_TEXTURE_2D, texName[4]);
//		glBegin(GL_QUADS);
//		glTexCoord2f(0, 0);	glNormal3f(0, 0, 1);	glVertex3f(1.0f, 1.0f, 1.0f);
//		glTexCoord2f(6, 0); glNormal3f(0, 0, 1);	glVertex3f(-1.0f, 1.0f, 1.0f);
//		glTexCoord2f(6, 1);	glNormal3f(0, 0, 1);	glVertex3f(-1.0f, -1.0f, 1.0f);
//		glTexCoord2f(0, 6);	glNormal3f(0, 0, 1);	glVertex3f(1.0f, -1.0f, 1.0f);
//		glEnd();
//
//		glBindTexture(GL_TEXTURE_2D, texName[5]);
//		glBegin(GL_QUADS);
//		glTexCoord2f(0, 0); glNormal3f(0, 0, -1);	glVertex3f(1.0f, 1.0f, -1.0f);
//		glTexCoord2f(6, 0);	glNormal3f(0, 0, -1);	glVertex3f(-1.0f, 1.0f, -1.0f);
//		glTexCoord2f(6, 3); glNormal3f(0, 0, -1);	glVertex3f(-1.0f, -1.0f, -1.0f);
//		glTexCoord2f(0, 6); glNormal3f(0, 0, -1);	glVertex3f(1.0f, -1.0f, -1.0f);
//		glEnd();
//
//	}
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
//	}
//
//	glutPostRedisplay();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	if (key == '1') 
//	{
//		object = Cube;
//	}
//	
//	if (key == '2') 
//	{
//		object = Can;
//	}
//
//	
//	if (key == '3') 
//	{
//		object = Earth;
//	}
//	
//	if (key == 'z') //�� ��
//	{
//		if (r > 0) r--;
//	}
//	else if (key == 'x') //�� �ƿ�
//	{
//		r++;
//	}
//	else if (key == 's') //ȸ����� on-off
//	{
//		if (stop_spin == false) stop_spin = true;
//		else stop_spin = false;
//	}
//
//	//'o' Ű�� ������ ��2 ���� ��-���� ���
//	if (key == 'l')
//	{
//		if (Light == false)  Light = true;
//		else Light = false;
//	}
//
//	glutPostRedisplay();
//}