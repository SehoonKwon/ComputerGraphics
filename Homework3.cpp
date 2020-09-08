//#include <gl/glut.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// 함수 프로토타입
//void init(void);
//void idle(void);
//void draw_point(void);
//void draw_line(void);
//void draw_triangle(void);
//void draw_quadrangle(void);
//void draw(void);
//void mouse(int botton, int state, int x, int y);
//void keyboard(unsigned char key, int x, int y);
//void sub_menu_function(int option);
//void main_menu_function(int option);
//
////전역변수 선언
//enum shape { point = 1, line, triangle, quadrangle, clear }; // 모드 선택시 알기 쉽게 열거형으로 정리
//enum Color_mode { Red = 1, Green, Blue };
//
//int count = 0, draw_mode, Color_mode = Red; // 점의 개수, 그림형태, 색(초기 값 빨강);
//int x_point[10], y_point[10]; //좌표 기억을 위한 배열
//
//// 기능 On-Off를 위한 bool타입 변수
//bool antialiase_on = false; 
//bool StudentName_on = false;
//bool Rotate_on = false;
//
//double spin = 0.01;  // 회전을 위한 변수
//
//
//int main(int argc, char** argv)
//{
//	int submenu1;
//
//	// 윈도우 초기화
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//	init(); // 사용자 초기화 함수
//
//	submenu1 = glutCreateMenu(sub_menu_function); //서브메뉴 생성
//	glutAddMenuEntry("점", 1);
//	glutAddMenuEntry("선", 2);
//	glutAddMenuEntry("삼각형", 3);
//	glutAddMenuEntry("사각형", 4);
//	glutAddMenuEntry("초기화", 5); // 5개의 항목이 있는 메뉴 생성
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddSubMenu("list", submenu1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	//// Callback 함수 정의
//	glutDisplayFunc(draw); // draw() -> 실제 그리기 함수
//	glutMouseFunc(mouse);  // mouse -> 마우스 클릭 및 좌표등을 나타내는 함수
//	glutIdleFunc(idle);	// 
//	glutKeyboardFunc(keyboard); // 키보드 콜백 함수
//
//								// Looping 시작
//	glutMainLoop();
//
//	return 0;
//}
//
//void init(void)
//{
//	// 화면의 기본색으로 blue 설정
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	// 화면 좌표 정보 설정
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
//}
//
//void idle(void)
//{
//	//회전하라는 명령이 on일때만 작동
//	if (Rotate_on == true)
//	{
//		spin = spin + 0.1;
//		if (spin > 360) spin -= 360;
//	}
//	glutPostRedisplay(); // 화면 다시 띄우기
//}
//
//// 점을 그리는 함수
//void draw_point()
//{
//	
//	glPointSize(30.0f); //점의 크기 30, 초기 값은 1.0
//
//	glBegin(GL_POINTS);
//	for (int i = 0; i < count; i++)
//	{
//		glVertex2i(x_point[i], y_point[i]);
//	}
//	glEnd();
//
//	glFlush();
//}
//
//// 선을 그리는 함수
//void draw_line()
//{
//	glBegin(GL_LINES);
//	for (int i = 0; i<count; i++)
//	{
//		glVertex2i(x_point[i], y_point[i]);
//	}
//	glEnd();
//
//	glFlush();
//}
//
//// 삼각형을 그리는 함수
//void draw_triangle()
//{
//	glBegin(GL_TRIANGLES);
//	for (int i = 0; i<count; i++)
//	{
//		glVertex2i(x_point[i], y_point[i]);
//	}
//	glEnd();
//	
//	glFlush();
//}
//
//// 사각형을 그리는 함수
//void draw_quadrangle()
//{
//	glBegin(GL_QUADS);
//	for (int i = 0; i<count; i++)
//	{
//		glVertex2i(x_point[i], y_point[i]);
//	}
//	glEnd();
//
//	glFlush();
//}
//
////문자열을 생성하는 함수
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
////사용자 설정 드로우 함수. 함수들을 이용해 실제 그림을 그리도록 작동
//void draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT); // 화면 초기화
//
//	//색 모드에 따른 색 변경
//	if (Color_mode == Red) glColor3f(1.0f, 0.0f, 0.0f);
//	else if (Color_mode == Green) glColor3f(0.0f, 1.0f, 0.0f);
//	else if (Color_mode == Blue) glColor3f(0.0f, 0.0f, 1.0f);
//
//	glMatrixMode(GL_MODELVIEW); //모드 변경
//	glLoadIdentity(); //행렬 초기화
//
//	//회전을 위한 행렬
//	glPushMatrix();
//	glTranslatef(250, 250, 0); 
//	glRotatef(spin, 0, 0, 1); // 회전
//	glTranslatef(-250, -250, 0);
//
//	//드로우 모드에 따라 어떻게 그릴지 설정하는 스위치문
//	switch (draw_mode)
//	{
//
//	case point:
//		draw_point();
//		break;
//
//	case line:
//		draw_line();
//		break;
//
//	case triangle:
//		draw_triangle();
//		break;
//
//	case quadrangle:
//		draw_quadrangle();
//		break;
//
//	default:
//		break;
//
//	}
//	glPopMatrix(); // push와 pop은 짝. 회전을 도형에만 적용하기 위해 매트릭스와 드로우만 포함시킴.
//
//	//이름을 띄우는 작업 on일때 화면에 문자열 생성
//	if (StudentName_on == true)
//	{
//		glColor3f(1.0f, 1.0f, 0.0f);
//		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "12131649 Kwon-Sehoon", 10, 30);
//	}
//
//	//안티앨리애싱 작업이 on일때 화면에 안티앨리애싱을 한다는 문자열 생성
//	if (antialiase_on == true)
//	{
//		glColor3f(1.0f, 0.0f, 1.0f);
//		draw_string(GLUT_BITMAP_HELVETICA_18, "Antialiasing", 400, 475);
//	}
//
//	//회전 작업이 on일때 회전하는 중이라는 문자열 생성
//	if (Rotate_on == true)
//	{
//		glColor3f(1.0f, 1.0f, 1.0f);
//		draw_string(GLUT_BITMAP_HELVETICA_18, "Rotate", 400, 30);
//	}
//
//	glFlush(); // 명령어들 모두 실행 후 비움
//	glutSwapBuffers(); // 프론트 버퍼와 백버퍼를 스왑해줌.
//}
//
////마우스 클릭시 작동하는 콜백함수
//void mouse(int button, int state, int x, int y)
//{
//	//왼쪽 버튼이 눌렸을 때만 작업
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		printf("%d %d\n", x, 500 - y);
//		x_point[count] = x;
//		y_point[count] = 500 - y; // 원래는 왼쪽 위가 좌표 0.0 이기에 아래쪽을 0.0으로 설정하면 마우스의 좌표받는 함수를 바꿔주어야 함.
//		count++; // 점의 개수 증가
//	}
//	glutPostRedisplay(); // 화면 재생성
//}
//
////키보드 콜백 함수
//void keyboard(unsigned char key, int x, int y)
//{
//	printf("Pressed %c\n", key); //누른 키 표시
//
//	//'a'키가 눌렸을 때 작동
//	if (key == 'a')
//	{
//		if (antialiase_on == false) antialiase_on = true; // 안티앨리애싱 on , 초기 값은 off라 첫 a키 누를시 온.
//		else antialiase_on = false; //안티앨리애싱이 off상태에서 a키가 눌리면 온으로 바꿈.
//
//		//안티앨리애싱 작업이 on일 때 안티앨리애싱 기능 실행
//		if (antialiase_on == true)
//		{
//			glEnable(GL_BLEND);
//			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//			glEnable(GL_POINT_SMOOTH);
//			glEnable(GL_LINE_SMOOTH);
//			glEnable(GL_POLYGON_SMOOTH);
//		}
//		//안티앨리애싱 작업이 off일 때 안티앨리애싱 기능 오프
//		else
//		{
//			glDisable(GL_BLEND);
//			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//			glDisable(GL_POINT_SMOOTH);
//			glDisable(GL_LINE_SMOOTH);
//			glDisable(GL_POLYGON_SMOOTH);
//		}
//	}
//
//	//'n'키가 눌렸을 때 작동
//	if (key == 'n')
//	{
//		if (StudentName_on == false) StudentName_on = true; // 이름 띄우는 기능 on. 초기 값은 off라 첫 n키 누를 시 온
//		else StudentName_on = false; // 이름 띄우는 기능이 온 상태일 때 n키가 눌리면 오프
//	}
//
//	//'s'키가 눌렸을 때 작동
//	if (key == 's')
//	{
//		if (Rotate_on == false) Rotate_on = true; //회전 기능 on. 초기 값은 off라 첫 s키 누를시 온
//		else Rotate_on = false; // 회전기능이 온 상태에서 s키가 눌리면 회전 기능 오프
//	}
//
//	//누르는 키에 따른 색 변화
//	if (key == 'r') Color_mode = Red;
//	else if (key == 'g') Color_mode = Green;
//	else if (key == 'b') Color_mode = Blue;
//
//	glutPostRedisplay();
//}
//
////서브메뉴 옵션에 따른 기능
//void sub_menu_function(int option)
//{
//	//서브메뉴에서 고른 메뉴에 따라 그리는 모드를 설정함.
//	switch (option)
//	{
//	case point:
//		printf("you select point\n");
//		draw_mode = point;
//		break;
//
//	case line:
//		printf("you slect line\n");
//		draw_mode = line;
//		break;
//
//	case triangle:
//		printf("you select triangle\n");
//		draw_mode = triangle;
//		break;
//
//	case quadrangle:
//		draw_mode = quadrangle;
//		printf("you select quadrangle\n");
//		break;
//
//	case clear:
//		count = 0;
//		break;
//
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//
////메인메뉴에 대한 기능. Quit를 누를시 프로그램 종료.
//void main_menu_function(int option)
//{
//	printf("Submenu %d has been selected\n", option);
//	if (option == 999) exit(0);
//}