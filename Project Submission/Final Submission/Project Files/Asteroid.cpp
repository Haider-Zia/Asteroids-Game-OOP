#include "Asteroid.h"



Asteroid::Asteroid()
{
	
}
void Asteroid::Draw(float given_x, float given_y, float given_theta) {
	float whitepointer[3];
	whitepointer[0] = 1;
	whitepointer[1] = 1;
	whitepointer[2] = 1;
	
	alpha_1 += given_theta;
	alpha_2 += given_theta;
	alpha_3 += given_theta;
	alpha_4 += given_theta;
	alpha_5 += given_theta;
	alpha_6 += given_theta;
	alpha_7 += given_theta;
	alpha_8 += given_theta;
	alpha_9 += given_theta;
	alpha_10 += given_theta;
	
	int x1, x2, y1, y2;
	x1 = given_x + radius * cos(Deg2Rad(alpha_1));
	y1 = given_y + radius * sin(Deg2Rad(alpha_1));
	x2 = given_x + radius * cos(Deg2Rad(alpha_2));
	y2 = given_y + radius * sin(Deg2Rad(alpha_2));
	DrawLine(x1, y1, x2, y2, 1, whitepointer);
	x1 = given_x + radius * cos(Deg2Rad(alpha_2));
	y1 = given_y + radius * sin(Deg2Rad(alpha_2));
	x2 = given_x + radius * cos(Deg2Rad(alpha_3));
	y2 = given_y + radius * sin(Deg2Rad(alpha_3));
	DrawLine(x1, y1, x2, y2, 1, whitepointer);
	x1 = given_x + radius * cos(Deg2Rad(alpha_3));
	y1 = given_y + radius * sin(Deg2Rad(alpha_3));
	x2 = given_x + radius * cos(Deg2Rad(alpha_4));
	y2 = given_y + radius * sin(Deg2Rad(alpha_4));
	DrawLine(x1, y1, x2, y2, 1, whitepointer);
	x1 = given_x + radius * cos(Deg2Rad(alpha_4));
	y1 = given_y + radius * sin(Deg2Rad(alpha_4));
	x2 = given_x + radius * cos(Deg2Rad(alpha_5));
	y2 = given_y + radius * sin(Deg2Rad(alpha_5));
	DrawLine(x1, y1, x2, y2, 1, whitepointer);
	x1 = given_x + radius * cos(Deg2Rad(alpha_5));
	y1 = given_y + radius * sin(Deg2Rad(alpha_5));
	x2 = given_x + radius * cos(Deg2Rad(alpha_6));
	y2 = given_y + radius * sin(Deg2Rad(alpha_6));
	DrawLine(x1, y1, x2, y2, 1, whitepointer);
	x1 = given_x + radius * cos(Deg2Rad(alpha_6));
	y1 = given_y + radius * sin(Deg2Rad(alpha_6));
	x2 = given_x + radius * cos(Deg2Rad(alpha_7));
	y2 = given_y + radius * sin(Deg2Rad(alpha_7));
	DrawLine(x1, y1, x2, y2, 1, whitepointer);
	x1 = given_x + radius * cos(Deg2Rad(alpha_7));
	y1 = given_y + radius * sin(Deg2Rad(alpha_7));
	x2 = given_x + radius * cos(Deg2Rad(alpha_8));
	y2 = given_y + radius * sin(Deg2Rad(alpha_8));
	DrawLine(x1, y1, x2, y2, 1, whitepointer);
	x1 = given_x + radius * cos(Deg2Rad(alpha_8));
	y1 = given_y + radius * sin(Deg2Rad(alpha_8));
	x2 = given_x + radius * cos(Deg2Rad(alpha_9));
	y2 = given_y + radius * sin(Deg2Rad(alpha_9));
	DrawLine(x1, y1, x2, y2, 1, whitepointer);
	x1 = given_x + radius * cos(Deg2Rad(alpha_9));
	y1 = given_y + radius * sin(Deg2Rad(alpha_9));
	x2 = given_x + radius * cos(Deg2Rad(alpha_10));
	y2 = given_y + radius * sin(Deg2Rad(alpha_10));
	DrawLine(x1, y1, x2, y2, 1, whitepointer);
	x1 = given_x + radius * cos(Deg2Rad(alpha_10));
	y1 = given_y + radius * sin(Deg2Rad(alpha_10));
	x2 = given_x + radius * cos(Deg2Rad(alpha_1));
	y2 = given_y + radius * sin(Deg2Rad(alpha_1));
	DrawLine(x1, y1, x2, y2, 1, whitepointer);
}

Asteroid::~Asteroid()
{
}
