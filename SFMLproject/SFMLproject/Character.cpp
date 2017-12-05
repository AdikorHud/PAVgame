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

/*
<SubTexture name="characterRed (1).png" x="147" y="93" width="21" height="31"/>
<SubTexture name="characterRed (10).png" x="168" y="31" width="21" height="31"/>
<SubTexture name="characterRed (11).png" x="57" y="186" width="19" height="13"/>
<SubTexture name="characterRed (12).png" x="38" y="186" width="19" height="13"/>
<SubTexture name="characterRed (13).png" x="0" y="186" width="19" height="13"/>
<SubTexture name="characterRed (14).png" x="19" y="186" width="19" height="13"/>
<SubTexture name="characterRed (2).png" x="147" y="155" width="21" height="31"/>
<SubTexture name="characterRed (3).png" x="126" y="31" width="21" height="31"/>
<SubTexture name="characterRed (4).png" x="168" y="0" width="21" height="31"/>
<SubTexture name="characterRed (5).png" x="147" y="62" width="21" height="31"/>
<SubTexture name="characterRed (6).png" x="147" y="31" width="21" height="31"/>
<SubTexture name="characterRed (7).png" x="147" y="0" width="21" height="31"/>
<SubTexture name="characterRed (8).png" x="63" y="155" width="21" height="31"/>
<SubTexture name="characterRed (9).png" x="84" y="0" width="21" height="31"/>
*/

sf::Sprite Character::Draw()
{
	body.setTexture(charTileset);
	body.setTextureRect(sf::IntRect(147, 93, 21, 31));

	leftArm.setTexture(charTileset);
	leftArm.setTextureRect(sf::IntRect(57, 186, 19, 13));
	
	rightArm.setTexture(charTileset);


	return sf::Sprite(body);
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
	body.move(-speed * elapsed.asSeconds(),0);
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

void Character::HitDrive()
{
}
