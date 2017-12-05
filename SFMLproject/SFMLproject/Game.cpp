#include "Game.h"
#include "Character.h"
#include "Input.h"
#include "Court.h"
#include "Ball.h"
#include "Physics.h"

#include <SFML\Graphics.hpp>
#include <iostream>
#include <STP\TMXLoader.hpp>



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
	
	Character player1;
	player1.SetStartingPosition(320, 68);
	player1.SetStartingRotation(90);

	Character player2;
	player2.SetStartingPosition(320, 700);
	player2.SetStartingRotation(-90);

	Ball ball;
	ball.SetService(player1);

	Physics gamePhysics;
	

	/*
	sf::SoundBuffer myBuffer;
	sf::Sound mySound;

	if (!myBuffer.loadFromFile("Assets/Audio/click3.wav"))
	{
	std::cout << "Error! No encontre un audio";
	//return -1;
	}

	mySound.setBuffer(myBuffer);
	mySound.play();
	*/


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

		gamePhysics.UpdateBallVelocity(ball);
		gamePhysics.CheckCollision(player2, ball);

		window.draw(court.DrawTerrain());
		window.draw(court.DrawLines());

		window.draw(player1.Draw());
		window.draw(player2.Draw());

		window.draw(ball.Draw());

		window.display();
		
	}
}



