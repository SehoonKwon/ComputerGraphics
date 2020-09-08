//#include <gl/glut.h>
//#include <stdio.h>
//
//void resize(int width, int height);
//void init();
//void draw();
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
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void init()
//{
//	GLfloat Imodel_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Imodel_ambient);
//	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
//
//	//광원의 성질들 값 설정
//	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
//
//	GLfloat ambient_Point[] = { 0.7f, 0.7f, 0.7f, 1.0f }; //반사율 70%
//	GLfloat diffuse_Point[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	GLfloat specular_Point[] = { 0.7f, 0.7f, 0.7f, 1.0f }; //반사율 70%
//
//	//설정값 적용
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//
//	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_Point);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_Point);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_Point);
//	glMateriali(GL_FRONT, GL_SHININESS, 16);
//
//	//제 1광원을 킨다(사용한다)
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//}
//
//void resize(int width, int height)
//{
//	glViewport(0, 0, width, height); 
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / (float) height, 1, 500);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glEnable(GL_DEPTH_TEST);
//	gluLookAt(2.45, 1.414, 0, 0, 0, 0, 0, 1, 0); //카메라의 시점 (V 벡터)
//
//	GLfloat light_position1[] = { -2, 1, 0, 1 }; // 광원 (L 벡터)
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//
//	glPointSize(25.0);
//	glBegin(GL_POINTS);
//	glNormal3f(0, 1, 0);	glVertex3f(0, 0, 0); // 노말 벡터(N)은 (0, 1, 0), 점은 (0, 0, 0)
//	glEnd();
//
//	glFlush();
//	glutSwapBuffers();
//}