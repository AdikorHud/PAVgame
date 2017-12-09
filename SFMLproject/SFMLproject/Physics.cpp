#include "Physics.h"
using namespace std;

namespace tennis_game
{
	Physics::Physics()
	{
	}


	Physics::~Physics()
	{
	}


	void Physics::UpdateBallVelocity(Ball &ball, sf::Time elapsed)
	{
		sf::Vector3<float> ballVelocity = ball.GetBallVelocity();

		ballVelocity.x = ballVelocity.x;
		ballVelocity.y = ballVelocity.y; // -airResistance;

		if (ballVelocity.z < terminalVelocity)
		{
			ballVelocity.z = ballVelocity.z + gravity;
		}

		else
		{
			ballVelocity.z = terminalVelocity;
		}

		ball.UpdateVelocity(ballVelocity, elapsed);
	}

	void Physics::CheckCollision(Character player, Ball &ball, sf::Time elapsed)
	{
		
		sf::Sprite playerSprite = player.GetSprite();
		sf::Sprite ballSprite = ball.GetSprite();
		

		if (playerSprite.getGlobalBounds().intersects(ballSprite.getGlobalBounds()))
		{
			sf::Vector3<float> ballVelocity = ball.GetBallVelocity();

			float hitPower = 1; //TEMP. Will be replaced by hitPower from player and IA input.

			ballVelocity.x = ballVelocity.x;

			if (ball.GetBallDirection())
			{
				ballVelocity.y = hitPower * (-1);
				ballVelocity.x = 0.005;
				ball.SetDirection(false);
			}

			else if (!ball.GetBallDirection())
			{
				ballVelocity.y = hitPower;
				ballVelocity.x = 0.005;
				ball.SetDirection(true);
			}

			ballVelocity.z = 1.0;

			ball.UpdateVelocity(ballVelocity, elapsed);
		}
	}
}