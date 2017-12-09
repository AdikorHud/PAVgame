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
		sf::Vector3<float> ballVelocity;
		sf::Vector2f ballPosition;
		sf::Texture ball;
		sf::Sprite yellowBall;
		bool isMovingBottom;

		void LoadTextures();

		void UpdatePosition(sf::Time elapsed);

		sf::Vector2f SetBallPosition();

		void SetScale();


	public:
		Ball();
		~Ball();

		sf::Sprite GetSprite();

		sf::Vector3<float> GetBallVelocity();

		void UpdateVelocity(sf::Vector3<float> velocity, sf::Time elapsed);

		void SetService(Character player);

		bool GetBallDirection();

		sf::Vector2f GetBallPosition();		

		void SetDirection(bool value);

	};
}