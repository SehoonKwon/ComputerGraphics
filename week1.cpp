//#include <gl/glut.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//void init(void);
//void draw(void);
//void mouse(int botton, int state, int x, int y);
//void motion(int x, int y);
//void keyboard(unsigned char key, int x, int y);
//void sub_menu_function(int option);
//void main_menu_function(int option);
//
//int main(int argc, char** argv)
//{
//	int submenu1;
//
//	// 윈도우 초기화
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//	init(); // 사용자 초기화 함수
//	
//	//  Pop-up menu 생성 및 추가
//	submenu1 = glutCreateMenu(sub_menu_function);
//	glutAddMenuEntry("Sub1", 1);
//	glutAddMenuEntry("Sub2", 2);
//	glutAddMenuEntry("Sub3", 3); // 3개의 항목이 있는 메뉴 생성
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Go!", 11);
//	glutAddSubMenu("Sub menu", submenu1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	// Callback 함수 정의
//	glutDisplayFunc(draw); // draw() -> 실제 그리기 함수
//	glutMouseFunc(mouse);  // mouse -> 마우스 클릭 및 좌표등을 나타내는 함수
//	glutMotionFunc(motion); // motion -> 마우스의 모션을 나타내는 함수
//	glutKeyboardFunc(keyboard); // 키보드 콜백 함수
//	
//	// Looping 시작
//	glutMainLoop();
//	
//	return 0;
//}
//void init(void)
//{
//	// 화면의 기본색으로 dark blue 설정
//	glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
//}
//void draw(void)
//{
//	// Teapot 1개를 그리는 임시 루틴
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glutWireTeapot(0.5f);
//	glFlush();
//}
//void mouse(int button, int state, int x, int y)
//{
//	// 인자들을 해석해서 원하는 기능을 구현
//	printf("Mouse button is clicked! (%d, %d, %d, %d) \n", button, state, x, y);
//}
//void motion(int x, int y)
//{
//	// 인자들을 해석해서 원하는 기능을 구현
//	printf("Mouse is moving!(%d, %d)\n", x, y);
//}
//void keyboard(unsigned char key, int x, int y)
//{
//	// 인자들을 해석해서 원하는 기능을 구현
//	printf("You pressed %c\n", key);
//}
//
//void sub_menu_function(int option)
//{
//	printf("Submenu %d has been selected\n", option);
//}
//
//void main_menu_function(int option)
//{
//	printf("Submenu %d has been selected\n", option);
//	if (option == 999) exit(0);
//}