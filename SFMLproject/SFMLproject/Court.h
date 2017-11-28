#pragma once
#include <SFML\Graphics.hpp>

class Court
{
private:
	sf::Texture surface;
	sf::Texture objects;
	sf::Sprite courtSurface;
	sf::Sprite courtLines;

	void LoadCourtTextures();


public:
	Court();
	~Court();

	sf::Sprite DrawTerrain();

	sf::Sprite DrawLines();

	sf::Sprite DrawNet();

};

