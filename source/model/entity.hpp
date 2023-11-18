#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include<SFML/Graphics.hpp>

#include "../util/scene_node.hpp"


class Entity : public SceneNode
{
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
public:
	sf::Vector2f mVelocity;

private:
	virtual void updateCurrent(sf::Time dt);
};
#endif // !ENTITY_HPP

