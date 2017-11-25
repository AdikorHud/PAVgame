#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#ifdef DEBUG
#include <vld.h>
#endif // DEBUG
#include <iostream>

int main()
{	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game on!");
		
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Yellow);
	
	sf::Texture myTexture;
	sf::Sprite blueChar;
		
	
	if (!myTexture.loadFromFile("Assets/PNG/Blue/characterBlue (1).png"))
	{
		std::cout << "Error! No encontre una textura";
	}

	blueChar.setTexture(myTexture);


	sf::SoundBuffer myBuffer;
	sf::Sound mySound;

	if (!myBuffer.loadFromFile("Assets/Audio/click3.wav"))
	{
		std::cout << "Error! No encontre un audio";
		//return -1;
	}
	
	mySound.setBuffer(myBuffer);
	mySound.play();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}		
		
		window.clear();
		window.draw(blueChar);
		//window.draw(shape);
		window.display();
	}

	return 0;
}