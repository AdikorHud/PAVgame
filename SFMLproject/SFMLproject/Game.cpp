#include "Game.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Input.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Execute()
{
	sf::RenderWindow window(sf::VideoMode(600, 800), "Sport Game");

	Input gameInput;
	
	Character player1;
	player1.SetStartingPosition(300, 50);
	player1.SetStartingRotation(90);

	Character player2;
	player2.SetStartingPosition(300, 750);
	player2.SetStartingRotation(-90);
	

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
		
		gameInput.processInput(player2);
		//player2.MoveRight(); //TEST for Player movement
		window.draw(player1.Draw());
		window.draw(player2.Draw());
		window.display();
		
	}
}



