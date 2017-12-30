#include "Raquet.h"


void Raquet::LoadTextures()
{
	if (!raquet.loadFromFile("Assets/Spritesheet/sheet_equipment.png"))
	{
		std::cout << "ERROR! Can't load equipment texture. Class: Ball" << std::endl;
	}
}

Raquet::Raquet()
	:
	raquetPosition(),
	raquet(),
	metalRaquet(raquet),
	isPlayingAnimation(false)
{
	LoadTextures();
}


Raquet::~Raquet()
{
}

sf::Sprite Raquet::GetSprite()
{
	metalRaquet.setTexture(raquet);
	metalRaquet.setTextureRect(sf::IntRect(0, 108, 29, 8));
	metalRaquet.setScale(1, 1);

	return metalRaquet;
}

void Raquet::SetPosition(sf::Vector2f position)
{
	raquetPosition = position;
}

void Raquet::UpdatePosition(sf::Vector2f position)
{
	metalRaquet.setPosition(position);
}

void Raquet::SetScale(float scale)
{
	metalRaquet.setScale(scale, scale);
}

void Raquet::SetRotation(float rotation)
{
	metalRaquet.setRotation(rotation);
}

float Raquet::GetRotation()
{
	if (metalRaquet.getRotation() > 180.0f)
	{
		return (360 - metalRaquet.getRotation()) * -1; //Changes +180 into negative values (a 315° angle becomes -45°)
	}

	else
	{
		return metalRaquet.getRotation();
	}
}

void Raquet::Rotate(float value)
{
	metalRaquet.rotate(value);
}

void Raquet::SetAnimationStatus()
{
	if (!isPlayingAnimation)
	{
		isPlayingAnimation = true;
	}
}

void Raquet::PlayAnimation()
{	
	if (metalRaquet.getRotation() < 45 && isPlayingAnimation || metalRaquet.getRotation() > 315 && isPlayingAnimation)
	{
		metalRaquet.rotate(-3.0);
	}

	else if (metalRaquet.getRotation() >= 315 || metalRaquet.getRotation() != 0.0)
	{
		metalRaquet.rotate(2.0);
		isPlayingAnimation = false;
	}
}


