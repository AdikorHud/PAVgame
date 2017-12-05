#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>
#include <iostream>


class Character
{
private:
	const float baseSpeed = 130.0f;
	const float maxSpeed = 200.0f;
	const float runningSpeedIncremental = 0.5f;
	float speed = baseSpeed;
	bool isRunning = false;
	
	
	sf::Texture charTileset;
	sf::Sprite body;
	sf::Sprite leftArm;
	sf::Sprite rightArm;
	sf::Sprite leftLeg;
	sf::Sprite rightLeg;


	void LoadTextures();


public:
	Character();
	~Character();

	sf::Sprite Draw();

	void SetStartingPosition(float posX, float posY);

	sf::Vector2<float> GetPlayerPosition();

	void SetStartingRotation(float rotation);

	void SetIsRunning(bool value);

	void UpdateSpeed();

	void MoveLeft(sf::Time elapsed);

	void MoveRight(sf::Time elapsed);

	void MoveUp(sf::Time elapsed);

	void MoveDown(sf::Time elapsed);

	void HitDrive();

};

