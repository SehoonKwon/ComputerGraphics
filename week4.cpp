//#include <gl/glut.h>
//#include <stdio.h>
//#include <math.h> // 사인, 코사인 함수를 사용하기 위해 이 함수의 헤더파일을 참조하였다.
//
//double E_angle = 90, A_angle = 0; // 라디안으로 변환하기 위해 Degree 변수 선언.
//#define PI 3.141592
//#define E_Radian PI*E_angle/180 //C언어에서는 라디안만 사용가능하다.
//#define A_Radian PI*A_angle/180
//
//void resize(int width, int height);
//void draw_axis();
//void draw();
//void specialkey(int key, int x, int y);
//
//double Cam_dis=0; // 카메라가 물체로부터 멀어지거나 가까워지도록 하기위해 생성한 변수
//double temp=0; //모드 조정에 대한 변수 비교를 위해 생성한 변수
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
//	glutReshapeFunc(resize);
//	glutSpecialFunc(specialkey);
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void resize(int width, int height)
//{
//	glViewport(0, 0, width, height); // width와 height는 윈도우사이즈 가 들어옴 , viewport는 Ortho2D와 같다(=평면)
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / (float) height, 1, 500);
//	glMatrixMode(GL_MODELVIEW);
//}
//
// //x, y, z 축 생성
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
//void draw()
//{
//	int up = 1;
//	int r = 20; // 구면좌표계에서 원점-점P까지의 거리
//	double eye_x = r*sin(E_Radian)*sin(A_Radian), eye_y = r*cos(E_Radian), eye_z = r*sin(E_Radian)*cos(A_Radian); //구면 좌표계를 나타내기 위함
//
//	if (E_angle > 180 || E_angle <= -180 ) up = -1;  // 특정 각도가 되면 카메라의 시점이 바뀌는데 이를 처리하기 위한 조건문
//
//	if (Cam_dis > temp) // 위로 멀어짐
//	{
//		eye_x = eye_x + Cam_dis;
//		eye_y = eye_y + Cam_dis;
//		eye_y = eye_z + Cam_dis;
//		temp = Cam_dis;
//	}
//	else if (Cam_dis < temp) //아래로 멀어짐
//	{
//		eye_x = eye_x + Cam_dis;
//		eye_y = eye_y + Cam_dis;
//		eye_y = eye_z + Cam_dis;
//		temp = Cam_dis;
//	}
//	
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(eye_x, eye_y, eye_z, 0, 0, 0, 0, up, 0);
//
//	glColor3f(1, 1, 0);
//	glutWireTeapot(4);
//	draw_axis();
//
//	glFlush();
//	glutSwapBuffers();
//}
//
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
//		if (E_angle > 360) E_angle = E_angle - 360;  // -1 = 359도와 같으므로 각도가 무제한으로 작아지는 일 방지
//	}
//	else if (key == GLUT_KEY_DOWN)
//	{
//		E_angle++;
//		if (E_angle == 360) E_angle = 0;  //360도 = 0도 이므로 각도가 무제한으로 커지는 일 방지
//		printf("E_angle : %f  A_angle : %f\n", E_angle, A_angle);
//	}
//	else if (key == GLUT_KEY_F1) //위로 멀어지는 키 
//	{
//		Cam_dis++;
//	}
//	else if (key == GLUT_KEY_F2) //아래로 멀어지는 키
//	{
//		Cam_dis--;
//	}
//	else if (key == GLUT_KEY_F3) //각도 초기화
//	{
//		E_angle = 90;
//		A_angle = 0;
//	}
//
//	glutPostRedisplay();
//}