#pragma once

#include "Object.h"

// I'll clean up this code later, put all the fuctions here so I could get the window up and running


class Boid : public Object
{
public:
	Boid()
	{
		this->viewDistance = 100;
		this->fov = 90;
		this->velocity = 1.f;
		this->direction = 0.f;
		this->setRadius(10);
	}
	Boid(sf::Vector2f startingPosition, float radius, float viewDistance, float fov) : Object(startingPosition, radius)
	{
		this->viewDistance = viewDistance;
		this->fov = fov;

		this->velocity = .7f;
		this->direction = 0.f;
	};

	void move(sf::Time deltaTime, float speed)
	{
		float x = std::cos(this->direction) * speed * deltaTime.asSeconds() + this->getPosition().x,
			y = std::sin(this->direction) * speed * deltaTime.asSeconds() + this->getPosition().y;

		sf::Vector2f newPosition(x, y);

		this->setPosition(newPosition);


		
	}

	void turn(sf::Time deltaTime, float degrees)
	{
		float rotation = degrees * deltaTime.asSeconds();

		this->direction += rotation;
	}

private:
	float viewDistance;
	float fov;

	float velocity;
	float direction; // keeps track of direction in degrees (mod 360)

	

};