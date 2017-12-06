#pragma once
#include <SFML\Graphics.hpp>
using namespace std;

namespace tennis_game
{
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
}
