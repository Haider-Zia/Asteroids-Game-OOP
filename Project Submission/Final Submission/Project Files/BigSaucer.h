#pragma once
#include "Saucer.h"
class BigSaucer :
	public Saucer
{
public:
	BigSaucer();
	void Move(float increment, float theta_increment = 0);
	~BigSaucer();
};

