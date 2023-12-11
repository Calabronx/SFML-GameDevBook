#pragma once

#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include "entity.hpp"
#include "../util/resource_holder.hpp"
#include "../util/resource_holder.inl"
#include "../util/text_node.hpp"


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
private:

	virtual unsigned int getCategory() const;

	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void		 updateTexts();
	void		 updateMovementPattern(sf::Time dt);
private:
	Type			mType;
	sf::Sprite		mSprite;
	TextNode*		mHealthDisplay;
	float			mTravelledDistance;
	std::size_t		mDirectionIndex;
};
#endif // !AIRCRAFT_HPP

