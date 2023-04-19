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