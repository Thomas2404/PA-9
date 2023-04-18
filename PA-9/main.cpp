#include "Boid.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boid Simulation");
	sf::Event event;
	sf::Clock clock;
	sf::Time deltaTime;


	Object o1(sf::Vector2f(500, 500), 50);
	Boid b1(sf::Vector2f(500, 500), 25, 100, 90);



	// initialize boids

	// start loop
		// draw boids
		// move boids
	// end loop


	while (window.isOpen())
	{
		deltaTime = clock.restart();


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}




		window.clear();


		window.draw(b1);

		b1.move(deltaTime, 1000);
		b1.turn(deltaTime, 5);


		window.display();
	}




	return 0;
}