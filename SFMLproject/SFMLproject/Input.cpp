#include "Input.h"
using namespace std;

namespace tennis_game
{
	Input::Input()
	{
	}

	Input::~Input()
	{
	}

	void Input::processInput(Character &player, sf::Time elapsed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			player.SetIsRunning(true);
			player.UpdateSpeed();
		}

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			player.SetIsRunning(false);
			player.UpdateSpeed();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player.MoveLeft(elapsed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.MoveRight(elapsed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.MoveUp(elapsed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.MoveDown(elapsed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.ShotDrive();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.ShotSlice();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.ShotLob();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.ShotDropshot();
		}
	}
}