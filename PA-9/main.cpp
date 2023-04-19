#include "BoidManager.h"


// start loop
	// draw boids
	// move boids
// end loop;

int main(void)
{
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boid Simulation");
	sf::Event event;
	sf::Clock clock;
	sf::Time deltaTime;


	Object o1(sf::Vector2f(500, 500), 50);
	BoidManager manager;

	// INITIALIZE BOIDS
	manager.populateList(10);
	manager.randomizePositions(window.getSize());

	// initialize boids

	while (window.isOpen())
	{
		deltaTime = clock.restart();


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		

		// DRAW BOIDS
		window.clear();

		manager.drawBoids(window);
		window.draw(o1);

		window.display();


		// MOVE BOIDS

		
	}




	return 0;
}