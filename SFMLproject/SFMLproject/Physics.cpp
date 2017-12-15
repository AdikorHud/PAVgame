#include "Physics.h"

using namespace std;

namespace tennis_game
{
	Physics::Physics()
		:
		gravity(9.8),
		terminalVelocity(50.0),
		bounceFactor(0.6), //Should be defined by the Court type.
		airResistanceFactor(0.999)
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
			ballVelocity.z = ballVelocity.z;
		}

		else
		{
			ballVelocity.z = terminalVelocity;
		}
	}



	void Physics::SetBallVelocity(Ball &ball, sf::Vector3f vector, sf::Time elapsed)
	{
		sf::Vector3<float> ballVelocity = ball.GetBallVelocity();

		ballVelocity.x = vector.x,
		ballVelocity.y = vector.y;
		ballVelocity.z = vector.z;
		
		/*float hitPower = 250.0; //TEMP. Will be replaced by hitPower from player and IA input.		
		ballVelocity.x = hitPower * 0.25; //TEMP HACK. Should be replaced by a factor derived from the raquet angle.
		ballVelocity.y = hitPower;
		ballVelocity.z = hitPower * 0.25; //TEMP HACK. Should be replaced by a factor derived from the shot type (Lob, Drop shot, Drive, etc).
		*/

		ball.UpdateVelocity(ballVelocity, elapsed);
	}

	//Applies air resistance to the ball
	void Physics::UpdateBallVelocity(Ball &ball, sf::Time elapsed)
	{
		sf::Vector3<float> ballVelocity = ball.GetBallVelocity();		
		
		ballVelocity.x = ballVelocity.x * airResistanceFactor;
		ballVelocity.y = ballVelocity.y * airResistanceFactor;
		ballVelocity.z = ballVelocity.z;


		//DEBUG
		/*
		std::cout << "X: " << ballVelocity.x << std::endl;
		std::cout << "Y: " << ballVelocity.y << std::endl;
		std::cout << "Z: " << ballVelocity.z << std::endl;
		*/
		ball.UpdateVelocity(ballVelocity, elapsed);
	}


	//Check collision between an Sprite and the &Ball.
	//Returns a boolean.
	bool Physics::CheckCollision(sf::Sprite raquetSprite, Ball &ball)
	{

		sf::Sprite ballSprite = ball.GetSprite();

		if (raquetSprite.getGlobalBounds().intersects(ballSprite.getGlobalBounds()))
		{
			return true;
		}
		return false;
	}
}