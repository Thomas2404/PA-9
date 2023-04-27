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

#include "Test.h"
//#include "BoidManager.h"

int main(void)
{
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boid Simulation");
	sf::Event event;
	sf::Clock clock;
	sf::Time deltaTime;
	sf::Texture titlePNG;
	bool loadTitle = true; // while true, will display titlescreen and not boid
	bool foundPNG = true; // if PNG was loaded (tested later)

	BoidManager manager(200, 4, 0.025, 30, 0.012, 80, 0.004, 200, 0.5, 50, 30, 0.0001);

	Test test;
	test.runTest();

	// INITIALIZE BOIDS
	manager.init(window);

	// if Title Screen picture couldn't be loaded, say so in console and run
	// boid like normal
	if (!titlePNG.loadFromFile("assets/PA9_Title_Screen.png")) {
		// png can be found in the assets folder in the same directory the source files are found
		std::cout << "PA9_Title_Screen.png not found! Boid will skip title screen and run simulation." << std::endl;
		foundPNG = false;
	}


	while (window.isOpen())
	{

		deltaTime = clock.restart();


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed) {
				// if player pressed a key
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
					// if that player has pressed P specifically
					loadTitle = false; // stop loading titlescreen for rest of runtime
				}
			}
		}
		if (loadTitle == true && foundPNG == true) {
			// if title needs to be loaded AND it can be loaded
			sf::Sprite title;
			title.setTexture(titlePNG);
			window.clear();
			window.draw(title);
			window.display();
		}
		// if titlescreen isn't or can't be displayed
		else {
			// DRAW BOIDS
			window.clear();

			manager.drawBoids(window);

			window.display();


			// MOVE BOIDS
			manager.runSimulation(deltaTime, window);
		}
	}

	return 0;
}