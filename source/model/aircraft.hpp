#pragma once

#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include "entity.hpp"
#include "../util/resource_holder.hpp"
#include "../util/resource_holder.inl"
#include "../util/text_node.hpp"
#include "../input/command_queue.h"
#include "projectile.hpp"


class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
		Avenger,
		TypeCount
	};

public:
	float				getMaxSpeed() const;
	explicit							Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts);
	void				fire();
	void				launchMissile();
private:

	virtual unsigned int getCategory() const;

	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void		 updateTexts();
	void		 updateMovementPattern(sf::Time dt);
	void		 checkProjectileLaunch(sf::Time dt, CommandQueue& commands);

	void		 createBullets(SceneNode& node, const TextureHolder& textures) const;
	void		 createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const;
private:
	Type			mType;
	sf::Sprite		mSprite;
	TextNode*		mHealthDisplay;
	float		    mTravelledDistance;
	float		    mFireRateLevel;
	std::size_t		mDirectionIndex;
	bool			mIsFiring;
	bool			mIsLaunchingMissile;
	sf::Time		mFireCountdown;
	Command			mFireCommand;
	Command			mMissileCommand;
};
#endif // !AIRCRAFT_HPP

