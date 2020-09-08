//#include <gl/glut.h>
//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//using namespace std;
//
//void resize(int width, int height);
//void draw_axis(); // 축을 그리는 함수.
//void draw(); // 전체적인 draw함수
//void draw_can(); //can을 그리는 함수
//void draw_disk(); //disk를 그리는 함수
//void draw_teapot(); //주전자를 그리는 함수
//void draw_text(); //문자열을 출력하는 함수
//void idle(); 
//void keyboard(unsigned char key, int x, int y);
//void draw_string(void *font, const char* str, float x, float y, float red, float green, float blue); //문자열을 화면에 표시하는 함수
//
//int current_width = 0, current_height = 0; //윈도우 사이즈 값을 받아오기 위해 전역변수 선언
//
//char my_string[255]; // 문자열 저장을 위한 char배열 선언
//
//char* Test = "Hi";
//
////각 객체들의 회전율을 다르게 하기 위해 모두 다른 변수 선언
//double spin_disk = 0.01;
//double spin_teapot = 0.01;
//double spin_can = 0.01;
//
//GLUquadric *q;
//
//bool String_on = false; //이름 띄우기 온오프 기능
//bool Rotate_on = true;//회전 온오프 기능
//
//int main(int argc, char** argv)
//{
//	// 윈도우 초기화
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//
//	glutDisplayFunc(draw);
//	glutKeyboardFunc(keyboard);
//	glutReshapeFunc(resize);
//	glutIdleFunc(idle);
//	
//	glutMainLoop();
//
//	return 0;
//}
//
//void idle()
//{
//	//회전 모드가 on일 때만 회전한다
//	if (Rotate_on == true)
//	{
//		spin_disk = spin_disk + 0.8;
//		spin_can = spin_can + 0.4;
//		spin_teapot = spin_teapot + 0.1;
//		if (spin_disk > 360) spin_disk -= 360;
//		if (spin_can > 360) spin_can -= 360;
//		if (spin_teapot > 360) spin_teapot -= 360;
//	}
//	glutPostRedisplay();
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
//	current_width = width; //윈도우 사이즈를 이용하기 위해 전역변수를 이용해 값을 저장한다.
//	current_height = height; //width와 같은 용도
//}
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
//	glVertex3f(7, 0, 0);
//
//	glColor3f(0, 1, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 7, 0);
//
//	glColor3f(0, 0, 1);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 7);
//	
//	glEnd();
//
//	glLineWidth(1); // 와이어 티폿 같은 선을 이용한 물체에 영향을 주지않기 위해 초기값으로 초기화
//}
//
//void draw_can()
//{
//	glViewport(0, 0, current_width / 2, current_height / 2); //시작점은 (0,0) 크기는 윈도우의 1/4
//	draw_axis();
//	glPushMatrix(); //다른 물체의 회전에 영향을 주지 않도록 push-pop으로 묶어준다
//	glRotatef(spin_can, 1, 0, 0);
//	q = gluNewQuadric();
//	glColor3f(0, 1, 1);
//	gluQuadricNormals(q, GLU_NONE);
//	gluCylinder(q, 0, 2, 5, 50, 50); // 실린더를 그린다. Base 값이 0 이므로 원뿔형태가 그려진다.
//	glPopMatrix();
//	glFlush();
//	gluDeleteQuadric(q);
//}
//
//void draw_teapot()
//{
//	glViewport(current_width / 2, 0, current_width / 2, current_height / 2); //시작점은 (width/2 , 0) 크기는 윈도우의 1/4
//	draw_axis();
//	glPushMatrix(); //다른 물체의 회전에 영향을 주지 않도록 push-pop으로 묶어준다
//	glRotatef(spin_teapot, 0, 0, 1);
//	glColor3f(1, 1, 0);
//	glutWireTeapot(2);
//	glPopMatrix();
//	glFlush();
//}
//
//void draw_disk()
//{
//	glViewport(current_width / 2, current_height / 2, current_width /2, current_height/2); //시작점은 (width / 2 , height / 2) 크기는 윈도우의 1/4
//	gluLookAt(10, 10, 10, 0, 0, 0, 0, 1, 0); // 제일 처음 그리는 Disk에 glLookAt함수 선언
//	draw_axis();
//	glPushMatrix(); //다른 물체의 회전에 영향을 주지 않도록 push-pop으로 묶어준다
//	glRotatef(spin_disk, 0, 1, 0);
//	glColor3f(1, 0, 0);
//	q = gluNewQuadric();
//	gluDisk(q, 1, 3, 30, 30);
//	glPopMatrix();
//	glFlush();
//	gluDeleteQuadric(q);
//}
//
////문자열을 생성하는 함수
//void draw_string(void *font, const char* str, float x, float y, float red, float green, float blue)
//{
//	glPushAttrib(GL_LIGHTING_BIT);
//	glDisable(GL_LIGHTING);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity(); // 기존 행렬 초기화
//	gluOrtho2D(-5, 5, -5, 5); // 이제 화면의 좌표는 (-5,-5) ~ (5, 5);
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
//void draw_text()
//{
//	glViewport(0, current_height / 2, current_width / 2, current_height / 2); //시작점은 (0,height / 2) 크기는 윈도우의 1/4
//	glLoadIdentity(); // 기존의 회전 변환을 무시
//
//	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "12131649 Kwon-Sehoon", -5, 0, 1, 0, 0);
//
////	draw_string(GLUT_BITMAP_HELVETICA_18, "Multi-Viewprot Example!!", -5, 1, 0, 1, 5);
//
//	draw_string(GLUT_BITMAP_TIMES_ROMAN_10, Test, -5, 1, 0, 1, 5);
//
//	if (String_on == true)	draw_string(GLUT_BITMAP_TIMES_ROMAN_24, my_string, -5, 2, 50, 30, 10);
//
//	glFlush();
//}
//
//void draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	draw_text();
//	draw_disk();
//	draw_can();
//	draw_teapot();
//
//	glutSwapBuffers();
//}
//
//
//void keyboard(unsigned char key, int x, int y)
//{
//	//'n'키가 눌렸을 때 작동
//	if (key == 'i')
//	{
//		printf("Input your string\n");
//		gets_s(my_string);
//	}
//
//	//'n'키가 눌렸을 때 작동
//	if (key == 'n')
//	{
//		if (String_on == false)
//		{
//			printf("String_on\n");
//			String_on = true; // 문자열 출력 기능 on. 초기 값은 off이므로 처음 n키 누르면 on
//		}
//		else
//		{
//			printf("StudentName_off\n");
//			String_on = false; 
//		}
//	}
//	//'s'키가 눌렸을 때 작동
//	if (key == 's')
//	{
//		if (Rotate_on == false)
//		{
//			printf("Rotate_on\n");
//			Rotate_on = true; //회전 기능 on. 초기 값은 on라 첫 s키 누를시 off
//		}
//		else
//		{
//			printf("Rotate_off\n");
//			Rotate_on = false; // 회전기능이 온 상태에서 s키가 눌리면 회전 기능 오프
//		}
//	}
//	glutPostRedisplay();
//}