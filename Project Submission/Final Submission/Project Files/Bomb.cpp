#include "Bomb.h"



Bomb::Bomb()
{
	dead = 0;
	x = -1500;
	y = -1500;
	theta = 0;
	radius = 2;
}
void Bomb::Draw(float given_x, float given_y, float given_theta) {
	float whitepointer[3];
	whitepointer[0] = 1;
	whitepointer[1] = 1;
	whitepointer[2] = 1;
	DrawCircle(given_x, given_y, 2, whitepointer);
}
void Bomb::Move(float increment, float theta_increment) {
	x += increment*(sin(theta));
	y += increment*(cos(theta));
	if (x >= 1020 || x <= 0 || y >= 840 || y <= 0) {
		x = -1500;
		y = -1500;
	}
}
Bomb::~Bomb()
{
}
