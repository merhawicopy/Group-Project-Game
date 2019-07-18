/**
* Program Name:   cis27Spring2017Group2Project.c
* Discussion:	  Final Project
* Written By:     Besufekad, Jose, Merhawi
* Date:           2017/05/25
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define FPS 8

void display(void);
void init(void);
void reShape(int, int);
void unit(int, int);
void initGrid(int, int);
void keyboard(int, int, int);
void drawBox(void);
void destinyBox(void);
void displayStepCount(void);
void obstacleBox(void);
void timerCallback(int);
void instruction(void);

int gridX;
int gridY;
int posX = 0, posY = 0;
int destinyPosX = 0, destinyPosY = 0;
int obstacleBoxX, obstacleBoxY;
short boxDirection = 0;
int gameOver = 0;
int obstacleBoxFlag = 1;
int steps = 0;
int x[30] = { -1 };
int y[30] = { -1 };
int growthUp = 0;
int growthRight = 0;
int puzzle = 1;

int main(int argc, char** argv) {
	instruction();

	srand(time(NULL));
	puzzle = rand() % 10 + 1;
	printf("%d", puzzle);
	//puzzle = 1;
	if (puzzle == 1) {
		memcpy(x, (int[30]) {
			1, 2, 3, 4, 11, 11, 11, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1
		}, 30 * sizeof(int));
		memcpy(y, (int[30]) {
			3, 11, 12, 5, 2, 9, 11, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1
		}, 30 * sizeof(int));
		posX = 0, posY = 11;
		destinyPosX = 11, destinyPosY = 10;
	}
	if (puzzle == 2) {
		memcpy(x, (int[30]) {
			0, 0, 0, 1, 1, 2, 5, 6, 10, 10, 11, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1
		}, 30 * sizeof(int));
		memcpy(y, (int[30]) {
			14, 11, 2, 0, 2, 14, 0, 13, 13, 2, 3, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1
		}, 30 * sizeof(int));
		posX = 11, posY = 14;
		destinyPosX = 0, destinyPosY = 0;
	}
	if (puzzle == 3) {
		memcpy(x, (int[30]) {
			0, 1, 1, 1, 2, 5, 8, 8, 9, 10, 10, 11, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1
		}, 30 * sizeof(int));
		memcpy(y, (int[30]) {
			10, 1, 7, 12, 3, 0, 0, 8, 13, 2, 11, 4, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1
		}, 30 * sizeof(int));
		posX = 1, posY = 6;
		destinyPosX = 6, destinyPosY = 7;
	}
	if (puzzle == 10) {
		memcpy(x, (int[30]) {
			0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6,
			6, 6, 7, 7, 7, 7, 8, 8, 9, 10, 10, 11, 11
		}, 30 * sizeof(int));
		memcpy(y, (int[30]) {
			0, 6, 8, 6, 8, 9, 11, 6, 8, 12, 6, 8, 6, 8, 6, 8,
			6, 8, 12, 4, 6, 8, 9, 1, 12, 11, 3, 10, 3, 6
		}, 30 * sizeof(int));
		posX = 1, posY = 0;
		destinyPosX = 0, destinyPosY = 7;
	}
	if (puzzle == 5) {
		memcpy(x, (int[30]) {
			1, 2, 3, 4, 11, 11, 11, -1, -1, -1, -1, -1, -1, 
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1
		}, 30 * sizeof(int));
		memcpy(y, (int[30]) {
			3, 11, 12, 5, 2, 9, 11, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1
		}, 30 * sizeof(int));
		posX = 0, posY = 11;
		destinyPosX = 11, destinyPosY = 10;
	}
	if (puzzle == 6) {
		memcpy(x, (int[30]) {
			0, 0, 0, 1, 1, 2, 5, 6, 10, 10, 11, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1
		}, 30 * sizeof(int));
		memcpy(y, (int[30]) {
			14, 11, 2, 0, 2, 14, 0, 13, 13, 2, 3, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1
		}, 30 * sizeof(int));
		posX = 11, posY = 14;
		destinyPosX = 0, destinyPosY = 0;
	}
	if (puzzle == 7) {
		memcpy(x, (int[30]) {
			0, 1, 1, 1, 2, 5, 8, 8, 9, 10, 10, 11, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1
		}, 30 * sizeof(int));
		memcpy(y, (int[30]) {
			10, 1, 7, 12, 3, 0, 0, 8, 13, 2, 11, 4, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1
		}, 30 * sizeof(int));
		posX = 1, posY = 6;
		destinyPosX = 6, destinyPosY = 7;
	}
	if (puzzle == 8) {
		memcpy(x, (int[30]) {
			0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6,
			6, 6, 7, 7, 7, 7, 8, 8, 9, 10, 10, 11, 11
		}, 30 * sizeof(int));
		memcpy(y, (int[30]) {
			0, 6, 8, 6, 8, 9, 11, 6, 8, 12, 6, 8, 6, 8, 6, 8,
			6, 8, 12, 4, 6, 8, 9, 1, 12, 11, 3, 10, 3, 6
		}, 30 * sizeof(int));
		posX = 1, posY = 0;
		destinyPosX = 0, destinyPosY = 7;
	}
	if (puzzle == 9) {
		memcpy(x, (int[30]) {
			0, 1, 1, 1, 2, 5, 8, 8, 9, 10, 10, 11, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1
		}, 30 * sizeof(int));
		memcpy(y, (int[30]) {
			10, 1, 7, 12, 3, 0, 0, 8, 13, 2, 11, 4, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1
		}, 30 * sizeof(int));
		posX = 1, posY = 6;
		destinyPosX = 6, destinyPosY = 7;
	}
	if (puzzle == 4) {
		memcpy(x, (int[30]) {
			0, 1, 2, 3, 5, 6, 7, 8, 8, 9, 9, 11, 11, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1
		}, 30 * sizeof(int));
		memcpy(y, (int[30]) {
			7, 8, 4, 13, 1, 5, 2, 7, 14, 1, 9, 3, 6, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1
		}, 30 * sizeof(int));
		posX = 11, posY = 0;
		destinyPosX = 11, destinyPosY = 5;
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(750, 450);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DESTINY");

	printf("\nCreated Successfuly...");
	printf("%d", posX);
	printf(" %d\n", posX);
	glutDisplayFunc(display);
	glutReshapeFunc(reShape);
	glutTimerFunc(0, timerCallback, 0);
	glutSpecialFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}

void displayStepCount() {
	char buffer[256];
	sprintf(buffer, "Moves: %d", steps);
	glutSetWindowTitle(buffer);
}

void obstacleBox() {
	int minXY = 0;

	srand(time(NULL));

	for (int i = 0; i < 30; i++) {
		glColor3f(0.0, 0.5, 0.7);
		glRectd(x[i], y[i], x[i] + 1, y[i] + 1);
	}

	obstacleBoxFlag = 0;
}

void destinyBox() {

	if (posX == destinyPosX && posY == destinyPosY) {
		glColor3f(0.0, 1.0, 0.0);
		gameOver = 1;
	} else {
		glColor3f(0.7, 0.0, 0.0);
	}

	glRectd(destinyPosX, destinyPosY, destinyPosX + 1, 
		                             destinyPosY + 1);
}

void drawBox() {
	if (growthUp == 0 && growthRight == 0) {
		if (boxDirection == UP) {
			displayStepCount();
			growthUp = 1;
		}
		if (boxDirection == DOWN) {
			displayStepCount();
			growthUp = -1;
		}
		if (boxDirection == RIGHT) {
			displayStepCount();
			growthRight = 1;
		}
		if (boxDirection == LEFT) {
			displayStepCount();
			growthRight = -1;
		}
	} else {
		posX += growthRight;
		posY += growthUp;
		steps++;
		displayStepCount();
		//If box is moving up
		if (growthUp == 1) {
			if (posY >= gridY) {
				posY = gridY - 1;
				boxDirection = 0;
				growthUp = 0;
			} else if ((posY == y[0] && posX == x[0]) || 
				(posY == y[1] && posX == x[1]) || 
				(posY == y[2] && posX == x[2]) ||
				(posY == y[3] && posX == x[3]) || 
				(posY == y[4] && posX == x[4]) || 
				(posY == y[5] && posX == x[5]) ||
				(posY == y[6] && posX == x[6]) || 
				(posY == y[7] && posX == x[7]) || 
				(posY == y[8] && posX == x[8]) || 
				(posY == y[9] && posX == x[9]) || 
				(posY == y[10] && posX == x[10]) || 
				(posY == y[11] && posX == x[11]) || 
				(posY == y[12] && posX == x[12]) || 
				(posY == y[13] && posX == x[13]) || 
				(posY == y[14] && posX == x[14]) || 
				(posY == y[15] && posX == x[15]) || 
				(posY == y[16] && posX == x[16]) || 
				(posY == y[17] && posX == x[17]) || 
				(posY == y[18] && posX == x[18]) || 
				(posY == y[19] && posX == x[19]) || 
				(posY == y[20] && posX == x[20]) || 
				(posY == y[21] && posX == x[21]) || 
				(posY == y[22] && posX == x[22]) || 
				(posY == y[23] && posX == x[23]) || 
				(posY == y[24] && posX == x[24]) || 
				(posY == y[25] && posX == x[25]) || 
				(posY == y[26] && posX == x[26]) || 
				(posY == y[27] && posX == x[27]) || 
				(posY == y[28] && posX == x[28]) || 
				(posY == y[29] && posX == x[29])) {
				boxDirection = 0;
				growthUp = 0;
				posY += -1;
			}
		}
		//if box is moving down
		if (growthUp == -1) {
			if (posY <= -1) {
				posY = 0;
				boxDirection = 0;
				growthUp = 0;
			} else if ((posY == y[0] && posX == x[0]) ||
				(posY == y[1] && posX == x[1]) || 
				(posY == y[2] && posX == x[2]) ||
				(posY == y[3] && posX == x[3]) || 
				(posY == y[4] && posX == x[4]) || 
				(posY == y[5] && posX == x[5]) ||
				(posY == y[6] && posX == x[6]) || 
				(posY == y[7] && posX == x[7]) || 
				(posY == y[8] && posX == x[8]) || 
				(posY == y[9] && posX == x[9]) || 
				(posY == y[10] && posX == x[10]) || 
				(posY == y[11] && posX == x[11]) || 
				(posY == y[12] && posX == x[12]) || 
				(posY == y[13] && posX == x[13]) || 
				(posY == y[14] && posX == x[14]) || 
				(posY == y[15] && posX == x[15]) || 
				(posY == y[16] && posX == x[16]) || 
				(posY == y[17] && posX == x[17]) || 
				(posY == y[18] && posX == x[18]) || 
				(posY == y[19] && posX == x[19]) || 
				(posY == y[20] && posX == x[20]) || 
				(posY == y[21] && posX == x[21]) || 
				(posY == y[22] && posX == x[22]) || 
				(posY == y[23] && posX == x[23]) || 
				(posY == y[24] && posX == x[24]) || 
				(posY == y[25] && posX == x[25]) || 
				(posY == y[26] && posX == x[26]) || 
				(posY == y[27] && posX == x[27]) || 
				(posY == y[28] && posX == x[28]) || 
				(posY == y[29] && posX == x[29])) {
				boxDirection = 0;
				growthUp = 0;
				posY += 1;
			}
		}
		//if box is moving right
		if (growthRight == 1) {
			if (posX >= gridX) {
				posX = gridX - 1;
				boxDirection = 0;
				growthRight = 0;
			} else if ((posY == y[0] && posX == x[0]) ||
				(posY == y[1] && posX == x[1]) || 
				(posY == y[2] && posX == x[2]) ||
				(posY == y[3] && posX == x[3]) || 
				(posY == y[4] && posX == x[4]) || 
				(posY == y[5] && posX == x[5]) ||
				(posY == y[6] && posX == x[6]) || 
				(posY == y[7] && posX == x[7]) || 
				(posY == y[8] && posX == x[8]) || 
				(posY == y[9] && posX == x[9]) || 
				(posY == y[10] && posX == x[10]) || 
				(posY == y[11] && posX == x[11]) || 
				(posY == y[12] && posX == x[12]) || 
				(posY == y[13] && posX == x[13]) || 
				(posY == y[14] && posX == x[14]) || 
				(posY == y[15] && posX == x[15]) || 
				(posY == y[16] && posX == x[16]) || 
				(posY == y[17] && posX == x[17]) || 
				(posY == y[18] && posX == x[18]) || 
				(posY == y[19] && posX == x[19]) || 
				(posY == y[20] && posX == x[20]) || 
				(posY == y[21] && posX == x[21]) || 
				(posY == y[22] && posX == x[22]) || 
				(posY == y[23] && posX == x[23]) || 
				(posY == y[24] && posX == x[24]) || 
				(posY == y[25] && posX == x[25]) || 
				(posY == y[26] && posX == x[26]) || 
				(posY == y[27] && posX == x[27]) || 
				(posY == y[28] && posX == x[28]) || 
				(posY == y[29] && posX == x[29])) {
				boxDirection = 0;
				growthRight = 0;
				posX += -1;
			}
		}
		//if box is moving left
		if (growthRight == -1) {
			if (posX <= -1) {
				posX = 0;
				boxDirection = 0;
				growthRight = 0;
			} else if ((posY == y[0] && posX == x[0]) || 
				(posY == y[1] && posX == x[1]) || 
				(posY == y[2] && posX == x[2]) ||
				(posY == y[3] && posX == x[3]) || 
				(posY == y[4] && posX == x[4]) || 
				(posY == y[5] && posX == x[5]) ||
				(posY == y[6] && posX == x[6]) || 
				(posY == y[7] && posX == x[7]) || 
				(posY == y[8] && posX == x[8]) || 
				(posY == y[9] && posX == x[9]) || 
				(posY == y[10] && posX == x[10]) || 
				(posY == y[11] && posX == x[11]) || 
				(posY == y[12] && posX == x[12]) || 
				(posY == y[13] && posX == x[13]) || 
				(posY == y[14] && posX == x[14]) || 
				(posY == y[15] && posX == x[15]) || 
				(posY == y[16] && posX == x[16]) || 
				(posY == y[17] && posX == x[17]) || 
				(posY == y[18] && posX == x[18]) || 
				(posY == y[19] && posX == x[19]) || 
				(posY == y[20] && posX == x[20]) || 
				(posY == y[21] && posX == x[21]) || 
				(posY == y[22] && posX == x[22]) || 
				(posY == y[23] && posX == x[23]) || 
				(posY == y[24] && posX == x[24]) || 
				(posY == y[25] && posX == x[25]) || 
				(posY == y[26] && posX == x[26]) || 
				(posY == y[27] && posX == x[27]) || 
				(posY == y[28] && posX == x[28]) || 
				(posY == y[29] && posX == x[29])) {
				boxDirection = 0;
				growthRight = 0;
				posX += 1;
			}
		}
	}
	glColor3f(0.0, 1.0, 0.0);
	glRectd(posX, posY, posX + 1, posY + 1);
}

void keyboard(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		if (boxDirection != DOWN)
			boxDirection = UP;
		break;
	case GLUT_KEY_DOWN:
		if (boxDirection != UP)
			boxDirection = DOWN;
		break;
	case GLUT_KEY_LEFT:
		if (boxDirection != RIGHT)
			boxDirection = LEFT;
		break;
	case GLUT_KEY_RIGHT:
		if (boxDirection != LEFT)
			boxDirection = RIGHT;
		break;
	}
	glutPostRedisplay();
}

void initGrid(int x, int y) {
	gridX = x;
	gridY = y;
}

void drawGrid() {
	for (int x = 0; x < gridX; x += 1) {
		for (int y = 0; y < gridY; y += 1) {
			unit(x, y);
		}
	}
}

void unit(int x, int y) {

	glLineWidth(1.0);
	glColor3f(0.5, 0.0, 0.0);

	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();
}

void reShape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 12.0, 0.0, 15.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	initGrid(12, 15);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawBox();
	destinyBox();
	obstacleBox();
	obstacleBoxFlag = 0;
	glutSwapBuffers();
	glFlush();

	if (gameOver == 1) {             // this exits the game
		char score[10];
		char text[50] = "Your Score: ";
		itoa(steps, score, 10);
		strcat(text, score);
		MessageBoxA(NULL, text, "GAME OVER", 0);
		exit(0);
		puzzle++;
	}
}

void timerCallback(int t) {
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timerCallback, 0);
}

void instruction(void) {

	printf("CIS 27: Destiny Final Project --\n");
	printf("\nWritten By:");
	printf("\n  Besufekad");
	printf("\n  Jose");
	printf("\n  Merhawi\n\n");

	printf(
		"\n		HOW TO PLAY"
"\nTo play the game use the four bottons UP, DOWN, RIGHT, and "
"\nLEFT arrows on the keyboard to move the GREEN BLOCK"
"\nto the DESTINATION which is the RED BLOCK by using "
"\nthe BLUE BLOCKS or the BORDER on the SCREEN "
"\nas a DIRECTION CHANGER. Once you chose a direction you "
"\ncannot change the direction while the BLUE BLOCK is "
"\nmoving. Enjoy!\n\n");
}
