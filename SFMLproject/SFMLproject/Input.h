#pragma once
#include <SFML\Window\Keyboard.hpp>
#include "Character.h"


class Input
{
public:
	Input();
	~Input();

	void processInput(Character &player, sf::Time elapsed);
};

