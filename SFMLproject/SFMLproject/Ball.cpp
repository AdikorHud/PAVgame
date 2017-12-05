#include "Ball.h"



void Ball::LoadTextures()
{
	if (!ball.loadFromFile("Assets/Spritesheet/sheet_charactersEquipment.png"))
	{
		std::cout << "ERROR! Can't load equipment texture. Class: Ball" << std::endl;
	}
}

Ball::Ball()
	:
	ballVelocity()
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

	sf::Vector2f ballVector2 = yellowBall.getPosition();	
	yellowBall.setPosition(ballVector2.x + ballVelocity.x, ballVector2.y + ballVelocity.y);

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
	yellowBall.setPosition(playerPos);
}
