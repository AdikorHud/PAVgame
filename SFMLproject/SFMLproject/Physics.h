#pragma once
#include "Ball.h"
#include "Character.h"

using namespace std;

namespace tennis_game
{
	class Physics
	{
	private:
		const float gravity;
		const float terminalVelocity;
		const float bounceFactor; //Should be defined by the Court type.
		const float airResistanceFactor;


	public:
		Physics();
		~Physics();

		void UpdateBallGravity(Ball &ball, sf::Time elapsed);

		void SetBallVelocity(Ball &ball, sf::Vector3f vector, sf::Time elapsed);

		void UpdateBallVelocity(Ball & ball, sf::Time elapsed);

		bool CheckCollision(sf::Sprite raquetSprite, Ball &ball);
	};
}
