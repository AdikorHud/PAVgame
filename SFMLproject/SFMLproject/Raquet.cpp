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
	metalRaquet(raquet)
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
