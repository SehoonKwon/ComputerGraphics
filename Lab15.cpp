//#pragma comment(lib, "legacy_stdio_definitions.lib")
//#include <gl/glut.h>
//#include <gl/GLAUX.H>
//#include <stdio.h>
//#include <gl/glext.h>
//#include <math.h>
//
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
//bool Light = false;
//
//int r = 3;
//
//GLuint g_nCubeTex;
//GLuint img0[1];
//GLuint img1[1];
//GLuint img2[1];
//GLuint img3[1];
//GLuint img4[1];
//GLuint img5[1];
//
//int g_nSkySize = 10;
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
//	glutIdleFunc(idle);
//	glutKeyboardFunc(keyboard);
//	glutSpecialFunc(specialkey);
//	
//	glutMainLoop();
//
//	return 0;
//}
//
//void idle()
//{
//	//if (stop_spin == false) //ȸ����� on-off�� ���� �Լ����� �κ�
//	//{
//	//	m_RotateAngle = m_RotateAngle + 0.05; //���� �������� ȸ��
//	//}
//	glutPostRedisplay();
//}
//
//
//void init()
//{
//	glClearColor(0.5, 0.5, 0.5, 1);
//	glClearDepth(1.0);
//	glEnable(GL_DEPTH_TEST);
//
//	glGenTextures(1, img0);
//	AUX_RGBImageRec *img0;
//
//	glGenTextures(1, img1);
//	AUX_RGBImageRec *img1;
//
//	glGenTextures(1, img2);
//	AUX_RGBImageRec *img2;
//
//	glGenTextures(1, img3);
//	AUX_RGBImageRec *img3;
//
//	glGenTextures(1, img4);
//	AUX_RGBImageRec *img4;
//
//	glGenTextures(1, img5);
//	AUX_RGBImageRec *img5;
//
//	img0 = auxDIBImageLoadA("512px.BMP");
//	img1 = auxDIBImageLoadA("512nx.BMP");
//	img2 = auxDIBImageLoadA("512py.BMP");
//	img3 = auxDIBImageLoadA("512ny.BMP");
//	img4 = auxDIBImageLoadA("512pz.BMP");
//	img5 = auxDIBImageLoadA("512nz.BMP");
//
//	glGenTextures(1, &g_nCubeTex);
//	glBindTexture(GL_TEXTURE_CUBE_MAP, g_nCubeTex);
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, img0->sizeX, img0->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img0->data);
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, img1->sizeX, img1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img1->data);
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, img2->sizeX, img2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img2->data);
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, img3->sizeX, img3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img3->data);
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, img4->sizeX, img4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img4->data);
//	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, img5->sizeX, img5->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img5->data);
//
//	glBindTexture(GL_TEXTURE_CUBE_MAP, g_nCubeTex);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
//	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
//	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
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
//double Determinant(GLfloat **a, int n)
//{
//	int i, j, j1, j2;
//	double det = 0;
//	GLfloat **m = NULL;
//
//	if (n == 2) det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
//	else 
//	{
//		det = 0;
//		for (j1 = 0; j1 < n; j1++)
//		{
//			m = new GLfloat*[n - 1];
//		
//			for (i = 0; i<n - 1; i++)
//			{
//				m[i] = new GLfloat[n - 1]; 
//			}
//
//			for (i = 1; i<n; i++)
//			{
//				j2 = 0;
//			
//				for (j = 0; j<n; j++)
//				{
//					if (j == j1)	continue;
//					m[i - 1][j2] = a[i][j];
//					j2++;
//				}
//			}
//
//			det += pow(-1.0, j1 + 2.0) * a[0][j1] * Determinant(m, n - 1); 
//			for (i = 0; i < n - 1; i++)	delete[] m[i];
//			delete[] m;
//		}
//	}
//
//	return det;
//}
//
//void draw_skybox()
//{
//	//Skybox
//	glBegin(GL_QUADS);
//	glTexCoord3d(1.0, -1.0, -1.0); 	glVertex3f(g_nSkySize, -g_nSkySize, -g_nSkySize);
//	glTexCoord3d(1.0, -1.0, 1.0);	glVertex3f(g_nSkySize, -g_nSkySize, g_nSkySize);
//	glTexCoord3d(1.0, 1.0, 1.0);	glVertex3f(g_nSkySize, g_nSkySize, g_nSkySize);
//	glTexCoord3d(1.0, 1.0, -1.0);	glVertex3f(g_nSkySize, g_nSkySize, -g_nSkySize);
//
//	glTexCoord3d(-1.0, 1.0, -1.0); 	glVertex3f(-g_nSkySize, g_nSkySize, -g_nSkySize);
//	glTexCoord3d(-1.0, -1.0, -1.0);	glVertex3f(-g_nSkySize, -g_nSkySize, -g_nSkySize);
//	glTexCoord3d(-1.0, -1.0, 1.0);	glVertex3f(-g_nSkySize, -g_nSkySize, g_nSkySize);
//	glTexCoord3d(-1.0, 1.0, 1.0);	glVertex3f(-g_nSkySize, g_nSkySize, g_nSkySize);
//
//	glTexCoord3d(-1.0, -1.0, -1.0); glVertex3f(-g_nSkySize, -g_nSkySize, -g_nSkySize);
//	glTexCoord3d(1.0, -1.0, -1.0);	glVertex3f(g_nSkySize, -g_nSkySize, -g_nSkySize);
//	glTexCoord3d(1.0, -1.0, 1.0);	glVertex3f(g_nSkySize, -g_nSkySize, g_nSkySize);
//	glTexCoord3d(-1.0, -1.0, 1.0);	glVertex3f(-g_nSkySize, -g_nSkySize, g_nSkySize);
//
//	glTexCoord3d(-1.0, 1.0, 1.0); 	glVertex3f(-g_nSkySize, g_nSkySize, g_nSkySize);
//	glTexCoord3d(1.0, 1.0, 1.0);	glVertex3f(g_nSkySize, g_nSkySize, g_nSkySize);
//	glTexCoord3d(1.0, 1.0, -1.0);	glVertex3f(g_nSkySize, g_nSkySize, -g_nSkySize);
//	glTexCoord3d(-1.0, 1.0, -1.0);	glVertex3f(-g_nSkySize, g_nSkySize, -g_nSkySize);
//
//	glTexCoord3d(1.0, 1.0, 1.0); 	glVertex3f(g_nSkySize, g_nSkySize, g_nSkySize);
//	glTexCoord3d(-1.0, 1.0, 1.0);	glVertex3f(-g_nSkySize, g_nSkySize, g_nSkySize);
//	glTexCoord3d(-1.0, -1.0, 1.0);	glVertex3f(-g_nSkySize, -g_nSkySize, g_nSkySize);
//	glTexCoord3d(1.0, -1.0, 1.0);	glVertex3f(g_nSkySize, -g_nSkySize, g_nSkySize);
//
//	glTexCoord3d(1.0, 1.0, -1.0); 	glVertex3f(g_nSkySize, g_nSkySize, -g_nSkySize);
//	glTexCoord3d(-1.0, 1.0, -1.0);	glVertex3f(-g_nSkySize, g_nSkySize, -g_nSkySize);
//	glTexCoord3d(-1.0, -1.0, -1.0);	glVertex3f(-g_nSkySize, -g_nSkySize, -g_nSkySize);
//	glTexCoord3d(1.0, -1.0, -1.0);	glVertex3f(g_nSkySize, -g_nSkySize, -g_nSkySize);
//
//	glEnd();
//}
//
//void draw_Sphere()
//{
//	glEnable(GL_TEXTURE_GEN_S);
//	glEnable(GL_TEXTURE_GEN_R);
//	glEnable(GL_TEXTURE_GEN_T);
//	glBindTexture(GL_TEXTURE_CUBE_MAP, g_nCubeTex);
//
//	glutSolidSphere(0.5f, 30, 30);
//
//	glDisable(GL_TEXTURE_GEN_S);
//	glDisable(GL_TEXTURE_GEN_R);
//	glDisable(GL_TEXTURE_GEN_T);
//	glDisable(GL_TEXTURE_CUBE_MAP);
//}
//
//void CoFactor(GLfloat **a, int n, GLfloat **b)
//{
//		int i, j;
//		int i2, j2;
//		int x, y;
//		GLfloat **CoMatrix = NULL;
//
//		CoMatrix = new GLfloat*[n - 1];
//
//		for (i = 0; i < n - 1; i++)	CoMatrix[i] = new GLfloat[n - 1];
//
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				x = 0;
//				for (i2 = 0; i2 < n; i2++)
//				{
//					if (i2 == i) continue;
//					y = 0;
//	
//						for (j2 = 0; j2 < n; j2++)
//						{
//							if (j2 == j) continue;
//							CoMatrix[x][y] = a[i2][j2];
//							y++;
//						}
//						x++;
//					
//				}
//			b[i][j] = pow(-1.0, i + j)*Determinant(CoMatrix, n - 1);
//			}
//		}
//		for (i = 0; i < n - 1; i++)	delete[] CoMatrix[i];
//		delete[] CoMatrix;
//}
//
//
//void Transpose(GLfloat **b, int n)
//{
//	int i, j;
//
//	GLfloat **Tmatrix = NULL;
//
//	Tmatrix = new GLfloat*[n];
//	for (i = 0; i < n; i++)	Tmatrix[i] = new GLfloat[n];
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)	Tmatrix[i][j] = b[j][i];
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)	b[i][j] = Tmatrix[i][j];
//	}
//
//	for (i = 0; i < n; i++)	delete[] Tmatrix[i];
//	delete[] Tmatrix;
//}
//
//void div_det(GLfloat **b, int n, double det)
//{
//	GLfloat **InverMatrix = NULL;
//	InverMatrix = new GLfloat*[n];
//	for (int i = 0; i < n; i++) InverMatrix[i] = new GLfloat[n];
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++) InverMatrix[i][j] = b[i][j]/ det;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			b[i][j] = InverMatrix[i][j];
//		}
//	}
//
//	for (int i = 0; i < n; i++)	delete[] InverMatrix[i];
//	delete[] InverMatrix;
//}
//
////������� ���ϴ� �Լ�
//void gluInvertMatrix(GLfloat **a, GLfloat **b)
//{
//	double det = Determinant(a, 4);
//	CoFactor(a, 4, b);  //���μ�(cofactor ���ϴ� �Լ�(��������)
//	Transpose(b, 4);  //��ġ��� ���ϴ� �Լ�(���� ����)
//	div_det(b, 4, det); //����� ���ϴ� �Լ�(���� ����)
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
//	glDisable(GL_LIGHTING);
//	glEnable(GL_TEXTURE_CUBE_MAP);
//	glBindTexture(GL_TEXTURE_CUBE_MAP, g_nCubeTex);
//
//	glMatrixMode(GL_TEXTURE);
//	glPushMatrix();  //������ texture ���¸� ����
//
//	draw_skybox();
//
//	GLfloat camera[16];
//	GLfloat inv_camera[16];
//	glGetFloatv(GL_MODELVIEW_MATRIX, camera);
//	camera[14] = 0;
//
//	GLfloat **camera_4x4, **inv_camera_4x4; // 2���� �迭�� ����Ű�� ���� 2���� �����ͼ���
//	camera_4x4 = new GLfloat*[4]; 
//	inv_camera_4x4 = new GLfloat*[4];
//	for (int i = 0; i<4; i++)
//	{
//		camera_4x4[i] = new GLfloat[4]; 
//		inv_camera_4x4[i] = new GLfloat[4]; 
//	}
//
//	for (int row = 0; row<4; row++)
//	{ 
//		for (int col = 0; col<4; col++)	camera_4x4[row][col] = camera[row * 4 + col]; 
//	}
//
//	//����� ���ϱ�
//	gluInvertMatrix(camera_4x4, inv_camera_4x4);
//
//	for (int row = 0; row<4; row++)
//	{
//		for (int col = 0; col<4; col++) inv_camera[row * 4 + col] = inv_camera_4x4[row][col];
//	}
//
//	glMultMatrixf(inv_camera);
//
//	glMatrixMode(GL_MODELVIEW);
//	draw_Sphere();
//
//	glMatrixMode(GL_TEXTURE);
//	glPopMatrix();  //����� �����ֱ� ���� ���·� ���ư���.
//
//	glMatrixMode(GL_MODELVIEW);  //�� �� ���·� �ǵ��� ����
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
//	}
//
//	glutPostRedisplay();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	if (key == 'z') //�� ��
//	{
//		if (r > 0) r--;
//	}
//	else if (key == 'x') //�� �ƿ�
//	{
//		r++;
//	}
//	glutPostRedisplay();
//}