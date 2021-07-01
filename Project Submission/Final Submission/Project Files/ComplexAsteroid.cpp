#include "ComplexAsteroid.h"



ComplexAsteroid::ComplexAsteroid()
{
}
void ComplexAsteroid::Move(float increment, float theta_increment) {
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
	increment_count++;
	if (increment_count >= 1000) {
		theta = GetRandInRange(0, 7);
		increment_count = 0;
	}
}

ComplexAsteroid::~ComplexAsteroid()
{
}
