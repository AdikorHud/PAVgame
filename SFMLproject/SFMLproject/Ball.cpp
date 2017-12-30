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

		ball.setSmooth(true);
	}

	void Ball::UpdatePosition(sf::Time elapsed)
	{
		if (GetBallDirection())
		{
			ballPosition.x = ballPosition.x + ballVelocity.x * elapsed.asSeconds();
			ballPosition.y = ballPosition.y + ballVelocity.y * elapsed.asSeconds();
		}

		else
		{
			ballPosition.x = ballPosition.x + (ballVelocity.x * elapsed.asSeconds()) * -1;
			ballPosition.y = ballPosition.y + (ballVelocity.y * elapsed.asSeconds()) * -1;
		}


		if (ballPosition.z <= 0.0f)
		{
			//DEBUG
			//std::cout << "BOUNCE! " << ballVelocity.z << std::endl;

			this->ballPosition.z = 0.0f;
			this->ballVelocity.z = this->ballVelocity.z * -1;
			this->ballVelocity.z = this->ballVelocity.z * 0.65f;

			//std::cout << "------! " << ballVelocity.z << std::endl;
		}
		/*
		else if (ballPosition.z <= 0.0f)
		{
			//DEBUG
			std::cout << "NOT BOUNCE! " << ballVelocity.z << std::endl;

			ballPosition.z = 0.0f;
			ballVelocity.z = 0.0f;
		}
		*/
		ballPosition.z = ballPosition.z + ballVelocity.z * elapsed.asSeconds();;
		
		//DEBUG
		//std::cout << "Position: " << ballPosition.z << std::endl;
		SetScale();

		//DEBUG
		//std::cout << "Position: " << ballPosition.z << std::endl;
	}

	void Ball::SetScale()
	{
		yellowBall.setScale(1 + ballPosition.z / 10, 1 + ballPosition.z / 10);
	}


	//PUBLIC
	Ball::Ball()
		:
		ballVelocity(0, 350, 25.0f),
		ballPosition(0, 0, 5),
		isMovingBottom(true),
		ball(),
		yellowBall()
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
		yellowBall.setPosition(ballPosition.x, ballPosition.y);

		return yellowBall;
	}

	sf::Vector3f Ball::GetVelocity()
	{
		return ballVelocity;
	}

	void Ball::SetVelocity(sf::Vector3f velocity, sf::Time elapsed)
	{
		ballVelocity = velocity;
		UpdatePosition(elapsed);
	}

	void Ball::SetService(Character player)
	{		
		ballPosition.x = player.GetPlayerPosition().x;
		ballPosition.y = player.GetPlayerPosition().y;
	}

	void Ball::ChangeBallDirection()
	{
		if (!GetBallDirection())
		{
			isMovingBottom = true;
		}

		else
		{
			isMovingBottom = false;
		}
	}

	sf::Vector3f Ball::GetBallPosition()
	{
		return ballPosition;
	}

	//Returns true if the ball is moving bottom.
	bool Ball::GetBallDirection()
	{
		return isMovingBottom;
	}

	//Set the ball direction (true if is moving bottom)
	void Ball::SetDirection(bool value)
	{
		isMovingBottom = value;
	}
}