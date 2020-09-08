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
//	// ������ �ʱ�ȭ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//	init(); // ����� �ʱ�ȭ �Լ�
//	
//	//  Pop-up menu ���� �� �߰�
//	submenu1 = glutCreateMenu(sub_menu_function);
//	glutAddMenuEntry("Sub1", 1);
//	glutAddMenuEntry("Sub2", 2);
//	glutAddMenuEntry("Sub3", 3); // 3���� �׸��� �ִ� �޴� ����
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Go!", 11);
//	glutAddSubMenu("Sub menu", submenu1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	// Callback �Լ� ����
//	glutDisplayFunc(draw); // draw() -> ���� �׸��� �Լ�
//	glutMouseFunc(mouse);  // mouse -> ���콺 Ŭ�� �� ��ǥ���� ��Ÿ���� �Լ�
//	glutMotionFunc(motion); // motion -> ���콺�� ����� ��Ÿ���� �Լ�
//	glutKeyboardFunc(keyboard); // Ű���� �ݹ� �Լ�
//	
//	// Looping ����
//	glutMainLoop();
//	
//	return 0;
//}
//void init(void)
//{
//	// ȭ���� �⺻������ dark blue ����
//	glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
//}
//void draw(void)
//{
//	// Teapot 1���� �׸��� �ӽ� ��ƾ
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glutWireTeapot(0.5f);
//	glFlush();
//}
//void mouse(int button, int state, int x, int y)
//{
//	// ���ڵ��� �ؼ��ؼ� ���ϴ� ����� ����
//	printf("Mouse button is clicked! (%d, %d, %d, %d) \n", button, state, x, y);
//}
//void motion(int x, int y)
//{
//	// ���ڵ��� �ؼ��ؼ� ���ϴ� ����� ����
//	printf("Mouse is moving!(%d, %d)\n", x, y);
//}
//void keyboard(unsigned char key, int x, int y)
//{
//	// ���ڵ��� �ؼ��ؼ� ���ϴ� ����� ����
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