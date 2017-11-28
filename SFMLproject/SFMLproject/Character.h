#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


class Character
{
private:
	sf::Texture charTileset;
	sf::Sprite charBody;

public:
	Character();
	~Character();

	sf::Sprite Draw();

	void SetStartingPosition(float posX, float posY);

	void SetStartingRotation(float rotation);

	void MoveLeft();

	void MoveRight();

	void MoveUp();

	void MoveDown();


};

