#pragma once
#include "Objects.h"
class SpaceShip :
	public Objects
{
private:

public:
	SpaceShip();
	void Draw(float given_x, float given_y, float given_theta);
	~SpaceShip();
};

