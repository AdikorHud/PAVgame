#include "Character.h"


void Character::LoadTextures()
{
	if (!charTileset.loadFromFile("Assets/Spritesheet/sheet_characters.png"))
	{
		std::cout << "ERROR! Missing character texture. Class: Character." << std::endl;
	}
}


Character::Character()
{
	Character::LoadTextures();
}


Character::~Character()
{
}

sf::Sprite Character::Draw()
{
	charBody.setTexture(charTileset);
	charBody.setTextureRect(sf::IntRect(0, 0, 21, 31));
	return sf::Sprite(charBody);
}

void Character::SetStartingPosition(float posX, float posY)
{
	charBody.setPosition(posX, posY);
}

void Character::SetStartingRotation(float rotation)
{
	charBody.setRotation(rotation);
}

void Character::SetIsRunning(bool value)
{
	if (value == true)
	{
		isRunning = true;
	}

	else
	{
		isRunning = false;
	}
}

void Character::UpdateSpeed()
{
	if (isRunning && speed < maxSpeed)
	{
		speed += runningSpeedIncremental;
	}

	if (!isRunning && speed > baseSpeed)
	{
		speed -= runningSpeedIncremental;
	}
}

void Character::MoveLeft(sf::Time elapsed)
{
	charBody.move(-speed * elapsed.asSeconds(),0);
}

void Character::MoveRight(sf::Time elapsed)
{
	charBody.move(speed * elapsed.asSeconds(), 0);
}

void Character::MoveUp(sf::Time elapsed)
{
	charBody.move(0, -speed * elapsed.asSeconds());
}

void Character::MoveDown(sf::Time elapsed)
{
	charBody.move(0, speed * elapsed.asSeconds());
}