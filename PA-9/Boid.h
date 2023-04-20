#pragma once

#include "SFML/Graphics.hpp"

class Boid : public sf::CircleShape
{
public:
	Boid(sf::Vector2f startingPosition, sf::Vector2f startingVelocity, float radius);

	void move(sf::Time deltaTime);
	void addVelocity(sf::Vector2f velocity);
	void setVelocity(sf::Vector2f velocity);

	sf::Vector2f& getVelocity();

	bool operator==(const Boid& other);
	bool operator!=(const Boid& other);

private:
	sf::Vector2f velocity;
};