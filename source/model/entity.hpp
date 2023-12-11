#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include<SFML/Graphics.hpp>

#include "../util/scene_node.hpp"


class Entity : public SceneNode
{
public:
	explicit Entity(int hitpoints);
	void repair(int points);
	void damage(int points);
	void destroy();

	int getHitpoints() const;
	bool isDestroyed() const;

	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	void accelerate(sf::Vector2f velocity);
	void accelerate(float vx, float vy);
	sf::Vector2f getVelocity() const;
public:
	sf::Vector2f mVelocity;

private:
	int mHitpoints;
	virtual void updateCurrent(sf::Time dt);
};
#endif // !ENTITY_HPP

