#pragma once

#include "Node.h"
#include "Time.h"

// Contains a linked list of boids and controls them all
class BoidManager
{
public:
	BoidManager(Node* pHead = nullptr) {};

	// Inserts the given amount of boids the front of the linked list
	bool populateList(int amount);

	void drawBoids(sf::RenderWindow& window);

	void randomizePositions(const sf::Vector2u& windowSize);
	int randomNegative();

	// Inserts a new node at the front of the linked list
	bool insert();

	Node* getHeadPtr();


	// BOID RULES

		// Move boids towards their precieved center of the flock
		sf::Vector2f& rule1(Boid boid);

private:
	int boidCount;

	Node* pHead;

};