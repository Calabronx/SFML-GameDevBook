#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include<SFML/Graphics.hpp>

#include "../util/scene_node.hpp"
#include "../input/command_queue.h"


class Entity : public SceneNode
{
public:
	explicit Entity(int hitpoints);
	void repair(int points);
	void damage(int points);
	void destroy();

	int getHitpoints() const;
	sf::FloatRect getBoundingRect() const;
	bool isDestroyed() const;

	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	void accelerate(sf::Vector2f velocity);
	void accelerate(float vx, float vy);
	sf::Vector2f getVelocity() const;

	virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
public:
	sf::Vector2f mVelocity;

private:
	int mHitpoints;
};
#endif // !ENTITY_HPP

