//#pragma comment(lib, "legacy_stdio_definitions.lib")
//#pragma comment(lib, "winmm")
//#include <gl/glut.h>
//#include <stdio.h>
//#include <math.h> 
//#include <Windows.h>
//#include <mmsystem.h>
//#include <gl/GLAUX.H>
//#include "Project_function.h"
//#include <iostream>
//using namespace std;
//
//
//double E_angle = 67 , A_angle = 0; // 라디안으로 변환하기 위해 Degree 변수 선언.
//#define Sound "./sound/Print_Sound2.wav"
//#define PI 3.141592
//#define E_Radian PI*E_angle/180 //C언어에서는 라디안만 사용가능하다.
//#define A_Radian PI*A_angle/180
//
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
//
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
//	glutIdleFunc(idle);
//	init();
//
//	glutMainLoop();
//
//	return 0;
//}