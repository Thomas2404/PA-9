#pragma once

#include "SFML/Graphics.hpp"

class Object : public sf::CircleShape
{
public:
	Object(sf::Vector2f startingPosition, float radius) : sf::CircleShape(radius)
	{
		this->setPosition(startingPosition);
		this->setOrigin(radius, radius);
	};



private:


};