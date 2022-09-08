#include <gl/glut.h>

//�F�̃p�����[�^
GLfloat orange[] = { 0.9, 0.6, 0.0 };
GLfloat green[] = { 0.3, 0.8, 0.0 };
GLfloat gray[] = { 0.5, 0.5,0.5 };
GLfloat white[] = { 1.0, 1.0, 1.0 };
GLfloat black[] = { 0.0, 0.0, 0.0 };

//������`���֐�
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

//���H��`���֐�
void drawRoad()
{
	//��(�Ԑ������O)�`��
	glPushMatrix();
	glTranslatef(0, 0.1, -600);
	glScalef(11, 0.1, 1200);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, gray);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();

	//��(�Ԑ�������)�`��
	glPushMatrix();
	glTranslatef(0, 0.1, 599.75);
	glScalef(20, 0.1, 1200);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, gray);
	glEnable(GL_NORMALIZE);
	glutSolidCube(1.0);
	glDisable(GL_NORMALIZE);
	glPopMatrix();
}

//�X�^�[�g�ƃS�[���̃T�C����`���֐�
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

//�Ԑ��p������`���֐�
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

//��������`���֐�
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

//�ԓ��O������`���֐�
void drawSideLine(){
	//�ԓ��O����(��)�`��
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

	//�ԓ��O����(�E)�`��
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

//�K�[�h���[������`�悷��֐�
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

//�K�[�h���[���㕔��`�悷��֐�
void drawFence()
{
	//���K�[�h���[���㕔�`��
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

	//�E�K�[�h���[���㕔�`��
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