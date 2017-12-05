#include "Physics.h"


Physics::Physics()
{
}


Physics::~Physics()
{
}


void Physics::UpdateBallVelocity(Ball &ball)
{
	sf::Vector3<float> ballVelocity = ball.GetBallVelocity();	

	ballVelocity.x += 0.0f;
	ballVelocity.y += 0.0001;
	ballVelocity.z -= gravity;
	
	ball.UpdateVelocity(ballVelocity);
}

void Physics::CheckCollision(Character player, Ball &ball)
{
	sf::Sprite playerSprite = player.Draw();
	sf::FloatRect playerBox = playerSprite.getGlobalBounds();

	sf::Sprite ballSprite = ball.Draw();
	sf::FloatRect ballBox = ballSprite.getGlobalBounds();


	if (playerBox.intersects(ballBox))
	{
		sf::Vector3<float> ballVelocity = ball.GetBallVelocity();

		ballVelocity.x += 0.0f;
		ballVelocity.y = ballVelocity.y - (ballVelocity.y * 2);
		ballVelocity.z -= gravity;

		ball.UpdateVelocity(ballVelocity);
	}

}
