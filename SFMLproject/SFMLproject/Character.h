#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>
#include <iostream>
#include "Raquet.h"

using namespace std;

namespace tennis_game
{
	class Character
	{
	private:
		const float baseSpeed = 130.0f;
		const float maxSpeed = 200.0f;
		const float runningSpeedIncremental = 0.5f;
		float speed = baseSpeed;
		bool isRunning = false;
		bool isAIControlled = false;

		float drivePower;
		float lobPower;
		float slicePower;
		float dropShotPower;

		float shotPowerMultiplier;

		sf::Vector3f shotPower;

		Raquet raquet;


		sf::Texture charTileset;
		sf::Sprite body;
		sf::Sprite leftArm;
		sf::Sprite rightArm;
		sf::Sprite leftLeg;
		sf::Sprite rightLeg;


		void LoadTextures();


	public:
		Character(bool isAIControlled);
		~Character();


		sf::Sprite GetSprite();

		sf::Sprite GetRaquetSprite();

		void SetStartingPosition(float posX, float posY);

		sf::Vector2<float> GetPlayerPosition();

		void SetStartingRotation(float rotation);

		void SetIsRunning(bool value);

		void UpdateSpeed();


		//INPUT
		void MoveLeft(sf::Time elapsed);

		void MoveRight(sf::Time elapsed);

		void MoveUp(sf::Time elapsed);

		void MoveDown(sf::Time elapsed);

		void ShotDrive();

		void ShotSlice();

		void ShotLob();

		void ShotDropshot();

		//SHOTS
		void SetShotPower(sf::Vector3f value);

		void SetShotPowerMultiplier(float value);

		float GetShotPowerMultiplier();

		void ResetPowerMultiplier();

		sf::Vector3f GetShotPower();

	};
}
