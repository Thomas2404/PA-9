#pragma once

#include "Boid.h"

class Node
{
public:
	Node(Node* pNext = nullptr, Boid* pBoid = nullptr) {};
	Node(sf::Vector2f position, sf::Vector2f velocity, float radius);

	void setNextPtr(Node* pNext);
	void setBoid(Boid* pBoid);

	Node* getNextPtr();
	Boid* getBoid();

private:
	Node* pNext;
	Boid* pBoid;
};