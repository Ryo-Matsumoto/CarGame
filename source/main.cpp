#include <stdio.h>
#include <gl/glut.h>
#include <math.h>
#include <time.h>

#include "world.h"
#include "car.h"


#define FALSE 0
#define TRUE 1
#define LEFT 1	//左クリックに対応するTRUE値
#define RIGHT -1	//右マウスクリックに対応するTRUE値
/* LEFT + RIGHT = FALSE を満たしている*/

#define EOD -1

int fail = FALSE, goal = FALSE, move = FALSE, start = FALSE;	//fail : 衝突の判断   goal : ゴールの判断   move : 左右の動きの判断   start : スタートの判断
int mouse_click_state = FALSE, mouse_l_click_state = FALSE, mouse_r_click_state = FALSE;	//各マウスクリックの判断
int width, height;

//光のパラメータ
GLfloat lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat lightDiff[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lightSpec[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lightPos[] = { 150.0, 1500.0, -1300.0, 0.0 };


//文字列を描く関数
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

//メインループ描画
void display(void) {
	
	//初期化対象
	static bool init = true;

	//初期路端
	static float max = 2.45;

	//プレイヤーの各種座標設定
	static float x = 2.0, dx = 0.03;
	static float z = -1000, dz = 0.12;
	//同一方向車初期位置, 同一方向車速度
	static float z1[20] = {}, dz1[20] = {};
	static float z3[10] = {}, dz3[10] = {};
	//逆方向車初期位置, 逆方向車速度
	static float z2[20] = {}, dz2[20] = {};
	static float z4[10] = {}, dz4[10] = {};
	
	//初期位置・速度をランダムに初期化
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
	
	//初期化終了
	init = init and false;
	
	// glClear する際の背景色を指定
	glClearColor(0.0, 0.8, 0.9, 1.0);	
	
	// カラーバッファを初期化
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();

	//テキストの表示
	if (start != TRUE) {
		drawString(90, "Press middle click to start!");
	}
	else if (goal == TRUE) {
		drawString(90, "You goaled!! Press middle click to exit.");
	}
	else if (fail == TRUE) {
		drawString(90, "You failed!! Press middle click to exit.");
	}

	//視点位置の設定
	if (goal != TRUE) {
		gluLookAt(x, 5, z - 8, x, 0, z + 17, 0.0, 1.0, 0.0);
	}
	else if (goal == TRUE) {
		gluLookAt(x, 5, 1000 - 8, x, 0, 1000 + 17, 0.0, 1.0, 0.0);
	}

	//光
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	//草原描画
	drawGrass();

	//道路描画
	drawRoad();

	//中央線描画
	drawCenterLine();
	
	//車道外側線描画
	drawSideLine();

	//左車線描画
	for (int i = 20; i <= 1200; i = i + 20) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE)
			drawDashedLine(4.25, (float)i);
	}
	//右車線描画
	for (int i = 20; i <= 1200; i = i + 20) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE)
			drawDashedLine(-4.25, (float)i);
	}

	//スタートサイン描画
	if ((-996.75 - z < 110 && -996.75 - z > -10) || goal == TRUE) {
		glEnable(GL_NORMALIZE);
		drawSign(-996.75, 9);
		glDisable(GL_NORMALIZE);
	}
	//ゴールサイン描画
	if ((1003.25 - z < 110 && 1003.25 - z > -10) || goal == TRUE) {
		glEnable(GL_NORMALIZE);
		drawSign(1003.25, 18);
		glDisable(GL_NORMALIZE);
	}
	
	//ガードレール上部描画
	drawFence();

	//左ガードレール支柱描画
	for (int i = -1200; i <= 0; i = i + 10) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE)
			drawPillar(5.25, (float)i);
	}
	for (int i = 0; i <= 1200; i = i + 10) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE)
			 drawPillar(9.75, (float)i);
	}

	//右ガードレール支柱描画
	for (int i = -1200; i <= 0; i = i + 10) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE) 
			drawPillar(-5.25, (float)i);
	}
	for (int i = 0; i <= 1200; i = i + 10) {
		if ((i - z < 110 && i - z > -10) || goal == TRUE) 
			drawPillar(-9.75, (float)i);   
	}
	
	//プレイヤー描画
	if (z < 1200) {
		glEnable(GL_NORMALIZE);
		drawPlayer(x, z);
		glDisable(GL_NORMALIZE);
	}

	//同一方向車描画
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

	//逆方向車描画
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

	glFinish();	// 命令の実行

	glutSwapBuffers();

	if (start == TRUE) {

		//プレイヤーの動き
		x = x + move * dx;
		if (z < 1200 && fail != 1) {
			z = z + dz;
		}

		//同一方向車の動き
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

		//逆方向車の動き
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

		//マウスクリックによる move 制御
		if (goal == TRUE || fail == TRUE) {
			move = FALSE;
		}
		else if (x >= max && mouse_l_click_state == LEFT) {	//路端(左)判定
			move = FALSE;
		}
		else if (x <= -max && mouse_r_click_state == RIGHT) {	//路端(右)判定
			move = FALSE;
		}
		else {
			move = mouse_r_click_state + mouse_l_click_state;
		}

		//衝突判定(同一方向車)
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
		//衝突判定(逆方向車)
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

		//車線増加後の max 切り替え
		if (z >= 0) {
			max = 7.00;
		}

		//ゴール判定
		if (z >= 1000) {
			goal = TRUE;
		}

	}
}

//マウス処理
void mouse(int button, int state, int x, int y) {

	//中央クリックの挙動
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

	//左右クリックの挙動
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

//キーボード処理
void keyboard(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);	//Escキーで強制終了
	}
}

//ディレイ
void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(0.5, timer, value);
}

//描画設定
void reshape(int w, int h) {
	glViewport(0, 0, w, h);	// ビューポートの設定
	width = w;
	height = h;

	glMatrixMode(GL_PROJECTION);	// 射影行列モード
	glLoadIdentity();
	// 透視投影の射影行列を設定
	// 画角60度，アスペクト比はウィンドウから設定，zNear=1.0, zFar=100
	gluPerspective(60.0, (double)w / h, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);	// モデルビュー行列モード
}

//その他初期化
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

//メイン関数
int main(int argc, char *argv[]) {
	printf("【操作方法】\n・左クリック：左方向へ移動\n・右クリック：右方向へ移動\n・中央クリック：メッセージを確認\n・Escキー：ゲーム終了");
	srand((unsigned int)time(NULL));

	glutInit(&argc, argv);	// GLUTの初期化

	glutInitDisplayMode(GLUT_RGB);	// ディスプレイモードをRGBに設定
	glutInitWindowSize(640, 480);	// ウィンドウの作成
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("Car Game");

	glutDisplayFunc(display);	// ディスプレイ用のコールバック関数の設定
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0, timer, 15);
	glutReshapeFunc(reshape);	// reshape用のコールバック関数の設定

	otherInit();

	glutMainLoop();	// メインループへ

	return 0;
}