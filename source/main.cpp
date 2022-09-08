#include <stdio.h>
#include <gl/glut.h>
#include <math.h>
#include <time.h>

#include "world.h"
#include "car.h"


#define FALSE 0
#define TRUE 1
#define LEFT 1	//���N���b�N�ɑΉ�����TRUE�l
#define RIGHT -1	//�E�}�E�X�N���b�N�ɑΉ�����TRUE�l
/* LEFT + RIGHT = FALSE �𖞂����Ă���*/

#define EOD -1

int fail = FALSE, goal = FALSE, move = FALSE, start = FALSE;	//fail : �Փ˂̔��f   goal : �S�[���̔��f   move : ���E�̓����̔��f   start : �X�^�[�g�̔��f
int mouse_click_state = FALSE, mouse_l_click_state = FALSE, mouse_r_click_state = FALSE;	//�e�}�E�X�N���b�N�̔��f
int width, height;

//���̃p�����[�^
GLfloat lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat lightDiff[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lightSpec[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lightPos[] = { 150.0, 1500.0, -1300.0, 0.0 };


//�������`���֐�
void drawString(float y, const char* str)
{
	float x;
	int length = 0;
	char* p = (char*)str;
	char* q = (char*)str;

	glDisable(GL_LIGHTING);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	while (*p != '\0') {
		length = length + glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
	}
	x = (float)(width - length) / 2;
	glRasterPos2f(x, y);
	glColor3f(0, 0, 0);
	while (*q != '\0') {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *q++);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
}

//���C�����[�v�`��
void display(void) {
	
	//�������Ώ�
	static bool init = true;

	//�����H�[
	static float max = 2.45;

	//�v���C���[�̊e����W�ݒ�
	static float x = 2.0, dx = 0.03;
	static float z = -1000, dz = 0.12;
	//��������ԏ����ʒu, ��������ԑ��x
	static float z1[20] = {}, dz1[20] = {};
	static float z3[10] = {}, dz3[10] = {};
	//�t�����ԏ����ʒu, �t�����ԑ��x
	static float z2[20] = {}, dz2[20] = {};
	static float z4[10] = {}, dz4[10] = {};
	
	//�����ʒu�E���x�������_���ɏ�����
	if (init){
		int idx1 = 0, idx2 = 0, idx3 = 0, idx4 = 0;
		for (int i = -850; i <= 950; i = i + 100){
			int r = 0 + rand() % 4;
			if (i < 0){
				if (r % 2 == 0){
					dz1[idx1] = (float)(15 + rand() % 15)/1000;
					z1[idx1] = i - ( dz1[idx1] * (i - z) / dz );
					idx1++;
				}
				else{
					dz2[idx2] = -(float)(30 + rand() % 90)/1000;
					z2[idx2] = i + ( -dz2[idx2] * (i - z) / dz );
					idx2++;
				}
			}else{
				switch(r){
					case 0:
						dz2[idx2] = -(float)(30 + rand() % 90)/1000;
						z2[idx2] = i + ( -dz2[idx2] * (i - z) / dz );
						idx2++;
						dz3[idx3] = (float)(15 + rand() % 15)/1000;
						z3[idx3] = i - ( dz3[idx3] * (i - z) / dz );
						idx3++;
						dz4[idx4] = -(float)(30 + rand() % 90)/1000;
						z4[idx4] = i + ( -dz4[idx4] * (i - z) / dz );
						idx4++;
						break;
					case 1:
						dz1[idx1] = (float)(15 + rand() % 15)/1000;
						z1[idx1] = i - ( dz1[idx1] * (i - z) / dz );
						idx1++;
						dz3[idx3] = (float)(15 + rand() % 15)/1000;
						z3[idx3] = i - ( dz3[idx3] * (i - z) / dz );
						idx3++;
						dz4[idx4] = -(float)(30 + rand() % 90)/1000;
						z4[idx4] = i + ( -dz4[idx4] * (i - z) / dz );
						idx4++;
						break;
					case 2:
						dz1[idx1] = (float)(15 + rand() % 15)/1000;
						z1[idx1] = i - ( dz1[idx1] * (i - z) / dz );
						idx1++;
						dz2[idx2] = -(float)(30 + rand() % 90)/1000;
						z2[idx2] = i + ( -dz2[idx2] * (i - z) / dz );
						idx2++;
						dz4[idx4] = -(float)(30 + rand() % 90)/1000;
						z4[idx4] = i + ( -dz4[idx4] * (i - z) / dz );
						idx4++;
						break;
					case 3:
						dz1[idx1] = (float)(15 + rand() % 15)/1000;
						z1[idx1] = i - ( dz1[idx1] * (i - z) / dz );
						idx1++;
						dz2[idx2] = -(float)(30 + rand() % 90)/1000;
						z2[idx2] = i + ( -dz2[idx2] * (i - z) / dz );
						idx2++;
						dz3[idx3] = (float)(15 + rand() % 15)/1000;
						z3[idx3] = i - ( dz3[idx3] * (i - z) / dz );
						idx3++;
						break; 
						
				}
			}
		}
		z1[idx1] = EOD;
		dz1[idx1] = EOD;
		z2[idx2] = EOD;
		dz2[idx2] = EOD;
		z3[idx3] = EOD;
		dz3[idx3] = EOD;
		z4[idx4] = EOD;
		dz4[idx4] = EOD;
	}
	
	//�������I��
	init = init and false;
	
	// glClear ����ۂ̔w�i�F���w��
	glClearColor(0.0, 0.8, 0.9, 1.0);	
	
	// �J���[�o�b�t�@��������
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();

	//�e�L�X�g�̕\��
	if (start != TRUE) {
		drawString(90, "Press middle click to start!");
	}
	else if (goal == TRUE) {
		drawString(90, "You goaled!! Press middle click to exit.");
	}
	else if (fail == TRUE) {
		drawString(90, "You failed!! Press middle click to exit.");
	}

	//���_�ʒu�̐ݒ�
	if (goal != TRUE) {
		gluLookAt(x, 5, z - 8, x, 0, z + 17, 0.0, 1.0, 0.0);
	}
	else if (goal == TRUE) {
		gluLookAt(x, 5, 1000 - 8, x, 0, 1000 + 17, 0.0, 1.0, 0.0);
	}

	//��
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	//�����`��
	drawGrass();

	//���H�`��
	drawRoad();

	//�������`��
	drawCenterLine();
	
	//�ԓ��O�����`��
	drawSideLine();

	//���Ԑ��`��
	for (int i = 20; i <= 1200; i = i + 20) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE)
			drawDashedLine(4.25, (float)i);
	}
	//�E�Ԑ��`��
	for (int i = 20; i <= 1200; i = i + 20) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE)
			drawDashedLine(-4.25, (float)i);
	}

	//�X�^�[�g�T�C���`��
	if ((-996.75 - z < 110 && -996.75 - z > -10) || goal == TRUE) {
		glEnable(GL_NORMALIZE);
		drawSign(-996.75, 9);
		glDisable(GL_NORMALIZE);
	}
	//�S�[���T�C���`��
	if ((1003.25 - z < 110 && 1003.25 - z > -10) || goal == TRUE) {
		glEnable(GL_NORMALIZE);
		drawSign(1003.25, 18);
		glDisable(GL_NORMALIZE);
	}
	
	//�K�[�h���[���㕔�`��
	drawFence();

	//���K�[�h���[���x���`��
	for (int i = -1200; i <= 0; i = i + 10) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE)
			drawPillar(5.25, (float)i);
	}
	for (int i = 0; i <= 1200; i = i + 10) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE)
			 drawPillar(9.75, (float)i);
	}

	//�E�K�[�h���[���x���`��
	for (int i = -1200; i <= 0; i = i + 10) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE) 
			drawPillar(-5.25, (float)i);
	}
	for (int i = 0; i <= 1200; i = i + 10) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE) 
			drawPillar(-9.75, (float)i);   
	}
	
	//�v���C���[�`��
	if (z < 1200) {
		glEnable(GL_NORMALIZE);
		drawPlayer(x, z);
		glDisable(GL_NORMALIZE);
	}

	//��������ԕ`��
	for (int i = 0; z1[i] != EOD; i++) {
		if (z1[i] - z < 110 && z1[i] - z > -10) {
			glEnable(GL_NORMALIZE);
			drawCar1(2.0, z1[i]);
			glDisable(GL_NORMALIZE);
		}
	}

	for (int i = 0; z3[i] != EOD; i++) {
		if (z3[i] - z < 110 && z3[i] - z > -10) {
			glEnable(GL_NORMALIZE);
			drawCar1(6.55, z3[i]);
			glDisable(GL_NORMALIZE);
		}
	}

	//�t�����ԕ`��
	for (int i = 0; z2[i] != EOD; i++) {
		if (z2[i] - z < 110 && z2[i] - z > -10) {
			glEnable(GL_NORMALIZE);
			drawCar2(-2.0, z2[i]);
			glDisable(GL_NORMALIZE);
		}
	}

	for (int i = 0; z4[i] != EOD; i++) {
		if (z4[i] - z < 110 && z4[i] - z > -10) {
			glEnable(GL_NORMALIZE);
			drawCar2(-6.55, z4[i]);
			glDisable(GL_NORMALIZE);
		}
	}

	glFinish();	// ���߂̎��s

	glutSwapBuffers();

	if (start == TRUE) {

		//�v���C���[�̓���
		x = x + move * dx;
		if (z < 1200 && fail != 1) {
			z = z + dz;
		}

		//��������Ԃ̓���
		for (int i = 0; z1[i] != EOD; i++) {
			if (z1[i] - z > -10 && fail != 1) {
				z1[i] = z1[i] + dz1[i];
			}
		}

		for (int i = 0; z3[i] != EOD; i++) {
			if (z3[i] - z > -10 && fail != 1) {
				z3[i] = z3[i] + dz3[i];
			}
		}

		//�t�����Ԃ̓���
		for (int i = 0; z2[i] != EOD; i++) {
			if (z2[i] - z > -10 && fail != 1) {
				z2[i] = z2[i] + dz2[i];
			}
		}

		for (int i = 0; z4[i] != EOD; i++) {
			if (z4[i] - z > -10 && fail != 1) {
				z4[i] = z4[i] + dz4[i];
			}
		}

		//�}�E�X�N���b�N�ɂ�� move ����
		if (goal == TRUE || fail == TRUE) {
			move = FALSE;
		}
		else if (x >= max && mouse_l_click_state == LEFT) {	//�H�[(��)����
			move = FALSE;
		}
		else if (x <= -max && mouse_r_click_state == RIGHT) {	//�H�[(�E)����
			move = FALSE;
		}
		else {
			move = mouse_r_click_state + mouse_l_click_state;
		}

		//�Փ˔���(���������)
		for (int i = 0; z1[i] != EOD; i++) {
			if (fabs(z - z1[i]) < 4.5 && fabs(x - 2.0) < 2.475) {
				fail = TRUE;
			}
		}
		for (int i = 0; z3[i] != EOD; i++) {
			if (fabs(z - z3[i]) < 4.5 && fabs(x - 6.55) < 2.475) {
				fail = TRUE;
			}
		}
		//�Փ˔���(�t������)
		for (int i = 0; z2[i] != EOD; i++) {
			if (fabs(z - z2[i]) < 4.5 && fabs(x + 2.0) < 2.475) {
				fail = TRUE;
			}
		}
		for (int i = 0; z4[i] != EOD; i++) {
			if (fabs(z - z4[i]) < 4.5 && fabs(x + 6.55) < 2.475) {
				fail = TRUE;
			}
		}

		//�Ԑ�������� max �؂�ւ�
		if (z >= 0) {
			max = 7.00;
		}

		//�S�[������
		if (z >= 1000) {
			goal = TRUE;
		}

	}
}

