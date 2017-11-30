#pragma once
#include <SFML\System\Vector3.hpp>
#include <SFML\Graphics.hpp>

class Ball
{
private:
	sf::Vector3<float> ballVelocity;


public:
	Ball();
	Ball(float x, float y, float z, Character player);
	~Ball();

	void UpdateMovement();
};