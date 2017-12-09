#pragma once
#include <SFML\Graphics.hpp>
using namespace std;

namespace tennis_game
{
	class TextureManager
	{
	private:
		//Court textures
		sf::Texture surface;
		sf::Texture elements;

		//Character textures
		sf::Texture charTileset;

		//Ball Textures
		sf::Texture objects;




	public:
		TextureManager();
		~TextureManager();

		void LoadTextures();

		static sf::Texture GetCharacterTexture();
		sf::Texture GetSurfaceTexture();
		sf::Texture GetBallTexture();

	};
}
