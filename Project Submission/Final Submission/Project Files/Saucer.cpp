#include "Saucer.h"



Saucer::Saucer()
{
}
void Saucer::Draw(float given_x, float given_y, float given_theta) {
	float whitepointer[3];
	whitepointer[0] = 1;
	whitepointer[1] = 1;
	whitepointer[2] = 1;
	DrawLine(x, y, x + radius, y, 1, whitepointer);
	DrawLine(x, y, x - radius, y, 1, whitepointer);
	DrawLine(x + radius, y, x + radius/2, y - radius/1.5, 1, whitepointer);
	DrawLine(x - radius, y, x - radius/2, y - radius/1.5, 1, whitepointer);
	DrawLine(x, y - radius/1.5, x + radius/2, y - radius/1.5, 1, whitepointer);
	DrawLine(x, y - radius/1.5, x - radius/2, y - radius/1.5, 1, whitepointer);
	DrawLine(x + radius, y, x + radius/2, y + radius/1.5, 1, whitepointer);
	DrawLine(x - radius, y, x - radius/2, y + radius/1.5, 1, whitepointer);
	DrawLine(x, y + radius/1.5, x + radius/2, y + radius/1.5, 1, whitepointer);
	DrawLine(x, y + radius/1.5, x - radius/2, y + radius/1.5, 1, whitepointer);
	DrawLine(x + radius/4, y + radius/1.5, x + radius/5, y + radius, 1, whitepointer);
	DrawLine(x - radius/4, y + radius/1.5, x - radius/5, y + radius, 1, whitepointer);
	DrawLine(x, y + radius, x + radius/5, y + radius, 1, whitepointer);
	DrawLine(x, y + radius, x - radius/5, y + radius, 1, whitepointer);
}
Saucer::~Saucer()
{
}
