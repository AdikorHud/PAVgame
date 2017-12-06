#include "Ball.h"



void Ball::LoadTextures()
{
	if (!ball.loadFromFile("Assets/Spritesheet/sheet_charactersEquipment.png"))
	{
		std::cout << "ERROR! Can't load equipment texture. Class: Ball" << std::endl;
	}
}

void Ball::UpdatePosition()
{
	sf::Vector2f ballVector2 = yellowBall.getPosition();
	yellowBall.setPosition(ballVector2.x + ballVelocity.x, ballVector2.y + ballVelocity.y);
}

void Ball::UpdateScale()
{
	yellowBall.setScale(1 + ballVelocity.z, 1 + ballVelocity.z);
}

Ball::Ball()
	:
	ballVelocity(0, 1.0, 0),
	isMovingBottom(true)
{
	LoadTextures();
}


Ball::~Ball()
{
}

sf::Sprite Ball::Draw()
{
	yellowBall.setTexture(ball);
	yellowBall.setTextureRect(sf::IntRect(50, 155, 12, 12));

	UpdatePosition();
	//UpdateScale();

	return sf::Sprite(yellowBall);
}

sf::Vector3<float> Ball::GetBallVelocity()
{
	return ballVelocity;
}

void Ball::UpdateVelocity(sf::Vector3<float> velocity)
{
	ballVelocity = velocity;
}

void Ball::SetService(Character player)
{
	sf::Vector2<float> playerPos = player.GetPlayerPosition();
	yellowBall.setPosition(playerPos.x - 10, playerPos.y + 50); // TEMP HACK
}

bool Ball::GetBallDirection()
{
	return isMovingBottom;
}

void Ball::SetDirection(bool value)
{
	isMovingBottom = value;
}

