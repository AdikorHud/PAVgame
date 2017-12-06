#include "Physics.h"


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
	ballVelocity.y = ballVelocity.y - airResistance;

	if (ballVelocity.z < terminalVelocity)
	{
		ballVelocity.z = ballVelocity.z + gravity;
	}

	else
	{
		ballVelocity.z = terminalVelocity;
	}
	
	ball.UpdateVelocity(ballVelocity);
}

void Physics::CheckCollision(Character player, Ball &ball, sf::Time elapsed)
{
	sf::Sprite playerSprite = player.Draw();
	sf::FloatRect playerBox = playerSprite.getGlobalBounds();

	sf::Sprite ballSprite = ball.Draw();
	sf::FloatRect ballBox = ballSprite.getGlobalBounds();


	if (playerBox.intersects(ballBox))
	{
		sf::Vector3<float> ballVelocity = ball.GetBallVelocity();

		float hitPower = 1.0; //TEMP. Will be replaced by hitPower from player and IA input.

		ballVelocity.x = ballVelocity.x;
		
		if (ball.GetBallDirection())
		{
			ballVelocity.y = hitPower * (-1);
			ball.SetDirection(false);
		}

		else if (!ball.GetBallDirection())
		{
			ballVelocity.y = hitPower;
			ball.SetDirection(true);
		}

		ballVelocity.z = 1.0;

		ball.UpdateVelocity(ballVelocity);
	}

}
