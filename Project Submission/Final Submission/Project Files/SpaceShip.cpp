#include "SpaceShip.h"



SpaceShip::SpaceShip()
{
	dead = 0;
	x = 510;
	y = 420;
	theta = 0;
	radius = 20;
}

void SpaceShip::Draw(float given_x, float given_y, float given_theta){
	float whitepointer[3];
	whitepointer[0] = 1;
	whitepointer[1] = 1;
	whitepointer[2] = 1;
	int Top_x = given_x + (20 * sin(given_theta)), Top_y = (given_y + 20 * cos(given_theta));
	int Left_x = given_x - (20 * cos(given_theta)) - (20 * sin(given_theta)), Left_y = given_y - (20 * cos(given_theta)) + (20 * sin(given_theta));
	int Right_x = given_x + (20 * cos(given_theta)) - (20 * sin(given_theta)), Right_y = given_y - (20 * cos(given_theta)) - (20 * sin(given_theta));
	int Bottom_x = given_x - (10 * sin(given_theta)), Bottom_y = given_y - (10 * cos(given_theta));
	DrawLine(Bottom_x, Bottom_y, Left_x, Left_y, 1, whitepointer);
	DrawLine(Left_x, Left_y, Top_x, Top_y, 1, whitepointer);
	DrawLine(Bottom_x, Bottom_y, Right_x, Right_y, 1, whitepointer);
	DrawLine(Right_x, Right_y, Top_x, Top_y, 1, whitepointer);
}

SpaceShip::~SpaceShip()
{
}
