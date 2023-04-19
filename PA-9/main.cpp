#include "BoidManager.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boid Simulation");
	sf::Event event;
	sf::Clock clock;
	sf::Time deltaTime;


	Object o1(sf::Vector2f(500, 500), 50);
	BoidManager manager;

	manager.populateList(10);

	// initialize boids

	// start loop
		// draw boids
		// move boids
	// end loop;


	while (window.isOpen())
	{
		deltaTime = clock.restart();


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(*manager.getHeadPtr()->getBoid());
		(*manager.getHeadPtr()->getBoid()).move(deltaTime, 1000);
		(*manager.getHeadPtr()->getBoid()).turn(deltaTime, 5);


		window.display();
	}




	return 0;
}