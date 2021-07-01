#include "BigAsteroid.h"



BigAsteroid::BigAsteroid()
{
	dead = 0;
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
	radius = 75;
}


BigAsteroid::~BigAsteroid()
{
}
