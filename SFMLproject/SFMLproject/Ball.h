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

	void LoadTextures();


public:
	Ball();
	~Ball();

	sf::Sprite Draw();

	sf::Vector3<float> GetBallVelocity();

	void UpdateVelocity(sf::Vector3<float> velocity);

	void SetService(Character player);

};