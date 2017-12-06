#include "TextureManager.h"
#include <iostream>
using namespace std;

namespace tennis_game
{
	void TextureManager::LoadTextures()
	{
		if (!charTileset.loadFromFile("Assets/Spritesheet/sheet_characters.png"))
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

	TextureManager::TextureManager()
	{
		LoadTextures();

	}


	TextureManager::~TextureManager()
	{
	}
}