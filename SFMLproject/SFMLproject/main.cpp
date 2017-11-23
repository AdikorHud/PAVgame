#include <SFML/Graphics.hpp>
#include <vld.h>
#include <iostream>

int main()
{	
	sf::Texture myTexture;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game on!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Yellow);
	
	sf::Sprite mySheet;
	mySheet.setTexture(myTexture);

	if (!myTexture.loadFromFile("Assets/Spritesheet/sheet_characters.png"))
	{
		std::cout << "Error! No encontre una textura";
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		

		window.clear();
		window.draw(mySheet);
		//window.draw(shape);
		window.display();
	}

	return 0;
}