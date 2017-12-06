#include "Court.h"
#include <iostream>
using namespace std;

namespace tennis_game
{

	void Court::LoadCourtTextures()
	{
		if (!surface.loadFromFile("Assets/Tilesheet/groundGravel.png"))
		{
			std::cout << "ERROR! Couldn't load Court texture. Class: Court." << std::endl;
		}

		if (!objects.loadFromFile("Assets/Tilesheet/elements.png"))
		{
			std::cout << "ERROR! Couldn't load Elements texture. Class: Court." << std::endl;
		}
	}

	Court::Court()
	{
		Court::LoadCourtTextures();
	}


	Court::~Court()
	{
	}



	sf::Sprite Court::DrawTerrain()
	{
		courtSurface.setTexture(surface);
		courtSurface.setTextureRect(sf::IntRect(0, 0, 32, 32));
		courtSurface.setPosition(0.0f, 0.0f);
		courtSurface.setScale(20, 25);


		return sf::Sprite(courtSurface);
	}

	sf::Sprite Court::DrawLines()
	{
		courtLines.setTexture(surface);
		courtLines.setTextureRect(sf::IntRect(670, 5, 70, 115));
		courtLines.setPosition(0.0f, 0.0f);
		courtLines.setScale(7.5, 6.5);


		return sf::Sprite(courtLines);
	}

	sf::Sprite Court::DrawNet()
	{
		return sf::Sprite();
	}
}