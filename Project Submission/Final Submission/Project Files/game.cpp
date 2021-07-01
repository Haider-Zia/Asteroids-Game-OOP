
#ifndef AsteroidS_CPP_
#define AsteroidS_CPP_
#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> 
#include "Objects.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "SimpleAsteroid.h"
#include "ComplexAsteroid.h"
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "SmallAsteroid.h"
#include "Saucer.h"
#include "BigSaucer.h"
#include "SmallSaucer.h"
#include "Bomb.h"
#include "VacantObject.h"
using namespace std;
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
Board *b;
void GameDisplay() {
	glClearColor(0, 0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	if (b->Lives > 0) {
		b->DisplayGameDetails();
		b->DrawAndMoveObjects();
		b->DetectCollisions();
	}
	else {
		b->DisplayGameOver();
	}
	b->GenerateAndShootSaucers();
	b->IncrementLives();
	b->IncrementLevel();

	glutPostRedisplay();
	glutSwapBuffers();
}

void NonPrintableKeys(int key, int x, int y) {
	if (key== GLUT_KEY_LEFT) {
		b->RotateShipLeft();
	}
	else if (key
		== GLUT_KEY_RIGHT) {
		b->RotateShipRight();
	}
	else if (key== GLUT_KEY_UP) {
		b->MoveShipForward();
	}
	glutPostRedisplay();
}
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(1);
	}
	if (key == 'b' || key == 'B'){
		b->ShootBomb();
	}
	if (key == 'h' || key == 'H') {
		b->HyperSpaceShip();
	}
	if (key == 'r' || key == 'R') {
		b->RestartGame();
	}
	glutPostRedisplay();
}
int main(int argc, char*argv[]) {
	b = new Board(60, 60);
	int width = 1020, height = 840;
	b->InitalizeBoard(width, height, b->Level);
	InitRandomizer();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(width, height);
	glutCreateWindow("CP's Bomber Bomberman");
	SetCanvasSize(width, height);
	glutDisplayFunc(GameDisplay);
	glutSpecialFunc(NonPrintableKeys);
	glutKeyboardFunc(PrintableKeys);
	glutMainLoop();
	return 1;
}
#endif
