#pragma once
#include "Asteroid.h"
class ComplexAsteroid :
	public Asteroid
{
protected:
	int increment_count;
public:
	ComplexAsteroid();
	virtual void Move(float increment, float theta_increment = 0);
	virtual ~ComplexAsteroid();
};

