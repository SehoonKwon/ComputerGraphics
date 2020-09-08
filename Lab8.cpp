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
//void draw();
//void init();
//void idle();
//void keyboard(unsigned char key, int x, int y);
//void specialkey(int key, int x, int y);
//
//double zoom = 0; // 줌 인, 아웃 정도 조절
//double temp=0; //모드 조정에 대한 변수 비교를 위해 생성한 변수
//double m_RotateAngle = 0; //회전율
//double zoom_x = 0, zoom_y = 0, zoom_z = 0; //줌을 위한 변수 
//
//bool CW_mode = true; //그리는 기준 선택
//bool CULL_FACE_mode = true; //Cull-face on-off
//bool spin_right = true; // 그리는 방향(좌우) 선택
//bool zoom_in = false; // 줌 인 조절
//bool zoom_out = false; // 줌 아웃 조절
//bool stop_spin = false; // 회전기능 on-off
//
//int main(int argc, char** argv)
//{
//	// 윈도우 초기화
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glClearDepth(1.0f);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutSpecialFunc(specialkey);
//	glutKeyboardFunc(keyboard);
//	glutIdleFunc(idle);
//	init();
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void init()
//{
//	GLfloat ambientLight[] = { 0.2f,0.2f,0.2f,1.0f };
//	GLfloat diffuseLight[] = { 0.7f,0.7f,0.7f,1.0f };
//	GLfloat specularLight[] = { 0.9f,0.9f,0.9f,1.0f };
//	GLfloat specularMaterial[] = { 1.0f,1.0f,1.0f,1.0f };
//
//	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
//
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
//	glMateriali(GL_FRONT, GL_SHININESS, 20);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	//Depth-Test Enable
//	glFrontFace(GL_CW); //CW로 그리면 내부가 와이어, CCW로 그리면 외부가 와이어
//	glEnable(GL_DEPTH_TEST);
//
//	glPolygonMode(GL_BACK, GL_LINE); //내부를 와이어로 그림
//}
//
//void idle()
//{
//	if (stop_spin == false) //회전기능 on-off에 대한 함수구현 부분
//	{
//		if (spin_right == true) m_RotateAngle = m_RotateAngle + 0.2; //양의 방향으로 회전
//		else m_RotateAngle = m_RotateAngle - 0.2; //음의 방향으로 회전
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
//}
//
//void draw()
//{
//	//CW_mode 설정.
//	if (CW_mode == false) glFrontFace(GL_CCW); 
//	else glFrontFace(GL_CW);
//
//	//CULL_FACE_mode 설정
//	if (CULL_FACE_mode == false) glDisable(GL_CULL_FACE); //GL_CULL_FACE 기능을 끄면 속에 주전자 속에 와이어가 그려짐.
//	else glEnable(GL_CULL_FACE);
//
//	int up = 1;
//	int r = 20; // 구면좌표계에서 원점-점P까지의 거리
//	double eye_x = r*sin(E_Radian)*sin(A_Radian), eye_y = r*cos(E_Radian), eye_z = r*sin(E_Radian)*cos(A_Radian); //구면 좌표계를 나타내기 위함
//
//	//줌 인, 아웃 함수 구현부분
//	if (zoom_in == true)
//	{
//		zoom_x = eye_x - zoom;
//		zoom_y = eye_y - zoom;
//		zoom_z = eye_z - zoom;
//		if (zoom_x <= 0) zoom_x = 0;
//		if (zoom_y <= 0) zoom_y = 0;
//		if (zoom_z <= 0) zoom_z = 0;
//	}
//	else if (zoom_out == true)
//	{
//		zoom_x = eye_x - zoom;
//		zoom_y = eye_y - zoom;
//		zoom_z = eye_z - zoom;
//	}
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	if (zoom_in == true || zoom_out == true)
//	{
//		if (E_angle > 180 || E_angle <= -180) up = -1;  // 특정 각도가 되면 카메라의 시점이 바뀌는데 이를 처리하기 위한 조건문
//		gluLookAt(zoom_x, zoom_y, zoom_z, 0, 0, 0, 0, up, 0); //줌 모드면 줌의 시점으로 보아라.
//	}
//	else
//	{
//		if (E_angle > 180 || E_angle <= -180 || E_angle==0) up = -1;  // 특정 각도가 되면 카메라의 시점이 바뀌는데 이를 처리하기 위한 조건문
//		gluLookAt(eye_x, eye_y, eye_z, 0, 0, 0, 0, up, 0); //줌 모드가 아니면 원래의 시점으로 보아라.
//	}
//
//	glPushMatrix();
//	glRotatef(m_RotateAngle, 0, 1, 0);
//	GLdouble eq[4] = { 1.0, 0.0, 0.0, 0.0 };
//	glClipPlane(GL_CLIP_PLANE0, eq);
//	glEnable(GL_CLIP_PLANE0);
//	glPopMatrix();
//
//	glColor3f(1, 1, 0);
//	glutSolidTeapot(4);
//
//	glFlush();
//	glutSwapBuffers();
//}
//
//void specialkey(int key, int x, int y)
//{
//	//방향키에 따른 위도와 경도에 증감시킨다.
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
//	else if (key == GLUT_KEY_F3) //모든 설정 초기화
//	{
//		E_angle = 90;
//		A_angle = 0;
//		zoom = 0;
//		zoom_in = false;
//		zoom_out = false;
//	}
//
//	glutPostRedisplay();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	//키보드 버튼에 따른 각 조작기능들 구현
//	if (key == '1') //CW_mode 설정
//	{
//		if (CW_mode == true) CW_mode = false; 
//		else CW_mode = true; 
//	}
//	else if (key == '2') //CULL_FACE_mode 설정
//	{
//		if (CULL_FACE_mode == true) CULL_FACE_mode = false;
//		else CULL_FACE_mode = true;
//	}
//	else if (key == '3') //회전 방향 설정
//	{
//		if (spin_right == true) spin_right = false;
//		else spin_right = true;
//	}
//	else if (key == 'z') //줌 인
//	{
//		if (zoom_out == true)	zoom_out = false;
//		zoom_in = true;
//		zoom = zoom + 0.1;
//	}
//	else if (key == 'x') //줌 아웃
//	{
//		if (zoom_in == true)	zoom_in = false;
//		zoom_out = true;
//		zoom = zoom - 0.1;
//	}
//	else if (key == 'c') //줌 기능 모두 off
//	{
//		zoom_in = false;
//		zoom_out = false;
//	}
//	else if (key == 's') //회전기능 on-off
//	{
//		if (stop_spin == false) stop_spin = true;
//		else stop_spin = false;
//	}
//	glutPostRedisplay();
//}