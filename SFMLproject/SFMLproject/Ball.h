#pragma once
#include <SFML\System\Vector3.hpp>
#include <SFML\Graphics.hpp>
#include "Character.h"
using namespace std;

namespace tennis_game
{
	class Ball
	{
	private:
		sf::Vector3f ballVelocity;
		sf::Vector3f ballPosition;
		sf::Texture ball;
		sf::Sprite yellowBall;
		bool isMovingBottom;

		void LoadTextures();

		void UpdatePosition(sf::Time elapsed);

		void SetScale();


	public:
		Ball();
		~Ball();

		sf::Sprite GetSprite();

		sf::Vector3f GetVelocity();

		void SetVelocity(sf::Vector3f velocity, sf::Time elapsed);

		void SetService(Character player);

		bool GetBallDirection();

		void ChangeBallDirection();

		sf::Vector3f GetBallPosition();		

		void SetDirection(bool value);

	};
}