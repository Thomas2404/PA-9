#pragma once

#include "Node.h"
#include "VectorUtility.h"
#include <time.h>

// Contains a linked list of boids and controls them all
class BoidManager
{
public:
	BoidManager(int boidCount, float boidRadius, float avoidFactor, float protectedRadius, float matchingFactor, float visibleRadius, float centeringFactor, 
		float screenMargin, float turnFactor, float maxSpeed, float minSpeed);


	// INITIALIZATION
	void init(sf::RenderWindow& window);
	bool insertAtFront(sf::Vector2f position, sf::Vector2f velocity, float radius);
	sf::Vector2f& randomPosition(sf::Vector2u windowSize);
	sf::Vector2f& randomVelocity();
	int randomNegative();

	// SIMULATION
	void drawBoids(sf::RenderWindow& window);

	void runSimulation(sf::Time deltaTime, sf::RenderWindow& window);

	// UTILITY
	float calculateDistance(sf::Vector2f v1, sf::Vector2f v2);


	// BOID RULES
	sf::Vector2f& separation(Boid& boid);
	sf::Vector2f& alignment(Boid& boid);
	sf::Vector2f& cohesion(Boid& boid);

	sf::Vector2f& screenEdges(sf::RenderWindow& window, Boid& boid);
	void speedLimits(Boid& boid);

private:
	Node* pHead;

	int boidCount;
	float boidRadius;
	float protectedRadius;
	float visibleRadius;
	float matchingFactor;
	float centeringFactor;
	float screenMargin;
	float turnFactor;
	float maxSpeed;
	float minSpeed;

	float avoidFactor;
};