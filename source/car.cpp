#include <gl/glut.h>
#include <math.h>

//é‘ÇÃêFÇ∆çﬁéøÇÃê›íË
GLfloat tireAmb[] = { 0.02f, 0.02f, 0.02f, 1.f };
GLfloat tireDiff[] = { 0.01f, 0.01f , 0.01f, 1.f };
GLfloat tireSpec[] = { 0.4f, 0.4f, 0.4f,1.f };
GLfloat tireShin = .078125f;

GLfloat blackAmb[] = { 0.0f, 0.0f, 0.0f, 1.f };
GLfloat blackDiff[] = { 0.2f, 0.2f , 0.2f, 1.f };
GLfloat blackSpec[] = { 0.50f, 0.50f, 0.50f,1.f };
GLfloat blackShin = .25f;

GLfloat whiteAmb[] = { 0.0f, 0.0f, 0.0f, 1.f };
GLfloat whiteDiff[] = { 0.9f, 0.9f , 0.9f, 1.f };
GLfloat whiteSpec[] = { 0.7f, 0.7f,0.7f,1.f };
GLfloat whiteShin = .25f;

GLfloat redAmb[] = { 0.0f, 0.0f, 0.0f, 1.f };
GLfloat redDiff[] = { 0.5f, 0.0f , 0.0f, 1.f };
GLfloat redSpec[] = { 0.7f, 0.6f,0.6f,1.f };
GLfloat redShin = .25f;

GLfloat yellowAmb[] = { 0.0f, 0.0f, 0.0f, 1.f };
GLfloat yellowDiff[] = { 0.5f, 0.5f, 0.0f, 1.f };
GLfloat yellowSpec[] = { 0.60f, 0.60f, 0.50f, 1.f };
GLfloat yellowShin = .25f;

GLfloat cyanAmb[] = { 0.0f, 0.1f, 0.06f, 1.f };
GLfloat cyanDiff[] = { 0.0f, 0.50980392f, 0.50980392f, 1.f };
GLfloat cyanSpec[] = { 0.50196078f, 0.50196078f, 0.50196078f ,1.f };
GLfloat cyanShin = .25f;

GLfloat greenAmb[] = { 0.0f, 0.0f, 0.0f, 1.f };
GLfloat gregoaliff[] = { 0.1f, 0.35f, 0.1f, 1.f };
GLfloat greenSpec[] = { 0.45f, 0.45f, 0.45f, 1.f };
GLfloat greenShin = .25f;

//â~íåÇï`Ç≠ä÷êî
void drawCylinder(float height, float radius, int sides) {

	double step = 2 * M_PI / (double)sides;

	glPushMatrix();

	glRotatef(90, 0, 0, 1);

	glNormal3d(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < sides; i++) {
		double t = step * (double)i;
		glVertex3d(radius * sin(t), height, radius * cos(t));
	}
	glEnd();


	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= sides; i++) {
		double t = step * (double)i;
		double x = sin(t);
		double z = cos(t);
		glNormal3d(x, 0.0, z);
		glVertex3f(radius * x, height, radius * z);
		glVertex3f(radius * x, 0.0, radius * z);
	}
	glEnd();

	glNormal3d(0.0, -1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = sides; --i >= 0; ) {
		double t = step * (double)i;
		glVertex3d(radius * sin(t), 0.0, radius * cos(t));
	}
	glEnd();

	glPopMatrix();

}

//ÉvÉåÉCÉÑÅ[ÇÃé‘Çï`Ç≠ä÷êî
void drawPlayer(float x, float z) {

	glPushMatrix();

	glTranslatef(x, 0, z);

	glPushMatrix();

	glScalef(2.25, 2.25, 2.25);
	glTranslatef(0, 0.375, 0);

	glPushMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(0.6, 0, -0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(-0.4, 0, 0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(0.6, 0, 0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(-0.4, 0, -0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.3, 0);

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blackAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blackDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blackSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, blackShin * 128);
	glScalef(1, 0.5, 2);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, whiteAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, whiteDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whiteSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, whiteShin * 128);
	glTranslatef(0, 0.5, 0);
	glScalef(1, 0.5, 1);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, redAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, redDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, redSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, redShin * 128);
	glTranslatef(0, 0.7, 0);
	glEnable(GL_NORMALIZE);
	glutSolidSphere(0.2, 20, 20);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

}

//ìØàÍï˚å¸é‘Çï`Ç≠ä÷êî
void drawCar1(float x, float z) {

	glPushMatrix();

	glTranslatef(x, 0, z);

	glPushMatrix();

	glScalef(2.25, 2.25, 2.25);
	glTranslatef(0, 0.375, 0);

	glPushMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(0.6, 0, -0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(-0.4, 0, 0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(0.6, 0, 0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(-0.4, 0, -0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.3, 0);

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cyanAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cyanDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cyanSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cyanShin * 128);
	glScalef(1, 0.5, 2);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, greenAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gregoaliff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, greenSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, greenShin * 128);
	glTranslatef(0, 0.5, 0);
	glScalef(1, 0.5, 1);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

}

//ãtï˚å¸é‘Çï`Ç≠ä÷êî
void drawCar2(float x, float z) {

	glPushMatrix();

	glTranslatef(x, 0, z);

	glPushMatrix();

	glScalef(2.25, 2.25, 2.25);
	glTranslatef(0, 0.375, 0);

	glPushMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(0.6, 0, -0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(-0.4, 0, 0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(0.6, 0, 0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tireAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tireDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tireSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tireShin * 128);
	glTranslatef(-0.4, 0, -0.5);
	glEnable(GL_NORMALIZE);
	drawCylinder(0.2, 0.3, 100);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.3, 0);

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, redAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, redDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, redSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, redShin * 128);
	glScalef(1, 0.5, 2);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, yellowAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yellowDiff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, yellowSpec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, yellowShin * 128);
	glTranslatef(0, 0.5, 0);
	glScalef(1, 0.5, 1);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

}