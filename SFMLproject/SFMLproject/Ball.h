#pragma once
#include <SFML\System\Vector3.hpp>
#include <SFML\Graphics.hpp>
#include "Character.h"

class Ball
{
private:
	sf::Vector3<float> ballVelocity;
	sf::Texture ball;
	sf::Sprite yellowBall;
	bool isMovingBottom;

	void LoadTextures();

	void UpdatePosition();

	void UpdateScale();


public:
	Ball();
	~Ball();

	sf::Sprite Draw();

	sf::Vector3<float> GetBallVelocity();	

	void UpdateVelocity(sf::Vector3<float> velocity);

	void SetService(Character player);

	bool GetBallDirection();

	void SetDirection(bool value);

};