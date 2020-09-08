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
//void idle();
//void draw_axis(); // 축을 그리는 함수. 이 과제에서는 사용하지 않음.
//void draw(); 
//void specialkey(int key, int x, int y); //카메라의 시점을 바꾸는 키를 입력받기 위한 함수
//
//float angle1 = 0; //지구 공전
//float angle2 = 0; //지구 자전
//float angle3 = 0; //화성 공전
//float angle4 = 0; //화성 자전
//float angle5 = 0; //달 공전
//float angle6 = 0; //달 자전
//float angle7 = 0; //태양 자전
//double temp = 0; //모드 조정에 대한 변수 비교를 위해 생성한 변수
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
//	glutIdleFunc(idle);
//	
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void idle(void)
//{
//	//지구의 공전과 자전 추가
//	angle1 = angle1 + 0.5;
//	if (angle1 > 360) angle1 -= 360; 
//	angle2 = angle2 + 1;
//	if (angle2 > 360)	angle2 -= 360;
//
//	//행성들의 공전, 자전 추가 
//	//화성은 지구보다 자전과 공전이 느리다.
//	angle3 = angle3 + 0.25;
//	if (angle3 > 360) angle3 -= 360;
//	angle4 = angle4 + 0.6;
//	if (angle4 > 360)	angle4 -= 360;
//
//	//달, 달의 자전과 공전은 서로 같고 지구의 자전과 약간 작다.
//	angle5 = angle5 + 1;
//	if (angle5 > 360) angle5 -= 360;
//	angle6 = angle6 + 1;
//	if (angle6 > 360)	angle6 -= 360;
//
//	//태양의 자전, 태양의 자전은 매우느리다.
//	angle7 = angle7 + 0.05;
//	if (angle7 > 360)	angle7 -= 360;
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
//	//구를 그리는 함수에 이용
//	GLUquadric *q;
//	q = gluNewQuadric();
//
//	int up = 1;
//	int r = 20; // 구면좌표계에서 원점-점P까지의 거리
//	double eye_x = r*sin(E_Radian)*sin(A_Radian), eye_y = r*cos(E_Radian), eye_z = r*sin(E_Radian)*cos(A_Radian); //구면 좌표계를 나타내기 위함
//	
//	if (E_angle > 180 || E_angle <= -180 ) up = -1; // 특정 각도가 되면 카메라의 시점이 바뀌는데 이를 처리하기 위한 조건문
//
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glEnable(GL_DEPTH_TEST);
//	gluLookAt(eye_x, eye_y, eye_z, 0, 0, 0, 0, up, 0); //카메라의 시점
//
//	//태양, 월드좌표
//	glColor3f(1, 0, 0); //태양의 색은 Red
//	glPushMatrix(); //push - pop 의 존재이유 : 만약 push-pop이 없다면 행렬의 회전 및 이동이 이 밑에 코드들 모두에 영향을 미쳐서 원하는 결과를 얻을 수 없다. 
//	glRotatef(angle7, 0, 1, 0);
//	//glutWireTeapot(1.2);
//	gluQuadricNormals(q, GLU_FLAT);
//	gluSphere(q, 2.0f, 32, 16);
//	glPopMatrix();
//	//draw_axis();
//	
//	//지구
//	glPushMatrix();
//	glRotatef(angle1, 0, 1, 0);
//	glTranslatef(5, 0, 0);
//	glRotatef(angle2, 0, 1, 0);
//
//	glColor3f(0, 0, 1); //지구의 색은 blue
//	glutWireTeapot(1);
//	glRotatef(-angle2, 0, 1, 0);
//	glRotatef(-angle1, 0, 1, 0);
//	
//	//달
//	glRotatef(angle5, 0, 1, 0);
//	glTranslatef(3, 0, 0);
//	glRotatef(angle6, 0, 1, 0);
//
//	glColor3f(1, 0.9, 0); //달의 색은 Yellow
//	glutWireTeapot(0.5);  //작업량에 따라서 렌더링 속도가 다름
//	//gluSphere(q, 0.4f, 32, 16);
//	glPopMatrix();
//
//	//화성
//	glPushMatrix();
//	glRotatef(angle3, 0, 1, 0);
//	glTranslatef(8, 0, 0);
//	glRotatef(angle4, 0, 1, 0);
//
//	glColor3f(1.5, 0.5, 0); //화성의 색은 Brown
//	glutWireTeapot(1.2);
//	//gluSphere(q, 1.0f, 32, 16);
//	glPopMatrix();
//
///*	//달
//	glRotatef(angle5, 0, 1, 0);
//	glTranslatef(6.5, 0, 0);
//	glRotatef(angle6, 0, 1, 0);
//
//	glColor3f(1, 0.9, 0); //달의 색은 Yellow
//	glutWireTeapot(0.5);  //작업량에 따라서 렌더링 속도가 다름
//	gluSphere(q, 0.5f, 32, 16);
//	*/
//	glFlush();
//	glutSwapBuffers();
//}
//
// //방향키를 입력받아 각도를 변화시켜 카메라의 시점을 바꾼다.
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
//
//	}
//	else if (key == GLUT_KEY_DOWN)
//	{
//		E_angle++;
//		if (E_angle == 360) E_angle = 0;  //360도 = 0도 이므로 각도가 무제한으로 커지는 일 방지
//		printf("E_angle : %f  A_angle : %f\n", E_angle, A_angle);
//
//	}
//	else if (key == GLUT_KEY_F3) //각도 초기화
//	{
//		E_angle = 90;
//		A_angle = 0;
//	}
//
//	glutPostRedisplay();
//}