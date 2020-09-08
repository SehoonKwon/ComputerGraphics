//#pragma comment(lib, "legacy_stdio_definitions.lib")
//#include <gl/glut.h>
//#include <gl/GLAUX.H>
//#include <stdio.h>
//#include <math.h> // 사인, 코사인 함수를 사용하기 위해 이 함수의 헤더파일을 참조하였다.
//
//double E_angle = 90, A_angle = 0; // 라디안으로 변환하기 위해 Degree 변수 선언.
//#define PI 3.141592
//#define E_Radian PI*E_angle/180 //C언어에서는 라디안만 사용가능하다.
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
//double zoom = 0; // 줌 인, 아웃 정도 조절
//double temp=0; //모드 조정에 대한 변수 비교를 위해 생성한 변수
//double m_RotateAngle = 0; //회전율
//double zoom_x = 0, zoom_y = 0, zoom_z = 0; //줌을 위한 변수 
//
//bool Light = false;
//bool stop_spin = false; // 회전기능 on-off
//bool spin_right = true; // 그리는 방향(좌우) 선택
//
//enum object { Cube = 1, Can, Earth };
//int object = 1; // 초기 모드는 큐브
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
//	// 윈도우 초기화
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
//	if (stop_spin == false) //회전기능 on-off에 대한 함수구현 부분
//	{
//		m_RotateAngle = m_RotateAngle + 0.05; //양의 방향으로 회전
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
//	//광원의 성질들 값 설정
//	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
//		
//	GLfloat ambient_Sun[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//	GLfloat diffuse_Sun[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	GLfloat specular_Sun[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//		
//	//설정값 적용
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
//	glViewport(0, 0, width, height); // width와 height는 윈도우사이즈 가 들어옴 , viewport는 Ortho2D와 같다(=평면)
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / (float) height, 1, 500);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//  //x, y, z 축 생성
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
//	double eye_x = r*sin(E_Radian)*sin(A_Radian), eye_y = r*cos(E_Radian), eye_z = r*sin(E_Radian)*cos(A_Radian); //구면 좌표계를 나타내기 위함
//	if (E_angle > 180 || E_angle <= -180) up = -1; // 특정 각도가 되면 카메라의 시점이 바뀌는데 이를 처리하기 위한 조건문
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
//			gluQuadricOrientation(m_pQuadric2, GLU_INSIDE); // 사이다 윗면 빛 비추게 , 뚜껑과 캔 밑면이 같은 방향의 법선벡터라 안그려졌었음
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
//	//방향키에 따른 위도와 경도에 증감시킨다.
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
//		if (E_angle > 360) E_angle = E_angle - 360;  // -1 = 359도와 같으므로 각도가 무제한으로 작아지는 일 방지
//
//	}
//	else if (key == GLUT_KEY_DOWN)
//	{
//		E_angle++;
//		if (E_angle == 360) E_angle = 0;  //360도 = 0도 이므로 각도가 무제한으로 커지는 일 방지
//		printf("E_angle : %f  A_angle : %f\n", E_angle, A_angle);
//
//	}
//	else if (key == GLUT_KEY_F3) //모든 설정 초기화
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
//	if (key == 'z') //줌 인
//	{
//		if (r > 0) r--;
//	}
//	else if (key == 'x') //줌 아웃
//	{
//		r++;
//	}
//	else if (key == 's') //회전기능 on-off
//	{
//		if (stop_spin == false) stop_spin = true;
//		else stop_spin = false;
//	}
//
//	//'o' 키를 누르면 제2 광원 온-오프 기능
//	if (key == 'l')
//	{
//		if (Light == false)  Light = true;
//		else Light = false;
//	}
//
//	glutPostRedisplay();
//}