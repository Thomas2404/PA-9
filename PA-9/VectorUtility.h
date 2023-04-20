#pragma once

#include "SFML/Graphics.hpp"

class VectorUtility
{
public:


	float calculateDistance(sf::Vector2f v1, sf::Vector2f v2)
	{
		return std::sqrt(std::pow(v1.x - v2.x, 2) + std::pow(v1.y - v2.y, 2));
	}

};