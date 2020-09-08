//#include <Windows.h>
//#include <gl/glut.h>
//#include <stdio.h>
//
//void draw(void);
//void resize(int width, int height);
//void mouse(int botton, int state, int x, int y);
//void motion(int x, int y);
//void Picking(int x, int y);
//void init(void);
//void DrawBackground();
//void DrawSphere();
//
//
//GLUquadric *q;
//
//float g_pPosition[6] = { 0.0f, 144.0f, -100.0f, -100.0f, 100.0f, -100.0f };
//
//int g_nX, g_nY;
//int g_nSelect = 0;
//
//int g_nGLWidth = 500, g_nGLHeight = 500;
//
//int main(int argc, char** argv)
//{
//	// 윈도우 초기화
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(g_nGLWidth, g_nGLHeight);
//	glutInitWindowPosition(300, 100);
//	glutCreateWindow("Picking");
//	init();
//
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutMouseFunc(mouse);
//	glutMotionFunc(motion);
//	
//	glutMainLoop();
//
//	return 0;
//}
//
//void resize(int width, int height)
//{
//	g_nGLWidth = width;
//	g_nGLHeight = height;
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, -100, 100);
//	glMatrixMode(GL_MODELVIEW);
//
//}
//
//void init(void)
//{
//	glClearColor(0.0f, 0.0f, 0.5f, 1.0f); 
//	glClearDepth(1.0f);
//	glEnable(GL_DEPTH_TEST);
//
//	//광원의 성질들 값 설정
//	GLfloat light_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
//	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//
//	/*빛의 설정*/
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//
//	GLfloat light_position[] = { 1.0,1.0,1.0,0.0 };
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//	/*광원 ON*/
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMateriali(GL_FRONT, GL_SHININESS, 64);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//	glEnable(GL_COLOR_MATERIAL);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-g_nGLWidth / 2.0f, g_nGLWidth / 2.0f, -g_nGLHeight / 2.0f, g_nGLHeight / 2.0f, -100, 100);
//}
//
//void DrawBackground()
//{
//	glPushAttrib(GL_ALL_ATTRIB_BITS);
//	glDisable(GL_LIGHTING);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	int i;
//	int offset = 50;
//	glBegin(GL_LINES);
//	for (i = -g_nGLWidth / 2.0f; i < g_nGLWidth / 2.0f; i += offset)
//	{
//		glVertex3f(i, -g_nGLHeight / 2.0f, 0.0f);
//		glVertex3f(i, g_nGLHeight / 2.0f, 0.0f);
//	}
//	for (i = -g_nGLHeight / 2.0f; i < g_nGLHeight / 2.0f; i += offset)
//	{
//		glVertex3f(-g_nGLWidth / 2.0f, i, 0.0f);
//		glVertex3f(g_nGLWidth / 2.0f, i, 0.0f);
//	}
//	glEnd();
//	glPopAttrib();
//}
//
//void draw_Cylinder()
//{
//	q = gluNewQuadric();
//	glPushMatrix();
//	glRotatef(90, 1, 0, 0);
//	gluCylinder(q, 30, 30, 50, 50, 50);
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
//
//void draw_Cone()
//{
//	q = gluNewQuadric();
//	q = gluNewQuadric();
//	glPushMatrix();
//	glRotatef(90, 1, 0, 0);
//	gluCylinder(q, 0, 30, 50, 50, 50);
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
//
//void DrawSphere()
//{
//	glLoadName(1);
//	glPushMatrix();
//	glTranslatef(g_pPosition[0], g_pPosition[1], 0.0f);
//	glColor3f(1, 0, 0);
//	glutSolidSphere(25.0f, 30, 30);
////	draw_Cylinder();
//	glPopMatrix();
//
//	glLoadName(2);
//	glPushMatrix();
//	glTranslatef(g_pPosition[2], g_pPosition[3], 0.0f);
//	glColor3f(0, 1, 0);
////	glutSolidSphere(25.0f, 30, 30);
//	glPushMatrix();
//	glRotatef(45, 1, 1, 0);
//	glutSolidCube(30);
//	glPopMatrix();
//	glPopMatrix();
//
//	glLoadName(3);
//	glPushMatrix();
//	glTranslatef(g_pPosition[4], g_pPosition[5], 0.0f);
//	glColor3f(0, 0, 1);
////	glutSolidSphere(25.0f, 30, 30);
////	glutSolidTeapot(30);
//	draw_Cone();
//	glPopMatrix();
//}
//
//void Picking(int x, int y)
//{
//	GLuint selectBuf[512];
//	//first step
//	glSelectBuffer(512, selectBuf);
//	glRenderMode(GL_SELECT);
//	//second step
//	glInitNames();
//	glPushName(1);
//	glLoadName(1);
//
//	//thrid step
//	GLint viewport[4];
//	glGetIntegerv(GL_VIEWPORT, viewport);
//
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//		glLoadIdentity();
//
//	//fourth step
//		gluPickMatrix(x, y, 0.1, 0.1, viewport);
//		glOrtho(-g_nGLWidth / 2.0f, g_nGLWidth / 2.0f, -g_nGLHeight / 2.0f, g_nGLHeight / 2.0f, -100, 100);
//		glMatrixMode(GL_MODELVIEW);
//		glPushMatrix();
//			DrawSphere();
//		glPopMatrix();
//		glMatrixMode(GL_PROJECTION);
//		glPopMatrix();
//	glFlush();
//
//	GLint hits;
//	hits = glRenderMode(GL_RENDER);
//
//	if (hits <= 0) return;
//
//	int stack = selectBuf[0];
//	unsigned int zMax = selectBuf[2];
//	g_nSelect = selectBuf[3];
//
//	int index = 3 + stack;
//	int i;
//	for (i = 1; i < hits; i++)
//	{
//		stack = selectBuf[index];
//		if (zMax > selectBuf[index + 2])
//		{
//			zMax = selectBuf[index + 2];
//			g_nSelect = selectBuf[index + 3];
//		}
//		index += 3 + stack;
//	}
//}
//
//void draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	DrawBackground();
//	DrawSphere();
//	glFlush();
//	glutSwapBuffers();
//}
//
//void mouse(int button, int state, int x, int y)
//{
//	y = g_nGLHeight - y;
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		Picking(x, y);
//		g_nX = x;
//		g_nY = y;
//	}
//
//	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//	{
//		g_nSelect = 0;
//	}
//}
//
//void motion(int x, int y)
//{
//	y = g_nGLHeight - y;
//	if (g_nSelect > 0)
//	{
//		g_pPosition[(g_nSelect - 1) * 2 + 0] += x - g_nX;
//		g_pPosition[(g_nSelect - 1) * 2 + 1] += y - g_nY;
//		g_nX = x;
//		g_nY = y;
//		glutPostRedisplay();
//	}
//}
//
//
//
////1.원하는 대상 지정
////2. 클릭된 대상으로부터 선택여부 확인을 위한 선택 공간 정의
////3.선택된 대상이 될 수 있는 요소들에게 ID부여(Name Stack)
////4.선택된 ID를통해 정보를 확인
//
//
