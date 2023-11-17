#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include<SFML/Graphics.hpp>

class Entity
{
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
public:
	sf::Vector2f mVelocity;
};
#endif // !ENTITY_HPP

