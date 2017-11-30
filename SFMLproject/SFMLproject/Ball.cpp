#include "Ball.h"
#include "Character.h"



Ball::Ball()
	:
	ballVelocity()
{
}

Ball::Ball(float x, float y, float z, Character player)
{
	ballVelocity.x = x;
	ballVelocity.y = y;
	ballVelocity.z = y;
}


Ball::~Ball()
{
}

void Ball::UpdateMovement()
{
}
