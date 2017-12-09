#include "Ball.h"
using namespace std;

namespace tennis_game
{
	//PRIVATE
	void Ball::LoadTextures()
	{
		if (!ball.loadFromFile("Assets/Spritesheet/sheet_charactersEquipment.png"))
		{
			std::cout << "ERROR! Can't load equipment texture. Class: Ball" << std::endl;
		}
	}

	void Ball::UpdatePosition(sf::Time elapsed)
	{		
		ballPosition.x = ballPosition.x + ballVelocity.x;
		ballPosition.y = ballPosition.y + ballVelocity.y;
	}

	sf::Vector2f Ball::SetBallPosition()
	{
		return sf::Vector2f();
	}

	void Ball::SetScale()
	{
		yellowBall.setScale(1 + ballVelocity.z, 1 + ballVelocity.z);
	}


	//PUBLIC
	Ball::Ball()
		:
		ballVelocity(0, 1, 0),
		ballPosition(),
		isMovingBottom(true)
	{
		LoadTextures();
	}


	Ball::~Ball()
	{
	}

	sf::Sprite Ball::GetSprite()
	{
		yellowBall.setTexture(ball);
		yellowBall.setTextureRect(sf::IntRect(50, 155, 12, 12));
		yellowBall.setPosition(ballPosition);
		//SetScale();

		return sf::Sprite(yellowBall);
	}

	sf::Vector3<float> Ball::GetBallVelocity()
	{
		return ballVelocity;
	}

	void Ball::UpdateVelocity(sf::Vector3<float> velocity, sf::Time elapsed)
	{
		ballVelocity = velocity;
		UpdatePosition(elapsed);
	}

	void Ball::SetService(Character player)
	{		
		ballPosition.x = player.GetPlayerPosition().x - 10;
		ballPosition.y = player.GetPlayerPosition().y + 50;
	}

	bool Ball::GetBallDirection()
	{
		return isMovingBottom;
	}

	sf::Vector2f Ball::GetBallPosition()
	{
		return ballPosition;
	}

	//Returns true if the ball is moving bottom.
	void Ball::SetDirection(bool value)
	{
		isMovingBottom = value;
	}
}