//�}�E�X����
void mouse(int button, int state, int x, int y) {

	//�����N���b�N�̋���
	if (button == GLUT_MIDDLE_BUTTON) {
		if (goal != TRUE) {
			start = TRUE;
		}
		else if (goal == TRUE) {
			exit(0);
		}

		if (fail == TRUE) {
			exit(0);
		}
	}

	//���E�N���b�N�̋���
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mouse_l_click_state = LEFT;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		mouse_l_click_state = FALSE;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		mouse_r_click_state = RIGHT;
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		mouse_r_click_state = FALSE;
	}

}

//�L�[�{�[�h����
void keyboard(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);	//Esc�L�[�ŋ����I��
	}
}

//�f�B���C
void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(0.5, timer, value);
}

//�`��ݒ�
void reshape(int w, int h) {
	glViewport(0, 0, w, h);	// �r���[�|�[�g�̐ݒ�
	width = w;
	height = h;

	glMatrixMode(GL_PROJECTION);	// �ˉe�s�񃂁[�h
	glLoadIdentity();
	// �������e�̎ˉe�s���ݒ�
	// ��p60�x�C�A�X�y�N�g��̓E�B���h�E����ݒ�CzNear=1.0, zFar=100
	gluPerspective(60.0, (double)w / h, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);	// ���f���r���[�s�񃂁[�h
}

//���̑�������
void otherInit(void)
{
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClearDepth(1.f);
	glEnable(GL_DEPTH_TEST);

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}

//���C���֐�
int main(int argc, char *argv[]) {
	printf("�y������@�z\n�E���N���b�N�F�������ֈړ�\n�E�E�N���b�N�F�E�����ֈړ�\n�E�����N���b�N�F���b�Z�[�W���m�F\n�EEsc�L�[�F�Q�[���I��");
	srand((unsigned int)time(NULL));

	glutInit(&argc, argv);	// GLUT�̏�����

	glutInitDisplayMode(GLUT_RGB);	// �f�B�X�v���C���[�h��RGB�ɐݒ�
	glutInitWindowSize(640, 480);	// �E�B���h�E�̍쐬
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("Car Game");

	glutDisplayFunc(display);	// �f�B�X�v���C�p�̃R�[���o�b�N�֐��̐ݒ�
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0, timer, 15);
	glutReshapeFunc(reshape);	// reshape�p�̃R�[���o�b�N�֐��̐ݒ�

	otherInit();

	glutMainLoop();	// ���C�����[�v��

	return 0;
}