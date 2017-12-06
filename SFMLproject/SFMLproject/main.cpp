#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#ifdef DEBUG
#include <vld.h>
#endif // DEBUG
#include "Game.h"
using namespace tennis_game;

int main()
{
	Game myGame;
	myGame.Execute();

	return 0;
}
