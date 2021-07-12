#include<cstdio>
#include <windows.h>
#include <GL/glut.h>
#include<math.h>>

#define PI           3.14159265358979323846

GLfloat j = 0.0f;
void Idle()
{
    glutPostRedisplay();
}

GLfloat position = 0.0f;
GLfloat speed = 0.1f;

void update(int value) {

    if(position >1.4)
        position = -1.0f;

    position += speed; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}

GLfloat position1 = 0.0f;
GLfloat speed1 = 0.1f;

void update1(int value1) {

    if(position1 <-1.4)
        position1 = 1.0f;

    position1 -= speed1;

	glutPostRedisplay();


	glutTimerFunc(100, update1, 0);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON){
			speed += 0.1f;
			}
			if (button == GLUT_RIGHT_BUTTON)
	{speed -= 0.1f;
			}
	glutPostRedisplay();
	}

void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_LEFT:
speed1=.5;
break;
case GLUT_KEY_RIGHT:
speed1=.2;
break;
}
}



void display1() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //sky start
    glBegin(GL_QUADS);
    glColor3ub(0, 153, 255);
    glVertex2f(-1.0f,.3f);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(1.0f,1.0f);
    glVertex2f(1.0f,0.3f);
    glEnd();
    //sky end

    //sun start
    glColor3ub(255, 255, 0);
    int i;

	GLfloat x=.7f; GLfloat y=.7f; GLfloat radius =.2f;
	int triangleAmount = 20;


	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    //sun end


    //surface start
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 51);
    glVertex2f(-0.2f, -1.0f);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.5f, 0.3f);
    glVertex2f(-1.0f, 0.3f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
    //surface end

    //river
    glBegin(GL_POLYGON);
    glColor3ub(102, 204, 255);
    glVertex2f(0.5f, .3f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.5f, -0.2f);

    glVertex2f(-0.2f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 255, 51);
    glVertex2f(1.0f,0.3f);
    glVertex2f(.85f,.1f);
    glVertex2f(1.0f,.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 255, 51);
    glVertex2f(1.0f,-.5f);
    glVertex2f(0.7f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glEnd();

    //boat
    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);
    glVertex2f(0.1f,-.45f);
    glVertex2f(0.2f,-.55f);
    glVertex2f(0.5f,-.55f);
    glVertex2f(0.6f,-0.45f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 153, 0);
    glVertex2f(0.2f,-.45f);
    glVertex2f(0.5f,-.45f);
    glVertex2f(0.5f,-.35f);
    glVertex2f(0.2f,-0.35f);
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 1);
    glVertex2f(0.1f, -0.45f);
    glVertex2f(0.1f, -0.1f);
    glEnd();
    //river end

    //tree start

    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);
    glVertex2f(-.9f,.3f);
    glVertex2f(-.8f,.3f);
    glVertex2f(-.8f,.5f);
    glVertex2f(-.9f,.5f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0,1,0);
    glVertex2f(-.75f,.5f);
    glVertex2f(-.85f,.7f);
    glVertex2f(-0.95f,.5f);
    glEnd();

    for(int i=0;i<6;i++)
    {
        glTranslated(.2,0,0);
        glBegin(GL_QUADS);
        glColor3ub(128, 0, 0);
        glVertex2f(-.9f,.3f);
        glVertex2f(-.8f,.3f);
        glVertex2f(-.8f,.5f);
        glVertex2f(-.9f,.5f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        glVertex2f(-.75f,.5f);
        glVertex2f(-.85f,.7f);
        glVertex2f(-0.95f,.5f);
        glEnd();
    }

    glLoadIdentity();

    glBegin(GL_TRIANGLES);
    glColor3f(0,1,0);
    glVertex2f(.45f,.3f);
    glVertex2f(.55f,.3f);
    glVertex2f(0.5f,.5f);
    glEnd();

    for(int i=0;i<5;i++)
    {
        glTranslated(.1,0,0);
        glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        glVertex2f(.45f,.3f);
        glVertex2f(.55f,.3f);
        glVertex2f(0.5f,.5f);
        glEnd();
    }
    glLoadIdentity();

    //tree end

    //house start
    glBegin(GL_TRIANGLES);
    glColor3ub(204, 51, 0);
    glVertex2f(-.8f,.2f);
    glVertex2f(-.45f,.7f);
    glVertex2f(-.15f,.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 204, 0);
    glVertex2f(-.7f,.2f);
    glVertex2f(-.7f,-.3f);
    glVertex2f(-.25f,-.3f);
    glVertex2f(-.25f,.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 51, 0);
    glVertex2f(-.7f,-.3f);
    glVertex2f(-.8f,-.4f);
    glVertex2f(-.15f,-.4f);
    glVertex2f(-.25f,-.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);
    glVertex2f(-.56f,-.3f);
    glVertex2f(-.39f,-.3f);
    glVertex2f(-.39f,.0f);
    glVertex2f(-.56f,.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 153, 0);
    glVertex2f(-.6f,-.4f);
    glVertex2f(-.9f,-1.0f);
    glVertex2f(-.65f,-1.0f);
    glVertex2f(-.35f,-.4f);
    glEnd();
    //house end

    //wind mill start

    glPushMatrix();
    glTranslated(-.45,.7,0);
    glRotatef(j,0.0,0.0,0.1);

    glBegin(GL_TRIANGLES);
    glColor3ub(153, 255, 204);
    glVertex2f(-.1f,-.4f);
    glVertex2f(.0f,.0f);
    glVertex2f(.1f,-.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(153, 255, 204);
    glVertex2f(.35f,.05f);
    glVertex2f(.0f,.0f);
    glVertex2f(.3f,.25f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(153, 255, 204);
    glVertex2f(-.35f,.05f);
    glVertex2f(.0f,.0f);
    glVertex2f(-.3f,.25f);
    glEnd();
    glLoadIdentity();
    glPopMatrix();
    j+=0.1f;


    glColor3ub(0, 51, 0);


	GLfloat x1=-.45f; GLfloat y1=.7f; GLfloat radius1 =.05f;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    //wind mill end

    //clock start
    glBegin(GL_QUADS);
    glColor3ub(204, 153, 0);
    glVertex2f(-.1f,.35f);
    glVertex2f(-.1f,-.05f);
    glVertex2f(.2f,-.05f);
    glVertex2f(.2f,.35f);
    glEnd();

    glColor3ub(153, 255, 204);


	GLfloat x2=.05f; GLfloat y2=.35f; GLfloat radius2 =.2f;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2);
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
            x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
            y2 + (radius2 * sin(i * twicePi / triangleAmount))
        );
    }
	glEnd();

    glPushMatrix();
    glTranslated(.05,.35,0);
    glRotatef(j,0.0,0.0,0.1);
    glLineWidth(0.5);
	glBegin(GL_LINES);
	glColor3ub(0, 51, 0);
    glVertex2f(.0f,.0f);
    glVertex2f(.0f,.18f);
    glEnd();
    glLoadIdentity();
    glPopMatrix();
    j+=0.1f;

    glBegin(GL_LINES);
	glColor3ub(0, 51, 0);
    glVertex2f(.05f,.35f);
    glVertex2f(.18f,.35f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(0, 51, 0);
    glVertex2f(.05f,.35f);
    glVertex2f(-.1f,.29f);
    glEnd();




    //clock end

    //bird start

    glPushMatrix();
    glTranslatef(position,0,0);
    glTranslated(0,-0.1,0);

    glBegin(GL_POLYGON);
    glColor3ub(153, 0, 204);
    glVertex2f(-0.1f,0.8f);
    glVertex2f(-0.05f,0.8f);
    glVertex2f(0.0f,0.8f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.75f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 51, 0);
    glVertex2f(0.04f,0.8f);
    glVertex2f(0.08f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glPopMatrix();

    glPushMatrix();
    glTranslated(0,.1,0);
    glTranslatef(position1,0,0);


    glBegin(GL_POLYGON);
    glColor3ub(0, 51, 0);
    glVertex2f(-0.1f,0.8f);
    glVertex2f(-0.05f,0.8f);
    glVertex2f(0.0f,0.8f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.75f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 51, 0);
    glVertex2f(0.04f,0.8f);
    glVertex2f(0.08f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();

    glLoadIdentity();

    glPopMatrix();

    //bird end

    glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Test");
	glutInitWindowSize(320, 320);
	glutDisplayFunc(display1);
	glutTimerFunc(100, update, 0);
	glutTimerFunc(100, update1, 0);
	glutMouseFunc(handleMouse);
	glutSpecialFunc(SpecialInput);
	glutIdleFunc(Idle);
	glutMainLoop();
	return 0;
}
