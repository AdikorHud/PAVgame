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

	void LoadTextures();

public:
	Raquet();
	~Raquet();

	sf::Sprite GetSprite();

	void SetPosition(sf::Vector2f position);

	void UpdatePosition(sf::Vector2f position);

	void SetScale(float scale);

	void SetRotation(float rotation);

};

