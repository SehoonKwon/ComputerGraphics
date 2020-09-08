//#include <gl/glut.h>
//#include <windows.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <String.h>
//
//void init(void);
//void draw(void);
//void idle(void);
//double spin = 0.01;
//
//
//int main(int argc, char** argv)
//{
//
//	// 윈도우 초기화
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//	init(); // 사용자 초기화 함수
//
//
//	// Callback 함수 정의
//	glutDisplayFunc(draw); // draw() -> 실제 그리기 함수
//	glutIdleFunc(idle);
//
//	// Looping 시작
//	glutMainLoop();
//
//	return 0;
//}
//
//void init(void)
//{
//	// 화면의 기본색으로 blue 설정
//	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
//	
//	// 화면 좌표 정보 설정
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
//
//	/*glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glEnable(GL_POINT_SMOOTH);*/
//}
//
//void idle(void)
//{
//	spin = spin + 0.1;
//	if (spin > 360) spin -= 360;
//	glutPostRedisplay();
//}
//
//void draw_point(void)
//{
//	// 점의 색상 RED
//	glColor3f(1.0f, 0.0f, 0.0f);
//
//	// 점의 크기 수정 ( 초기값은 10.0)
//	glPointSize(10.0f);
//
//	glBegin(GL_POINTS);
//	glVertex2i(50, 50);
//	glVertex2i(100, 150);
//	glVertex2i(200, 200);
//	glVertex2i(350, 300);
//	glVertex2i(450, 300);
//	glEnd();
//}
//
//void draw_line(void)
//{
//	/*glLineWidth(2.0f);
//	glEnable(GL_LINE_STIPPLE);
//	glLineStipple(3, 0xAAAA);*/
//
//	// 선의 색상을 노란색으로
//	glColor3f(1.0f, 1.0f, 0.0f);
//	glBegin(GL_LINES);
//	glVertex2i(50, 50);
//	glVertex2i(250, 450);
//	glVertex2i(300, 450);
//	glEnd();
//}
//
//void draw_Left_triangle(void)
//{
//	/*glPolygonMode(GL_FRONT, GL_LINE);
//	glFrontFace(GL_CCW);*/
//	/*glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);*/
//
//	// 면의 색상을 노란색으로
//	//glEnable(GL_BLEND); // 알파 블렌딩 on
//	//glDisable(GL_BLEND); // 알파 블렌딩 off
//	glColor4f(1.0f, 1.0f, 0.0f,0.75);
//	glBegin(GL_TRIANGLES);
//	glVertex2i(100, 300);
//	glVertex2i(300, 200);
//	glVertex2i(100, 100);
//	glEnd();
//}
//
//void draw_triangle(void)
//{
//	// 면의 색상을 노란색으로
//	glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
//	glBegin(GL_TRIANGLES);
//	glVertex2i(100, 100);
//	glVertex2i(300, 400);
//	glVertex2i(400, 100);
//	glEnd();
//}
//
//void draw_Right_triangle(void)
//{
//	// 면의 색상을 청록색으로
//	//glEnable(GL_BLEND);
//	//glDisable(GL_BLEND);
//	glColor4f(0.0f, 1.0f, 1.0f, 0.75);
//	glBegin(GL_TRIANGLES);
//	glVertex2i(400, 300);
//	glVertex2i(200, 200);
//	glVertex2i(400, 100);
//	glEnd();
//}
//
//void draw_string(void *font, const char* str, int x, int y)
//{
//	unsigned int i;
//	glRasterPos2i(x, y);
//	for (i = 0; i < strlen(str); i++)
//	{
//		glutBitmapCharacter(font, str[i]);
//	}
//}
//
//void draw(void)
//{
//	// 화면을 깨끗하게 지우기
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glPushMatrix();
//	glTranslatef(250, 250, 0);
//	glRotatef(spin, 0, 0, 1);
//	glTranslatef(-250, -250, 0);
//	draw_triangle();
//	glPopMatrix();
//
//	//draw_point();
//	//draw_line();
//	//draw_Left_triangle();
//	//draw_Right_triangle();
//
//	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Graphics are cool!!", 10, 10);
//	glColor3f(0.5f, 1.0f, 0);
//	draw_string(GLUT_BITMAP_HELVETICA_18, "I Like Coumputer Graphics!!", 250, 475);
//
//
//	glFlush();
//	glutSwapBuffers();
//}
