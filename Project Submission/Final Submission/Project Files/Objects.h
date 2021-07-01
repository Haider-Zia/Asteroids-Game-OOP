#pragma once
#include "util.h"
class Objects
{
protected:
	float x, y, theta, radius;
	bool dead;
public:
	Objects();
	virtual void Draw(float given_x, float given_y, float given_theta) = 0;
	virtual void Move(float increment, float theta_increment=0);
	float Get_x();
	float Get_y();
	float Get_theta();
	float Get_radius();
	bool Get_dead();
	void Set_x(float given_x);
	void Set_y(float given_y);
	void Set_theta(float given_theta);
	void Set_dead(bool state);

	virtual ~Objects();
};