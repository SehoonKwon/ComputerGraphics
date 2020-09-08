//#include <gl/glut.h>
//#include <stdio.h>
//
//void resize(int width, int height);
//void idle();
//void init();
//void draw(); 
//void keyboard(unsigned char key, int x, int y);
//
//float angle1 = 0; //지구 공전
//float angle2 = 0; //지구 자전
//float angle3 = 0; //화성 공전
//float angle4 = 0; //화성 자전
//float angle5 = 0; //달 공전
//float angle6 = 0; //달 자전
//float angle7 = 0; //태양 자전
//
//double temp = 0; //모드 조정에 대한 변수 비교를 위해 생성한 변수
//double p_x = 15, p_y = 15, p_z = 15; //light_position의 위치를 설정하기 위한 변수, 초기값은 카메라의 위치와 같다.
//
//enum light_position { Sun = 1, Earth, Moon, Mars, Init}; // 가독성을 위해 int타입을 enum타입 표현
//int light_position_case = 0; // 광원의 위치 case 초기 값 선언
//bool second_light = false; // 제 2광원 on-off용도
//
//int main(int argc, char** argv)
//{
//	// 윈도우 초기화
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//	init();
//
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutKeyboardFunc(keyboard);
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
//	angle1 = angle1 + 0.05;
//	if (angle1 > 360) angle1 -= 360; 
//	angle2 = angle2 + 0.1;
//	if (angle2 > 360)	angle2 -= 360;
//
//	//행성들의 공전, 자전 추가 
//	//화성은 지구보다 자전과 공전이 느리다.
//	angle3 = angle3 + 0.025;
//	if (angle3 > 360) angle3 -= 360;
//	angle4 = angle4 + 0.06;
//	if (angle4 > 360)	angle4 -= 360;
//
//	//달, 달의 자전과 공전은 서로 같고 지구의 자전과 약간 작다.
//	angle5 = angle5 + 0.1;
//	if (angle5 > 360) angle5 -= 360;
//	angle6 = angle6 + 0.1;
//	if (angle6 > 360)	angle6 -= 360;
//
//	//태양의 자전, 태양의 자전은 매우느리다.
//	angle7 = angle7 + 0.005;
//	if (angle7 > 360)	angle7 -= 360;
//	glutPostRedisplay();
//}
//
//void init()
//{
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
//	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
//
//	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_Sun);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_Sun);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_Sun);
//	glMateriali(GL_FRONT, GL_SHININESS, 20);
//
//	glEnable(GL_COLOR_MATERIAL);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//
//	//제 1광원을 킨다(사용한다)
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
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
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glEnable(GL_DEPTH_TEST);
//	if (second_light == true) glEnable(GL_LIGHT1); //제 2광원을 키는 설정이면 제2광원 on
//	else glDisable(GL_LIGHT1); //그렇지 않으면 off
//	gluLookAt(15, 15, 15, 0, 0, 0, 0, 1, 0); //카메라의 시점
//
//	GLfloat light_position1[] = { p_x, p_y, p_z, 1 }; //제1광원의 위치를 변경하기위해 변수로 값을 넣어준다.
//	GLfloat light_position2[] = { -15, 15, 15, 1 }; //제 2광원의 위치
//	glLightfv(GL_LIGHT1, GL_POSITION, light_position2); // 제 2광원의 위치설정. 카메라의 x좌표 반대
//
//	//case에 따른 제 1광원의 위치 변경
//	if (light_position_case == Sun)
//	{
//		p_x = 0;
//		p_y = 0;
//		p_z = 0;
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//	}
//
//	else if (light_position_case == Earth)
//	{
//		glPushMatrix();
//		glRotatef(angle1, 0, 1, 0);
//		glTranslatef(5, 0, 0);
//		p_x = 0;
//		p_y = 0;
//		p_z = 0;
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//		glPopMatrix();
//	}
//
//	else if (light_position_case == Moon)
//	{
//		glPushMatrix();
//		glRotatef(angle1, 0, 1, 0);
//		glTranslatef(5, 0, 0);
//		glRotatef(-angle1, 0, 1, 0);
//		glRotatef(angle5, 0, 1, 0);
//		glTranslatef(3, 0, 0);
//		p_x = 0;
//		p_y = 0;
//		p_z = 0;
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//		glPopMatrix();
//	}
//
//	else if (light_position_case == Mars)
//	{
//		glPushMatrix();
//		glRotatef(angle3, 0, 1, 0);
//		glTranslatef(8, 0, 0);
//		p_x = 0;
//		p_y = 0;
//		p_z = 0;
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//		glPopMatrix();
//	}
//
//	else
//	{
//		p_x = 15;
//		p_y = 15;
//		p_z = 15;
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
//	}
//
//	GLfloat emission[] = { 1.0f, 0.0f, 0.0f, 1.0f }; //태양의 발산광을 만들어주기 위해 설정
//
//	//태양, 월드좌표
//	glMaterialfv(GL_FRONT, GL_EMISSION, emission); //태양의 발산광을 만들어주기 위해 설정
//	glColor3f(1, 0, 0); //태양의 색은 Red
//	glPushMatrix(); //push - pop 의 존재이유 : 만약 push-pop이 없다면 행렬의 회전 및 이동이 이 밑에 코드들 모두에 영향을 미쳐서 원하는 결과를 얻을 수 없다. 
//	glRotatef(angle7, 0, 1, 0);
//	glutSolidSphere(1, 30, 30);
//	glPopMatrix();
//	emission[0] = 0.0f; //태양의 발산광을 만들어주기 위해 설정
//	glMaterialfv(GL_FRONT, GL_EMISSION, emission); //태양의 발산광을 만들어주기 위해 설정
//	
//	//지구
//	glPushMatrix();
//	glRotatef(angle1, 0, 1, 0);
//	glTranslatef(5, 0, 0);
//	glRotatef(angle2, 0, 1, 0);
//
//	glColor3f(0, 0, 1); //지구의 색은 blue
//	glutSolidSphere(0.5, 30, 30);
//	glRotatef(-angle2, 0, 1, 0); //달은 지구 자전에 영향받으면 안되므로 자전 만큼 반대로 좌표계를 돌린다
//	glRotatef(-angle1, 0, 1, 0); //달은 지구 공전에 영향받으면 안되므로 자전 만큼 반대로 좌표계를 돌린다
//	
//	//달
//	glRotatef(angle5, 0, 1, 0);
//	glTranslatef(3, 0, 0);
//	glRotatef(angle6, 0, 1, 0);
//
//	glColor3f(1, 0.9, 0); //달의 색은 Yellow
//	glutSolidSphere(0.35, 30, 30);
//	glPopMatrix();
//
//	//화성
//	glPushMatrix();
//	glRotatef(angle3, 0, 1, 0);
//	glTranslatef(8, 0, 0);
//	glRotatef(angle4, 0, 1, 0);
//
//	glColor3f(1.5, 0.5, 0); //화성의 색은 Brown
//	glutSolidSphere(0.7, 30, 30);
//	glPopMatrix();
//
//	glFlush();
//	glutSwapBuffers();
//}
//
// //키를 입력받아 광원의 위치를 바꾼다
//void keyboard(unsigned char key, int x, int y)
//{
//	//누르는 키에 따라 광원의 위치가 바뀌도록 설정
//	if (key == '1')
//	{
//		light_position_case = Sun;
//	}
//
//	if (key == '2')
//	{
//		light_position_case = Earth;
//	}
//
//	if (key == '3')
//	{
//		light_position_case = Moon;
//	}
//
//	if (key == '4')
//	{
//		light_position_case = Mars;
//	}
//
//	if (key == '5') //광원 위치 초기화
//	{
//		light_position_case = Init;
//	}
//
//	//'o' 키를 누르면 제2 광원 온-오프 기능
//	if (key == 'o')
//	{
//		if (second_light == false)  second_light = true;
//		else second_light = false;
//	}
//
//	glutPostRedisplay();
//}