#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#ifdef DEBUG
#include <vld.h>
#endif // DEBUG
#include <iostream>
#include "Game.h"

int main()
{
	Game myGame;
	myGame.Execute();

	return 0;
}