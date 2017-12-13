#include "Physics.h"
using namespace std;

namespace tennis_game
{
	Physics::Physics()
		:
		gravity(9.8),
		terminalVelocity(50.0),
		bounceFactor(0.6), //Should be defined by the Court type.
		airResistanceFactor(-0.3)
	{
	}


	Physics::~Physics()
	{
	}

	void Physics::UpdateBallGravity(Ball &ball, sf::Time elapsed)
	{
		sf::Vector3<float> ballVelocity = ball.GetBallVelocity();

		if (ballVelocity.z < terminalVelocity)
		{
			ballVelocity.z += ballVelocity.z;
		}

		else
		{
			ballVelocity.z = terminalVelocity;
		}
	}



	void Physics::SetBallVelocity(Ball &ball, sf::Time elapsed)
	{
		float hitPower = 250.0; //TEMP. Will be replaced by hitPower from player and IA input.
		
		sf::Vector3<float> ballVelocity = ball.GetBallVelocity();
		
		ballVelocity.x = hitPower * 0.25; //TEMP HACK. Should be replaced by a factor derived from the raquet angle.
		ballVelocity.y = hitPower;
		ballVelocity.z = hitPower * 0.25; //TEMP HACK. Should be replaced by a factor derived from the shot type (Lob, Drop shot, Drive, etc).

		ball.UpdateVelocity(ballVelocity, elapsed);
	}


	//Check collision between and Sprite and the &Ball.
	//Returns a boolean.
	bool Physics::CheckCollision(sf::Sprite raquetSprite, Ball &ball, sf::Time elapsed)
	{

		sf::Sprite ballSprite = ball.GetSprite();

		if (raquetSprite.getGlobalBounds().intersects(ballSprite.getGlobalBounds()))
		{
			return true;
		}
		return false;
	}
}