#include "Game.h"
#include "Character.h"
#include "Input.h"
#include "Court.h"
#include "Ball.h"
#include "Physics.h"

#include <SFML\Graphics.hpp>
#include <iostream>
//#include <STP\TMXLoader.hpp>
using namespace std;

namespace tennis_game
{
	Game::Game()
	{
	}


	Game::~Game()
	{
	}

	void Game::Execute()
	{
		sf::RenderWindow window(sf::VideoMode(640, 768), "Sport Game");

		//tmx::TileMap map("C:/Users/Playstation/Desktop/CourtSurface.tmx");
		//map.ShowObjects();

		sf::Clock clock;
		Input gameInput;
		Court court;

		Character player1(true);
		player1.SetStartingPosition(320, 68);
		player1.SetStartingRotation(90);

		Character player2(false);
		player2.SetStartingPosition(300, 700);
		player2.SetStartingRotation(-90);

		Ball ball;
		ball.SetService(player1);

		Physics gamePhysics;


		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();

			sf::Time elapsed = clock.restart();

			gameInput.processInput(player2, elapsed);

			gamePhysics.UpdateBallVelocity(ball, elapsed);
			gamePhysics.CheckCollision(player1, ball, elapsed);
			gamePhysics.CheckCollision(player2, ball, elapsed);

			window.draw(court.DrawTerrain());
			window.draw(court.DrawLines());

			window.draw(player1.Draw());
			window.draw(player2.Draw());

			window.draw(ball.Draw());

			window.display();

		}
	}
}