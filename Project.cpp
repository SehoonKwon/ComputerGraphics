//#pragma comment(lib, "legacy_stdio_definitions.lib")
//#pragma comment(lib, "winmm")
//#include <gl/glut.h>
//#include <stdio.h>
//#include <math.h> 
//#include <Windows.h>
//#include <mmsystem.h>
//#include <gl/GLAUX.H>
//#include <iostream>
//using namespace std;
//
//double E_angle = 67 , A_angle = 0; // 라디안으로 변환하기 위해 Degree 변수 선언.
//#define Sound "./sound/Print_Sound2.wav"
//#define PI 3.141592
//#define E_Radian PI*E_angle/180 //C언어에서는 라디안만 사용가능하다.
//#define A_Radian PI*A_angle/180
//
//void init();
//void resize(int width, int height);
//void draw();
//void specialkey(int key, int x, int y); //카메라의 시점을 바꾸는 키를 입력받기 위한 함수
//void keyboard(unsigned char key, int x, int y); //기능을 위한 키보드 callback 함수
//void mouse(int botton, int state, int x, int y);
//void motion(int x, int y);
//void sub_menu_function(int option);
//void main_menu_function(int option);
//void idle();
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
//void draw_Printer_back3();
//void draw_Printer_back3_2();
//void draw_Printer_back3_3();
//void draw_Printer_back3_4();
//void draw_Printer_down();
//void draw_Printer_In();
//void draw_Printer_In2();
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
//void draw_MyPrinter_In();
//void draw_Quad();
//void draw_skybox();
//void draw_MyInk();
//void draw_A4();
//void draw_text();
//void draw_Ink_line();
//void draw_Ink_line2();
//void draw_Ink_line3();
//void draw_Ink_line4();
//void Refill_A4();
//void Act_Printing();
//void Display_Ink();
//void DIsplay_Ink2();
//void draw_Table_1();
//void draw_Table_2();
//void draw_Table();
//void draw_Disk();
//
//GLUquadric *q,*p;
//
//
//bool Light = false;
//bool Printing = false;
//bool Ink_Cover = true;
//bool Ink_Cover2 = true;
//bool Ink_Cover3 = true;
//bool Ink_Cover4 = true;
//bool Act_Printing_on = false;
//bool Printing_A4_count2_2_on = false;
//bool Printing_A4_count2_3_on = false;
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
//bool Mouse_mode = false;
//bool SelectMode_on = true;
//bool A4_refill = false;
//bool Refill_on = false;
//bool Display_Ink_on = false;
//bool Display_Ink_on2 = false;
//bool Lookat_Print = false;
//
//float Printing_A4_count = 0;
//float Printing_A4_count2 = 0;
//float Printing_A4_count2_2 = 1.0f;
//float Printing_A4_count2_3 = -1.0f;
//float Refill_A4_count = 0.0f;
//float Ink_cover_x, Ink_cover_y, Ink_cover_z = 0.0f;
//float Ink_cover_x2, Ink_cover_y2, Ink_cover_z2 = 0.0f;
//float Ink_cover_x3, Ink_cover_y3, Ink_cover_z3 = 0.0f;
//float Ink_cover_x4, Ink_cover_y4, Ink_cover_z4 = 0.0f;
//float Red = 0.2f, Yellow = 0.2f, Blue = 0.2f, Black = 0.2f;
//float g_nSkySize = 45.0f;
//
//int r = 35; // 구면좌표계에서 원점-점P까지의 거리
//int Ink_down_Color = 0;
//int Refill_A4_count2 = 0;
//int current_width, current_height = 0;
//int temp_option = 0;
//
//enum Printmode { Apple = 1, Strawberry, Pear, InhaF, InhaJ, InhaH, Gyeryong, Taebaek, Bukhan };
//int Printmode = 0;
//GLuint texName[9];
//GLuint texP[10];
//GLuint texMap[6];
//GLuint g_nCubeTex;
//GLuint texText[2];
//
//int main(int argc, char** argv)
//{
//	int submenu1, submenu2, submenu3;
//
//	// 윈도우 초기화
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//	glutInitWindowSize(1000, 600);
//	glutInitWindowPosition(80, 40);
//	glutCreateWindow("Computer Graphcis Mini Project");
//
//	//  Popup menu 생성 및 추가
//	submenu1 = glutCreateMenu(sub_menu_function);
//	glutAddMenuEntry("Apple", 1);
//	glutAddMenuEntry("Strawberry", 2);
//	glutAddMenuEntry("Pear", 3); // 3개의 항목이 있는 메뉴 생성
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
//	glutMouseFunc(mouse);
//	
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
//	glGenTextures(10, texP);
//	AUX_RGBImageRec *pRGBImage2;
//
//	glGenTextures(6, texMap);
//	AUX_RGBImageRec *pRGBImage3;
//
//	glGenTextures(2, texText);
//	AUX_RGBImageRec *pRGBImage4;
//
//	glBindTexture(GL_TEXTURE_2D, texP[0]);
//	pRGBImage2 = auxDIBImageLoadA("./map/front_cv.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage2->sizeX, pRGBImage2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage2->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texP[1]);
//	pRGBImage2 = auxDIBImageLoadA("./map/front_a4.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage2->sizeX, pRGBImage2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage2->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texP[2]);
//	pRGBImage2 = auxDIBImageLoadA("./map/front_b.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage2->sizeX, pRGBImage2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage2->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texP[3]);
//	pRGBImage2 = auxDIBImageLoadA("./map/front_l.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage2->sizeX, pRGBImage2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage2->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texP[4]);
//	pRGBImage2 = auxDIBImageLoadA("./map/front_r.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage2->sizeX, pRGBImage2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage2->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texP[5]);
//	pRGBImage2 = auxDIBImageLoadA("./map/front_wall.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage2->sizeX, pRGBImage2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage2->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texP[6]);
//	pRGBImage2 = auxDIBImageLoadA("./map/front_wall2.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage2->sizeX, pRGBImage2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage2->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
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
//	glBindTexture(GL_TEXTURE_2D, texMap[0]);
//	pRGBImage3 = auxDIBImageLoadA("./map/TexImage000.bmp"); //왼쪽
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage3->sizeX, pRGBImage3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage3->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texMap[1]);
//	pRGBImage3 = auxDIBImageLoadA("./map/TexImage000.bmp"); //오른쪽
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage3->sizeX, pRGBImage3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage3->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texMap[2]); //바닥면
//	pRGBImage3 = auxDIBImageLoadA("./map/TexImage12.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage3->sizeX, pRGBImage3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage3->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texMap[3]); //천장
//	pRGBImage3 = auxDIBImageLoadA("./map/TexImage56.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage3->sizeX, pRGBImage3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage3->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texMap[4]);
//	pRGBImage3 = auxDIBImageLoadA("./map/TexImage000.bmp"); //뒤
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage3->sizeX, pRGBImage3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage3->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texMap[5]);
//	pRGBImage3 = auxDIBImageLoadA("./map/TexImage000.bmp"); //정면
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage3->sizeX, pRGBImage3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage3->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	//텍스트 매핑
//	glBindTexture(GL_TEXTURE_2D, texText[0]);
//	pRGBImage4 = auxDIBImageLoadA("./map/Text1.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage4->sizeX, pRGBImage4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage4->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, texText[1]);
//	pRGBImage4 = auxDIBImageLoadA("./map/Text2.bmp");
//	glTexImage2D(GL_TEXTURE_2D, 0, 3, pRGBImage4->sizeX, pRGBImage4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pRGBImage4->data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//
//	//광원의 성질들 값 설정
//	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
//			
//	GLfloat ambient_Sun[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//	GLfloat diffuse_Sun[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	GLfloat specular_Sun[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//			
//	//설정값 적용
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//	
//	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
//
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_Sun);
//	glMateriali(GL_FRONT, GL_SHININESS, 30);
//			
//	glEnable(GL_COLOR_MATERIAL);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//	
//	glEnable(GL_LIGHTING);
//	glEnable(GL_DEPTH_TEST);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//	glEnable(GL_POINT_SMOOTH);
//	glEnable(GL_LINE_SMOOTH);
//	glEnable(GL_POLYGON_SMOOTH);
//}
//
//void resize(int width, int height)
//{
//	glViewport(0, 0, width, height); // width와 height는 윈도우사이즈 가 들어옴 , viewport는 Ortho2D와 같다(=평면)
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / (float) height, 1, 500);
//	glMatrixMode(GL_MODELVIEW);
//
//	current_width = width;
//	current_height = height;
//}
//
//void idle()
//{
//	//프린팅시 기능
//	if (Act_Printing_on == true)
//	{
//		if (Printing_A4_count < 2)	Printing_A4_count += 0.01;
//		else if (Printing_A4_count > 2 && Printing_A4_count < 4.8) Printing_A4_count += 0.02;
//		else Printing_A4_count = 5.0;
//
//		if (Printing_A4_count2 < 1)		Printing_A4_count2 += 0.02;
//		else Printing_A4_count2_2_on = true;
//
//		if (Printing_A4_count2_2_on == true)
//		{
//			if (Printing_A4_count2_2 > -1)	Printing_A4_count2_2 -= 0.02;
//			else
//			{
//				Printing_A4_count2_3_on = true;
//			}
//		}
//
//		if (Printing_A4_count2_3_on == true)
//		{
//			Printing_A4_count2_2_on = false;
//			if (Printing_A4_count2_3 < 0)	Printing_A4_count2_3 += 0.01;
//		}
//	}
//
//	//잉크 뚜껑 열기
//	if (Ink_cover_off == true)
//	{
//		if (Ink_cover_x <2.1 && Ink_cover_z < 3.6) Ink_cover_z += 0.02;
//		else if (Ink_cover_x < 2.1) Ink_cover_x += 0.02;
//		else if (Ink_cover_x > 2.1 && Ink_cover_z > -0.8) Ink_cover_z -= 0.02;
//		else Ink_Cover = false;
//	}
//
//	if (Ink_cover_off2 == true)
//	{
//		if (Ink_cover_x2 <2.1 && Ink_cover_z2 < 3.6) Ink_cover_z2 += 0.02;
//		else if (Ink_cover_x2 < 2.1) Ink_cover_x2 += 0.02;
//		else if (Ink_cover_x2 > 2.1 && Ink_cover_z2 > -0.8) Ink_cover_z2 -= 0.02;
//		else Ink_Cover2 = false;
//	}
//
//	if (Ink_cover_off3 == true)
//	{
//		if (Ink_cover_x3 <2.1 && Ink_cover_z3 < 3.6) Ink_cover_z3 += 0.02;
//		else if (Ink_cover_x3 < 2.1) Ink_cover_x3 += 0.02;
//		else if (Ink_cover_x3 > 2.1 && Ink_cover_z3 > -0.8) Ink_cover_z3 -= 0.02;
//		else Ink_Cover3 = false;
//	}
//
//	if (Ink_cover_off4 == true)
//	{
//		if (Ink_cover_x4 <2.1 && Ink_cover_z4 < 3.6) Ink_cover_z4 += 0.02;
//		else if (Ink_cover_x4 < 2.1) Ink_cover_x4 += 0.02;
//		else if (Ink_cover_x4 > 2.1 && Ink_cover_z4 > -0.8) Ink_cover_z4 -= 0.02;
//		else Ink_Cover4 = false;
//	}
//
//	if (Refill_on == true)
//	{
//		if (Refill_A4_count < 8.5)
//		{
//			Refill_A4_count += 0.08;
//			Refill_A4_count2 = 1;
//		}
//	}
//
//	glutPostRedisplay();
//}
//
//void draw_skybox()
//{
//	glEnable(GL_TEXTURE_2D);
//
//	glBindTexture(GL_TEXTURE_2D, texMap[0]);
//	glBegin(GL_QUADS);
//	glTexCoord2f(0, 0);	glNormal3f(-1, 0, 0);	glVertex3f(-g_nSkySize, g_nSkySize, -g_nSkySize);
//	glTexCoord2f(1, 0);	glNormal3f(-1, 0, 0);	glVertex3f(-g_nSkySize, -g_nSkySize, -g_nSkySize);
//	glTexCoord2f(1, 1);	glNormal3f(-1, 0, 0);	glVertex3f(-g_nSkySize, -g_nSkySize, g_nSkySize);
//	glTexCoord2f(0, 1);	glNormal3f(-1, 0, 0);	glVertex3f(-g_nSkySize, g_nSkySize, g_nSkySize);
//	glEnd();
//
//	glBindTexture(GL_TEXTURE_2D, texMap[1]);
//	glBegin(GL_QUADS);
//	glTexCoord2f(0, 0);	glNormal3f(1, 0, 0);	glVertex3f(g_nSkySize, g_nSkySize, g_nSkySize);
//	glTexCoord2f(1, 0);	glNormal3f(1, 0, 0);	glVertex3f(g_nSkySize, -g_nSkySize, g_nSkySize);
//	glTexCoord2f(1, 1);	glNormal3f(1, 0, 0);	glVertex3f(g_nSkySize, -g_nSkySize, -g_nSkySize);
//	glTexCoord2f(0, 1);	glNormal3f(1, 0, 0);	glVertex3f(g_nSkySize, g_nSkySize, -g_nSkySize);
//	glEnd();
//
//	glBindTexture(GL_TEXTURE_2D, texMap[2]);
//	glBegin(GL_QUADS);
//	glTexCoord2f(0, 0);	glNormal3f(0, -1, 0);	glVertex3f(-g_nSkySize, -g_nSkySize/4.85, -g_nSkySize);
//	glTexCoord2f(1, 0);	glNormal3f(0, -1, 0);	glVertex3f(g_nSkySize, -g_nSkySize/4.85, -g_nSkySize);
//	glTexCoord2f(1, 1);	glNormal3f(0, -1, 0);	glVertex3f(g_nSkySize, -g_nSkySize/4.85,  g_nSkySize);
//	glTexCoord2f(0, 1);	glNormal3f(0, -1, 0);	glVertex3f(-g_nSkySize, -g_nSkySize/4.85,  g_nSkySize);
//	glEnd();
//
//	glBindTexture(GL_TEXTURE_2D, texMap[3]);
//	glBegin(GL_QUADS);
//	glTexCoord2f(0, 0);	glNormal3f(0, 1, 0);	glVertex3f(-g_nSkySize, g_nSkySize, g_nSkySize);
//	glTexCoord2f(1, 0);	glNormal3f(0, 1, 0);	glVertex3f(g_nSkySize, g_nSkySize, g_nSkySize);
//	glTexCoord2f(1, 1);	glNormal3f(0, 1, 0);	glVertex3f(g_nSkySize, g_nSkySize, -g_nSkySize);
//	glTexCoord2f(0, 1);	glNormal3f(0, 1, 0);	glVertex3f(-g_nSkySize, g_nSkySize, -g_nSkySize);
//	glEnd();
//
//	glBindTexture(GL_TEXTURE_2D, texMap[4]);
//	glBegin(GL_QUADS);
//	glTexCoord2f(0, 0);	glNormal3f(0, 0, 1);	glVertex3f(g_nSkySize, g_nSkySize, g_nSkySize);
//	glTexCoord2f(1, 0); glNormal3f(0, 0, 1);	glVertex3f(-g_nSkySize, g_nSkySize, g_nSkySize);
//	glTexCoord2f(1, 1);	glNormal3f(0, 0, 1);	glVertex3f(-g_nSkySize, -g_nSkySize, g_nSkySize);
//	glTexCoord2f(0, 1);	glNormal3f(0, 0, 1);	glVertex3f(g_nSkySize, -g_nSkySize, g_nSkySize);
//	glEnd();
//
//	glBindTexture(GL_TEXTURE_2D, texMap[5]);
//	glBegin(GL_QUADS);
//	glTexCoord2f(0, 0); glNormal3f(0, 0, -1);	glVertex3f(g_nSkySize, g_nSkySize, -g_nSkySize);
//	glTexCoord2f(1, 0);	glNormal3f(0, 0, -1);	glVertex3f(-g_nSkySize, g_nSkySize, -g_nSkySize);
//	glTexCoord2f(1, 1); glNormal3f(0, 0, -1);	glVertex3f(-g_nSkySize, -g_nSkySize, -g_nSkySize);
//	glTexCoord2f(0, 1); glNormal3f(0, 0, -1);	glVertex3f(g_nSkySize, -g_nSkySize, -g_nSkySize);
//	glEnd();
//
//	glDisable(GL_TEXTURE_2D);
//}
//
//
//  //x, y, z 축 생성
//void draw_axis() 
//{
//	glLineWidth(3);
//	
//	glBegin(GL_LINES);
//	
//	glColor3f(1, 0, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(100, 0, 0);
//
//	glColor3f(0, 1, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 100, 0);
//
//	glColor3f(0, 0, 1);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 100);
//	
//	glEnd();
//	glLineWidth(1);
//}
//
////문자열을 생성하는 함수
//void draw_string(void *font, const char* str, float x, float y, float red, float green, float blue)
//{
//	glPushAttrib(GL_LIGHTING_BIT);
//	glDisable(GL_LIGHTING);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//		glLoadIdentity(); // 기존 행렬 초기화
//		gluOrtho2D(-5, 5, -5, 5); // 이제 화면의 좌표는 (-5,-5) ~ (5, 5);
//	
//		glMatrixMode(GL_MODELVIEW);
//		glPushMatrix();
//			glLoadIdentity();
//			glColor3f(red, green, blue);
//			glRasterPos3f(x, y,0);
//			for (unsigned int i = 0; i < strlen(str); i++)	glutBitmapCharacter(font, str[i]);
//		glPopMatrix();
//		glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glMatrixMode(GL_MODELVIEW);
//	glPopAttrib();
//}
//
//void draw_text()
//{
//	glViewport(3*current_width /4, 0, current_width / 4, current_height / 4); //시작점은 (0,height / 2) 크기는 윈도우의 1/4
//	glLoadIdentity(); // 기존의 회전 변환을 무시
//
//	glPushAttrib(GL_LIGHTING_BIT);
//	glDisable(GL_LIGHTING);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity(); // 기존 행렬 초기화
//	gluOrtho2D(-5, 5, 0, 5); // 이제 화면의 좌표는 (-5,-5) ~ (5, 5);
//
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texText[0]);
//
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0, 0);		glVertex2f(-5.0, 2.8);
//	glTexCoord2f(1, 0);		glVertex2f(-1.0, 2.8);
//	glTexCoord2f(1, 1);		glVertex2f(-1.0, 0.0);
//	glTexCoord2f(0, 1);		glVertex2f(-5.0, 0.0);
//	glEnd();
//
//	glBindTexture(GL_TEXTURE_2D, texText[1]);
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0, 0);		glVertex2f(0.0, 3.0);
//	glTexCoord2f(1, 0);		glVertex2f(5.0, 3.0);
//	glTexCoord2f(1, 1);		glVertex2f(5.0, 0.0);
//	glTexCoord2f(0, 1);		glVertex2f(0.0, 0.0);
//	glEnd();
//
//	glPopMatrix();
//	glPopAttrib();
//	glEnable(GL_LIGHTING);
//	glDisable(GL_TEXTURE_2D);
//
//	glFlush();
//}
//
//void draw_Quad()
//{
////	glColor3f(0.0f, 1.0f, 1.0f);
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0, 0);		glNormal3f(0, 1, 0);	glVertex3f(-1.0f, 1.0f, 0.0f);
//	glTexCoord2f(1, 0);		glNormal3f(0, 1, 0);	glVertex3f(1.0f, 1.0f, 0.0f);
//	glTexCoord2f(1, 1);		glNormal3f(0, 1, 0);	glVertex3f(1.0f, 0.0f, 0.0f);
//	glTexCoord2f(0, 1);		glNormal3f(0, 1, 0);	glVertex3f(-1.0f, 0.0f, 0.0f);
//	glEnd();
//}
//
//void draw_Quad2()
//{
//	//	glColor3f(0.0f, 1.0f, 1.0f);
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0, 0);		glNormal3f(0, -1, 0);	glVertex3f(-1.0f, 1.0f, 0.0f);
//	glTexCoord2f(1, 0);		glNormal3f(0, -1, 0);	glVertex3f(1.0f, 1.0f, 0.0f);
//	glTexCoord2f(1, 1);		glNormal3f(0, -1, 0);	glVertex3f(1.0f, 0.0f, 0.0f);
//	glTexCoord2f(0, 1);		glNormal3f(0, -1, 0);	glVertex3f(-1.0f, 0.0f, 0.0f);
//	glEnd();
//}
//
//void draw_Quad3()
//{
//	//	glColor3f(0.0f, 1.0f, 1.0f);
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0, 0);		glNormal3f(-1, 0, 0);	glVertex3f(-1.0f, 1.0f, 0.0f);
//	glTexCoord2f(1, 0);		glNormal3f(-1, 0, 0);	glVertex3f(1.0f, 1.0f, 0.0f);
//	glTexCoord2f(1, 1);		glNormal3f(-1, 0, 0);	glVertex3f(1.0f, 0.0f, 0.0f);
//	glTexCoord2f(0, 1);		glNormal3f(-1, 0, 0);	glVertex3f(-1.0f, 0.0f, 0.0f);
//	glEnd();
//}
//
////윗면
//void draw_Printer_up() //윗면
//{
////	glColor3f(0.270f, 0.290f, 0.267f);
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 1, 0);	glVertex3f(-5.0f, 3.0f, -1.0f);
//	glNormal3f(0, 1, 0);	glVertex3f(5.0f, 3.0f, -1.0f);
//	glNormal3f(0, 1, 0);	glVertex3f(5.0f, 3.0f, 3.0f);
//	glNormal3f(0, 1, 0);	glVertex3f(-5.0f, 3.0f, 3.0f);
//	glEnd();
//}
//
//// 정면 곡면부분
//void draw_Printer_up2() // 정면 곡면부분
//{
//	//glPushMatrix();
//	//glEnable(GL_TEXTURE_2D);
//	//glBindTexture(GL_TEXTURE_2D, texP[0]);
//	//glColor3f(0, 0.2f, 0.4f);
//	//glBegin(GL_POLYGON);
//	//glTexCoord2f(0, 0);	glNormal3f(0, 0.5, 1);	glVertex3f(-5.0f, 3.0f, 3.0f);
//	//glTexCoord2f(0.8, 0);	glNormal3f(0, 0.5, 1);	glVertex3f(5.0f, 3.0f, 3.0f);
//	//glTexCoord2f(0.8, 1);	glNormal3f(0, 0.5, 1);	glVertex3f(5.0f, 2.2f, 3.5f);
//	//glTexCoord2f(0, 1);	glNormal3f(0, 0.5, 1);	glVertex3f(-5.0f, 2.2f, 3.5f);
//	//glEnd();
//	//glDisable(GL_TEXTURE_2D);
//	//glPopMatrix();
//
//	glPushMatrix();
//	glEnable(GL_NORMALIZE);
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texP[0]);
//	glScalef(5, 0.9, 1);
//	glTranslatef(0,2.445, 3.5);
//	glRotatef(-30, 1, 0, 0);
//	draw_Quad();
//	glDisable(GL_TEXTURE_2D);
//	glDisable(GL_NORMALIZE);
//	glPopMatrix();
//
//}
//
//void draw_Printer_front() 
//{
//	//glColor3f(0, 0, 0.0f);
//	//glBegin(GL_POLYGON);
//	//glNormal3f(0, 0, 1);	glVertex3f(-5.0f, 2.2f, 3.5f);
//	//glNormal3f(0, 0, 1);	glVertex3f(5.0f, 2.2f, 3.5f);
//	//glNormal3f(0, 0, 1);	glVertex3f(5.0f, 1.9f, 3.4f);
//	//glNormal3f(0, 0, 1);	glVertex3f(-5.0f, 1.9f, 3.4f);
//	//glEnd();
//
//	glPushMatrix();
//		glEnable(GL_NORMALIZE);
////		glColor3f(0.270f, 0.290f, 0.267f);
////		glColor3f(0.1921, 0.196, 0.1647);
////		glColor3f(0.074f, 0.07f, 0.059f);
//		glColor3f(0.1098f, 0.1176f, 0.0667f);
//		glScalef(5, 0.2, 1);
//		glTranslatef(0, 10, 3.4);
//		glRotatef(3, 1, 0, 0);
//		draw_Quad();
//		glDisable(GL_NORMALIZE);
//	glPopMatrix();
//}
//
//// 정면 왼쪽
//void draw_Printer_front1()
//{
//	glPushMatrix();
//		glEnable(GL_NORMALIZE);
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, texP[3]);
//		glScalef(1.22, 1.9, 1);
//		glTranslatef(-3.1, 0, 3.5);
//		glRotatef(-5, 1, 0, 0);
//		draw_Quad();
//		glDisable(GL_TEXTURE_2D);
//		glDisable(GL_NORMALIZE);
//	glPopMatrix();
//}
//
//void draw_Printer_front2()
//{
//	glPushMatrix();
//		glEnable(GL_TEXTURE_2D);
//		glEnable(GL_NORMALIZE);
//		glBindTexture(GL_TEXTURE_2D, texP[4]);
//		glScalef(1.22, 1.9, 1);
//		glTranslatef(3.1, 0, 3.5);
//		glRotatef(-5, 1, 0, 0);
//		draw_Quad();
//		glDisable(GL_TEXTURE_2D);
//		glDisable(GL_NORMALIZE);
//	glPopMatrix();
//}
//
//void draw_Printer_front3()
//{
//	glColor3f(0.074f, 0.07f, 0.059f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, 1);	glVertex3f(-2.55f, 1.9f, 3.4f);
//	glNormal3f(0, 0, 1);	glVertex3f(2.55f, 1.9f, 3.4f);
//	glNormal3f(0, 0, 1);	glVertex3f(2.55f, 1.7f, 3.38f);
//	glNormal3f(0, 0, 1);	glVertex3f(-2.55f, 1.7f, 3.38f);
//	glEnd();
//}
//
//// 앞 장벽영역 윗면
//void draw_Printer_front4() // 앞 장벽영역 윗면
//{
//	glPushMatrix();
//	//glEnable(GL_TEXTURE_2D);
//	//glBindTexture(GL_TEXTURE_2D, texP[6]);
//	//glColor3f(0.2352f, 0.2392f, 0.2196f);
//	//glColor3f(0.1412f, 0.149f, 0.145f);
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0, 0);		glNormal3f(0, 1, 0);	glVertex3f(-2.5f, 1.2f, 2.5f);
//	glTexCoord2f(1, 0);		glNormal3f(0, 1, 0);	glVertex3f(2.5f, 1.2f, 2.5f);
//	glTexCoord2f(1, 1);		glNormal3f(0, 1, 0);	glVertex3f(2.5f, 1.2f, 5.5f);
//	glTexCoord2f(0, 1);		glNormal3f(0, 1, 0);	glVertex3f(-2.5f, 1.2f, 5.5f);
//	glEnd();
////	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//}
//
//// 앞 장벽영역 아랫면
//void draw_Printer_front4_2() // 앞 장벽영역 아랫면
//{
//	glColor3f(0.270f, 0.290f, 0.267f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0);	glVertex3f(-2.5f, 0.8f, 2.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(2.5f, 0.8f, 2.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(2.5f, 0.8f, 5.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(-2.5f, 0.8f, 5.5f);
//	glEnd();
//}
//
//// 앞 장벽 오른쪽
//void draw_Printer_front4_3()  // 앞 장벽 오른쪽
//{
//	glColor3f(0.270f, 0.290f, 0.267f);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 1.2f, 2.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 1.2f, 5.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 0.8f, 5.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 0.8f, 2.5f);
//	glEnd();
//}
//
////앞 장벽 왼쪽
//void draw_Printer_front4_4() //앞 장벽 왼쪽
//{
//	glColor3f(0.270f, 0.290f, 0.267f);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 1.2f, 2.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 1.2f, 5.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 0.8f, 5.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 0.8f, 2.5f);
//	glEnd();
//}
//
//// A4용지 윗면
//void draw_Printer_front5() // A4용지 윗면
//{
//	glColor3f(0.270f, 0.290f, 0.267f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 1, 0);	glVertex3f(-2.5f, 0.6f, 2.5f);
//	glNormal3f(0, 1, 0);	glVertex3f(2.5f, 0.6f, 2.5f);
//	glNormal3f(0, 1, 0);	glVertex3f(2.5f, 0.6f, 5.5f);
//	glNormal3f(0, 1, 0);	glVertex3f(-2.5f, 0.6f, 5.5f);
//	glEnd();
//}
//
//// A4용지 아랫면
//void draw_Printer_front5_2() // A4용지 아랫면
//{
//	glColor3f(0.270, 0.290f, 0.267f);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0);	glVertex3f(-2.5f, 0.01f, 2.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(2.5f, 0.01f, 2.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(2.5f, 0.01f, 5.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(-2.5f, 0.01f, 5.5f);
//	glEnd();
//}
//
////A4 왼쪽
//void draw_Printer_front5_3() //A4 왼쪽
//{
//	glColor3f(0.270f, 0.290f, 0.267f);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 0.6f, 2.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 0.6f, 5.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 0.0f, 5.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-2.5f, 0.0f, 2.5f);
//	glEnd();
//}
//
////A4 오른쪽
//void draw_Printer_front5_4() //A4 오른쪽
//{
//	glColor3f(0.270f, 0.290f, 0.267f);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 0.6f, 2.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 0.6f, 5.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 0.0f, 5.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(2.5f, 0.0f, 2.5f);
//	glEnd();
//}
//
//// 용지날림 방지 벽-튀어나오는 부분
//void draw_Printer_front5_5() // 용지날림 방지 벽-튀어나오는 부분
//{
////	glColor3f(0.270, 0.290f, 0.267f);
//	glPushMatrix();
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texP[5]);
////	glColor3f(0.133f, 0.1294f, 0.1098f);
////		glColor3f(0.2352f, 0.2392f, 0.2196f);
//		glBegin(GL_POLYGON);
//		glTexCoord2f(0, 0);		glNormal3f(0, 1, 0);	glVertex3f(-2.2f, 1.0f, 5.5f);
//		glTexCoord2f(1, 0);		glNormal3f(0, 1, 0);	glVertex3f(2.2f, 1.0f, 5.5f);
//		glTexCoord2f(1, 1);		glNormal3f(0, 1, 0);	glVertex3f(2.2f, 1.0f, 8.5f);
//		glTexCoord2f(0, 1);		glNormal3f(0, 1, 0);	glVertex3f(-2.2f, 1.0f, 8.5f);
//		glEnd();
//	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//}
//
//void draw_Printer_front5_5_2()
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0, 0);		glNormal3f(0, 1, 0);	glVertex3f(-2.2f, 1.2f, 8.5f);
//	glTexCoord2f(1, 0);		glNormal3f(0, 1, 0);	glVertex3f(2.2f, 1.2f, 8.5f);
//	glTexCoord2f(1, 1);		glNormal3f(0, 1, 0);	glVertex3f(2.2f, 1.0f, 8.5f);
//	glTexCoord2f(0, 1);		glNormal3f(0, 1, 0);	glVertex3f(-2.2f, 1.0f, 8.5f);
//	glEnd();
//}
//
//void draw_Printer_front5_5_3() 
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	q = gluNewQuadric();
//	gluQuadricNormals(q, GLU_SMOOTH);
//	glPushMatrix();
//		glEnable(GL_CLIP_PLANE5);
//		GLdouble eq5[4] = { 0,1,0,0 };
//		glTranslatef(0, 1, 8.5);
//		glClipPlane(GL_CLIP_PLANE5, eq5);
//		gluDisk(q, 0, 0.5, 50, 50);
//		glDisable(GL_CLIP_PLANE5);
//	glPopMatrix();
//	glFlush();
//	gluDeleteQuadric(q);
//}
//
//// 용지날림 방지 벽 정면(앞퉁이)
//void draw_Printer_front5_6() // 용지날림 방지 벽 정면(앞퉁이)
//{
//	glPushMatrix();
//		glColor3f(0.1921, 0.196, 0.1647);
//		glBegin(GL_POLYGON);
//		glTexCoord2f(0, 0);		glNormal3f(0, 0, 1);	glVertex3f(-2.5f, 1.2f, 5.5f);
//		glTexCoord2f(1, 0);		glNormal3f(0, 0, 1);	glVertex3f(2.5f, 1.2f, 5.5f);
//		glTexCoord2f(1, 1);		glNormal3f(0, 0, 1);	glVertex3f(2.5f, 0.8f, 5.5f);
//		glTexCoord2f(0, 1);		glNormal3f(0, 0, 1);	glVertex3f(-2.5f, 0.8f, 5.5f);
//		glEnd();
//	glPopMatrix();
//}
//
////A4용지통 정면
//void draw_Printer_front6() //A4용지통 정면
//{
//	glPushMatrix();
//		glEnable(GL_TEXTURE_2D);
//		glBindTexture(GL_TEXTURE_2D, texP[1]);
//		glBegin(GL_POLYGON);
//		glTexCoord2f(0, 0);		glNormal3f(0, 0, 1);	glVertex3f(-2.5f, 0.6f, 5.5f);
//		glTexCoord2f(1, 0);		glNormal3f(0, 0, 1);	glVertex3f(2.5f, 0.6f, 5.5f);
//		glTexCoord2f(1, 1);		glNormal3f(0, 0, 1);	glVertex3f(2.5f, 0.0f, 5.5f);
//		glTexCoord2f(0, 1);		glNormal3f(0, 0, 1);	glVertex3f(-2.5f, 0.0f, 5.5f);
//		glEnd();
//		glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//}
//
////A4용지 넣기
//void Refill_A4()
//{
//	glPushMatrix();
//		glTranslatef(0, 0.85, 12);
//		glRotatef(-10, 1, 0, 0);
//		glTranslatef(0, 0, -Refill_A4_count);
//		glTranslatef(0, -0.3, 0);
//
//		if (Refill_A4_count2 == 1)
//		{
//			glRotatef(10, 1, 0, 0);
//		}
//
//		draw_A4();
//	glPopMatrix();
//}
//
////프린터 용지통 열기
//void draw_Printer_front7()
//{
//	glPushMatrix();
//		glTranslatef(0, 0, 2);
//		draw_Printer_front6();
//		glPushMatrix();
//		glColor3f(0.270f, 0.290f, 0.267f);
//			glScalef(1, 0.7, 1);
//			draw_Printer_front5_2();
//			draw_Printer_front5_3();
//			draw_Printer_front5_4();
//		glPopMatrix();
//	glPopMatrix();
//}
//
////윗면-옆면 사이 곡면부분
//void draw_Printer_right1() //윗면-옆면 사이 곡면부분
//{
////	glColor3f(0.270f, 0.290f, 0.267f);
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//		glVertex3f(5.0f, 3.0f, -1.0f);
//		glVertex3f(5.05f, 2.9f, -1.0f);
//		glVertex3f(5.05f, 2.9f, 3.0f);
//		glVertex3f(5.0f, 3.0f, 3.0f);
//	glEnd();
//}
//
////곡면-옆면 사이 곡면부분
//void draw_Printer_right2() //곡면-옆면 사이 곡면부분
//{
////	glColor3f(0.270, 0.290f, 0.267f);
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//		glVertex3f(5.0f, 3.0f, 3.0f);
//		glVertex3f(5.05f, 2.9f, 3.0f);
//		glVertex3f(5.05f, 2.1f, 3.5f);
//		glVertex3f(5.0f, 2.2f, 3.5f);
//	glEnd();
//}
//
//// 옆면 중 윗부분
//void draw_Printer_right3() // 옆면 중 윗부분
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.9f, 3.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.9f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.1f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.1f, 3.5f);
//	glEnd();
//}
//
//// 옆면 중 가운데 부분
//void draw_Printer_right4() // 옆면 중 가운데 부분
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.1f, 3.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 2.1f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 1.9f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 1.9f, 3.4f);
//	glEnd();
//}
//
//// 옆면 중 아랫부분
//void draw_Printer_right5() // 옆면 중 아랫부분
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 1.9f, 3.5f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 1.9f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.05f, 0.0f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.0f, 0.0f, 3.5f);
//	glEnd();
//}
//
//// 옆면 윗 부분
//void draw_Printer_left() // 옆면 윗 부분
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 3.0f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 3.0f, 3.0);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 2.2f, 3.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 2.2f, -1.0f);
//	glEnd();
//}
//
//// 옆면 중간 부분
//void draw_Printer_left2() // 옆면 중간 부분
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 2.2f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 2.2f, 3.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.9f, 3.4f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.9f, -1.0f);
//	glEnd();
//}
//
//// 옆면 아랫 부분
//void draw_Printer_left3() // 옆면 아랫 부분
//{
////	glColor3f(0.270, 0.290f, 0.267f);
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.9f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.9f, 3.4f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 0.0f, 3.5f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 0.0f, -1.0f);
//	glEnd();
//}
//
////프린터의 뒷판
//void draw_Printer_back1() //프린터의 뒷판
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, -1);	glVertex3f(-5.0f, 3.0f, -1.0f);
//	glNormal3f(0, 0, -1);	glVertex3f(5.0f, 3.0f, -1.0f);
//	glNormal3f(0, 0, -1);	glVertex3f(5.0f, 0.0f, -1.0f);
//	glNormal3f(0, 0, -1);	glVertex3f(-5.0f, 0.0f, -1.0f);
//	glEnd();
//}
//
////프린터 뒷판의 튀어나온 부분표시
//void draw_Printer_back2() //프린터 뒷판의 튀어나온 부분표시
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, -1);	glVertex3f(-4.5f, 2.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(5.0f, 2.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(5.0f, 1.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(-4.5f, 1.8f, -1.2f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-위
//void draw_Printer_back2_2() // 뒷판-튀어나옴-위
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 1, 0);	glVertex3f(-4.5f, 2.8f, -1.2f);
//	glNormal3f(0, 1, 0);	glVertex3f(5.0f, 2.8f, -1.2f);
//	glNormal3f(0, 1, 0);	glVertex3f(5.0f, 2.8f, -1.0f);
//	glNormal3f(0, 1, 0);	glVertex3f(-4.5f, 2.8f, -1.0f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-오른
//void draw_Printer_back2_3() // 뒷판-튀어나옴-오른
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//		glVertex3f(-4.5f, 2.8f, -1.2f);
//		glVertex3f(-4.5f, 2.8f, -1.0f);
//		glVertex3f(-4.5f, 1.8f, -1.0f);
//		glVertex3f(-4.5f, 1.8f, -1.2f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-왼
//void draw_Printer_back2_4() // 뒷판-튀어나옴-왼
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//		glVertex3f(5.0f, 2.8f, -1.2f);
//		glVertex3f(5.0f, 2.8f, -1.0f);
//		glVertex3f(5.0f, 1.8f, -1.0f);
//		glVertex3f(5.0f, 1.8f, -1.2f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-오른-아래
//void draw_Printer_back2_5() // 뒷판-튀어나옴-오른-아래
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, -1);	glVertex3f(-2.5f, 1.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(-5.0f, 1.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(-5.0f, 0.4f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(-2.5f, 0.4f, -1.2f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-오른-아래-아래
//void draw_Printer_back2_5_1() // 뒷판-튀어나옴-오른-아래-아래
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0);	glVertex3f(-2.5f, 0.4f, -1.2f);
//	glNormal3f(0, -1, 0);	glVertex3f(-5.0f, 0.4f, -1.2f);
//	glNormal3f(0, -1, 0);	glVertex3f(-5.0f, 0.4f, -1.0f);
//	glNormal3f(0, -1, 0);	glVertex3f(-2.5f, 0.4f, -1.0f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-오른-아래-오른
//void draw_Printer_back2_5_2() // 뒷판-튀어나옴-오른-아래-오른
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.8f, -1.2f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 1.8f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 0.4f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(-5.0f, 0.4f, -1.2f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-오른-아래-왼
//void draw_Printer_back2_5_3() // 뒷판-튀어나옴-오른-아래-왼
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 1.8f, -1.2f);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 1.8f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 0.4f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(-2.5f, 0.4f, -1.2f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-왼-아래
//void draw_Printer_back2_6() // 뒷판-튀어나옴-왼-아래
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, -1);	glVertex3f(2.5f, 1.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(5.0f, 1.8f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(5.0f, 0.4f, -1.2f);
//	glNormal3f(0, 0, -1);	glVertex3f(2.5f, 0.4f, -1.2f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-왼-아래-아래
//void draw_Printer_back2_6_2() // 뒷판-튀어나옴-왼-아래-아래
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0);	glVertex3f(2.5f, 0.4f, -1.2f);
//	glNormal3f(0, -1, 0);	glVertex3f(5.0f, 0.4f, -1.2f);
//	glNormal3f(0, -1, 0);	glVertex3f(5.0f, 0.4f, -1.0f);
//	glNormal3f(0, -1, 0);	glVertex3f(2.5f, 0.4f, -1.0f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-왼-아래-오른
//void draw_Printer_back2_6_3() // 뒷판-튀어나옴-왼-아래-오른
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 1.8f, -1.2f);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 1.8f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 0.4f, -1.0f);
//	glNormal3f(-1, 0, 0);	glVertex3f(2.5f, 0.4f, -1.2f);
//	glEnd();
//}
//
//// 뒷판-튀어나옴-왼-아래-왼
//void draw_Printer_back2_6_4() // 뒷판-튀어나옴-왼-아래-왼
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(1, 0, 0);	glVertex3f(5.0f, 1.8f, -1.2f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.0f, 1.8f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.0f, 0.4f, -1.0f);
//	glNormal3f(1, 0, 0);	glVertex3f(5.0f, 0.4f, -1.2f);
//	glEnd();
//}
//
//void draw_Disk()
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	p = gluNewQuadric();
//	gluQuadricNormals(p, GLU_SMOOTH);
//	gluQuadricOrientation(p, GLU_INSIDE);
//	gluDisk(p, 0, 1, 50, 50);
//	glFlush();
//	gluDeleteQuadric(p);
//}
//
////3 3_2 3_3은 3_4를 만들기 위한 함수
//void draw_Printer_back3()
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	q = gluNewQuadric();
//	gluQuadricNormals(q, GLU_SMOOTH);
//	gluQuadricOrientation(q, GLU_INSIDE);
//
//	gluCylinder(q, 1, 1, 7, 50, 50);
//	draw_Disk();
//	glPushMatrix();
//	glTranslatef(0, 0, 7);
//	draw_Disk();
//	glPopMatrix();
//
//	glFlush();
//	gluDeleteQuadric(q);
//}
//
//void draw_Printer_back3_2()
//{
//	glPushMatrix();
//		glEnable(GL_CLIP_PLANE0);
//		GLdouble eq[4] = { 1,0,0,0 };
//		glClipPlane(GL_CLIP_PLANE0, eq);
//		draw_Printer_back3();
//		glDisable(GL_CLIP_PLANE0);
//	glPopMatrix();
//}
//
//void draw_Printer_back3_3()
//{
//	glPushMatrix();
//	glTranslatef(-2.9, -1, -0.01);
//	glScalef(3, 2, 1);
//	draw_Quad();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-2.9, -1, 7.01);
//	glScalef(3, 2, 1);
//	draw_Quad();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-2.9, -1, 0.01);
//	glRotatef(90, 1, 0, 0);
//	glScalef(3, 7, 1);
//	draw_Quad3();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-2.9, 1, 0.01);
//	glRotatef(90, 1, 0, 0);
//	glScalef(3, 7, 1);
//	draw_Quad3();
//	glPopMatrix();
//
//	draw_Printer_back3_2();
//}
//
////뒷면 둥글게 튀어나온 부분
//void draw_Printer_back3_4()
//{
//	glPushMatrix();
//		glEnable(GL_CLIP_PLANE1);
//		GLdouble eq1[4] = { 1, 0, 0, 1.5 };
//		glClipPlane(GL_CLIP_PLANE1, eq1);
//		draw_Printer_back3_3();
//		glDisable(GL_CLIP_PLANE1);
//	glPopMatrix();
//}
//
//void draw_Printer_down()
//{
//	glColor3f(0.1921, 0.196, 0.1647);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0);	glVertex3f(-5.0f, 0.0f, 3.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(5.0f, 0.0f, 3.5f);
//	glNormal3f(0, -1, 0);	glVertex3f(5.0f, 0.0f, -1.0f);
//	glNormal3f(0, -1, 0);	glVertex3f(-5.0f, 0.0f, -1.0f);
//	glEnd();
//}
//
//void draw_Printer_In()
//{
//	q = gluNewQuadric();
//	glPushMatrix();
//		glColor3f(1.0f, 1.0f, 1.0f);
//		gluQuadricNormals(q, GLU_SMOOTH);
//		gluCylinder(q, 0.04, 0.04, 5.3, 50, 50);
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
//
//void draw_Printer_In2()
//{
//	q = gluNewQuadric();
//	p = gluNewQuadric();
//	glPushMatrix();
//		if (Printing_A4_count2_2_on == false && Printing_A4_count2_3_on == false) glTranslatef(0, 0, Printing_A4_count2);
//		else if (Printing_A4_count2_3_on == false) 	glTranslatef(0, 0, Printing_A4_count2_2);
//		else if (Printing_A4_count2_3_on == true) glTranslatef(0, 0, Printing_A4_count2_3);
//		glColor3f(0.0f, 0.0f, 0.0f);
//		gluQuadricNormals(q, GLU_SMOOTH);
//		gluCylinder(q, 0.05, 0.05, 0.1, 50, 50);
//		glRotatef(-90, 1, 0, 0);
//		glTranslatef(0, -0.05, -0.15);
//		gluCylinder(p, 0, 0.08, 0.1, 50, 50);
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//	gluDeleteQuadric(p);
//}
//
//void draw_Ink_can()
//{
//	glDisable(GL_DEPTH_TEST);
//	glEnable(GL_BLEND);
//	q = gluNewQuadric();
//	glPushMatrix();
//	glColor4f(0.9f, 0.9f, 0.9f, 0.1f); // 잉크통을 표현하기 위해 최대한 흰색에 가깝게 표현
//	gluQuadricNormals(q, GLU_SMOOTH);
//	gluCylinder(q, 0.5, 0.5, 1, 50, 50);
//	glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//	glDisable(GL_BLEND);
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
////빨간색 잉크 채우기
//void draw_Ink_Red(float Red) 	//빨간색 잉크 채우기
//{
//	glPushMatrix();
//		glTranslatef(6, 0, -0.6);//첫 번째 잉크통 위치
//		q = gluNewQuadric();
//		glColor3f(1, 0, 0);
//		glPushMatrix();
//			gluQuadricNormals(q, GLU_SMOOTH);
//			glRotatef(90, -1, 0, 0);
//			gluCylinder(q, 0.48, 0.48, Red, 50, 50);
//		glPopMatrix();
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
//
////파란색 잉크 채우기
//void draw_Ink_Blue(float Blue) 	//파란색 잉크 채우기
//{
//	glPushMatrix();
//		glTranslatef(6, 0, 0.6);//세 번째 잉크통 위치
//		q = gluNewQuadric();
//		glColor3f(0, 0, 1);
//		glPushMatrix();
//			gluQuadricNormals(q, GLU_SMOOTH);
//			glRotatef(90, -1, 0, 0);
//			gluCylinder(q, 0.48, 0.48, Blue, 50, 50);
//		glPopMatrix();
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
//
////노란색 잉크 채우기
//void draw_Ink_Yellow(float Yellow) 	//노란색 잉크 채우기
//{
//	glPushMatrix();
//		glTranslatef(6, 0, 1.8); // 두 번째 잉크통 위치
//		q = gluNewQuadric();
//		glColor3f(1, 0.8, 0);
//		glPushMatrix();
//			gluQuadricNormals(q, GLU_SMOOTH);
//			glRotatef(90, -1, 0, 0);
//			gluCylinder(q, 0.48, 0.48, Yellow, 50, 50);
//			glPopMatrix();
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
//
////검은색 잉크 채우기
//void draw_Ink_Black(float Black) 	//검은색 잉크 채우기
//{
//	glPushMatrix();
//		glTranslatef(6, 0, 3);//첫 번째 잉크통 위치
//		q = gluNewQuadric();
//		glColor3f(0, 0, 0);
//		glPushMatrix();
//			gluQuadricNormals(q, GLU_SMOOTH);
//			glRotatef(90, -1, 0, 0);
//			gluCylinder(q, 0.48, 0.48, Black, 50, 50);
//		glPopMatrix();
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//}
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
//	draw_Printer_front5_6();
//	if (Printing == true)
//	{
//		draw_Printer_front5_5();
//		draw_Printer_front5_5_2();
//		draw_Printer_front5_5_3();
//	}
//
//	
//	if (A4_refill == false)	draw_Printer_front6();
//	else	draw_Printer_front7();
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
//
//	glPushMatrix();
//		glEnable(GL_NORMALIZE);
//		glTranslatef(-3.5, 1.3, -1.7);
//		glRotatef(90, 0, 1, 0);
//		glScalef(0.37, 0.8, 1);
//		draw_Printer_back3_4();
//		glDisable(GL_NORMALIZE);
//	glPopMatrix();
//}
//
//void draw_MyPrinter_Down()
//{
//	draw_Printer_down();
//}
//
//void draw_MyPrinter_In()
//{
//	glPushMatrix();
//		glRotatef(90, 0, 1, 0);
//		draw_Printer_In();
//		glTranslatef(0, 0, 1.2);
//		draw_Printer_In2();
//		glTranslatef(0, 0, 0.4);
//		draw_Printer_In2();
//		glTranslatef(0, 0, 0.4);
//		draw_Printer_In2();
//		glTranslatef(0, 0, 0.4);
//		draw_Printer_In2();
//		glTranslatef(0, 0, 0.4);
//		draw_Printer_In2();
//		glTranslatef(0, 0, 0.4);
//		draw_Printer_In2();
//		glTranslatef(0, 0, 0.4);
//		draw_Printer_In2();
//		glTranslatef(0, 0, 0.4);
//		draw_Printer_In2();
//	glPopMatrix();
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
//
//	glPushMatrix();
//		glTranslatef(-2.7, 1.5, 3);
//		draw_MyPrinter_In();
//	glPopMatrix();
//}
//
//void draw_MyInk()
//{
//	//잉크통 구현
//	glPushMatrix();
//		glRotatef(90, 1, 0, 0);
//		glTranslatef(6, 3, -1);//첫 번째 잉크통 위치
//		draw_Ink_can();
//		glPushMatrix();
//			glTranslatef(0, 0, 1.0f);
//			if (Black > 0.0f)	draw_Ink_down_Color(4);
//			else	draw_Ink_can_down_cover();
//		glPopMatrix();
//		glPushMatrix();
//			if (Ink_cover_off == false)
//			{
//				glTranslatef(0, 0, -0.2); //잉크통 뚜껑 위치 설정. 축을 회전 시켰으므로 z축을 회전 시켜야 원하는 방향 설정가능
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//				Ink_Cover = true;
//			}
//				
//			else
//			{
//					glTranslatef(Ink_cover_x, Ink_cover_y, -Ink_cover_z);
//					draw_Ink_can_cover();
//					draw_Ink_can_cover2();
//			}
//		glPopMatrix();
//
//		glTranslatef(0, -1.2, 0); //첫 번째 잉크통으로부터의 이동 설정. 같은 push안에 있으므로 처음 translatef에 계속 영향받는다.
//		draw_Ink_can();
//		glPushMatrix();
//			glTranslatef(0, 0, 1.0f);
//			if (Yellow > 0.0f)	draw_Ink_down_Color(3);
//			else  draw_Ink_can_down_cover();
//		glPopMatrix();
//		glPushMatrix();
//		if (Ink_cover_off2 == false)
//		{
//			glTranslatef(0, 0, -0.2); //잉크통 뚜껑 위치 설정. 축을 회전 시켰으므로 z축을 회전 시켜야 원하는 방향 설정가능
//			draw_Ink_can_cover();
//			draw_Ink_can_cover2();
//			Ink_Cover2 = true;
//		}
//
//		else
//		{
//			glTranslatef(Ink_cover_x2, Ink_cover_y2, -Ink_cover_z2);
//			draw_Ink_can_cover();
//			draw_Ink_can_cover2();
//		}
//
//		glPopMatrix();
//		glTranslatef(0, -1.2, 0); //두 번째 잉크통으로부터의 이동 설정.
//		draw_Ink_can();
//		glPushMatrix();
//			glTranslatef(0, 0, 1.0f);
//			if (Blue > 0.0f)	draw_Ink_down_Color(2);
//			else	draw_Ink_can_down_cover();
//			glPopMatrix();
//		glPushMatrix();
//		if (Ink_cover_off3 == false)
//		{
//			glTranslatef(0, 0, -0.2); //잉크통 뚜껑 위치 설정. 축을 회전 시켰으므로 z축을 회전 시켜야 원하는 방향 설정가능
//			draw_Ink_can_cover();
//			draw_Ink_can_cover2();
//			Ink_Cover3 = true;
//		}
//
//		else
//		{
//			glTranslatef(Ink_cover_x3, Ink_cover_y3, -Ink_cover_z3);
//			draw_Ink_can_cover();
//			draw_Ink_can_cover2();
//		}
//
//		glPopMatrix();
//
//		glTranslatef(0, -1.2, 0); //세 번째 잉크통으로부터의 이동 설정.
//		draw_Ink_can();
//		glPushMatrix();
//			glTranslatef(0, 0, 1.0f);
//			if (Red > 0.0f) draw_Ink_down_Color(1);
//			else draw_Ink_can_down_cover();
//			glPopMatrix();
//		glPushMatrix();
//			if (Ink_cover_off4 == false)
//			{
//				glTranslatef(0, 0, -0.2); //잉크통 뚜껑 위치 설정. 축을 회전 시켰으므로 z축을 회전 시켜야 원하는 방향 설정가능
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//				Ink_Cover4 = true;
//			}
//
//			else
//			{
//				glTranslatef(Ink_cover_x4, Ink_cover_y4, -Ink_cover_z4);
//				draw_Ink_can_cover();
//				draw_Ink_can_cover2();
//			}
//		glPopMatrix();
//	glPopMatrix();
//
//}
//
//void draw_A4()
//{
//	glPushMatrix();
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glTranslatef(0, 0, -1.5);
//	glEnable(GL_TEXTURE_2D);
//	if (Printmode_change == true) 
//	{
//		switch (Printmode)
//		{
//		case Apple:
//			glBindTexture(GL_TEXTURE_2D, texName[0]);
//			break;
//		case Strawberry:
//			glBindTexture(GL_TEXTURE_2D, texName[1]);
//			break;
//		case Pear:
//			glBindTexture(GL_TEXTURE_2D, texName[2]);
//			break;
//		case InhaF:
//			glBindTexture(GL_TEXTURE_2D, texName[3]);
//			break;
//		case InhaJ:
//			glBindTexture(GL_TEXTURE_2D, texName[4]);
//			break;
//		case InhaH:
//			glBindTexture(GL_TEXTURE_2D, texName[5]);
//			break;
//		case Gyeryong:
//			glBindTexture(GL_TEXTURE_2D, texName[6]);
//			break;
//		case Taebaek:
//			glBindTexture(GL_TEXTURE_2D, texName[7]);
//			break;
//		case Bukhan:
//			glBindTexture(GL_TEXTURE_2D, texName[8]);
//			break;
//		default:
//			glDisable(GL_TEXTURE_2D);
//			break;
//		}
//	}
//
//	glBegin(GL_POLYGON);
//	glTexCoord2f(0, 0);	glNormal3f(0, 1, 0);	glVertex3f(-1.5f, 1.25f, 1.0f);
//	glTexCoord2f(1, 0);	glNormal3f(0, 1, 0);	glVertex3f(1.5f, 1.25f, 1.0f);
//	glTexCoord2f(1, 1);	glNormal3f(0, 1, 0);	glVertex3f(1.5f, 1.25f, 5.0f);
//	glTexCoord2f(0, 1);	glNormal3f(0, 1, 0);	glVertex3f(-1.5f, 1.25f, 5.0f);
//	glEnd();
//	glPopMatrix();
//	SelectMode_on = false;
//	glDisable(GL_TEXTURE_2D);
//}
//
//void Act_Printing()
//{
//	if (Act_Printing_on == true)
//	{
//		glPushMatrix();
//		glTranslatef(0, 0, Printing_A4_count);
//		draw_A4();
//		glPopMatrix();
//	}
//}
//
//void draw_Ink_line() //잉크선
//{
//	glPushMatrix();
//	q = gluNewQuadric();
//	glTranslatef(0, 0, -0.8);
//	gluQuadricNormals(q, GLU_SMOOTH);
//	gluCylinder(q, 0.005, 0.005, 1, 50, 50);
//	glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//
//	glPushMatrix();
//	glRotatef(8, 0, 0, 1);
//
//	glEnable(GL_CLIP_PLANE0);
//	glEnable(GL_CLIP_PLANE1);
//	GLdouble eq[4] = { -1,0,0,0 };
//	GLdouble eq2[4] = { 0,-1,0,0 };
//	glPushMatrix();
//		glRotatef(90, 0, 1, 0);
//		glTranslatef(-0.2, 0.2, 0);
//		glClipPlane(GL_CLIP_PLANE0, eq);
//		glClipPlane(GL_CLIP_PLANE1, eq2);
//		glutSolidTorus(0.01, 0.2, 50, 50);
//	glPopMatrix();
//	glDisable(GL_CLIP_PLANE0);
//	glDisable(GL_CLIP_PLANE1);
//
//	glPushMatrix();
//		q = gluNewQuadric();
//		gluQuadricNormals(q, GLU_SMOOTH);
//		glRotatef(90, 1, 0, 0);
//		glTranslatef(0, 0.4, -3.2);
//		gluCylinder(q, 0.01, 0.01, 3, 50, 50);
//		glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//
//	glEnable(GL_CLIP_PLANE3);
//	glEnable(GL_CLIP_PLANE4);
//	GLdouble eq3[4] = { 1,0,0,0 };
//	GLdouble eq4[4] = { 0,1,0,0 };
//	glPushMatrix();
//		glTranslatef(-0.2, 3.2, 0.4);
//		glClipPlane(GL_CLIP_PLANE3, eq3);
//		glClipPlane(GL_CLIP_PLANE4, eq4);
//		glutSolidTorus(0.01, 0.2, 50, 50);
//	glPopMatrix();
//	glDisable(GL_CLIP_PLANE3);
//	glDisable(GL_CLIP_PLANE4);
//
//	glPushMatrix();
//	q = gluNewQuadric();
//	glTranslatef(-0.2, 3.4, 0.4);
//	glRotatef(-90, 0, 1, 0);
//	glRotatef(-20, 0, 1, 0);
//	gluQuadricNormals(q, GLU_SMOOTH);
//	gluCylinder(q, 0.01, 0.01, 3.32, 50, 50);
//	glFlush();
//	glPopMatrix();
//	gluDeleteQuadric(q);
//
//	glPopMatrix();
//}
//
//void draw_Ink_line2()
//{
//	glPushMatrix();
//	glTranslatef(0.03, 0, 0);
//	draw_Ink_line();
//	glPopMatrix();
//}
//
//void draw_Ink_line3()
//{
//	glPushMatrix();
//	glTranslatef(0.06, 0, 0);
//	draw_Ink_line();
//	glPopMatrix();
//}
//
//void draw_Ink_line4()
//{
//	glPushMatrix();
//	glTranslatef(0.09, 0, 0);
//	draw_Ink_line();
//	glPopMatrix();
//}
//
//void Display_Ink()
//{
//	gluLookAt(12, 5, -7, 0, 2, -6.8, 0, 1, 0);	
//}
//
//void DIsplay_Ink2()
//{
//	glViewport(0, 0, current_width / 4, current_height / 4);
//
//	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Ink_Red : ", -5, 3.5, 1, 1, 1);
//	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Ink_Blue : ", -5, 1, 1, 1, 1);
//	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Ink_Yellow : ", -5, -1.5, 1, 1, 1);
//	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Ink_Black : ", -5, -4, 1, 1, 1);
//
//	for (int i = 0; i < 10; i++)
//	{
//		if (Red >= 0.09999f && Red <= 0.100111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "10%", -0.5, 3.5, 1, 1, 1);
//		else if (Red >= 0.19999f && Red <=0.200111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "20%", -0.5, 3.5, 1, 1, 1);
//		else if (Red >= 0.2999f && Red <= 0.300111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "30%", -0.5, 3.5, 1, 1, 1);
//		else if (Red >= 0.39999f && Red <= 0.400111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "40%", -0.5, 3.5, 1, 1, 1);
//		else if (Red >= 0.49999f && Red <= 0.500111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "50%", -0.5, 3.5, 1, 1, 1);
//		else if (Red >= 0.59999f && Red <= 0.600111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "60%", -0.5, 3.5, 1, 1, 1);
//		else if (Red >= 0.69999f && Red <= 0.700111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "70%", -0.5, 3.5, 1, 1, 1);
//		else if (Red >= 0.79999f && Red <= 0.800111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "80%", -0.5, 3.5, 1, 1, 1);
//		else if (Red >= 0.89999f && Red <= 0.900111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "90%", -0.5, 3.5, 1, 1, 1);
//		else if (Red >= 0.99999f && Red <= 1.000111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "100%", -0.5, 3.5, 1, 1, 1);
//		else draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "0%", -0.5, 3.5, 1, 1, 1);
//
//		if (Yellow >= 0.09999f && Yellow <=0.100111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "10%", 0.5, -1.5, 1, 1, 1);
//		else if (Yellow >= 0.19999f && Yellow <= 0.200111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "20%", 0.5, -1.5, 1, 1, 1);
//		else if (Yellow >= 0.29999f && Yellow <= 0.300111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "30%", 0.5, -1.5, 1, 1, 1);
//		else if (Yellow >= 0.39999f && Yellow <= 0.400111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "40%", 0.5, -1.5, 1, 1, 1);
//		else if (Yellow >= 0.49999f && Yellow <= 0.500111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "50%", 0.5, -1.5, 1, 1, 1);
//		else if (Yellow >= 0.59999f && Yellow <= 0.600111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "60%", 0.5, -1.5, 1, 1, 1);
//		else if (Yellow >= 0.69999f && Yellow <= 0.700111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "70%", 0.5, -1.5, 1, 1, 1);
//		else if (Yellow >= 0.79999f && Yellow <= 0.800111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "80%", 0.5, -1.5, 1, 1, 1);
//		else if (Yellow >= 0.89999f && Yellow <= 0.900111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "90%", 0.5, -1.5, 1, 1, 1);
//		else if (Yellow >= 0.99999f && Yellow <= 1.000111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "100%", 0.5, -1.5, 1, 1, 1);
//		else draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "0%", 1, -1.5, 1, 1, 1);
//		
//		if (Blue >= 0.09999f && Blue <= 0.100111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "10%", 0.0, 1, 1, 1, 1);
//		else if (Blue >= 0.19999f && Blue <= 0.200111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "20%", 0.0, 1, 1, 1, 1);
//		else if (Blue >= 0.29999f && Blue <= 0.300111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "30%", 0.0, 1, 1, 1, 1);
//		else if (Blue >= 0.39999f && Blue <= 0.400111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "40%", 0.0, 1, 1, 1, 1);
//		else if (Blue >= 0.49999f && Blue <= 0.500111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "50%", 0.0, 1, 1, 1, 1);
//		else if (Blue >= 0.59999f && Blue <= 0.600111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "60%", 0.0, 1, 1, 1, 1);
//		else if (Blue >= 0.69999f && Blue <= 0.700111f)draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "70%", 0.0, 1, 1, 1, 1);
//		else if (Blue >= 0.79999f && Blue <= 0.800111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "80%", 0.0, 1, 1, 1, 1);
//		else if (Blue >= 0.89999f && Blue <= 0.900111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "90%", 0.0, 1, 1, 1, 1);
//		else if (Blue >= 0.99999f && Blue <= 1.000111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "100%", 0.0, 1, 1, 1, 1);
//		else draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "0%", 0.0, 1, 1, 1, 1);
//
//		if (Black >= 0.09999f && Black <= 0.100111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "10%", 0.2, -4, 1, 1, 1);
//		else if (Black >= 0.19999f && Black <= 0.200111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "20%", 0.2, -4, 1, 1, 1);
//		else if (Black >= 0.29999f && Black <= 0.300111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "30%", 0.2, -4, 1, 1, 1);
//		else if (Black >= 0.39999f && Black <= 0.400111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "40%", 0.2, -4, 1, 1, 1);
//		else if (Black >= 0.49999f && Black <= 0.500111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "50%", 0.2, -4, 1, 1, 1);
//		else if (Black >= 0.59999f && Black <= 0.600111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "60%", 0.2, -4, 1, 1, 1);
//		else if (Black >= 0.69999f && Black <= 0.700111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "70%", 0.2, -4, 1, 1, 1);
//		else if (Black >= 0.79999f && Black <= 0.800111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "80%", 0.2, -4, 1, 1, 1);
//		else if (Black >= 0.89999f && Black <= 0.900111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "90%", 0.2, -4, 1, 1, 1);
//		else if (Black >= 0.99999f && Black <= 1.000111f) draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "100%", 0.2, -4, 1, 1, 1);
//		else draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "0%", 0.2, -4, 1, 1, 1);
//	}
//
//	glFlush();
//}
//
//void draw_Table_1()
//{
//	glPushMatrix();
//	glScalef(1, 10, 1);
//	glutSolidCube(1);
//	glPopMatrix();
//}
//
//void draw_Table_2()
//{
//	glPushMatrix();
//	glScalef(18, 1, 8);
//	glutSolidCube(2);
//	glPopMatrix();
//}
//
//void draw_Table()
//{
//	glPushMatrix();
//		glEnable(GL_NORMALIZE);
//		glColor3f(0.4627f, 0.3372f, 0.247f);
//
//		glPushMatrix();
//			glTranslatef(0, 2, 5);
//			draw_Table_2();
//		glPopMatrix();
//
//		glColor3f(0.995f, 0.995f, 0.995f);
//		glPushMatrix();
//			glTranslatef(15.5, -4, -1);
//			draw_Table_1();
//		glPopMatrix();
//
//		glPushMatrix();
//			glTranslatef(15.5, -4, 11);
//			draw_Table_1();
//		glPopMatrix();
//
//		glPushMatrix();
//			glTranslatef(-15.5, -4, -1);
//			draw_Table_1();
//		glPopMatrix();
//
//		glPushMatrix();
//			glTranslatef(-15.5, -4, 11);
//			draw_Table_1();
//		glPopMatrix();
//
//	glDisable(GL_NORMALIZE);
//	glPopMatrix();
//}
//
//void Preview_Print()
//{
//	glViewport(800, 400, 200, 300);
//	glLoadIdentity(); // 기존의 회전 변환을 무시
//	gluLookAt(5, 5, 3, -1, 0, 0, 0, 1, 0);
//	
//	glPushMatrix();
//	glRotatef(63.5, 0, 1, 0);
//	if(Printmode !=0) draw_A4();
//	glRotatef(180, 1, 0, 0);
//	glPopMatrix();
//
//	glutPostRedisplay();
//}
//
//void draw()
//{
//	glClearColor(0.5f, 0.5f, 0.5f, 1);
//	glViewport(0, 0, current_width, current_height);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	if (Display_Ink_on == true) Display_Ink();
//	else if (Lookat_Print == true) gluLookAt(0, 18, 2, 0, 0, 0, 0, 1, 0);
//	else
//	{
//		int up = 1;
//		double eye_x = r*sin(E_Radian)*sin(A_Radian), eye_y = r*cos(E_Radian), eye_z = r*sin(E_Radian)*cos(A_Radian); //구면 좌표계를 나타내기 위함
//		if (E_angle > 180 || E_angle <= -180) up = -1; // 특정 각도가 되면 카메라의 시점이 바뀌는데 이를 처리하기 위한 조건문
//
//		gluLookAt(eye_x, eye_y, eye_z, 0, 0, 0, 0, up, 0); //카메라의 시점
//	}
//	
//	glEnable(GL_LIGHT0);
//
//	if (Light == true) glEnable(GL_LIGHT1); 
//	else glDisable(GL_LIGHT1);
//
//	GLfloat light_position1[] = { 0, 100, 100, 1 }; 
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//
//	GLfloat light_position2[] = { 200, 100, -200, 1 };
//	glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
//
//	//glPushMatrix();
//	//	glTranslatef(0, 0.01, 0);
//	//	draw_axis(); //알아보기 쉽게 좌표축 생성
//	//glPopMatrix();
//
//	draw_skybox();
//
//	glTranslatef(0, 0, -10);
//
//	glPushMatrix();
//		glScalef(0.7, 1, 1);
//		draw_Table();
//	glPopMatrix();
//	glTranslatef(0, 3.15, 2);
//
//	draw_MyPrinter();
//
//	if (Refill_on == true) Refill_A4();
//
//	draw_MyInk();
//
//	draw_Ink_Red(Red);
//	draw_Ink_Yellow(Yellow);
//	draw_Ink_Blue(Blue);
//	draw_Ink_Black(Black);
//
//	glPushMatrix();
//		glTranslatef(6, -0.1, 4);
//		glColor3f(0, 0, 0);
//		draw_Ink_line();
//		glColor3f(1.0f, 0.8f, 0);
//		draw_Ink_line2();
//		glColor3f(0, 0, 1.0f);
//		draw_Ink_line3();
//		glColor3f(1.0f, 0, 0);
//		draw_Ink_line4();
//	glPopMatrix();
//
//	Act_Printing();
//	if (Printmode != 0) Preview_Print();
//
//	draw_text();
//
//	if (Display_Ink_on2 == true) DIsplay_Ink2();
//
//	glFlush();
//	glutSwapBuffers();
//
//}
//
//void sub_menu_function(int option)
//{
//	printf("Submenu %d has been selected\n", option);
//	
//	if (SelectMode_on == true || temp_option != option)
//	{
//		switch (option)
//		{
//		case Apple:
//			Printmode = Apple;
//			break;
//		case Strawberry:
//			Printmode = Strawberry;
//			break;
//		case Pear:
//			Printmode = Pear;
//			break;
//		case InhaF:
//			Printmode = InhaF;
//			break;
//		case InhaJ:
//			Printmode = InhaJ;
//			break;
//		case InhaH:
//			Printmode = InhaH;
//			break;
//		case Gyeryong:
//			Printmode = Gyeryong;
//			break;
//		case Taebaek:
//			Printmode = Taebaek;
//			break;
//		case Bukhan:
//			Printmode = Bukhan;
//			break;
//		default:
//			Printmode = 0;
//			break;
//		}
//	}
//	temp_option = option;
//}
//
//void main_menu_function(int option)
//{
//	printf("Submenu %d has been selected\n", option);
//	if (option == 999) exit(0);
//}
//
// //방향키를 입력받아 각도를 변화시켜 카메라의 시점을 바꾼다.
//void specialkey(int key, int x, int y)
//{
//	if (key == GLUT_KEY_LEFT)
//	{
//		A_angle--;
////		printf("E_angle : %f  A_angle : %f\n", E_angle, A_angle);
//		if (A_angle < 0)  A_angle = 360 + A_angle;
//		if (A_angle > 360) A_angle = A_angle - 360;
//	}
//	else if (key == GLUT_KEY_RIGHT)
//	{
//		A_angle++;
//		if (A_angle == 360) A_angle = 0;
//	}
//	else if (key == GLUT_KEY_UP)
//	{
//		E_angle--;
//		if (E_angle < 0)  E_angle = 360 + E_angle;
//		if (E_angle > 360) E_angle = E_angle - 360;  // -1 = 359도와 같으므로 각도가 무제한으로 작아지는 일 방지
//
//	}
//	else if (key == GLUT_KEY_DOWN)
//	{
//		E_angle++;
//		if (E_angle == 360) E_angle = 0;  //360도 = 0도 이므로 각도가 무제한으로 커지는 일 방지
//
//	}
//	else if (key == GLUT_KEY_F3) //각도 초기화
//	{
//		E_angle = 67;
//		A_angle = 0;
//		r = 35;
//	}
//
//	glutPostRedisplay();
//}
//
//void mouse(int button, int state, int x, int y)
//{
//	// 인자들을 해석해서 원하는 기능을 구현
//	if (x > 755 && x < 840 && y > 525 && y < 590 && state == 0)
//	{
//		if ((Red >= -0.001f && Red <= 0.0001f) || (Yellow >= -0.001f && Yellow <= 0.0001f) || (Blue >= -0.001f && Blue <= 0.0001f) || (Black >= -0.001f && Black <= 0.0001f))
//		{
//			cout << "잉크가 없습니다." << endl;
//		}
//		else
//		{
//			Act_Printing_on = true;
//			PlaySound(TEXT(Sound), NULL, SND_ASYNC);
//			Red -= 0.1f;
//			Blue -= 0.1f;
//			Yellow -= 0.1f;
//			Black -= 0.1f;
//		}
//	}
//	if (x > 885 && x < 990 && y > 530 && y < 590 && state == 0)
//	{
//		if (Display_Ink_on == false)
//		{
//			Display_Ink_on = true;
//			Display_Ink_on2 = true;
//		}
//
//		else
//		{
//			Display_Ink_on = false;
//			Display_Ink_on2 = false;
//		}
//	}
//}
//
////void motion(int x, int y);
//
//void keyboard(unsigned char key, int x, int y)
//{
//	//키보드 버튼에 따른 각 조작기능들 구현
//	if (key == '1') //Ink_cover_off 설정
//	{
//		if (Ink_cover_off == false) Ink_cover_off = true;
//		else
//		{
//			Ink_cover_off = false;
//			Ink_cover_x = 0;
//			Ink_cover_y = 0;
//			Ink_cover_z = 0;
//		}
//	}
//
//	if (key == '2') //Ink_cover2_off 설정
//	{
//		if (Ink_cover_off2 == false) Ink_cover_off2 = true;
//		else
//		{
//			Ink_cover_off2 = false;
//			Ink_cover_x2 = 0;
//			Ink_cover_y2 = 0;
//			Ink_cover_z2 = 0;
//		}
//	}
//
//	if (key == '3') //Ink_cover3_off 설정
//	{
//		if (Ink_cover_off3 == false) Ink_cover_off3 = true;
//		else
//		{
//			Ink_cover_off3 = false;
//			Ink_cover_x3 = 0;
//			Ink_cover_y3 = 0;
//			Ink_cover_z3 = 0;
//		}
//	}
//
//	if (key == '4') //Ink_cover4_off 설정
//	{
//		if (Ink_cover_off4 == false) Ink_cover_off4 = true;
//		else
//		{
//			Ink_cover_off4 = false;
//			Ink_cover_x4 = 0;
//			Ink_cover_y4 = 0;
//			Ink_cover_z4 = 0;
//		}
//	}
//
//	if (key == 'z') //줌 인
//	{
//		if (r > 0) r--;
//	}
//	else if (key == 'x') //줌 아웃
//	{
//		r++;
//	}
//
//	//'o' 키를 누르면 조명 on-off
//	if (key == 'l')
//	{
//		if (Light == true)  Light = false;
//		else Light = true;
//	}
//
//	if (key == 'r') // 빨간색 잉크 채워 넣음
//	{
//		if (Ink_Cover4 == false)
//		{
//			if (Red < 1.0f)
//			{
//				Red += 0.1f;
//			}
//			else cout << "잉크 뚜껑을 열어주세요" << endl;
//		}
//	}
//
//	if (key == 'y') // 노란색 잉크 채워 넣음
//	{
//		if (Ink_Cover2 == false)
//		{
//			if (Yellow < 1.0f)	Yellow += 0.1f;
//		}
//		else cout << "잉크 뚜껑을 열어주세요" << endl;
//	}
//
//	if (key == 'b') // 파란색 잉크 채워 넣음
//	{
//		if (Ink_Cover3 == false)
//		{
//			if (Blue < 1.0f)	Blue += 0.1f;
//			cout << Blue;
//		}
//		else cout << "잉크 뚜껑을 열어주세요" << endl;
//	}
//
//	if (key == 'k') // 검은색 잉크 채워 넣음
//	{
//		if (Ink_Cover == false)
//		{				
//			if (Black < 1.0f)	Black += 0.1f;
//		}
//		else cout << "잉크 뚜껑을 열어주세요" << endl;
//	}
//
//	if (key == 'R') // 빨간색 잉크 뺌
//	{
//		if (Ink_Cover4 == false)
//		{
//			if (Red > 0.0f)	Red -= 0.1f;
//		}
//	}
//
//	if (key == 'Y') // 노란색 잉크 뺌
//	{
//		if (Ink_Cover2 == false)
//		{
//			if (Yellow > 0.0f)	Yellow -= 0.1f;
//		}
//	}
//
//	if (key == 'B') // 파란색 잉크 뺌
//	{
//		if (Ink_Cover3 == false)
//		{
//			if (Blue > 0.0f)	Blue -= 0.1f;
//		}
//	}
//
//	if (key == 'K') // 검은색 잉크 뺌
//	{
//		if (Ink_Cover == false)
//		{
//			if (Black > 0.0f)	Black -= 0.1f;
//		}
//	}
//
//	if (key == 'i') //잉크 초기화
//	{
//		Red = 0.2f;
//		Yellow = 0.2f;
//		Blue = 0.2f;
//		Black = 0.2f;
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
//		if ((Red >= -0.001f && Red <= 0.0001f) || (Yellow >= -0.001f && Yellow <= 0.0001f) || (Blue >= -0.001f && Blue <= 0.0001f) || (Black >= -0.001f && Black <= 0.0001f) )
//		{
//			cout << "잉크가 없습니다." << endl;
//		}
//		else
//		{
//			Act_Printing_on = true;
//			PlaySound(TEXT(Sound), NULL, SND_ASYNC);
//			Red -= 0.1f;
//			Blue -= 0.1f;
//			Yellow -= 0.1f;
//			Black -= 0.1f;
//		}
//	}
//
//	if (key == '[')
//	{
//		Act_Printing_on = false;
//		Printmode_change = true;
//		Printing_A4_count = 0;
//		Printing_A4_count2 = 0;
//		Printing_A4_count2_2 = 1;
//		Printing_A4_count2_2_on = false;
//		Printing_A4_count2_3_on = false;
//		Printmode = 0;
//		SelectMode_on = true;
//	}
//
//	if (key == 'f')
//	{
//		A4_refill = true;
//	}
//
//	if (key == 'F')
//	{
//		A4_refill = false;
//		Refill_on = false;
//		Refill_A4_count = 0;
//	}
//
//	if (key == 't')
//	{
//		if(A4_refill == true)	Refill_on = true;
//	}
//
//	if (key == 'a')
//	{
//		if (Lookat_Print == false)	Lookat_Print = true;
//		else Lookat_Print = false;
//	}
//
//	glutPostRedisplay();
//}