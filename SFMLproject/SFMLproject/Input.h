#pragma once
#include <SFML\Window\Keyboard.hpp>
#include "Character.h"
using namespace std;

namespace tennis_game
{
	class Input
	{
	public:
		Input();
		~Input();

		void processInput(Character &player, sf::Event event, sf::Time elapsed);
	};
}
