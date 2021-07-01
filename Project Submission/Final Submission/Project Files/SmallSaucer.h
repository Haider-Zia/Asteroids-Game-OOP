#pragma once
#include "Saucer.h"
class SmallSaucer :
	public Saucer
{
protected:
	int increment_count = 0;
public:
	SmallSaucer();
	void Move(float increment, float theta_increment = 0);
	~SmallSaucer();
};

