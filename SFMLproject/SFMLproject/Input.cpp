#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

void Input::processInput(Character &player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.MoveLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.MoveRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.MoveUp();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.MoveDown();
	}
}
