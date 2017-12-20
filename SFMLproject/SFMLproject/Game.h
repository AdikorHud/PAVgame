#pragma once
#include "Character.h"
#include "Input.h"
#include "Court.h"
#include "Ball.h"
#include "Physics.h"
#include "AI.h"
#include "Raquet.h"

#include <SFML\Graphics.hpp>
#include <iostream>
#include <STP\TMXLoader.hpp>


using namespace std;

namespace tennis_game
{
	class Game
	{
	public:
		Game();
		~Game();

		void NewGame();

		void Execute();

		void Update();
	};
}
