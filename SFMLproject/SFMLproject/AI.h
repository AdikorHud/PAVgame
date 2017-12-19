#pragma once
#include "Character.h"
#include "Ball.h"
#include <SFML\System\Vector3.hpp>

using namespace std;

namespace tennis_game
{
	class AI
	{
	private:
		static void Movement(Character &player, Ball &ball, sf::Time elapsed);
		static void Hit(Character &player, Ball &ball, sf::Time elapsed);

	public:
		AI();
		~AI();


		static void ProcessAI(Character &player, Ball &ball, sf::Time elapsed);
	};
}


