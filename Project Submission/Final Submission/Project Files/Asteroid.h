#pragma once
#include "Objects.h"
class Asteroid :
	public Objects
{
protected:
	float alpha_1, alpha_2, alpha_3, alpha_4, alpha_5, alpha_6, alpha_7, alpha_8, alpha_9, alpha_10;
public:
	Asteroid();
	virtual void Draw(float given_x, float given_y, float given_theta);
	virtual ~Asteroid();
};

