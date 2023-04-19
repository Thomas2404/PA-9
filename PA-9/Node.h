#pragma once

#include "Boid.h"

class Node
{
public:
	Node()
	{
		this->pNext = nullptr;
		this->pBoid = new Boid(*new sf::Vector2f(500, 500), 50, 300, 90);
	};

	void setNextPtr(Node* pNext);
	void setBoid(Boid* pBoid);

	Node* getNextPtr();
	Boid* getBoid();

private:
	Node* pNext;
	Boid* pBoid;
};