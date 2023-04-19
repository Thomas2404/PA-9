#include "Node.h"

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