/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	Boid algorithim referenced from:
		https://vanhunteradams.com/Pico/Animal_Movement/Boids-algorithm.html


	An implementation of the boid algorithm, a way to simulate the
	movements of a flock of birds or school of fish.

	Group Members:
		Thomas Wilme - Lab Section 2
		Matthew Hill - Lab Section 2
		Samantha Brewer - Lab Section 2
		Jayden Blewett - Lab Section 2

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "BoidManager.h"

int main(void)
{
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boid Simulation");
	sf::Event event;
	sf::Clock clock;
	sf::Time deltaTime;

	BoidManager manager(300, 2, 0.02, 30, 0.005, 70, 0.004, 200, 0.3, 50, 30);

	// INITIALIZE BOIDS
	manager.init(window);


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

		window.display();


		// MOVE BOIDS
		manager.runSimulation(deltaTime, window);
	}

	return 0;
}