#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>

class Raquet
{
private:
	sf::Vector2f raquetPosition;
	sf::Texture raquet;
	sf::Sprite metalRaquet;
	bool isPlayingAnimation;

	void LoadTextures();

public:
	Raquet();
	~Raquet();

	sf::Sprite GetSprite();

	void SetPosition(sf::Vector2f position);

	void UpdatePosition(sf::Vector2f position);

	void SetScale(float scale);

	void SetRotation(float rotation);

	void Rotate(float value);

	void SetAnimationStatus();

	void PlayAnimation();

};

