#include "Node.h"

Node::Node(sf::Vector2f position, sf::Vector2f velocity, float radius, int biasGroup)
{
	this->pBoid = new Boid(position, velocity, radius, biasGroup);
	this->pNext = nullptr;
}

void Node::setNextPtr(Node* pNext)
{
	this->pNext = pNext;
}
void Node::setBoid(Boid* pBoid)
{
	this->pBoid = pBoid;
}

Node* Node::getNextPtr()
{
	return this->pNext;
}
Boid* Node::getBoid()
{
	return this->pBoid;
}