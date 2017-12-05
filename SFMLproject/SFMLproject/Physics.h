#pragma once
#include "Ball.h"
#include "Character.h"

class Physics
{
private:
	const float gravity = 0.01;
	const float airResistance = 0.05;

public:
	Physics();
	~Physics();

	void UpdateBallVelocity(Ball &ball);

	void CheckCollision(Character player, Ball &ball);
};

