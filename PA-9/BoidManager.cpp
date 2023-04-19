#include "BoidManager.h"

bool BoidManager::populateList(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (!insert()) return false;
		this->boidCount++;
	}

	return true;
}

void BoidManager::drawBoids(sf::RenderWindow& window)
{
	Node* pCur = this->pHead;

	while (pCur != nullptr)
	{
		window.draw(*pCur->getBoid());

		pCur = pCur->getNextPtr();
	}
}

// Sets all the boids positions to random values off the screen.
void BoidManager::randomizePositions(const sf::Vector2u& windowSize)
{
	Node* pCur = this->pHead;
	float x, y;

	while (pCur != nullptr)
	{
		x = rand() % (int)windowSize.x + 1;
		x += ((int)windowSize.x + 100) * randomNegative();

		y = rand() % (int)windowSize.y + 1;
		y += ((int)windowSize.y + 100) * randomNegative();

		pCur->getBoid()->setPosition(sf::Vector2f(x , y));
		pCur = pCur->getNextPtr();
	}
}

int BoidManager::randomNegative()
{
	if (rand() % 2) return 1;

	return -1;
}

bool BoidManager::insert()
{
	Node* pMem = new Node();

	if (pMem == nullptr) return false;

	pMem->setNextPtr(this->pHead);
	this->pHead = pMem;

	this->boidCount++;

	return true;
}

Node* BoidManager::getHeadPtr()
{
	return this->pHead;
}

// BOID RULES

// Move boids towards their precieved center of the flock
sf::Vector2f& BoidManager::rule1(Boid boid)
{
	Node* pCur = this->pHead;
	sf::Vector2f* perceivedCenter;

	while (pCur != nullptr)
	{
		if (*pCur->getBoid() != boid)
		{
			*perceivedCenter += pCur->getBoid()->getPosition();
		}

		pCur = pCur->getNextPtr();
	}

	perceivedCenter->x /= (this->boidCount - 1);
	perceivedCenter->y /= (this->boidCount - 1);

	*perceivedCenter -= boid.getPosition();
	perceivedCenter->x /= 100;
	perceivedCenter->y /= 100;

	return (*perceivedCenter);
}