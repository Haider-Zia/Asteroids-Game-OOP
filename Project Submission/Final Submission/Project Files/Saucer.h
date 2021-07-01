#pragma once
#include "Objects.h"
class Saucer :
	public Objects
{
public:
	Saucer();
	virtual void Draw(float given_x, float given_y, float given_theta);
	virtual ~Saucer();
};

