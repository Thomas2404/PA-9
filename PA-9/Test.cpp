#include "Test.h"

// Runs all the test functions.
void Test::runTest()
{
	testInit();
	testBoidColorConstructor();
	testRandomBiasGroups();
	testDistanceFunction();
}

// Testing of the BoidManager.init function. Tests if the correct number of nodes are created.
void Test::testInit()
{
	BoidManager testManager(5, 2, 0.02, 30, 0.005, 70, 0.004, 200, 0.3, 50, 30, 0.001);
	sf::RenderWindow testWindow(sf::VideoMode(1000, 1000), "Test Window");
	testManager.init(testWindow);

	Node* pCur = testManager.getHeadPtr();
	int nodeCount = 0;

	while (pCur != nullptr)
	{
		nodeCount++;
		pCur = pCur->getNextPtr();
	}

	if (nodeCount == 5) std::cout << "Test init passed." << std::endl;
	else std::cout << "Test init failed" << std::endl;
}

// Testing of the random color feature in the Boid constructor. Tests to make sure that random colors are applied.
void Test::testBoidColorConstructor()
{
	Boid b1(sf::Vector2f(0, 0), sf::Vector2f(0, 0), 2, 0);
	Boid b2(sf::Vector2f(0, 0), sf::Vector2f(0, 0), 2, 0);
	Boid b3(sf::Vector2f(0, 0), sf::Vector2f(0, 0), 2, 0);

	if (b1.getFillColor() == b2.getFillColor() && b2.getFillColor() == b3.getFillColor()) std::cout << "Test boid color constructor failed." << std::endl;
	else std::cout << "Test boid color constructor passed." << std::endl;
}

// Testing to make sure that boids are assigned bias groups.
void Test::testRandomBiasGroups()
{
	BoidManager testManager(30, 2, 0.02, 30, 0.005, 70, 0.004, 200, 0.3, 50, 30, 0.001);
	sf::RenderWindow testWindow(sf::VideoMode(1000, 1000), "Test Window");
	testManager.init(testWindow);

	Node* pCur = testManager.getHeadPtr();
	int biasCount = 0;

	while (pCur != nullptr)
	{
		if (pCur->getBoid()->getBiasGroup() != 0) biasCount++;

		pCur = pCur->getNextPtr();
	}

	if (biasCount != 0) std::cout << "Test bias group assignment passed." << std::endl;
	else std::cout << "Test bias group assignment failed." << std::endl;
}

// Tests the calculateDistance utility function to make sure it calculates the right values.
void Test::testDistanceFunction()
{
	BoidManager testManager(30, 2, 0.02, 30, 0.005, 70, 0.004, 200, 0.3, 50, 30, 0.001);
	sf::Vector2f v1(0, 0), v2(5, 0); // expected distance = 5
	float distance = 0.f;

	distance = testManager.calculateDistance(v1, v2);

	if (distance == 5.f) std::cout << "Test distance calculation passed." << std::endl;
	else std::cout << "Test distance calculation failed" << std::endl;
}