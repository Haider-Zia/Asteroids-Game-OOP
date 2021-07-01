#include "BigSaucer.h"



BigSaucer::BigSaucer()
{
	dead = 0;
	radius = 50;
	int quarter = GetRandInRange(1, 4.9);
	if (quarter == 1) {
		x = GetRandInRange(75, 400);
		y = GetRandInRange(75, 320);
	}
	if (quarter == 2) {
		x = GetRandInRange(75, 400);
		y = GetRandInRange(520, 765);
	}
	if (quarter == 3) {
		x = GetRandInRange(620, 945);
		y = GetRandInRange(75, 320);
	}
	if (quarter == 4) {
		x = GetRandInRange(620, 945);
		y = GetRandInRange(520, 765);
	}
	theta = GetRandInRange(0, 7);
}
void BigSaucer::Move(float increment, float theta_increment) {
	theta += theta_increment;
	x += increment*(sin(theta));
	if (x >= 1020) {
		x -= 1020;
	}
	else if (x <= 0) {
		x += 1020;
	}
	y += increment*(cos(theta));
	if (y >= 840) {
		y -= 840;
	}
	else if (y <= 0) {
		y += 840;
	}
}
BigSaucer::~BigSaucer()
{
}
