#include "Game.h"


using namespace std;

namespace tennis_game
{
	Game::Game()
	{
	}


	Game::~Game()
	{
	}

	void Game::NewGame()
	{


	}
	

	void Game::Execute()
	{
		sf::RenderWindow window(sf::VideoMode(640, 768), "Sport Game");		
		window.setFramerateLimit(60);

		tmx::TileMap clayCourt("Assets/TiledFiles/CourtSurface.tmx");

		//clayCourt.ShowObjects();
		//clayCourt.GetLayer();
		
		sf::Clock clock;
		Input gameInput;

		sf::RectangleShape powerUI(sf::Vector2f(50.0, 5.0));
		//Court court;

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
			AI::ProcessAI(player1, ball, elapsed);			
			gameInput.processInput(player2, elapsed);
			gamePhysics.UpdateBallVelocity(ball, elapsed);


			if (gamePhysics.CheckCollision(player1.GetRaquetSprite(), ball) && !ball.GetBallDirection()) //Falla cuando durante la animación de la raqueta.
			{
				ball.ChangeBallDirection();
				gamePhysics.SetBallVelocity(ball, player1.GetShotPower(), elapsed);
				player1.ResetPowerMultiplier();
			}

			if (gamePhysics.CheckCollision(player2.GetRaquetSprite(), ball)&& ball.GetBallDirection())
			{
				ball.ChangeBallDirection();
				gamePhysics.SetBallVelocity(ball, player2.GetShotPower(), elapsed);
				player2.ResetPowerMultiplier();
			}

					
			window.draw(clayCourt);

			window.draw(player1.GetSprite());
			window.draw(player2.GetSprite());

			window.draw(player1.GetRaquetSprite());
			window.draw(player2.GetRaquetSprite());

			window.draw(ball.GetSprite());


			//DEBUG
			powerUI.setPosition(275, 720);
			powerUI.setFillColor(sf::Color(255,255,0));
			powerUI.setOutlineThickness(2.0);
			powerUI.setOutlineColor(sf::Color());
			powerUI.setScale(player2.GetShotPowerMultiplier(), 1);
			window.draw(powerUI);

			window.display();

		}
	}


	void Game::Update()
	{



	}
}