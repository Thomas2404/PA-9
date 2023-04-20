#include "Boid.h"

Boid::Boid(sf::Vector2f startingPosition, sf::Vector2f startingVelocity, float radius)
{
	this->setPosition(startingPosition);
	this->velocity = startingVelocity;
	this->setRadius(radius);
}


void Boid::move(sf::Time deltaTime)
{
	this->setPosition(this->getPosition() + (this->velocity * deltaTime.asSeconds()));
}

void Boid::addVelocity(sf::Vector2f velocity)
{
	this->velocity += velocity;
}

void Boid::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

sf::Vector2f& Boid::getVelocity()
{
	return this->velocity;
}

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