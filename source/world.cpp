#include <gl/glut.h>

//色のパラメータ
GLfloat orange[] = { 0.9, 0.6, 0.0 };
GLfloat green[] = { 0.3, 0.8, 0.0 };
GLfloat gray[] = { 0.5, 0.5,0.5 };
GLfloat white[] = { 1.0, 1.0, 1.0 };
GLfloat black[] = { 0.0, 0.0, 0.0 };

//草原を描く関数
void drawGrass()
{
	glPushMatrix();
	glTranslatef(0, 0.09, 0);
	glScalef(2400, 0.1, 2400);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, green);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();
	
}

//道路を描く関数
void drawRoad()
{
	//道(車線増加前)描画
	glPushMatrix();
	glTranslatef(0, 0.1, -600);
	glScalef(11, 0.1, 1200);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, gray);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	//道(車線増加後)描画
	glPushMatrix();
	glTranslatef(0, 0.1, 599.75);
	glScalef(20, 0.1, 1200);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, gray);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();
}

//スタートとゴールのサインを描く関数
void drawSign(float z, float size)
{
	glPushMatrix();
	glTranslatef(0, 0, z);

	for (double i = -size / 2 + 0.5; i <= size / 2 - 0.5; i = i + 2) {
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, black);
		glTranslatef(i, 0.1075, 0.5);
		glScalef(1, 0.1, 1);
		glEnable(GL_NORMALIZE);
		glutSolidCube(1.0);
		glDisable(GL_NORMALIZE);
		glPopMatrix();
	}
	for (double i = -size / 2 + 1.5; i <= size / 2 - 0.5; i = i + 2) {
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
		glTranslatef(i, 0.1075, 0.5);
		glScalef(1, 0.1, 1);
		glEnable(GL_NORMALIZE);
		glutSolidCube(1.0);
		glDisable(GL_NORMALIZE);
		glPopMatrix();
	}
	for (double i = -size / 2 + 0.5; i <= size / 2 - 0.5; i = i + 2) {
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
		glTranslatef(i, 0.1075, -0.5);
		glScalef(1, 0.1, 1);
		glEnable(GL_NORMALIZE);
		glutSolidCube(1.0);
		glDisable(GL_NORMALIZE);
		glPopMatrix();
	}
	for (double i = -size / 2 + 1.5; i <= size / 2 - 0.5; i = i + 2) {
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, black);
		glTranslatef(i, 0.1075, -0.5);
		glScalef(1, 0.1, 1);
		glEnable(GL_NORMALIZE);
		glutSolidCube(1.0);
		glDisable(GL_NORMALIZE);
		glPopMatrix();
	}

	glPopMatrix();
}

//車線用直線を描く関数
void drawDashedLine(float x, float z){
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(x, 0.105, z);
	glScalef(0.81, 0.1, 10);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();
}

//中央線を描く関数
void drawCenterLine(){
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, orange);
	glTranslatef(0, 0.105, 0);
	glScalef(0.81, 0.1, 2400);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();
}

//車道外側線を描く関数
void drawSideLine(){
	//車道外側線(左)描画
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(4.25, 0.105, -599.0);
	glScalef(0.5, 0.1, 1200);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(6.5, 0.105, 1.0);
	glScalef(5.0, 0.1, 0.5);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(8.75, 0.105, 601.0);
	glScalef(0.5, 0.1, 1200);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	//車道外側線(右)描画
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(-4.25, 0.105, -599.0);
	glScalef(0.5, 0.1, 1200);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(-6.5, 0.105, 1.0);
	glScalef(5.0, 0.1, 0.5);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(-8.75, 0.105, 601.0);
	glScalef(0.5, 0.1, 1200);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();
}

//ガードレール柱を描画する関数
void drawPillar(float x, float z)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(x, 0.7, z);
	glScalef(0.5, 1.5, 0.5);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();
}

//ガードレール上部を描画する関数
void drawFence()
{
	//左ガードレール上部描画
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(5.25, 1.5, -600);
	glScalef(0.5, 0.1, 1200);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(7.5, 1.5, 0);
	glScalef(5.0, 0.1, 0.5);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(9.75, 1.5, 600);
	glScalef(0.5, 0.1, 1200);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	//右ガードレール上部描画
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(-5.25, 1.5, -600);
	glScalef(0.5, 0.1, 1200);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(-7.5, 1.5, 0);
	glScalef(5.0, 0.1, 0.5);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
	glTranslatef(-9.75, 1.5, 600);
	glScalef(0.5, 0.1, 1200);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

}