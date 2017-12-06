#pragma once
#include "Ball.h"
#include "Character.h"

class Physics
{
private:
	const float gravity = 9.8;
	const float terminalVelocity = 50.0;
	const float bounceFactor = 0.6; //Should be defined by the Court type.
	const float airResistance = 0.001;


public:
	Physics();
	~Physics();

	void UpdateBallVelocity(Ball &ball, sf::Time elapsed);

	void CheckCollision(Character player, Ball &ball, sf::Time elapsed);
};

