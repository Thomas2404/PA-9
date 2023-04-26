#include "Test.h"

void Test::runTest()
{
	testInit();
}


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