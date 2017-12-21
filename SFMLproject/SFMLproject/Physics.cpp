#include "Physics.h"

using namespace std;

namespace tennis_game
{
	Physics::Physics()
		:
		gravity(-0.981),
		terminalVelocity(250.0),
		bounceFactor(0.6), //Should be defined by the Court type.
		airResistanceFactor(0.3f)
	{
	}


	Physics::~Physics()
	{
	}

	sf::Vector3f Physics::UpdateBallGravity(Ball &ball, sf::Time elapsed)
	{
		sf::Vector3f ballVelocity = ball.GetVelocity();

		ballVelocity.z = ballVelocity.z + gravity;

		return ballVelocity;
	}


	void Physics::SetBallVelocity(Ball &ball, sf::Vector3f vector, sf::Time elapsed)
	{
		vector.x = vector.y * 0.25;
		ball.SetVelocity(vector, elapsed);
	}

	//Applies air resistance to the ball
	void Physics::UpdateBallVelocity(Ball &ball, sf::Time elapsed)
	{
		sf::Vector3f ballVelocity = ball.GetVelocity();
	
		//Velocity Y
		if (ball.GetVelocity().y > 0.0f)
		{
			ballVelocity.y = ballVelocity.y - airResistanceFactor;
		}

		else
		{
			//std::cout << "LA BOLA SE DETUVO!" << std::endl;
		}

		//Gravity
		ballVelocity.z = UpdateBallGravity(ball, elapsed).z;


		//DEBUG
		//std::cout << "X: " << ballVelocity.x << std::endl;
		//std::cout << "Y: " << ballVelocity.y << std::endl;
		//std::cout << "Z: " << ballVelocity.z << std::endl;

		ball.SetVelocity(ballVelocity, elapsed);
	}


	//Check collision between an Sprite and the &Ball.
	//Returns a boolean.
	bool Physics::CheckCollision(sf::Sprite raquetSprite, Ball &ball)
	{

		//sf::Sprite ballSprite = ball.GetSprite();

		if (raquetSprite.getGlobalBounds().intersects(ball.GetSprite().getGlobalBounds()))
		{
			return true;
		}
		return false;
	}
}