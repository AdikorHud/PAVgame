#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

sf::Sprite Character::Draw()
{
	if (!charTileset.loadFromFile("Assets/Spritesheet/sheet_characters.png"))
	{
		std::cout << "ERROR! Missing character texture. Class: Character." << std::endl;
	}

	charBody.setTexture(charTileset);
	charBody.setTextureRect(sf::IntRect(147, 93, 21, 31));
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

void Character::MoveLeft()
{
	charBody.move(-1, 0);
}

void Character::MoveRight()
{
	charBody.move(1, 0);
}

void Character::MoveUp()
{
	charBody.move(0, -1);
}

void Character::MoveDown()
{
	charBody.move(0, 1);
}