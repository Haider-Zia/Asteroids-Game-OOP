
#ifndef _BOARD_H_
#define _BOARD_H_

#include <GL/glut.h>
#include <iostream>
#include "util.h"
#include "Objects.h"
#include "SpaceShip.h"
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

class Board {
private:

	int xcellsize, ycellsize;
	int width, height;
	ColorNames pcolor, bcolor, gcolor;

public:
	Objects** ObjArray;
	int Lives;
	int Score;
	int Level;
	float GameSpeed;
	int BigSaucerGenerationPoint, SmallSaucerGenerationPoint, BigSaucerShoot, SmallSaucerShoot;
	int LifeIncrementPoints;
	static const int BOARD_X = 17;
	static const int BOARD_Y = 14;
	float GetDistance(float x1, float y1, float x2, float y2);
	void DisplayGameDetails();
	void DrawAndMoveObjects();
	void DetectCollisions();
	void DisplayGameOver();
	void GenerateAndShootSaucers();
	void IncrementLives();
	void IncrementLevel();
	void RotateShipLeft();
	void RotateShipRight();
	void MoveShipForward();
	void ShootBomb();
	void HyperSpaceShip();
	void RestartGame();

	int board_array[BOARD_Y][BOARD_X];
	Board(int xsize = 8, int ysize = 8);
	void InitalizeBoard(int, int, int level);
	void Draw();
	static int GetBoardX() {
		return BOARD_X;
	}
	static int GetBoardY() {
		return BOARD_Y;
	}
	int GetMidX() {
		return BOARD_X * xcellsize / 2.0;
	}
	int GetMidY() {
		return BOARD_Y * ycellsize / 2.0;
	}
	int GetCellSize() {
		return xcellsize;
	}
	void GetInitRandomPosition(int &x, int &y) {
		x = GetRandInRange(50, width - 50);
		y = GetRandInRange(50, height - 50);
	}
	int GetWidth3() {
		return width;
	}
	int GetHeight() {
		return height;
	}
	void GetInitTextPosition(int &x, int &y);
	~Board(void);
};

#endif