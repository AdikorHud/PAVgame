#include "Physics.h"

using namespace std;

namespace tennis_game
{
	Physics::Physics()
		:
		gravity(9.8),
		terminalVelocity(50.0),
		bounceFactor(0.6), //Should be defined by the Court type.
		airResistanceFactor(0.9)
	{
	}


	Physics::~Physics()
	{
	}

	void Physics::UpdateBallGravity(Ball &ball, sf::Time elapsed)
	{
		sf::Vector3f ballVelocity = ball.GetVelocity();

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
		sf::Vector3f ballVelocity;

		ballVelocity.x = vector.x,
		ballVelocity.y = vector.y;
		ballVelocity.z = vector.z;

		ball.SetVelocity(ballVelocity, elapsed);
	}

	//Applies air resistance to the ball
	void Physics::UpdateBallVelocity(Ball &ball, sf::Time elapsed)
	{
		sf::Vector3f ballVelocity = ball.GetVelocity();		
		
		if (ball.GetVelocity().y > 0)
		{
			ballVelocity.y = ballVelocity.y - airResistanceFactor;
		}

		ballVelocity.x = ballVelocity.x; //Se puede borrar
		ballVelocity.z = ballVelocity.z; //Se puede borrar

		//DEBUG
		std::cout << "X: " << ballVelocity.x << std::endl;
		std::cout << "Y: " << ballVelocity.y << std::endl;
		std::cout << "Z: " << ballVelocity.z << std::endl;

		ball.SetVelocity(ballVelocity, elapsed);
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