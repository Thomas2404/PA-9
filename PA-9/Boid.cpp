#include "Boid.h"

Boid::Boid(sf::Vector2f startingPosition, sf::Vector2f startingVelocity, float radius, int biasGroup)
{
	int r = rand() % 255;
	int g = rand() % 255;
	int b = rand() % 255;

	this->setPosition(startingPosition);
	this->velocity = startingVelocity;
	this->setRadius(radius);
	this->setFillColor(sf::Color(r, g, b));
	this->biasGroup = biasGroup;
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

int Boid::getBiasGroup()
{
	return this->biasGroup;
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