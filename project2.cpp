//#pragma comment(lib, "legacy_stdio_definitions.lib")
//#include <gl/glut.h>
//#include <stdio.h>
//#include <math.h> 
//#include <Windows.h>
//#include <gl/GLAUX.H>
//#include <iostream>
//using namespace std;
//
//double E_angle = 76 , A_angle = 0; // �������� ��ȯ�ϱ� ���� Degree ���� ����.
//#define PI 3.141592
//#define E_Radian PI*E_angle/180 //C������ ���ȸ� ��밡���ϴ�.
//#define A_Radian PI*A_angle/180
//
//void init();
//void resize(int width, int height);
//void draw();
//void specialkey(int key, int x, int y); //ī�޶��� ������ �ٲٴ� Ű�� �Է¹ޱ� ���� �Լ�
//void keyboard(unsigned char key, int x, int y); //����� ���� Ű���� callback �Լ�
//void sub_menu_function(int option);
//void main_menu_function(int option);
//void draw_axis();
//
//void draw_Printer_up();
//void draw_Printer_up2();
//void draw_Printer_front();
//void draw_Printer_front1();
//void draw_Printer_front2();
//void draw_Printer_front3();
//void draw_Printer_front4();
//void draw_Printer_front4_2();
//void draw_Printer_front4_3();
//void draw_Printer_front4_4();
//void draw_Printer_front5();
//void draw_Printer_front5_2();
//void draw_Printer_front5_3();
//void draw_Printer_front5_4();
//void draw_Printer_front6();
//void draw_Printer_front6_1();
//void draw_Printer_right1();
//void draw_Printer_right2();
//void draw_Printer_right3();
//void draw_Printer_right4();
//void draw_Printer_right5();
//void draw_Printer_left();
//void draw_Printer_left2();
//void draw_Printer_left3();
//void draw_Printer_back1();
//void draw_Printer_back2();
//void draw_Printer_back2_2();
//void draw_Printer_back2_3();
//void draw_Printer_back2_4();
//void draw_Printer_back2_5();
//void draw_Printer_back2_5_1();
//void draw_Printer_back2_5_2();
//void draw_Printer_back2_5_3();
//void draw_Printer_back2_6();
//void draw_Printer_down();
//void draw_Ink_can();
//void draw_Ink_can_cover();
//void draw_Ink_can_cover2();
//void draw_Ink_can_down_cover();
//void draw_Ink_down_Color(int Ink_down_Color);
//void draw_Ink_Red(float Red);
//void draw_Ink_Yellow(float Yellow);
//void draw_Ink_Blue(float Blue);
//void draw_Ink_Black(float Black);
//void draw_MyPrinter_Up();
//void draw_MyPrinter_Right();
//void draw_MyPrinter_Front();
//void draw_MyPrinter_Left();
//void draw_MyPrinter_Down();
//void draw_MyPrinter_Back();
//void draw_MyPrinter();
//void draw_MyInk();
//
//GLUquadric *q;
//
//bool Light = true;
//bool Printing = false;
//bool Ink_Cover = true;
//bool Ink_Cover2 = true;
//bool Ink_Cover3 = true;
//bool Ink_Cover4 = true;
//bool Act_Printing_on = false;
//
//bool Ink_cover_off = false;
//bool Ink_cover_off2 = false;
//bool Ink_cover_off3 = false;
//bool Ink_cover_off4 = false;
//bool Sleep_off = false;
//bool Sleep_off2 = false;
//bool Sleep_off3 = false;
//bool Sleep_off4 = false;
//bool Sleep_off_print = false;
//bool Printmode_change = true;
//
//int Ink_cover_count = 0;
//int Ink_cover_count2 = 0;
//int Ink_cover_count3 = 0;
//int Ink_cover_count4 = 0;
//int Ink_down_Color = 0;
//
//int Printing_A4_count = 0;
//
//float Red = 0, Yellow = 0, Blue = 0, Black = 0;
//
//int r = 20; // ������ǥ�迡�� ����-��P������ �Ÿ�
//
//enum Printmode { Apple = 1, Strawberry, Pear, InhaF, InhaJ, InhaH, Gyeryong, Taebaek, Bukhan};
//int Printmode = 0;
//GLuint texName[9];
//
//int main(int argc, char** argv)
//{
//	int submenu1, submenu2, submenu3;
//
//	// ������ �ʱ�ȭ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(1000, 800);
//	glutInitWindowPosition(50, 70);
//	glutCreateWindow("Computer Graphcis Mini Project");
//
//	//  Popup menu ���� �� �߰�
//	submenu1 = glutCreateMenu(sub_menu_function);
//	glutAddMenuEntry("Apple", 1);
//	glutAddMenuEntry("Strawberry", 2);
//	glutAddMenuEntry("Pear", 3); // 3���� �׸��� �ִ� �޴� ����
//
//	submenu2 = glutCreateMenu(sub_menu_function);
//	glutAddMenuEntry("Inha Univ. Front", 4);
//	glutAddMenuEntry("Inha Univ. Jeongsuk", 5);
//	glutAddMenuEntry("Inha Univ Hightech", 6);
//
//	submenu3 = glutCreateMenu(sub_menu_function);
//	glutAddMenuEntry("Gyeryong mountin", 7);
//	glutAddMenuEntry("Taebaek mountin", 8);
//	glutAddMenuEntry("Bukhan mountin", 9);
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddSubMenu("Fruits", submenu1);
//	glutAddSubMenu("Inha Univ.", submenu2);
//	glutAddSubMenu("Scenery", submenu3);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutKeyboardFunc(keyboard);
//	glutSpecialFunc(specialkey);
//	init();
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void init()
//{
//	glClearColor(0.5f, 0.5f, 0.5f, 1);
//	glClearDepth(1.0f);
//
//	glGenTextures(9, texName);
//	AUX_RGBImageRec *pRGBImage;
//
//	glBindTexture(GL_TEXTURE_2D, texName[0]);
//	pRGBImage = auxDIBImageLoadA("./map/Apple.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texName[1]);
//	pRGBImage = auxDIBImageLoadA("./map/Strawberry.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texName[2]);
//	pRGBImage = auxDIBImageLoadA("./map/Pear.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texName[3]);
//	pRGBImage = auxDIBImageLoadA("./map/InhaF.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texName[4]);
//	pRGBImage = auxDIBImageLoadA("./map/InhaJ.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texName[5]);
//	pRGBImage = auxDIBImageLoadA("./map/InhaH.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texName[6]);
//	pRGBImage = auxDIBImageLoadA("./map/GM.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texName[7]);
//	pRGBImage = auxDIBImageLoadA("./map/TM.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texName[8]);
//	pRGBImage = auxDIBImageLoadA("./map/NM.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage->sizeX, pRGBImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
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
//	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//	
//	glEnable(GL_LIGHTING);
//	glEnable(GL_DEPTH_TEST);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
////	glEnable(GL_BLEND);
//	glEnable(GL_POINT_SMOOTH);
//	glEnable(GL_LINE_SMOOTH);
//	glEnable(GL_POLYGON_SMOOTH);
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
//  //x, y, z �� ����
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
//void draw_Quad()
//{
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 1, 0);	glVertex3f(-1.0f, 1.0f, 0.0f);
//	glNormal3f(0, 1, 0);	glVertex3f(1.0f, 1.0f, 0.0f);
//	glNormal3f(0, 1, 0);	glVertex3f(1.0f, 0.0f, 0.0f);
//	glNormal3f(0, 1, 0);	glVertex3f(-1.0f, 0.0f, 0.0f);
//	glEnd();
//}
//
//void draw_Printer_up() //����
//{
//	glColor3f(0.0, 0.0f, 0.0f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, 1);	glVertex3f(-5.0f, 3.0f, -1.0f);
//	glNormal3f(0, 0, 1);	glVertex3f(5.0f, 3.0f, -1.0f);
//	glNormal3f(0, 0, 1);	glVertex3f(5.0f, 3.0f, 3.0f);
//	glNormal3f(0, 0, 1);	glVertex3f(-5.0f, 3.0f, 3.0f);
//	glEnd();
//}
//
//void draw_Printer_up2() // ���κ�
//{
////	glPushMatrix();
//////	glEnable(GL_TEXTURE_2D);
//////	glBindTexture(GL_TEXTURE_2D, texName[0]);
////	glColor3f(0, 0.2f, 0.4f);
////	glBegin(GL_POLYGON);
////	glTexCoord2f(0, 0);	glNormal3f(0, 1, 1);	glVertex3f(-5.0f, 3.0f, 3.0f);
////	glTexCoord2f(1, 0);	glNormal3f(0, 1, 1);	glVertex3f(5.0f, 3.0f, 3.0f);
////	glTexCoord2f(1, 1);	glNormal3f(0, 1, 1);	glVertex3f(5.0f, 2.2f, 3.5f);
////	glTexCoord2f(0, 1);	glNormal3f(0, 1, 1);	glVertex3f(-5.0f, 2.2f, 3.5f);
////	glEnd();
//////	glDisable(GL_TEXTURE_2D);
////	glPopMatrix();
//	glPushMatrix();
//	glScalef(5, 0.8, 1);
//	glTranslatef(0,2.8, 3.5);
//	glRotatef(-30, 1, 0, 0);
//	draw_Quad();
//	glPopMatrix();
//
//
//
//}
//
//void draw_Printer_front() 
//{
//	glColor3f(0, 0, 0.5f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, 1);	glVertex3f(-5.0f, 2.2f, 3.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(5.0f, 2.2f, 3.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(5.0f, 1.9f, 3.4f);
//	glNormal3f(0, 0, 1);	glVertex3f(-5.0f, 1.9f, 3.4f);
//	glEnd();
//}
//
//void draw_Printer_front1()
//{
//	glColor3f(0, 0, 0);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, 1);	glVertex3f(-5.0f, 1.9f, 3.4f);
//	glNormal3f(0, 0, 1);	glVertex3f(-2.5f, 1.9f, 3.4f);
//	glNormal3f(0, 0, 1);	glVertex3f(-2.5f, 0.0f, 3.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(-5.0f, 0.0f, 3.5f);
//	glEnd();
//}
//
//void draw_Printer_front2()
//{
//	glColor3f(0, 0, 0.0f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, 1);	glVertex3f(2.5f, 1.9f, 3.4f);
//	glNormal3f(0, 0, 1);	glVertex3f(5.0f, 1.9f, 3.4f);
//	glNormal3f(0, 0, 1);	glVertex3f(5.0f, 0.0f, 3.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(2.5f, 0.0f, 3.5f);
//	glEnd();
//}
//
//void draw_Printer_front3()
//{
//	glColor3f(0, 0, 0.0f); 
//	glBegin(GL_POLYGON);
//	glVertex3f(-2.5f, 1.9f, 3.4f);
//	glVertex3f(2.5f, 1.9f, 3.4f);
//	glVertex3f(2.5f, 1.7f, 3.38f);
//	glVertex3f(-2.5f, 1.7f, 3.38f);
//	glEnd();
//}
//
//void draw_Printer_front4() 
//{
//	glColor3f(0, 0.5f, 0.1f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 1, 0);	glVertex3f(-2.5f, 1.2f, 2.5f);
//	glNormal3f(0, 1, 0);	glVertex3f(2.5f, 1.2f, 2.5f);
//	glNormal3f(0, 1, 0);	glVertex3f(2.5f, 1.2f, 5.5f);
//	glNormal3f(0, 1, 0);	glVertex3f(-2.5f, 1.2f, 5.5f);
//	glEnd();
//}
//
//void draw_Printer_front4_2()
//{
//	glColor3f(0, 0.5f, 0.1f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0);	glVertex3f(-2.5f, 0.8f, 2.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(2.5f, 0.8f, 2.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(2.5f, 0.8f, 5.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(-2.5f, 0.8f, 5.5f);
//	glEnd();
//}
//
//void draw_Printer_front4_3()  
//{
//	glColor3f(0, 0.5f, 0.1f);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 1.2f, 2.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 1.2f, 5.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 0.8f, 5.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 0.8f, 2.5f);
//	glEnd();
//}
//
//void draw_Printer_front4_4() 
//{
//	glColor3f(0, 0.5f, 0.1f);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 1.2f, 2.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 1.2f, 5.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 0.75f, 5.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 0.75f, 2.5f);
//	glEnd();
//}
//
//void draw_Printer_front5()
//{
//	glColor3f(0, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, 1);	glVertex3f(-2.5f, 0.6f, 2.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(2.5f, 0.6f, 2.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(2.5f, 0.6f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(-2.5f, 0.6f, 5.5f);
//	glEnd();
//}
//
//void draw_Printer_front5_2()
//{
//	glColor3f(0, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glVertex3f(-2.5f, 0.01f, 2.5f);
//	glVertex3f(2.5f, 0.01f, 2.5f);
//	glVertex3f(2.5f, 0.01f, 5.5f);
//	glVertex3f(-2.5f, 0.01f, 5.5f);
//	glEnd();
//}
//
//void draw_Printer_front5_3()
//{
//	glColor3f(0, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 0.6f, 2.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 0.6f, 5.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 0.0f, 5.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 0.0f, 2.5f);
//	glEnd();
//}
//
//void draw_Printer_front5_4()
//{
//	glColor3f(0, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 0.6f, 2.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 0.6f, 5.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 0.0f, 5.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 0.0f, 2.5f);
//	glEnd();
//}
//
//void draw_Printer_front5_5() // �������� ���� ��
//{
//	glColor3f(0.2f, 0.2f, 0.2f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 1, 0);	glVertex3f(-2.2f, 1.0f, 5.5f);
//	glNormal3f(0, 1, 0);	glVertex3f(2.2f, 1.0f, 5.5f);
//	glNormal3f(0, 1, 0);	glVertex3f(2.2f, 1.0f, 8.5f);
//	glNormal3f(0, 1, 0);	glVertex3f(-2.2f, 1.0f, 8.5f);
//	glEnd();
//}
//
//void draw_Printer_front6()
//{
//	glColor3f(0, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, 1);	glVertex3f(-2.5f, 0.6f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(-1.25f, 0.6f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(-1.25f, 0.0f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(-2.5f, 0.0f, 5.5f);
//	glEnd();
//}
//
//void draw_Printer_front6_1()
//{
//	glColor3f(0, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, 1);	glVertex3f(1.25f, 0.6f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(2.5f, 0.6f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(2.5f, 0.0f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(1.25f, 0.0f, 5.5f);
//	glEnd();
//}
//
//void draw_Printer_front6_2() //���� �ִ� �� ��-����
//{
//	glColor3f(0, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, 1);	glVertex3f(-1.25f, 0.6f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(1.25f, 0.6f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(1.25f, 0.4f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(-1.25f, 0.4f, 5.5f);
//	glEnd();
//}
//
//void draw_Printer_front6_3() // ���� �ִ� �� ��-�Ʒ���
//{
//	glColor3f(0, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, 1);	glVertex3f(-1.25f, 0.01f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(1.25f, 0.01f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(1.25f, 0.01f, 5.5f);
//	glNormal3f(0, 0, 1);	glVertex3f(-1.25f, 0.01f, 5.5f);
//	glEnd();
//}
//
//void draw_Printer_right1() //����-���� ���� ���κ�
//{
//	glColor3f(0.5f, 0.8f, 0.2f);
//	glBegin(GL_POLYGON);
//		glVertex3f(5.0f, 3.0f, -1.0f);
//		glVertex3f(5.05f, 2.9f, -1.0f);
//		glVertex3f(5.05f, 2.9f, 3.0f);
//		glVertex3f(5.0f, 3.0f, 3.0f);
//	glEnd();
//}
//
//void draw_Printer_right2() //���-���� ���� ���κ�
//{
//	glColor3f(0, 0.4f, 0.2f);
//	glBegin(GL_POLYGON);
//		glVertex3f(5.0f, 3.0f, 3.0f);
//		glVertex3f(5.05f, 2.9f, 3.0f);
//		glVertex3f(5.05f, 2.1f, 3.5f);
//		glVertex3f(5.0f, 2.2f, 3.5f);
//	glEnd();
//}
//
//void draw_Printer_right3() // ���� �� ���κ�
//{
//	glColor3f(0.2f, 0.2f, 0.2f);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.9f, 3.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.9f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.1f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.1f, 3.5f);
//	glEnd();
//}
//
//void draw_Printer_right4() // ���� �� ��� �κ�
//{
//	glColor3f(0.2f, 0.2f, 0.2f);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.1f, 3.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.1f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 1.9f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 1.9f, 3.4f);
//	glEnd();
//}
//
//void draw_Printer_right5() // ���� �� �Ʒ��κ�
//{
//	glColor3f(0.2f, 0.2f, 0.2f);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 1.9f, 3.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 1.9f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 0.0f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.0f, 0.0f, 3.5f);
//	glEnd();
//}
//
//void draw_Printer_left() // ���� �� �κ�
//{
//	glColor3f(0.2f, 0.2f, 0.2f);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 3.0f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 3.0f, 3.0);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 2.2f, 3.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 2.2f, -1.0f);
//	glEnd();
//}
//
//void draw_Printer_left2() // ���� �߰� �κ�
//{
//	glColor3f(0.2f, 0.2f, 0.2f);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 2.2f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 2.2f, 3.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.9f, 3.4f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.9f, -1.0f);
//	glEnd();
//}
//
//void draw_Printer_left3() // ���� �Ʒ� �κ�
//{
//	glColor3f(0.2f, 0.2f, 0.2f);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.9f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.9f, 3.4f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 0.0f, 3.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 0.0f, -1.0f);
//	glEnd();
//}
//
//void draw_Printer_back1() //�������� ����
//{
//	glColor3f(0, 0.0f, 0.2f);
//	glBegin(GL_POLYGON);
//		glVertex3f(-5.0f, 3.0f, -1.0f);
//		glVertex3f(5.0f, 3.0f, -1.0f);
//		glVertex3f(5.0f, 0.0f, -1.0f);
//		glVertex3f(-5.0f, 0.0f, -1.0f);
//	glEnd();
//}
//
//void draw_Printer_back2() //������ ������ Ƣ��� �κ�ǥ��
//{
//	glColor3f(0.4f, 0.4f, 0.0f);
//	glBegin(GL_POLYGON);
//		glVertex3f(-4.5f, 2.8f, -1.2f);
//		glVertex3f(5.0f, 2.8f, -1.2f);
//		glVertex3f(5.0f, 1.8f, -1.2f);
//		glVertex3f(-4.5f, 1.8f, -1.2f);
//	glEnd();
//}
//
//void draw_Printer_back2_2() // ����-Ƣ���-��
//{
//	glColor3f(0.4f, 0.2f, 0.2f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 1, 0);	glVertex3f(-4.5f, 2.8f, -1.2f);
//	glNormal3f(0, 1, 0);	glVertex3f(5.0f, 2.8f, -1.2f);
//	glNormal3f(0, 1, 0);	glVertex3f(5.0f, 2.8f, -1.0f);
//	glNormal3f(0, 1, 0);	glVertex3f(-4.5f, 2.8f, -1.0f);
//	glEnd();
//}
//
//void draw_Printer_back2_3() // ����-Ƣ���-����
//{
//	glColor3f(0.6f, 0.2f, 0.2f);
//	glBegin(GL_POLYGON);
//		glVertex3f(-4.5f, 2.8f, -1.2f);
//		glVertex3f(-4.5f, 2.8f, -1.0f);
//		glVertex3f(-4.5f, 1.8f, -1.0f);
//		glVertex3f(-4.5f, 1.8f, -1.2f);
//	glEnd();
//}
//
//void draw_Printer_back2_4() // ����-Ƣ���-��
//{
//	glColor3f(0.6f, 0.2f, 0.2f);
//	glBegin(GL_POLYGON);
//		glVertex3f(5.0f, 2.8f, -1.2f);
//		glVertex3f(5.0f, 2.8f, -1.0f);
//		glVertex3f(5.0f, 1.8f, -1.0f);
//		glVertex3f(5.0f, 1.8f, -1.2f);
//	glEnd();
//}
//
//void draw_Printer_back2_5() // ����-Ƣ���-����-�Ʒ�
//{
//	glColor3f(0.2f, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, -1);	glVertex3f(-2.5f, 1.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(-5.0f, 1.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(-5.0f, 0.4f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(-2.5f, 0.4f, -1.2f);
//	glEnd();
//}
//
//void draw_Printer_back2_5_1() // ����-Ƣ���-����-�Ʒ�-�Ʒ�
//{
//	glColor3f(0.2f, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0);	glVertex3f(-2.5f, 0.4f, -1.2f);
//	glNormal3f(0, -1, 0);	glVertex3f(-5.0f, 0.4f, -1.2f);
//	glNormal3f(0, -1, 0);	glVertex3f(-5.0f, 0.4f, -1.0f);
//	glNormal3f(0, -1, 0);	glVertex3f(-2.5f, 0.4f, -1.0f);
//	glEnd();
//}
//
//void draw_Printer_back2_5_2() // ����-Ƣ���-����-�Ʒ�-����
//{
//	glColor3f(0.2f, 0.1f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.8f, -1.2f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.8f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 0.4f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 0.4f, -1.2f);
//	glEnd();
//}
//
//void draw_Printer_back2_5_3() // ����-Ƣ���-����-�Ʒ�-��
//{
//	glColor3f(0.2f, 0.1f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 1.8f, -1.2f);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 1.8f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 0.4f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 0.4f, -1.2f);
//	glEnd();
//}
//
//void draw_Printer_back2_6() // ����-Ƣ���-��-�Ʒ�
//{
//	glColor3f(0.2f, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, -1);	glVertex3f(2.5f, 1.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(5.0f, 1.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(5.0f, 0.4f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(2.5f, 0.4f, -1.2f);
//	glEnd();
//}
//
//void draw_Printer_back2_6_2() // ����-Ƣ���-��-�Ʒ�-�Ʒ�
//{
//	glColor3f(0.2f, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0);	glVertex3f(2.5f, 0.4f, -1.2f);
//	glNormal3f(0, -1, 0);	glVertex3f(5.0f, 0.4f, -1.2f);
//	glNormal3f(0, -1, 0);	glVertex3f(5.0f, 0.4f, -1.0f);
//	glNormal3f(0, -1, 0);	glVertex3f(2.5f, 0.4f, -1.0f);
//	glEnd();
//}
//
//void draw_Printer_back2_6_3() // ����-Ƣ���-��-�Ʒ�-����
//{
//	glColor3f(0.2f, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 1.8f, -1.2f);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 1.8f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 0.4f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 0.4f, -1.2f);
//	glEnd();
//}
//
//void draw_Printer_back2_6_4() // ����-Ƣ���-��-�Ʒ�-��
//{
//	glColor3f(0.2f, 0.2f, 0.4f);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(5.0f, 1.8f, -1.2f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.0f, 1.8f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.0f, 0.4f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.0f, 0.4f, -1.2f);
//	glEnd();
//}
//
//
//void draw_Printer_down()
//{
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0);	glVertex3f(-5.0f, 0.0f, 3.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(5.0f, 0.0f, 3.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(5.0f, 0.0f, -1.0f);
//	glNormal3f(0, -1, 0);	glVertex3f(-5.0f, 0.0f, -1.0f);
//	glEnd();
//}
//
//void draw_Ink_can()
//{
//	glDisable(GL_DEPTH_TEST);
//	q = gluNewQuadric();
//	glPushMatrix();
//		glEnable(GL_BLEND); 
//		glColor4f(0.9f, 0.9f, 0.9f, 0.1f); //��ũ���� ǥ���ϱ� ���� �ִ��� ����� ������ ǥ��
//		gluQuadricNormals(q, GLU_NONE);
//		gluCylinder(q, 0.5, 0.5, 1, 50, 50);
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//	glEnable(GL_DEPTH_TEST);
//}
//
//void draw_Ink_can_cover()
//{
//	q = gluNewQuadric();
//	glColor3f(0.2f, 0.2f, 0.2f);
//	gluQuadricDrawStyle(q, GLU_FILL);
//	gluCylinder(q, 0.4, 0.4, 0.2, 50, 50);
//	glFlush();
//	gluDeleteQuadric(q);
//}
//
//void draw_Ink_can_cover2()
//{
//	q = gluNewQuadric();
//	glColor3f(0.4f, 0.4f, 0.1f);
//	gluDisk(q, 0, 0.4, 50, 50);
//	glFlush();
//	gluDeleteQuadric(q);
//}
//
//void draw_Ink_can_down_cover()
//{
//	q = gluNewQuadric();
//	glColor4f(0.9f, 0.9f, 0.9f, 0.1f);
//	gluDisk(q, 0, 0.5, 50, 50);
//	glFlush();
//	gluDeleteQuadric(q);
//}
//
//void draw_Ink_down_Color(int Ink_down_Color)
//{
//	q = gluNewQuadric();
//	if (Ink_down_Color == 1) glColor3f(1.0f, 0, 0);
//	else if (Ink_down_Color == 2) glColor3f(0, 0, 1.0f);
//	else if (Ink_down_Color == 3) glColor3f(1.0f, 0.8f, 0.0f);
//	else if (Ink_down_Color == 4) glColor3f(0, 0, 0);
//	gluDisk(q, 0, 0.48, 50, 50);
//	glFlush();
//	gluDeleteQuadric(q);
//}
//
//void draw_Ink_Red(float Red) 	///������ ��ũ ä���
//{
//	glPushMatrix();
//		glTranslatef(6, 0, -0.6);//ù ��° ��ũ�� ��ġ
//		q = gluNewQuadric();
//		glColor3f(1, 0, 0);
//		glPushMatrix();
//			gluQuadricNormals(q, GLU_NONE);
//			glRotatef(90, -1, 0, 0);
//			gluCylinder(q, 0.48, 0.48, Red, 50, 50);
//		glPopMatrix();
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
//
//void draw_Ink_Blue(float Blue) 	///������ ��ũ ä���
//{
//	glPushMatrix();
//		glTranslatef(6, 0, 0.6);//�� ��° ��ũ�� ��ġ
//		q = gluNewQuadric();
//		glColor3f(0, 0, 1);
//		glPushMatrix();
//			gluQuadricNormals(q, GLU_NONE);
//			glRotatef(90, -1, 0, 0);
//			gluCylinder(q, 0.48, 0.48, Blue, 50, 50);
//		glPopMatrix();
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
//
//void draw_Ink_Yellow(float Yellow) 	///����� ��ũ ä���
//{
//	glPushMatrix();
//		glTranslatef(6, 0, 1.8); // �� ��° ��ũ�� ��ġ
//		q = gluNewQuadric();
//		glColor3f(1, 0.8, 0);
//		glPushMatrix();
//			gluQuadricNormals(q, GLU_NONE);
//			glRotatef(90, -1, 0, 0);
//			gluCylinder(q, 0.48, 0.48, Yellow, 50, 50);
//			glPopMatrix();
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
//
//void draw_Ink_Black(float Black) 	///������ ��ũ ä���
//{
//	glPushMatrix();
//		glTranslatef(6, 0, 3);//ù ��° ��ũ�� ��ġ
//		q = gluNewQuadric();
//		glColor3f(0, 0, 0);
//		glPushMatrix();
//			gluQuadricNormals(q, GLU_NONE);
//			glRotatef(90, -1, 0, 0);
//			gluCylinder(q, 0.48, 0.48, Black, 50, 50);
//		glPopMatrix();
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
//
//
//
//
//void draw_MyPrinter_Up()
//{
//	draw_Printer_up();
//	draw_Printer_up2();
//}
//
//void draw_MyPrinter_Front()
//{
//	draw_Printer_front();
//	draw_Printer_front1();
//	draw_Printer_front2();
//	draw_Printer_front3();
//	draw_Printer_front4();
//
//	draw_Printer_front4_2();
//	draw_Printer_front4_3();
//	draw_Printer_front4_4();
//
//	draw_Printer_front5();
//	draw_Printer_front5_2();
//	draw_Printer_front5_3();
//	draw_Printer_front5_4();
//	if(Printing == true) draw_Printer_front5_5();
//
//	draw_Printer_front6();
//	draw_Printer_front6_1();
//	draw_Printer_front6_2();
//	draw_Printer_front6_3();
//}
//
//void draw_MyPrinter_Right()
//{
//	draw_Printer_right1();
//	draw_Printer_right2();
//	draw_Printer_right3();
//	draw_Printer_right4();
//	draw_Printer_right5();
//
//}
//
//void draw_MyPrinter_Left()
//{
//	draw_Printer_left();
//	draw_Printer_left2();
//	draw_Printer_left3();
//}
//
//void draw_MyPrinter_Back()
//{
//	draw_Printer_back1();
//	draw_Printer_back2();
//	draw_Printer_back2_2();
//	draw_Printer_back2_3();
//	draw_Printer_back2_4();
//	draw_Printer_back2_5();
//	draw_Printer_back2_5_1();
//	draw_Printer_back2_5_2();
//	draw_Printer_back2_5_3();
//	draw_Printer_back2_6();
//	draw_Printer_back2_6_2();
//	draw_Printer_back2_6_3();
//	draw_Printer_back2_6_4();
//}
//
//void draw_MyPrinter_Down()
//{
//	draw_Printer_down();
//}
//
//void draw_MyPrinter()
//{
//	draw_MyPrinter_Up();
//	draw_MyPrinter_Front();
//	draw_MyPrinter_Right();
//	draw_MyPrinter_Left();
//	draw_MyPrinter_Back();
//	draw_MyPrinter_Down();
//}
//
//void draw_MyInk()
//{
//	//��ũ�� ����
//	glPushMatrix();
//		glRotatef(90, 1, 0, 0);
//		glTranslatef(6, 3, -1);//ù ��° ��ũ�� ��ġ
//		draw_Ink_can();
//		glPushMatrix();
//			glTranslatef(0, 0, 1.0f);
//			if (Black > 0.0f)	draw_Ink_down_Color(4);
//			else	draw_Ink_can_down_cover();
//		glPopMatrix();
//		glPushMatrix();
//			if (Ink_cover_off == false)
//			{
//				glTranslatef(0, 0, -0.2); //��ũ�� �Ѳ� ��ġ ����. ���� ȸ�� �������Ƿ� z���� ȸ�� ���Ѿ� ���ϴ� ���� ��������
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//				Ink_cover_count = 0;
//				Sleep_off = false;
//				Ink_Cover = true;
//			}
//				
//			else
//			{
//				if (Ink_cover_count == 0)
//				{
//					glTranslatef(0, 0, -3.5);
//					draw_Ink_can_cover();
//					draw_Ink_can_cover2();
//					Ink_cover_count++; //Ink_cover_count == 1
//					Sleep(200);
//				}
//		
//				else if (Ink_cover_count == 1)
//				{
//					glTranslatef(2.0f, 0.0f, -3.5f);
//					draw_Ink_can_cover();
//					draw_Ink_can_cover2();
//					Ink_cover_count++; //Ink_cover_count == 2
//					Sleep(200);
//				}
//	
//				else if (Ink_cover_count == 2)
//				{
//					glTranslatef(2.0f, 0.0f, 0.8f);
//					draw_Ink_can_cover();
//					draw_Ink_can_cover2();
//					if (Sleep_off == false)	Sleep(200); // ��� Sleep�Լ��� �۵��ϴ°� �����ϱ� ���� ���ǹ� ����
//					Sleep_off = true;
//					Ink_Cover = false;
//				}
//			}
//		glPopMatrix();
//
//		glTranslatef(0, -1.2, 0); //ù ��° ��ũ�����κ����� �̵� ����. ���� push�ȿ� �����Ƿ� ó�� translatef�� ��� ����޴´�.
//		draw_Ink_can();
//		glPushMatrix();
//			glTranslatef(0, 0, 1.0f);
//			if (Yellow > 0.0f) draw_Ink_down_Color(3);
//			else  draw_Ink_can_down_cover();
//		glPopMatrix();
//		glPushMatrix();
//		if (Ink_cover_off2 == false)
//		{
//			glTranslatef(0, 0, -0.2); //��ũ�� �Ѳ� ��ġ ����. ���� ȸ�� �������Ƿ� z���� ȸ�� ���Ѿ� ���ϴ� ���� ��������
//			draw_Ink_can_cover();
//			draw_Ink_can_cover2();
//			Ink_cover_count2 = 0;
//			Sleep_off2 = false;
//			Ink_Cover2 = true;
//		}
//
//		else
//		{
//			if (Ink_cover_count2 == 0)
//			{
//				glTranslatef(0, 0, -3.5);
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//				Ink_cover_count2++; //Ink_cover_count == 1
//				Sleep(200);
//			}
//
//			else if (Ink_cover_count2 == 1)
//			{
//				glTranslatef(2.0f, 0.0f, -3.5f);
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//				Ink_cover_count2++; //Ink_cover_count == 2
//				Sleep(200);
//			}
//
//			else if (Ink_cover_count2 == 2)
//			{
//				glTranslatef(2.0f, 0.0f, 0.8f);
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//				if (Sleep_off2 == false)	Sleep(200); // ��� Sleep�Լ��� �۵��ϴ°� �����ϱ� ���� ���ǹ� ����
//				Sleep_off2 = true;
//				Ink_Cover2 = false;
//			}
//		}
//		glPopMatrix();
//		glTranslatef(0, -1.2, 0); //�� ��° ��ũ�����κ����� �̵� ����.
//		draw_Ink_can();
//		glPushMatrix();
//			glTranslatef(0, 0, 1.0f);
//			if (Blue > 0.0f)	draw_Ink_down_Color(2);
//			else	draw_Ink_can_down_cover();
//			glPopMatrix();
//		glPushMatrix();
//		if (Ink_cover_off3 == false)
//		{
//			glTranslatef(0, 0, -0.2); //��ũ�� �Ѳ� ��ġ ����. ���� ȸ�� �������Ƿ� z���� ȸ�� ���Ѿ� ���ϴ� ���� ��������
//			draw_Ink_can_cover();
//			draw_Ink_can_cover2();
//			Ink_cover_count3 = 0;
//			Sleep_off3 = false;
//			Ink_Cover3 = true;
//		}
//
//		else
//		{
//			if (Ink_cover_count3 == 0)
//			{
//				glTranslatef(0, 0, -3.5);
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//				Ink_cover_count3++; //Ink_cover_count == 1
//				Sleep(200);
//			}
//
//			else if (Ink_cover_count3 == 1)
//			{
//				glTranslatef(2.0f, 0.0f, -3.5f);
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//				Ink_cover_count3++; //Ink_cover_count == 2
//				Sleep(200);
//			}
//
//			else if (Ink_cover_count3 == 2)
//			{
//				glTranslatef(2.0f, 0.0f, 0.8f);
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//				if (Sleep_off3 == false)	Sleep(200); // ��� Sleep�Լ��� �۵��ϴ°� �����ϱ� ���� ���ǹ� ����
//				Sleep_off3 = true;
//				Ink_Cover3 = false;
//			}
//		}
//		glPopMatrix();
//
//		glTranslatef(0, -1.2, 0); //�� ��° ��ũ�����κ����� �̵� ����.
//		draw_Ink_can();
//		glPushMatrix();
//			glTranslatef(0, 0, 1.0f);
//			if (Red > 0.0f) draw_Ink_down_Color(1);
//			else draw_Ink_can_down_cover();
//			glPopMatrix();
//		glPushMatrix();
//			if (Ink_cover_off4 == false)
//			{
//				glTranslatef(0, 0, -0.2); //��ũ�� �Ѳ� ��ġ ����. ���� ȸ�� �������Ƿ� z���� ȸ�� ���Ѿ� ���ϴ� ���� ��������
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//				Ink_cover_count4 = 0;
//				Sleep_off4 = false;
//				Ink_Cover4 = true;
//			}
//
//			else
//			{
//				if (Ink_cover_count4 == 0)
//				{
//					glTranslatef(0, 0, -3.5);
//					draw_Ink_can_cover();
//					draw_Ink_can_cover2();
//					Ink_cover_count4++; //Ink_cover_count == 1
//					Sleep(200);
//				}
//		
//				else if (Ink_cover_count4 == 1)
//				{
//					glTranslatef(2.0f, 0.0f, -3.5f);
//					draw_Ink_can_cover();
//					draw_Ink_can_cover2();
//					Ink_cover_count4++; //Ink_cover_count == 2
//					Sleep(200);
//				}
//		
//				else if (Ink_cover_count4 == 2)
//				{
//					glTranslatef(2.0f, 0.0f, 0.8f);
//					draw_Ink_can_cover();
//					draw_Ink_can_cover2();
//					if (Sleep_off4 == false)	Sleep(200); // ��� Sleep�Լ��� �۵��ϴ°� �����ϱ� ���� ���ǹ� ����
//					Sleep_off4 = true;
//					Ink_Cover4 = false;
//				}
//			}
//		glPopMatrix();
//	glPopMatrix();
//}
//
//void draw_string(void *font, const char* str, float x, float y, float red, float green, float blue)
//{
//	glPushAttrib(GL_LIGHTING_BIT);
//	glDisable(GL_LIGHTING);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity(); // ���� ��� �ʱ�ȭ
//	gluOrtho2D(-5, 5, -5, 5); // ���� ȭ���� ��ǥ�� (-5,-5) ~ (5, 5);
//	
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glLoadIdentity();
//	glColor3f(red, green, blue);
//	glRasterPos3f(x, y,0);
//	for (unsigned int i = 0; i < strlen(str); i++)	glutBitmapCharacter(font, str[i]);
//	glPopMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glMatrixMode(GL_MODELVIEW);
//	glPopAttrib();
//}
//
////void draw_text()
////{
////	glViewport(0, current_height / 2, current_width / 2, current_height / 2); //�������� (0,height / 2) ũ��� �������� 1/4
////	glLoadIdentity(); // ������ ȸ�� ��ȯ�� ����
////
////	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "12131649 Kwon-Sehoon", -5, 0, 1, 0, 0);
////
////	draw_string(GLUT_BITMAP_HELVETICA_18, "Multi-Viewprot Example!!", -5, 1, 0, 1, 5);
////
////
////	if (String_on == true)	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, my_string, -5, 2, 50, 30, 10);
////
////	glFlush();
////}
//
//void draw_A4()
//{
//	glPushMatrix();
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glEnable(GL_TEXTURE_2D);
//	if (Printmode_change == true) 
//	{
//		switch (Printmode)
//		{
//		case Apple:
//			glBindTexture(GL_TEXTURE_2D, texName[0]);
//			printf("111");
//			break;
//		case Strawberry:
//			glBindTexture(GL_TEXTURE_2D, texName[1]);
//			printf("2");
//			break;
//		case Pear:
//			glBindTexture(GL_TEXTURE_2D, texName[2]);
//			printf("3");
//			break;
//		case InhaF:
//			glBindTexture(GL_TEXTURE_2D, texName[3]);
//			printf("4");
//			break;
//		case InhaJ:
//			glBindTexture(GL_TEXTURE_2D, texName[4]);
//			printf("5");
//			break;
//		case InhaH:
//			glBindTexture(GL_TEXTURE_2D, texName[5]);
//			printf("6");
//			break;
//		case Gyeryong:
//			glBindTexture(GL_TEXTURE_2D, texName[6]);
//			printf("7");
//			break;
//		case Taebaek:
//			glBindTexture(GL_TEXTURE_2D, texName[7]);
//			printf("8");
//			break;
//		case Bukhan:
//			glBindTexture(GL_TEXTURE_2D, texName[8]);
//			printf("9");
//			break;
//		default:
//			glDisable(GL_TEXTURE_2D);
//			break;
//		}
//	}
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0, 0);	glNormal3f(0, 1, 0);	glVertex3f(-1.5f, 1.25f, 1.0f);
//	glTexCoord2f(1, 0);	glNormal3f(0, 1, 0);	glVertex3f(1.5f, 1.25f, 1.0f);
//	glTexCoord2f(1, 1);	glNormal3f(0, 1, 0);	glVertex3f(1.5f, 1.25f, 5.0f);
//	glTexCoord2f(0, 1);	glNormal3f(0, 1, 0);	glVertex3f(-1.5f, 1.25f, 5.0f);
//	glEnd();
//	glPopMatrix();
//}
//
//void Act_Printing()
//{
//	glPushMatrix();
//	if (Act_Printing_on == true)
//	{
//		if (Printing_A4_count == 0)
//		{
//			glTranslatef(0.0f, 0.0f, 0.0f);
//			draw_A4();
//			Printing_A4_count++; //Ink_cover_count == 1
//			Sleep(200);
//		}
//
//		else if (Printing_A4_count == 1)
//		{
//			glTranslatef(0.0f, 0.0f, 1.0f);
//			draw_A4();
//			Printing_A4_count++; //Ink_cover_count == 2
//			Sleep(200);
//		}
//
//		else if (Printing_A4_count == 2)
//		{
//			glTranslatef(0.0f, 0.0f, 2.0f);
//			draw_A4();
//			Sleep(200);
//			Printing_A4_count++;
//		}
//
//		else if (Printing_A4_count == 3)
//		{
//			glTranslatef(0.0f, 0.0f, 3.0f);
//			draw_A4();
//			Sleep(200);
//			Printing_A4_count++;
//		}
//
//		else if (Printing_A4_count == 4)
//		{
//			glTranslatef(0.0f, 0.0f, 3.6f);
//			draw_A4();
//			if (Printmode != 0) Printmode_change = false;
//			if (Sleep_off_print == false)	Sleep(200); // ��� Sleep�Լ��� �۵��ϴ°� �����ϱ� ���� ���ǹ� ����
//			Sleep_off_print = true;
//		}
//	}
//	glPopMatrix();
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
//
//	gluLookAt(eye_x, eye_y, eye_z, 0, 0, 0, 0, up, 0); //ī�޶��� ����
//	
//	if (Light == true) glEnable(GL_LIGHT0); 
//	else glDisable(GL_LIGHT0);
//
//	GLfloat light_position1[] = { 100, 100, 100, 1 }; 
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//
//	//glPushMatrix();
//	//	glTranslatef(0, 0.01, 0);
//	//	draw_axis(); //�˾ƺ��� ���� ��ǥ�� ����
//	//glPopMatrix();
//
////	draw_MyPrinter();
//	draw_MyInk();
//	
//	draw_Ink_Red(Red);
//	draw_Ink_Yellow(Yellow);
//	draw_Ink_Blue(Blue);
//	draw_Ink_Black(Black);
//
//	Act_Printing();
//
////	draw_A4();
//
//	if (Act_Printing_on == true && Printing_A4_count<6) glutPostRedisplay();
//
//	glFlush();
//	glutSwapBuffers();
//
//	if ( ( Ink_cover_off == true && Ink_cover_count < 3 ) || (Ink_cover_off2 == true && Ink_cover_count < 3 ) ||
//		(Ink_cover_off3 == true && Ink_cover_count < 3) || (Ink_cover_off4 == true && Ink_cover_count < 3 ) )	glutPostRedisplay();
//}
//
//void sub_menu_function(int option)
//{
//	printf("Submenu %d has been selected\n", option);
//	switch (option)
//	{
//	case Apple : 
//		Printmode = Apple;
//		break;
//	case Strawberry :
//		Printmode = Strawberry;
//		break;
//	case Pear :
//		Printmode = Pear;
//		break;
//	case InhaF:
//		Printmode = InhaF;
//		break;
//	case InhaJ:
//		Printmode = InhaJ;
//		break;
//	case InhaH:
//		Printmode = InhaH;
//		break;
//	case Gyeryong:
//		Printmode = Gyeryong;
//		break;
//	case Taebaek:
//		Printmode = Taebaek;
//		break;
//	case Bukhan:
//		Printmode = Bukhan;
//		break;
//	default:
//		Printmode = 0;
//		break;
//	}
//}
//
//void main_menu_function(int option)
//{
//	printf("Submenu %d has been selected\n", option);
//	if (option == 999) exit(0);
//}
//
// //����Ű�� �Է¹޾� ������ ��ȭ���� ī�޶��� ������ �ٲ۴�.
//void specialkey(int key, int x, int y)
//{
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
//	else if (key == GLUT_KEY_F3) //���� �ʱ�ȭ
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
//	//Ű���� ��ư�� ���� �� ���۱�ɵ� ����
//	if (key == '1') //Ink_cover_off ����
//	{
//		if (Ink_cover_off == false) Ink_cover_off = true;
//		else Ink_cover_off = false;
//		printf("Ink_cover_off = %d\n", Ink_cover_off);
//	}
//
//	if (key == '2') //Ink_cover2_off ����
//	{
//		if (Ink_cover_off2 == false) Ink_cover_off2 = true;
//		else Ink_cover_off2 = false;
//		printf("Ink_cover_off2 = %d\n", Ink_cover_off2);
//	}
//
//	if (key == '3') //Ink_cover3_off ����
//	{
//		if (Ink_cover_off3 == false) Ink_cover_off3 = true;
//		else Ink_cover_off3 = false;
//		printf("Ink_cover_off3 = %d\n", Ink_cover_off3);
//	}
//
//	if (key == '4') //Ink_cover4_off ����
//	{
//		if (Ink_cover_off4 == false) Ink_cover_off4 = true;
//		else Ink_cover_off4 = false;
//		printf("Ink_cover_off4 = %d\n", Ink_cover_off4);
//	}
//
//	if (key == 'z') //�� ��
//	{
//		if (r > 0) r--;
//	}
//	else if (key == 'x') //�� �ƿ�
//	{
//		r++;
//	}
//
//	//'o' Ű�� ������ ���� on-off
//	if (key == 'l')
//	{
//		if (Light == true)  Light = false;
//		else Light = true;
//	}
//
//	if (key == 'r') // ������ ��ũ ä�� ����
//	{
//		if (Ink_Cover4 == false)
//		{
//			if (Red < 1.0f)
//			{
//				Red += 0.1;
//				Ink_down_Color = 1;
//			}
//		}
//	}
//
//	if (key == 'y') // ����� ��ũ ä�� ����
//	{
//		if (Ink_Cover2 == false)
//		{
//			if (Yellow < 1.0f)	Yellow += 0.1;
//		}
//	}
//
//	if (key == 'b') // �Ķ��� ��ũ ä�� ����
//	{
//		if (Ink_Cover3 == false)
//		{
//			if (Blue < 1.0f)	Blue += 0.1;
//		}
//	}
//
//	if (key == 'k') // ������ ��ũ ä�� ����
//	{
//		if (Ink_Cover == false)
//		{				
//			if (Black < 1.0f)	Black += 0.1;
//		}
//	}
//
//	if (key == 'R') // ������ ��ũ ��
//	{
//		if (Ink_Cover4 == false)
//		{
//			if (Red > 0.0f)	Red -= 0.1;
//		}
//	}
//
//	if (key == 'Y') // ����� ��ũ ��
//	{
//		if (Ink_Cover2 == false)
//		{
//			if (Yellow > 0.0f)	Yellow -= 0.1;
//		}
//	}
//
//	if (key == 'B') // �Ķ��� ��ũ ��
//	{
//		if (Ink_Cover3 == false)
//		{
//			if (Blue > 0.0f)	Blue -= 0.1;
//		}
//	}
//
//	if (key == 'K') // ������ ��ũ ��
//	{
//		if (Ink_Cover == false)
//		{
//			if (Black > 0.0f)	Black -= 0.1f;
//		}
//	}
//
//	if (key == 'i') //��ũ �ʱ�ȭ
//	{
//		Red = 0;
//		Yellow = 0;
//		Blue = 0;
//		Black = 0;
//	}
//
//	if (key == 'p')
//	{
//		if (Printing == false)  Printing = true;
//		else Printing = false;
//	}
//
//	if (key == 'P')
//	{
//		Act_Printing_on = true;
//	}
//
//	if (key == '[')
//	{
//		Act_Printing_on = false;
//		Printmode_change = true;
//		Printing_A4_count = 0;
//	}
//
//	glutPostRedisplay();
//}