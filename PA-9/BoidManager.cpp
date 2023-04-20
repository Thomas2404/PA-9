#include "BoidManager.h"

BoidManager::BoidManager(int boidCount = 0, float boidRadius = 5, float avoidFactor = 0.001, float protectedRadius = 20, float matchingFactor = 0.001, 
	float visibleRadius = 100, float centeringFactor = 0.001, float screenMargin = 100, float turnFactor = 0.001, float maxSpeed = 6, float minSpeed = 3)
{
	this->pHead = nullptr;
	this->boidCount = boidCount;
	this->boidRadius = boidRadius;
	this->avoidFactor = avoidFactor;
	this->protectedRadius = protectedRadius;
	this->matchingFactor = matchingFactor;
	this->visibleRadius = visibleRadius;
	this->centeringFactor = centeringFactor;
	this->screenMargin = screenMargin;
	this->turnFactor = turnFactor;
	this->maxSpeed = maxSpeed;
	this->minSpeed = minSpeed;
}

void BoidManager::init(sf::RenderWindow& window)
{
	for (int i = 0; i < this->boidCount; i++)
	{
		insertAtFront(randomPosition(window.getSize()), randomVelocity(), this->boidRadius);
	}
}

bool BoidManager::insertAtFront(sf::Vector2f position, sf::Vector2f velocity, float radius)
{
	Node* pMem = new Node(position, velocity, radius);

	if (pMem == nullptr) return false;

	pMem->setNextPtr(this->pHead);
	this->pHead = pMem;

	return true;
}

sf::Vector2f& BoidManager::randomPosition(sf::Vector2u windowSize)
{
	sf::Vector2f* randomPosition = new sf::Vector2f();

	randomPosition->x = rand() % windowSize.x;
	randomPosition->y = rand() % windowSize.y;

	return *randomPosition;
}

sf::Vector2f& BoidManager::randomVelocity()
{
	sf::Vector2f* randomVelocity = new sf::Vector2f();

	randomVelocity->x = (rand() % 100 + 1) * randomNegative();
	randomVelocity->y = (rand() % 100 + 1) * randomNegative();

	return *randomVelocity;
}

int BoidManager::randomNegative()
{
	if (rand() % 2) return 1;
	return -1;
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

void BoidManager::runSimulation(sf::Time deltaTime, sf::RenderWindow& window)
{
	Node* pCur = this->pHead;
	sf::Vector2f r1, r2, r3, pushBack, total;

	while (pCur != nullptr)
	{
		r1 = sf::Vector2f();
		r2 = sf::Vector2f();
		r3 = sf::Vector2f();
		pushBack = sf::Vector2f();

		r1 = separation(*pCur->getBoid());
		r2 = alignment(*pCur->getBoid());
		r3 = cohesion(*pCur->getBoid());
		pushBack = screenEdges(window, *pCur->getBoid());

		total = (r1 + r2 + r3 + pushBack);

		pCur->getBoid()->addVelocity(total);
		speedLimits(*pCur->getBoid());
		pCur->getBoid()->move(deltaTime);

		pCur = pCur->getNextPtr();
	}
}



// UTILITY
float BoidManager::calculateDistance(sf::Vector2f v1, sf::Vector2f v2)
{
	return std::sqrt(std::pow(v2.x - v1.x, 2) + std::pow(v2.y - v1.y, 2));
}



// BOID RULES
sf::Vector2f& BoidManager::separation(Boid& boid)
{
	Node* pCur = this->pHead;
	sf::Vector2f velocity = sf::Vector2f();

	while (pCur != nullptr)
	{
		if (*pCur->getBoid() != boid && calculateDistance(pCur->getBoid()->getPosition(), boid.getPosition()) < this->protectedRadius)
		{
			velocity += (boid.getPosition() - pCur->getBoid()->getPosition());
		}

		pCur = pCur->getNextPtr();
	}

	velocity *= this->avoidFactor;

	return velocity;
}

sf::Vector2f& BoidManager::alignment(Boid& boid)
{
	Node* pCur = this->pHead;
	sf::Vector2f velocityAverage = sf::Vector2f();
	int visibleBoids = 0;

	while (pCur != nullptr)
	{
		if (*pCur->getBoid() != boid && calculateDistance(pCur->getBoid()->getPosition(), boid.getPosition()) < this->visibleRadius)
		{
			velocityAverage += pCur->getBoid()->getVelocity();
			visibleBoids++;
		}

		pCur = pCur->getNextPtr();
	}

	if (visibleBoids == 0) return velocityAverage;

	velocityAverage /= (float)visibleBoids;
	velocityAverage -= boid.getVelocity();
	velocityAverage *= this->matchingFactor;

	return velocityAverage;
}

sf::Vector2f& BoidManager::cohesion(Boid& boid)
{
	Node* pCur = this->pHead;
	sf::Vector2f centeringAverage = sf::Vector2f();
	int visibleBoids = 0;

	while (pCur != nullptr)
	{
		if (*pCur->getBoid() != boid && calculateDistance(pCur->getBoid()->getPosition(), boid.getPosition()) < this->visibleRadius)
		{
			centeringAverage += pCur->getBoid()->getPosition();
			visibleBoids++;
		}

		pCur = pCur->getNextPtr();
	}

	if (visibleBoids == 0) return centeringAverage;

	centeringAverage /= (float)visibleBoids;
	centeringAverage -= boid.getPosition();
	centeringAverage *= this->centeringFactor;

	return centeringAverage;
}

sf::Vector2f& BoidManager::screenEdges(sf::RenderWindow& window, Boid& boid)
{
	sf::Vector2f pushBack = sf::Vector2f();
	sf::Vector2f position = boid.getPosition();

	if (position.x < this->screenMargin) pushBack.x += this->turnFactor;
	if (position.x > window.getSize().x - this->screenMargin) pushBack.x -= this->turnFactor;
	if (position.y < this->screenMargin) pushBack.y += this->turnFactor;
	if (position.y > window.getSize().y - this->screenMargin) pushBack.y -= this->turnFactor;

	return pushBack;
}

void BoidManager::speedLimits(Boid& boid)
{
	float speed = std::sqrt(boid.getVelocity().x * boid.getVelocity().x + boid.getVelocity().y * boid.getVelocity().y);

	if (speed > this->maxSpeed)
	{
		boid.setVelocity((boid.getVelocity() / speed) * this->maxSpeed);
	}
	if (speed < this->minSpeed)
	{
		boid.setVelocity((boid.getVelocity() / speed)*  this->minSpeed);
	}
}