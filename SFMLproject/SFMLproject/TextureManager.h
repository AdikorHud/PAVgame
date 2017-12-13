#pragma once
#include <SFML\Graphics.hpp>
using namespace std;

namespace tennis_game
{
	class TextureManager
	{
		
	private:

		TextureManager();
		
		static TextureManager* instance;

		//Court textures
		sf::Texture surface;
		sf::Texture elements;

		//Character textures
		sf::Texture character;

		//Ball Textures
		sf::Texture objects;

		void LoadTextures();

		
	public:
						
		~TextureManager();

		static TextureManager* GetInstance();

		sf::Texture* GetCharacterTexture();
		sf::Texture* GetSurfaceTexture();
		sf::Texture* GetBallTexture();

	};
}