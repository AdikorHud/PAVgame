#include "Game.h"
#include "Character.h"
#include "Input.h"
#include "Court.h"
#include "Ball.h"
#include "Physics.h"
#include "AI.h"
#include "Raquet.h"

#include <SFML\Graphics.hpp>
#include <iostream>
#include <tmxlite\Map.hpp>


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
		window.setFramerateLimit(60);

		
		tmx::Map court_tmx;
		if (!court_tmx.load("Assets/TiledFiles/CourtSurface.tmx"))
		{
			std::cout << "ERROR!" << std::endl;
		}

			
		
		sf::Clock clock;
		Input gameInput;
		Court court;

		Character player1(true);
		player1.SetStartingPosition(320, 68);
		player1.SetStartingRotation(90);

		//Raquet player1Raquet;
		//player1Raquet.SetPosition(player1.GetPlayerPosition());
		//player1Raquet.SetRotation(180);

		Character player2(false);
		player2.SetStartingPosition(300, 700);
		player2.SetStartingRotation(-90);
		/*
		Raquet player2Raquet;
		player2Raquet.SetPosition(player2.GetPlayerPosition());
		player2Raquet.SetRotation(0);
		*/

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

			AI::ProcessAI(player1, ball, elapsed);
			
			gameInput.processInput(player2, elapsed);
			

			//player1Raquet.UpdatePosition(player1.GetPlayerPosition());
			//player2Raquet.UpdatePosition(player2.GetPlayerPosition());

			if (gamePhysics.CheckCollision(player1.GetRaquetSprite(), ball))
			{
				ball.ChangeBallDirection();
				gamePhysics.SetBallVelocity(ball, player2.GetShotPower(), elapsed);
			}

			if (gamePhysics.CheckCollision(player2.GetRaquetSprite(), ball))
			{
				ball.ChangeBallDirection();
				gamePhysics.SetBallVelocity(ball, player2.GetShotPower(), elapsed);
			}

			gamePhysics.UpdateBallVelocity(ball, elapsed);


			//DEBUG
			sf::Sprite courtTest;
			/*
			for (int i = 0; i < court_tmx.getTileCount().x; i++)
			{
				for (int j = 0; j < court_tmx.getTileCount().y; j++)
				{
										
					window.draw(courtTest);
				}
			}

			*/
			//window.draw();
			//window.draw(court.DrawTerrain());
			//window.draw(court.DrawLines());
			

			window.draw(player1.GetSprite());
			window.draw(player2.GetSprite());

			window.draw(player1.GetRaquetSprite());
			window.draw(player2.GetRaquetSprite());


			window.draw(ball.GetSprite());

			window.display();

		}
	}


	void Game::Update()
	{



	}
}