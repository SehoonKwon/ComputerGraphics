//#include <stdlib.h> 
//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h> //idle func 사용시
//#include <string.h>
//
//
//int iDrawMode = 0; //전역변수, 그리기 모드를 위한 변수
//int iNumPoints = 0;//몇번째 마우스 클릭이 있는지를 저장해 놓음
//int xaxis[100];
//int yaxis[100];
//int color = 0;// RGB색상 변환을 위한 변수
//int The_Num;//도형이 몇개 그려졌는지 갯수를 저장해 놓는다.
//int Change_color[100];
//double Change_alpha[100];
//
//double spin = 0;
//double distance = 0;
//
//bool Antialiase_on = false;// 안티에일리어싱을 ON_OFF를 위한 변수
//bool Character_on = false; // 문자 출력 ON_OFF를 위한 변수
//
//bool Rotation_on = false;// 회전의 ON_OFF 를 위한 변수
//bool Translation_on = false;//평행이동의 ON_OFF 를 위한 변수
//
//
//void Init(void);
//void idle(void);
//void drawString(void * font, const char* str, int x, int y);
//void drawPoint(void);
//void drawLine(void);
//void drawPolygon(void);
//void drawTriangle(void);
//void drawQuad(void);
//void draw(void);
//void mouse(int button, int state, int x, int y);
//void motion(int x, int y);
//void keyboard(unsigned char key, int x, int y);
//void subsub_menu_function1(int option);
//void subsub_menu_function2(int option);
//void sub_menu_function1(int option);
//void main_menu_function(int option);
//
//
//int main(int argc, char** argv)
//{
//
//	int subsubmenu1;
//	int subsubmenu2;
//	int submenu1;
//
//	////////////////// 좌표와 색의 변환, 알파블랜딩을 하기 위한 배열을 초기화 시켜준다./////////////////////
//	for (int i = 0; i<100; i++)
//	{
//		Change_alpha[i] = 1;
//		Change_color[i] = 0;
//		xaxis[i] = 0;
//		yaxis[i] = 0;
//	}
//
//	///////////////// window 초기화 /////////////////
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First Gl Program");
//	Init(); //사용자 초기화 함수
//
//			////////////////////// 팝업메뉴 생성 및 추가 ///////////////////////////
//	subsubmenu1 = glutCreateMenu(subsub_menu_function1);
//	glutAddMenuEntry("GL_LINES", 21);
//	glutAddMenuEntry("GL_LINE_STRIP", 22);
//	glutAddMenuEntry("GL_LINE_LOOP", 23); //3개의 항목이 있는 메뉴 생성
//
//	subsubmenu2 = glutCreateMenu(subsub_menu_function2);
//	glutAddMenuEntry("GL_TRIANGLES", 31);
//	glutAddMenuEntry("GL_TRIANGLE_STRIP", 32);
//	glutAddMenuEntry("GL_QUADS", 33);
//	glutAddMenuEntry("GL_POLYGON", 34);
//
//	submenu1 = glutCreateMenu(sub_menu_function1);
//	glutAddMenuEntry("Point Draw", 1);
//	glutAddSubMenu("Line Draw", subsubmenu1);
//	glutAddSubMenu("Polygon Draw", subsubmenu2);
//
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Clear", 41);
//	glutAddMenuEntry("Antialiasing", 42);
//	glutAddMenuEntry("Character Print", 43);
//	glutAddSubMenu("Draw mode", submenu1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	//////////////////Call back 함수 정의//////////////////
//
//	glutDisplayFunc(draw); //draw() 실제 그리기함수
//	glutMouseFunc(mouse); //마우스 입력처리
//	glutMotionFunc(motion); //마우스 움직임 처리
//	glutKeyboardFunc(keyboard); //키보드 입력처리
//
//	glutIdleFunc(idle); //idle function 처리
//
//
//						//////////////////// Looping 시작 ///////////////////////
//	glutMainLoop();
//
//	return 0;
//}
//
//void Init(void)
//{
//	///////////////////// 화면의 기본색 설정 (RGB, alpha) //////////////////////////
//	glClearColor(0.0f, 0.0f, 0.5f, 0.0f);
//	//화면 좌표정보 설정
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
//}
//
//void idle(void)
//{
//	///////////////////////////물체의 움직임 animation 구현에 이용///////////////////////////
//	//printf("%d second has elapsed since the system was started \n", GetTickCount()/1000); //몇초 실행됬는지
//
//	if (Rotation_on == true)
//	{
//		spin = spin + 0.5;
//		if (spin > 360)
//		{
//			spin -= 360; // 360을 뺴서 spin에 대입해주겠다
//		}
//	}
//	if (Translation_on == true)
//	{
//		distance = distance + 0.5;
//		if (distance>500)
//		{
//			distance -= 1000; // 오른쪽 화면 끝까지 간 후에 다시 왼쪽화면에서 나타나야 하므로.
//		}
//	}
//	glutPostRedisplay();
//}
/////////////// character 출력을 위한 함수 ///////////////////////////
//void drawString(void * font, const char* str, int x, int y)
//{
//	unsigned int i;
//	glRasterPos2i(x, y);
//	for (i = 0; i<strlen(str); i++)
//	{
//		glutBitmapCharacter(font, str[i]);
//	}
//
//}
//
//void drawPoint(void)
//{
//	//점의 색상
//	//glColor3f(1.0f, 1.0f, 0.0f);
//	//점의 크기 (초기값 1.0)
//	glPointSize(20.0f);
//	switch (iDrawMode)
//	{
//	case 1:
//
//		glBegin(GL_POINTS); //그리는 좌표와 윈도우 창에서 얻어지는 좌표의 y 값이 다름
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//	}
//	glutPostRedisplay();
//}
//
//void drawLine(void)
//{
//	glLineWidth(10.0f); //줄 굵기
//	glEnable(GL_LINE_STIPPLE);//줄모양 변경 사용
//	glLineStipple(3, 0xAAAA); //줄 모양 지정
//	switch (iDrawMode)
//	{
//	case 21:
//	{
//		glBegin(GL_LINES);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	case 22:
//	{
//		glBegin(GL_LINE_STRIP);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	case 23:
//	{
//		glBegin(GL_LINE_LOOP);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	}
//	glutPostRedisplay();
//}
//
//void drawTriangle(void)
//{
//	//////glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // 그리기 모드 설정, 효과줄면과 point인지 line인지 면fill인지
//	//////glFrontFace(GL_CCW); //어느쪽이 앞면인지 정하는 default 값 CCW
//	//////glCullFace(GL_FRONT);//앞면을 보여줄지 뒷면을 보여줄지 앞뒤 모두 보여 줄지
//	//바로 윗줄의 함수를 사용할때, glEnable(GL_CULL_FACE);로 상태를 on해야함
//
//	glColor3f(1.0f, 1.0f, 0.0f); //노란색
//	if (Antialiase_on == false)
//	{
//		glDisable(GL_BLEND);//alpha blending OFF
//	}
//	else if (Antialiase_on == true)
//	{
//		glEnable(GL_BLEND);   //alpha blending ON
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	}
//	switch (iDrawMode)
//	{
//	case 31:
//	{
//		glBegin(GL_TRIANGLES);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			if (Change_color[t / 3] == 0)
//			{
//				glColor4f(1.0f, 1.0f, 0.0f, Change_alpha[t / 3]);
//			}
//			else if (Change_color[t / 3] == 1)
//			{
//				glColor4f(1.0f, 0.0f, 0.0f, Change_alpha[t / 3]);
//			}
//			else if (Change_color[t / 3] == 2)
//			{
//				glColor4f(0.0f, 1.0f, 0.0f, Change_alpha[t / 3]);
//			}
//			else if (Change_color[t / 3] == 3)
//			{
//				glColor4f(0.0f, 0.0f, 1.0f, Change_alpha[t / 3]);
//			}
//			else if (Change_color[t / 3] == 4)
//			{
//				glColor4f(0.0f, 1.0f, 1.0f, Change_alpha[t / 3]);
//			}
//			else if (Change_color[t / 3] == 5)
//			{
//				glColor4f(1.0f, 0.0f, 1.0f, Change_alpha[t / 3]);
//			}
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	case 32:
//	{
//		glBegin(GL_TRIANGLE_STRIP);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			if (Change_color[t / 3] == 0)
//			{
//				glColor3f(1.0f, 1.0f, 0.0f);
//			}
//			else if (Change_color[t / 3] == 1)
//			{
//				glColor3f(1.0f, 0.0f, 0.0f);
//			}
//			else if (Change_color[t / 3] == 2)
//			{
//				glColor3f(0.0f, 1.0f, 0.0f);
//			}
//			else if (Change_color[t / 3] == 3)
//			{
//				glColor3f(0.0f, 0.0f, 1.0f);
//			}
//			else if (Change_color[t / 3] == 4)
//			{
//				glColor3f(0.0f, 1.0f, 1.0f);
//			}
//			else if (Change_color[t / 3 == 5])
//			{
//				glColor3f(1.0f, 0.0f, 1.0f);
//			}
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	}
//	glutPostRedisplay();
//}
//
//void drawQuad(void)
//{
//	if (Antialiase_on == false)
//	{
//		glDisable(GL_BLEND);//alpha blending OFF
//
//	}
//	if (Antialiase_on == true)
//	{
//		glEnable(GL_BLEND);   //alpha blending ON
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	}
//
//	glColor3f(1.0f, 1.0f, 0.0f); //이거는 왜 써준거지??
//	switch (iDrawMode)
//	{
//	case 33:
//	{
//		glBegin(GL_QUADS);
//		for (int t = 0; t<iNumPoints; t++)
//		{
//			if (Change_color[t / 4] == 0)
//			{
//				glColor4f(1.0f, 1.0f, 0.0f, Change_alpha[t / 4]);
//			}
//			else if (Change_color[t / 4] == 1)
//			{
//				glColor4f(1.0f, 0.0f, 0.0f, Change_alpha[t / 4]);
//			}
//			else if (Change_color[t / 4] == 2)
//			{
//				glColor4f(0.0f, 1.0f, 0.0f, Change_alpha[t / 4]);
//			}
//			else if (Change_color[t / 4] == 3)
//			{
//				glColor4f(0.0f, 0.0f, 1.0f, Change_alpha[t / 4]);
//			}
//			else if (Change_color[t / 4] == 4)
//			{
//				glColor4f(0.0f, 1.0f, 1.0f, Change_alpha[t / 4]);
//			}
//			else if (Change_color[t / 4] == 5)
//			{
//				glColor4f(1.0f, 0.0f, 1.0f, Change_alpha[t / 4]);
//			}
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//	}
//	glutPostRedisplay();
//
//}
//
//void drawPolygon(void)
//{
//	glColor3f(1.0f, 1.0f, 0.0f);
//	switch (iDrawMode)
//	{
//	case 34:
//	{
//		glBegin(GL_POLYGON);
//		for (int t = 0; t < iNumPoints; t++)
//		{
//			glVertex2i(xaxis[t], yaxis[t]);
//		}
//		glEnd();
//		break;
//	}
//
//	}
//	glutPostRedisplay();
//}
//
//void draw(void)
//{
//	//glColor3f (0.0f, 0.0f, 0.5f);
//	//glutWireTeapot(0.5f); //주전자 그리기
//
//	glMatrixMode(GL_MODELVIEW);//좌표계에서 물체의 변환, 시점의 이동 등 반영
//							   //glMatrixMode(GL_PROJECTION); //카메라의 projection 특성 반영
//	glLoadIdentity();//현재 활성화된 행렬을 단위 행렬로 초기화
//
//
//	glClear(GL_COLOR_BUFFER_BIT); //화면지우기
//
//								  ////////////////// Rotation _ON , OFF 실행 /////////////////
//	if (Rotation_on == true)
//	{
//		glTranslatef(250 + distance, 250, 0); // 회전 중심(pivot point )을 정하여 원래의 좌표계의 중점을 이동시킨다.
//		glRotatef(spin, 0, 0, 1); // 원하는 회전 각도 spin, x,y,z 중심축
//		glTranslatef(-250 - distance, -250, 0);//회전하면서 평행이동 할 때에는 평행이동 된 만큼 Povot point 가 이동하기 때문에 이동한 좌표계의 중심을 평행이동 한 만큼 옮겨 주어야 한다.
//											   //적용 순서는 역순, 밑에서부터 적용됨
//	}
//
//	/////////////////// Translation_ON,OFF 실행 ////////////////////////////////////
//	if (Translation_on == true)
//	{
//		glTranslatef(distance, 0, 0);
//	}
//
//	//////////////////////// 키보드의 입력을 받아서 도형의 색깔 바꾸기 /////////////////////////////
//
//	if (iDrawMode == 1 || iDrawMode == 21 || iDrawMode == 22 || iDrawMode == 23 || iDrawMode == 34)
//	{
//		if (color == 1)
//		{
//			glColor3f(1.0f, 0.0f, 0.0f);//Red 색깔
//		}
//		else if (color == 2)
//		{
//			glColor3f(0.0f, 1.0f, 0.0f);//Green 색깔
//		}
//		else if (color == 3)
//		{
//			glColor3f(0.0f, 0.0f, 1.0f);//Blue 색깔
//		}
//		else if (color == 4)
//		{
//			glColor3f(0.0f, 1.0f, 1.0f);//Cyan 색깔
//		}
//		else if (color == 5)
//		{
//			glColor3f(1.0f, 0.0f, 1.0f);//Magenta 색깔
//		}
//		else if (color == 0)
//		{
//			glColor3f(1.0f, 1.0f, 0.0f);//노란색으로 초기화
//		}
//	}
//	/////////////////////////// AntiAliasing  과  Alpha Blending  설정 ///////////////////////////
//
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); //antialiasing 품질 결정
//	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
//	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
//
//	if (Antialiase_on == false)
//	{
//		glDisable(GL_BLEND);
//		glDisable(GL_POINT_SMOOTH);
//		glDisable(GL_LINE_SMOOTH);
//		glDisable(GL_POLYGON_SMOOTH);
//	}
//
//	else if (Antialiase_on == true)
//	{
//		glEnable(GL_BLEND); //antialiasing 사용 , alpha 블렌딩하고도 관련
//		glEnable(GL_POINT_SMOOTH);
//		glEnable(GL_LINE_SMOOTH);
//		glEnable(GL_POLYGON_SMOOTH);
//	}
//
//	/////////////////////////// 도형을 그리는 모드를 선택 /////////////////////////////
//
//	if (iDrawMode == 1)
//	{
//		drawPoint();
//	}
//	else if (iDrawMode == 21 || iDrawMode == 22 || iDrawMode == 23)
//	{
//		drawLine();
//	}
//	else if (iDrawMode == 31 || iDrawMode == 32)
//	{
//		drawTriangle();
//	}
//	else if (iDrawMode == 33)
//	{
//		drawQuad();
//	}
//	else if (iDrawMode == 34)
//	{
//		drawPolygon();
//	}
//	glLoadIdentity();
//	//문자열 출력은 제일 마지막에 해주어야 제대로 동작됨 (각draw함수 뒤에)
//	if (Character_on == true)
//	{
//		glColor3f(0.0f, 1.0f, 1.0f);
//		drawString(GLUT_BITMAP_TIMES_ROMAN_24, "12131668 YURI KIM", 5, 475);
//		if (Antialiase_on == false)
//			drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Antialiasing OFF!", 300, 5);
//		else if (Antialiase_on == true)
//			drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Antialiasing ON!", 300, 5);
//	}
//
//	glutSwapBuffers();
//	glutPostRedisplay();
//}
//
//void mouse(int button, int state, int x, int y)
//{
//	printf("Mouse button is clicked! (%d,%d,%d,%d)\n", button, state, x, y);
//	//왼쪽버튼0, 중간버튼1, 오른쪽버튼2
//	//누름 0, 뗌 1
//	if (button == 0 && state == 0) // 설정 안해주면 x,y가 버튼을 누르고 뗄때 계속 저장 될수도 있음
//	{
//		xaxis[iNumPoints] = x;
//		yaxis[iNumPoints] = 500 - y; // window와 opengl의 y축을 맞추어줌
//		iNumPoints++;
//	}
//	glutPostRedisplay();
//}
//
//void motion(int x, int y)
//{
//	printf("Mouse is moving! (%d, %d)\n", x, y);
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//
//	printf("You pressed %c \n", key);
//	/////////////////////// 키보드로 숫자를 입력 받아 도형의 색을 바꾼다./////////////////////////
//	if ((key >= 48) && (key <= 57))//키보드의 숫자 1부터 5 이외의 숫자를 입력받으면 노란색으로 초기화 시켜주기 위해서 1부터 5까지를 아스키 코드로 받았다.
//	{
//		if (iDrawMode == 1 || iDrawMode == 21 || iDrawMode == 22 || iDrawMode == 23 || iDrawMode == 34)
//		{
//			switch (key)
//			{
//
//			case '1':
//			{
//				color = 1;
//				printf("RED\n");
//				break;
//			}
//			case '2':
//			{
//				color = 2;
//				printf("GREEN\n");
//				break;
//			}
//			case '3':
//			{
//				color = 3;
//				printf("BLUE\n");
//				break;
//			}
//			case '4':
//			{
//				color = 4;
//				printf("CYAN\n");
//				break;
//			}
//			case '5':
//			{
//				color = 5;
//				printf("Magenta\n");
//				break;
//			}
//
//			default://1~5 이외의 숫자를 입력했을 시에는 노란색으로 초기화 시킨다.
//			{
//				color = 0;
//				printf("color reset\n");
//				break;
//			}
//
//			}
//			glutPostRedisplay();
//		}
//		//////////////////////// 삼각형 그리기 ////////////////////
//		////////////// 삼각형은 마지막에 그린 도형만 색깔이 바뀌어야 하므로 다른 도형과는 다른 설정을 준다 //////////////////
//		if (iDrawMode == 31 || iDrawMode == 32)
//		{
//			The_Num = iNumPoints / 3;
//
//			switch (key)
//			{
//
//			case '1':
//			{
//				Change_color[The_Num - 1] = 1;
//				printf("RED\n");
//				break;
//			}
//			case '2':
//			{
//				Change_color[The_Num - 1] = 2;
//				printf("GREEN\n");
//				break;
//			}
//			case '3':
//			{
//				Change_color[The_Num - 1] = 3;
//				printf("BLUE\n");
//				break;
//			}
//			case '4':
//			{
//				Change_color[The_Num - 1] = 4;
//				printf("CYAN\n");
//				break;
//			}
//			case '5':
//			{
//				Change_color[The_Num - 1] = 5;
//				printf("Magenta\n");
//				break;
//			}
//
//			default:
//			{
//				Change_color[The_Num - 1] = 0;
//				printf("color reset\n");
//				break;
//			}
//
//			}
//			glutPostRedisplay();
//
//		}
//
//		if (iDrawMode == 33)
//		{
//
//			The_Num = iNumPoints / 4;
//
//
//			switch (key)
//			{
//
//			case '1':
//			{
//				Change_color[The_Num - 1] = 1;
//				printf("RED\n");
//				break;
//			}
//			case '2':
//			{
//				Change_color[The_Num - 1] = 2;
//				printf("GREEN\n");
//				break;
//			}
//			case '3':
//			{
//				Change_color[The_Num - 1] = 3;
//				printf("BLUE\n");
//				break;
//			}
//			case '4':
//			{
//				Change_color[The_Num - 1] = 4;
//				printf("CYAN\n");
//				break;
//			}
//			case'5':
//			{
//				Change_color[The_Num - 1] = 5;
//				printf("Magenta\n");
//				break;
//			}
//			default:
//			{
//				Change_color[The_Num - 1] = 0;
//				printf("color reset\n");
//				break;
//			}
//
//			}
//		}
//		glutPostRedisplay();
//	}
//
//	if (iDrawMode == 31 || iDrawMode == 32)
//	{
//		The_Num = iNumPoints / 3;
//		if (Antialiase_on == true)    //alpha값을 변경한다
//		{
//			switch (key)
//
//			{
//			case'q':
//			{
//				Change_alpha[The_Num - 1] = 0.0f;
//				printf("alpha value : 0.0\n");
//				break;
//			}
//			case 'w':
//			{
//				Change_alpha[The_Num - 1] = 0.25f;
//				printf("alpha value : 0.25\n");
//				break;
//			}
//			case 'e':
//			{
//				Change_alpha[The_Num - 1] = 0.5f;
//				printf("alpha value : 0.5\n");
//				break;
//			}
//			case 'r':
//			{
//				Change_alpha[The_Num - 1] = 0.75f;
//				printf("alpha value : 0.75\n");
//				break;
//			}
//			case 't':
//			{
//				Change_alpha[The_Num - 1] = 1.0f;
//				printf("alpha value : 1.0\n");
//				break;
//			}
//			}
//		}
//		glutPostRedisplay();
//	}
//	if (iDrawMode == 33)
//	{
//		The_Num = iNumPoints / 4;
//
//		if (Antialiase_on == true)    //alpha값을 변경한다
//		{
//			switch (key)
//
//			{
//			case'q':
//			{
//				Change_alpha[The_Num - 1] = 0.0f;
//				printf("alpha value : 0.0\n");
//				break;
//			}
//			case 'w':
//			{
//				Change_alpha[The_Num - 1] = 0.25f;
//				printf("alpha value : 0.25\n");
//				break;
//			}
//			case 'e':
//			{
//				Change_alpha[The_Num - 1] = 0.5f;
//				printf("alpha value : 0.5\n");
//				break;
//			}
//			case 'r':
//			{
//				Change_alpha[The_Num - 1] = 0.75f;
//				printf("alpha value : 0.75\n");
//				break;
//			}
//			case 't':
//			{
//				Change_alpha[The_Num - 1] = 1.0f;
//				printf("alpha value : 1.0\n");
//				break;
//			}
//			}
//		}
//		glutPostRedisplay();
//	}
//	if (Antialiase_on == false)
//	{
//		if (key == 'a')
//		{
//			Antialiase_on = true;
//				printf("Antialiasing ON\n");
//		}
//	}
//	else if (Antialiase_on == true)
//	{
//		if (key == 'a')
//		{
//			Antialiase_on = false;
//				printf("Antialiasing OFF\n");
//		}
//	}
//	if (Character_on == false)
//	{
//		if (key == 'c')
//		{
//			Character_on = true;
//				printf("Character ON\n");
//		}
//		glutPostRedisplay();
//	}
//
//	else if (Character_on == true)
//	{
//		if (key == 'c')
//		{
//			Character_on = false;
//				printf("Character OFF\n");
//		}
//		glutPostRedisplay();
//	}
//	if (Translation_on == false)
//	{
//		if (key == 'T')
//		{
//			Translation_on = true;
//				printf("Translation_ON\n");
//		}
//		glutPostRedisplay();
//	}
//	else if (Translation_on == true)
//	{
//		if (key == 'T')
//		{
//			Translation_on = false;
//				printf("Translation_OFF\n");
//		}
//		glutPostRedisplay();
//	}
//	if (Rotation_on == false)
//	{
//		if (key == 'R')
//		{
//			Rotation_on = true;
//				printf("Rotaion_ON\n");
//		}
//		glutPostRedisplay();
//	}
//	else if (Rotation_on == true)
//	{
//		if (key == 'R')
//		{
//			Rotation_on = false;
//				printf("Rotation_OFF\n");
//		}
//		glutPostRedisplay();
//	}
//
//
//
//	glutPostRedisplay();
//}
//
//void subsub_menu_function1(int option)
//
//{
//	printf("SubSubmenu %d has been selected \n", option);
//
//	switch (option)
//	{
//	case 21:
//	{
//		iDrawMode = option;
//		printf("GL_LINES\n");
//		break;
//	}
//	case 22:
//	{
//		iDrawMode = option;
//		printf("GL_LINE_STRIP\n");
//		break;
//	}
//	case 23:
//	{
//		iDrawMode = option;
//		printf("GL_LINE_LOOP\n");
//		break;
//	}
//	}
//	glutPostRedisplay();
//}
//
//void subsub_menu_function2(int option)
//
//{
//	printf("SubSubmenu %d has been selected \n", option);
//
//	switch (option)
//	{
//	case 31:
//	{
//		iDrawMode = option;
//		printf("GL_TRIANGLES\n");
//		break;
//	}
//	case 32:
//	{
//		iDrawMode = option;
//		printf("GL_TRIANGLE_STRIP\n");
//		break;
//	}
//	case 33:
//	{
//		iDrawMode = option;
//		printf("GL_QUADS\n");
//		break;;
//	}
//	case 34:
//	{
//		iDrawMode = option;
//		printf("GL_POLYGON\n");
//		break;
//	}
//	}
//	glutPostRedisplay();
//}
//
//void sub_menu_function1(int option)
//
//{
//	printf("Submenu %d has beed selected \n", option);
//	if (option == 1)
//	{
//		iDrawMode = option;
//		printf("Point Draw\n");
//		glutPostRedisplay();
//	}
//}
//
//void main_menu_function(int option)
//{
//	printf("Mainmenu %d has beed selected \n", option);
//	if (option == 999)
//	{
//		exit(0);
//	}
//
//	if (option == 41)
//	{
//		printf("Clear\n");
//		iNumPoints = 0;
//		color = 0;
//
//		for (int i = 0; i<The_Num; i++)
//		{
//			Change_color[i] = 0;
//			Change_alpha[i] = 1;
//		}
//		glutPostRedisplay();
//	}
//
//	if (option == 42)
//	{
//		if (Antialiase_on == false)
//		{
//			Antialiase_on = true;
//				printf("Antialiasing ON\n");
//			glutPostRedisplay();
//		}
//
//		else if (Antialiase_on == true)
//		{
//			Antialiase_on = false;
//				printf("Antialiasing OFF\n");
//			glutPostRedisplay();
//		}
//	}
//
//	/*if (option == 43)
//	{
//		if (Character_on == false)
//		{
//			Character_on = true;
//				printf("Character ON\n");
//			glutPostRedisplay();
//		}
//		else if (Character_on == true)
//		{
//			Character_on = false;
//				printf("Character OFF\n");
//			glutPostRedisplay();
//		}
//	}*/
//}