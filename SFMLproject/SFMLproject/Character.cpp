#include "Character.h"
#include "Physics.h"

using namespace std;

namespace tennis_game
{

	void Character::LoadTextures()
	{
		if (!charTileset.loadFromFile("Assets/Spritesheet/sheet_characters.png"))
		{
			std::cout << "ERROR! Missing character texture. Class: Character." << std::endl;
		}
	}


	Character::Character(bool isAIControlled)
	{
		Character::LoadTextures();
		raquet.SetPosition(body.getPosition());
		raquet.SetRotation(45.0);
	}


	Character::~Character()
	{
	}


	sf::Sprite Character::GetSprite()
	{
		body.setTexture(charTileset);
		body.setTextureRect(sf::IntRect(147, 93, 21, 31));
		body.setOrigin(15, 31);

		return body;
	}

	sf::Sprite Character::GetRaquetSprite()
	{
		raquet.UpdatePosition(GetPlayerPosition());
		return raquet.GetSprite();
	}

	void Character::SetStartingPosition(float posX, float posY)
	{
		body.setPosition(posX, posY);
	}

	sf::Vector2<float> Character::GetPlayerPosition()
	{
		return body.getPosition();
	}

	void Character::SetStartingRotation(float rotation)
	{		
		body.setRotation(rotation);
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
		body.move(-speed * elapsed.asSeconds(), 0);
	}

	void Character::MoveRight(sf::Time elapsed)
	{
		body.move(speed * elapsed.asSeconds(), 0);
	}

	void Character::MoveUp(sf::Time elapsed)
	{
		body.move(0, -speed * elapsed.asSeconds());
	}

	void Character::MoveDown(sf::Time elapsed)
	{
		body.move(0, speed * elapsed.asSeconds());
	}

	void Character::ShotGroundStroke()
	{
		raquet.PlayAnimation();
	}
}