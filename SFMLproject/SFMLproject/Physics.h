#pragma once
#include "Ball.h"
#include "Character.h"
#include <Thor\Vectors.hpp>

using namespace std;

namespace tennis_game
{
	class Physics
	{

	private:
		float gravity;
		const float terminalVelocity;
		const float bounceFactor; //Should be defined by the Court type.
		const float airResistanceFactor;


	public:
		Physics();
		~Physics();

		sf::Vector3f UpdateBallGravity(Ball &ball, sf::Time elapsed);

		void SetBallVelocity(Ball &ball, sf::Vector3f vector, sf::Time elapsed);

		void UpdateBallVelocity(Ball & ball, sf::Time elapsed);

		bool CheckCollision(sf::Sprite raquetSprite, Ball &ball);


		//DEBUG
		sf::Vector2<float> rotate(sf::Vector2<float> &value, float angle);

	};
}
