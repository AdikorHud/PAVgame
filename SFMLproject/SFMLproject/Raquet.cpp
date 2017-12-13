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
	//<SubTexture name = "flag_checkered.png" x = "0" y = "27" width = "32" height = "27" / >
	//<SubTexture name = "racket_metal.png" x = "0" y = "108" width = "29" height = "8" / >
	metalRaquet.setTexture(raquet);
	metalRaquet.setTextureRect(sf::IntRect(0, 108, 29, 8));
	metalRaquet.setScale(1, 1);

	return metalRaquet;
}

void Raquet::SetPosition(sf::Vector2f position)
{
	raquetPosition = position;
	UpdatePosition(raquetPosition);
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
