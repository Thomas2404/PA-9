#include "Boid.h"

bool Boid::operator==(const Boid& other)
{
	if (this->getPosition() == other.getPosition()
		&& this->getOutlineColor() == other.getOutlineColor()
		&& this->getRadius() == other.getRadius())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Boid::operator!=(const Boid& other)
{
	return !(*this == other);
}