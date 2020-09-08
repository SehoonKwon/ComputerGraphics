//#include <gl/glut.h>
//#include <stdio.h>
//
//void resize(int width, int height);
//void draw();
//void draw_axis(int x, int y, int z);
//void mouse(int botton, int state, int x, int y);
//
//int main(int argc, char** argv)
//{
//	 윈도우 초기화
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(800, 600);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My first GL Program");
//
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutMouseFunc(mouse);
//
//	glutMainLoop();
//
//	return 0;
//}
//
//void resize(int width, int height)
//{
//	glViewport(0, 0, 800, 600);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, 4.0/3.0,1, 50);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void mouse(int button, int state, int x, int y)
//{
//	 인자들을 해석해서 원하는 기능을 구현
//	printf("Mouse button is clicked! (%d, %d, %d, %d) \n", button, state, x, 600-y);
//}
//
//x, y, z 축 생성
//void draw_axis(int x,int y,int z) 
//{
//	glLineWidth(3);
//	
//	glBegin(GL_LINES);
//	
//	glColor3f(1, 0, 0);
//	glVertex3f(x, y, z);
//	glVertex3f(4+x, y, z);
//
//	glColor3f(0, 1, 0);
//	glVertex3f(x, y, z);
//	glVertex3f(x, y+4, z);
//
//	glColor3f(0, 0, 1);
//	glVertex3f(x, y, z);
//	glVertex3f(x, y, z+4);
//	
//
//	glEnd();
//	glLineWidth(1);
//}
//
//
//void draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(7, 5, 8, 0, 0, 0, 0, 1, 0);
//
//	draw_axis(0,0,0); //월드 좌표계 원점
//	draw_axis(3, 0, 1); 
//	draw_axis(3, -1, 1);
//	draw_axis(7, 5, 8);
//	glTranslated(0, 1, 0); //로컬 좌표계 이동
//	gluLookAt(7, 5, 8, 0, 0, 0, 0, 1, 0);
//	glColor3f(1, 1, 0);
//	glBegin(GL_TRIANGLES);
//		glVertex3i(3, -2, 1);
//		glVertex3i(-5, 3, -1);
//		glVertex3i(0, 3, -1);
//	glEnd();
//	draw_axis(3, -2, 1);
//	draw_axis(-5, 3, -1);
//	draw_axis(0, 3, -1);
//	glFlush();
//	glutSwapBuffers();
//}
