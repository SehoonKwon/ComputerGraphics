//#include <gl/glut.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//void init(void);
//void draw(void);
//
//
//int main(int argc, char** argv)
//{
//
//	// 윈도우 초기화
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//	init(); // 사용자 초기화 함수
//
//
//	// Callback 함수 정의
//	glutDisplayFunc(draw); // draw() -> 실제 그리기 함수
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
//}
//
//void draw_point(void)
//{
//	// 점의 색상 RED
//	glColor3f(1.0f, 0.0f, 0.0f);
//
//	// 점의 크기 수정 ( 초기값은 1.0)
//	glPointSize(4.0f);
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
//	glBegin(GL_LINE_LOOP);
//	glVertex2i(50, 50);
//	glVertex2i(250, 450);
//	glVertex2i(300, 450);
//	glVertex2i(400, 100);
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
//	glDisable(GL_BLEND); // 알파 블렌딩 off
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glColor4f(1.0f, 1.0f, 0.0f,0.75);
//	glBegin(GL_TRIANGLES);
//	glVertex2i(100, 300);
//	glVertex2i(300, 200);
//	glVertex2i(100, 100);
//	glEnd();
//}
//
//void draw_Right_triangle(void)
//{
//	// 면의 색상을 청록색으로
//	//glEnable(GL_BLEND);
//	glDisable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glColor4f(0.0f, 1.0f, 1.0f, 0.75);
//	glBegin(GL_TRIANGLES);
//	glVertex2i(400, 300);
//	glVertex2i(200, 200);
//	glVertex2i(400, 100);
//	glEnd();
//}
//
//void draw(void)
//{
//	// 화면을 깨끗하게 지우기
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	//draw_point();
//	//draw_line();
//	draw_Left_triangle();
//	draw_Right_triangle();
//	
//	glFlush();
//}
