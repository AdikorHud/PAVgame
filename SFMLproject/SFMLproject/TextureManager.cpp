/*

#include "TextureManager.h"
#include <iostream>
using namespace std;

namespace tennis_game
{

	TextureManager::TextureManager()
		:
		surface(),
		elements(),
		character(),
		objects()
	{
		LoadTextures();

	}


	void TextureManager::LoadTextures()
	{
		if (!character.loadFromFile("Assets/Spritesheet/sheet_characters.png"))
		{
			std::cout << "ERROR! Missing character texture. Class: Character." << std::endl;
		}

		if (!surface.loadFromFile("Assets/Tilesheet/groundGravel.png"))
		{
			std::cout << "ERROR! Couldn't load Court texture. Class: Court." << std::endl;
		}

		if (!objects.loadFromFile("Assets/Tilesheet/elements.png"))
		{
			std::cout << "ERROR! Couldn't load Elements texture. Class: Court." << std::endl;
		}
	}


	TextureManager::~TextureManager()
	{
	}


	TextureManager* TextureManager::GetInstance()
	{
		if (instance == NULL)
		{
			instance = new TextureManager;
		}
		return instance;
	}

	sf::Texture* TextureManager::GetCharacterTexture()
	{
		return &sf::Texture();
	}

	sf::Texture* TextureManager::GetSurfaceTexture()
	{
		return &sf::Texture();
	}

	sf::Texture* TextureManager::GetBallTexture()
	{
		return &sf::Texture();
	}
}

*/