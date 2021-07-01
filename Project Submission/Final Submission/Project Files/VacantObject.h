#pragma once
#include "Objects.h"
class VacantObject :
	public Objects
{
public:
	VacantObject();
	void Draw(float given_x, float given_y, float given_theta);
	void Move(float increment, float theta_increment = 0);
	~VacantObject();
};

