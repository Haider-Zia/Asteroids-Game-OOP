#include "Objects.h"



Objects::Objects()
{
}
void Objects::Move(float increment, float theta_increment) {
	theta += theta_increment;
	x += increment*(sin(theta));
	if (x >= 1020) {
		x -= 1020;
	}
	else if (x <= 0) {
		x += 1020;
	}
	y += increment*(cos(theta));
	if (y >= 840) {
		y -= 840;
	}
	else if (y <= 0) {
		y += 840;
	}
}

float Objects::Get_x()
{
	return x;
}

float Objects::Get_y()
{
	return y;
}
float Objects::Get_theta()
{
	return theta;
}
float Objects::Get_radius()
{
	return radius;
}
bool Objects::Get_dead()
{
	return dead;
}
void Objects::Set_x(float given_x) {
	x = given_x;
}
void Objects::Set_y(float given_y) {
	y = given_y;
}
void Objects::Set_theta(float given_theta) {
	theta = given_theta;
}
void Objects::Set_dead(bool state)
{
	dead = state;
}
Objects::~Objects()
{
}
