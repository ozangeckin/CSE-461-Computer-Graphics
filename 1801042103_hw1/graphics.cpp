#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
class VectorCalculator
{
public:
    float xAxis, yAxis, zAxis;
    VectorCalculator(){
        xAxis = 0;
        yAxis = 0;
        zAxis = 0;
    }
    VectorCalculator(float x,float y,float z){
        xAxis = x;
        yAxis = y;
        zAxis = z;
    }
    VectorCalculator operator+(VectorCalculator const &Other){
        return VectorCalculator(xAxis + Other.xAxis, yAxis + Other.yAxis, zAxis + Other.zAxis);
    }
    VectorCalculator operator-(VectorCalculator &Other){
        return VectorCalculator(xAxis - Other.xAxis, yAxis - Other.yAxis, zAxis - Other.zAxis);
    }
    VectorCalculator operator*(float count){
        return VectorCalculator(xAxis * count, yAxis * count, zAxis * count);
    }
    VectorCalculator operator/(float count){
        return VectorCalculator(xAxis / count, yAxis / count, zAxis / count);
    }
    VectorCalculator unit(){
        return *this / sqrt(xAxis * xAxis + yAxis * yAxis + zAxis * zAxis);
    }
    VectorCalculator crossProduct(VectorCalculator other){
        return VectorCalculator(yAxis * other.zAxis - zAxis * other.yAxis, zAxis * other.xAxis - xAxis * other.zAxis, xAxis * other.yAxis - yAxis * other.xAxis);
    }
};

VectorCalculator eye, center, up ,temp;
float xAngle = 240.0f;
float yAngle = 0.0f;
float zAngle = 0.0f;
float angle = 0.0f;
float scale = 1;

void disPlay(); 
void keyboard(unsigned char key, int x, int y);
void reshape(GLsizei weight, GLsizei height); 

int main(int argc, char * * argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1600, 900);
    glutInitWindowPosition(200,100);
    glutCreateWindow("CSE 461 HOMEWORK 1");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(disPlay);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
void disPlay() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 0.8, 1, 200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye.xAxis, eye.yAxis, eye.zAxis,center.xAxis, center.yAxis, center.zAxis,up.xAxis, up.yAxis, up.zAxis);
    glTranslatef(-1.0f, -1.5f, -2.0f);
    glPushMatrix();
    glTranslatef(1.5f, 1.0f, 0.0f);
    glRotatef(xAngle, 0.0, 1.0f, 0.0f);
    glRotatef(yAngle, 1.0, 0.0f, 0.0f);
    glRotatef(zAngle, 0.0, 0.0f, 1.0f);
    glScalef(scale,scale,scale);

    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glEnd();

    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();
  
    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glEnd();
  
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.2, 0.1, 0.5);
    glEnd();

    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glEnd();

    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex3f (0.47, 0.105, -0.000001);
    glVertex3f (0.65, 0.105, -0.000001);
    glVertex3f (0.65, 0.46, -0.000001);
    glVertex3f (0.47, 0.46, -0.000001);
    glEnd();

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.72, 0.25, -0.000001);
    glVertex3f (0.83, 0.25,-0.000001);
    glVertex3f (0.83, 0.4, -0.000001);
    glVertex3f (0.72, 0.4, -0.000001);
    glEnd();

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f (0.27, 0.25, -0.000001);
    glVertex3f (0.38, 0.25, -0.000001);
    glVertex3f (0.38, 0.4, -0.000001);
    glVertex3f (0.27, 0.4, -0.000001);
    glEnd();
    
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char input, int x, int y){
    switch (input)
    {
    case 'a'://x
    	yAngle += -1.0f;
	    if (yAngle > 360) {
	        yAngle -= 360;
	    }
        break;
    case 'd'://x
        yAngle += 1.0f;
	    if (yAngle > 360) {
	        yAngle -= 360;
	    }
        break;
    case 'c'://y 
    	zAngle += -1.0f;
	    if (zAngle > 360) {
	        zAngle -= 360;
	    }
        break;
    case 'z'://y
        zAngle += 1.0f;
	    if (zAngle > 360) {
	        zAngle -= 360;
	    }
        break;
    case 'f'://z
       	xAngle += 1.0f;
	    if (xAngle > 360) {
	        xAngle -= 360;
	    }
        break;
    case 'g'://z
        xAngle += -1.0f;
	    if (xAngle > 360) {
	        xAngle -= 360;
	    }
        break;
    case '5'://up
        eye = eye + up.unit() * -0.1;
        center = center + up.unit() * -0.1;
        break;
    case '2'://down
        eye = eye + up.unit() * 0.1;
        center = center + up.unit() * 0.1;
        break;
    case '1'://left
        temp = up.crossProduct(center - eye).unit();
        eye = eye + temp * -0.1;
        center = center + temp * -0.1;
        break;
    case '3'://right
        temp = up.crossProduct(center - eye).unit();
        eye = eye + temp * 0.1;
        center = center + temp * 0.1; 
        break;
    case 'w'://zoom++
        scale += 0.1f;
        temp = up.crossProduct(center - eye).unit();
        eye = eye + temp * 0.05;
        center = center + temp * 0.05;
        break;
    case 's'://zoom--
        if(scale > 1.0f){
        	scale -= 0.1f;
            temp = up.crossProduct(center - eye).unit();
            eye = eye + temp * -0.05;
            center = center + temp * -0.05;
        }
        break;
    case 27:
        exit(EXIT_SUCCESS);
    }
    glutPostRedisplay();
}
void reshape(GLsizei weight, GLsizei height) {
    
    glViewport(0, 0, weight, height);  
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat) weight / (GLfloat) height, 1.0, 200.0);
    up.xAxis = -0.002;
    up.yAxis = 1;
    up.zAxis = -0.09;
    center.xAxis = 0.01;
    center.yAxis = 0.5;
    center.zAxis = 1.5;
    eye.xAxis = 0.03;
    eye.yAxis = 0.6;
    eye.zAxis = 2.6;
}

