#include "SmallAsteroid.h"



SmallAsteroid::SmallAsteroid()
{
	dead = 0;
	x = 1500;
	y = 1500;
	alpha_1 = GetRandInRange(0, 36);
	alpha_2 = GetRandInRange(36, 72);
	alpha_3 = GetRandInRange(72, 108);
	alpha_4 = GetRandInRange(108, 144);
	alpha_5 = GetRandInRange(144, 180);
	alpha_6 = GetRandInRange(180, 216);
	alpha_7 = GetRandInRange(216, 252);
	alpha_8 = GetRandInRange(252, 288);
	alpha_9 = GetRandInRange(288, 324);
	alpha_10 = GetRandInRange(324, 360);
	theta = GetRandInRange(0, 7);
	radius = 25;
}


SmallAsteroid::~SmallAsteroid()
{
}
