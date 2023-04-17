#include "Object.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boid Simulation");


	Object o1(sf::Vector2f(450, 450), 50);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(o1);
		window.display();
	}




	return 0;
}