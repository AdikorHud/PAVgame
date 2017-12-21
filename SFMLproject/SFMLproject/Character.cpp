#include "Character.h"

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
		:
		drivePower(),
		shotPowerMultiplier(0.0f)
		
	{
		Character::LoadTextures();
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
		raquet.PlayAnimation();
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

	void Character::ShotDrive()
	{
		shotPower.x = 0;
		shotPower.y = 450 * shotPowerMultiplier;
		shotPower.z = 25 * shotPowerMultiplier;

		raquet.SetRotation(44);
		raquet.SetAnimationStatus();
	}

	void Character::ShotSlice()
	{
		shotPower.x = 0;
		shotPower.y = 385 * shotPowerMultiplier;
		shotPower.z = 25 * shotPowerMultiplier;

		raquet.SetRotation(44);
		raquet.SetAnimationStatus();
	}

	void Character::ShotLob()
	{
		shotPower.x = 0;
		shotPower.y = 350 * shotPowerMultiplier;
		shotPower.z = 50 * shotPowerMultiplier;

		raquet.SetRotation(44);
		raquet.SetAnimationStatus();
	}

	void Character::ShotDropshot()
	{
		shotPower.x = 0;
		shotPower.y = 250 * shotPowerMultiplier;
		shotPower.z = 35 * shotPowerMultiplier;

		raquet.SetRotation(44);
		raquet.SetAnimationStatus();
	}

	//Shots

	void Character::SetShotPower(sf::Vector3f value)
	{
		shotPower = value;
	}

	void Character::SetShotPowerMultiplier(float value)
	{
		if (shotPowerMultiplier <= 1.0f)
		{
			shotPowerMultiplier += value;
		}

		else
		{
			shotPowerMultiplier = 1.0f;
		}
		
	}

	float Character::GetShotPowerMultiplier()
	{
		return shotPowerMultiplier;
	}

	void Character::ResetPowerMultiplier()
	{
		shotPowerMultiplier = 0.0f;
	}

	sf::Vector3f Character::GetShotPower()
	{
		return shotPower;
	}
}