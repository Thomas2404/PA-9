#pragma once

#include "Node.h"

// Contains a linked list of boids and controls them all
class BoidManager
{
public:
	BoidManager(Node* pHead = nullptr) {};

	// Inserts the given amount of boids the front of the linked list
	bool populateList(int amount);

	// Inserts a new node at the front of the linked list
	bool insert();


	Node* getHeadPtr();

private:
	int boidCount;

	Node* pHead;

};