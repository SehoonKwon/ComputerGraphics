//#include <stdio.h>
//#include <stdlib.h>
//#include <gl/glut.h>
//
//#pragma warning (disable : 4996)
//
//void file_load(char *fname);
//void idle();
//void draw();
//void init();
//void resize(int width, int height);
//void keyboard(unsigned char key, int x, int y);
//
//int f_num = 0;
//float angle1 = 0;
//
//float v_x[2000] = { 0 }, v_y[2000] = { 0 }, v_z[2000] = { 0 };
//float nvx[2000] = { 0 }, nvy[2000] = { 0 }, nvz[2000] = { 0 };
//int f_1[2000] = { 0 }, f_2[2000]= { 0 }, f_3[2000] = { 0 };
//
//bool second_light = false; // �� 2���� on-off�뵵
//
//int main(int argc, char** argv)
//{
//	// ������ �ʱ�ȭ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	//glClearDepth(1.0f);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 100);
//	glutCreateWindow("My first GL Program");
//
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutKeyboardFunc(keyboard);
//	glutIdleFunc(idle);
//	init();
//
//	glutMainLoop();
//
//	return 0;
//}
//
//
//void init()
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//
//	file_load("teapot.txt");
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
//	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
//	
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_Sun);
//	glMateriali(GL_FRONT, GL_SHININESS, 20);
//	
//	glEnable(GL_COLOR_MATERIAL);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	
//	//Depth-Test Enable
////	glFrontFace(GL_CW); //CW�� �׸��� ���ΰ� ���̾�, CCW�� �׸��� �ܺΰ� ���̾�
//	glEnable(GL_DEPTH_TEST);
//	
//}
//
//void resize(int width, int height)
//{
//	glViewport(0, 0, width, height); // width�� height�� ����������� �� ���� , viewport�� Ortho2D�� ����(=���)
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / (float) height, 1, 1000);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void idle()
//{
//	angle1 = angle1 + 0.01;
//	if (angle1 > 360) angle1 -= 360;
//	glutPostRedisplay();
//}
//
//void file_load(char *fname)
//{
//	int i = 0, j = 0, k = 0;
//	int read;
//	float x = 0, y = 0, z = 0;
//	char ch;
//
//	FILE *fp;
//	fp = fopen(fname, "r");
//	if (!fp)
//	{
//		printf("can't open file %s\n", fname);
//		exit(1);
//	}
//	
//	while (!(feof(fp))) //feof�� ������ ���� �˷��ִ� �Լ�
//	{
//		read = fscanf(fp, "%c %f %f %f", &ch, &x, &y, &z);
//		if (read == 4 && ch == 'v')
//		{
//			i++;
//			v_x[i] = x;
//			v_y[i] = y;
//			v_z[i] = z;
//		}
//		else if (read == 4 && ch == 't')
//		{
//			k++;
//			nvx[k] = x;
//			nvy[k] = y;
//			nvz[k] = z;
//		}
//		else if (read == 4 && ch == 'f')
//		{
//			j++;
//			f_1[j] = x ;
//			f_2[j] = y ;
//			f_3[j] = z ;
//			f_num = j;
//		}
//	}
//
//	fclose(fp);
//}
//
//
//
//void draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	if (second_light == true) glEnable(GL_LIGHT1); //�� 2������ Ű�� �����̸� ��2���� on
//	else glDisable(GL_LIGHT1); //�׷��� ������ off
//
//	gluLookAt(150, 150, 150, 0, 0, 0, 0, 1, 0);
//	GLfloat light_position1[] = { 1000, 1000, 0, 1 }; 
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position1); 
//	GLfloat light_position2[] = { 1000, 0, 3000, 1 }; //�� 2������ ��ġ
//	glLightfv(GL_LIGHT1, GL_POSITION, light_position2); 
//	
//	glPushMatrix();
//	//glScalef(0.4, 0.4, 0.4);
//	glRotatef(angle1, 0, 1, 0);
//	glColor3f(0.0f, 0.5f, 1.0f);
//	glBegin(GL_TRIANGLES);
//	for (int n = 1; n <= f_num; n++)
//	{
//		glNormal3f(nvx[f_1[n]], nvy[f_1[n]], nvz[f_1[n]]);
//		glVertex3f(v_x[f_1[n]], v_y[f_1[n]], v_z[f_1[n]]);
//
//		glNormal3f(nvx[f_2[n]], nvy[f_2[n]], nvz[f_2[n]]);
//		glVertex3f(v_x[f_2[n]], v_y[f_2[n]], v_z[f_2[n]]);
//
//		glNormal3f(nvx[f_3[n]], nvy[f_3[n]], nvz[f_3[n]]);
//		glVertex3f(v_x[f_3[n]], v_y[f_3[n]], v_z[f_3[n]]);
//	}
//	glEnd();
//	glPopMatrix();
//
//	glFlush();
//	glutSwapBuffers();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	//'o' Ű�� ������ ��2 ���� ��-���� ���
//	if (key == 'o')
//	{
//		if (second_light == false)  second_light = true;
//		else second_light = false;
//	}
//
//	glutPostRedisplay();
//}
