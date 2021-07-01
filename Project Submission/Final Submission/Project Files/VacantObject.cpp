#include "VacantObject.h"



VacantObject::VacantObject()
{
	x = -1500;
	y = 1500;
	dead = 1;
}
void VacantObject::Draw(float given_x, float given_y, float given_theta) {
	//Draws nothing
}
void VacantObject::Move(float increment, float theta_increment) {
	//Moves nothing
}
VacantObject::~VacantObject()
{
}
