#pragma once
#include "Objects.h"
class Bomb :
	public Objects
{
public:
	Bomb();
	void Move(float increment, float theta_increment = 0);
	void Draw(float given_x, float given_y, float given_theta);
	virtual ~Bomb();
};

