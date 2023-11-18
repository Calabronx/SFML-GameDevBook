#pragma once

#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include "entity.hpp"
#include "../util/resource_holder.hpp"
#include "../util/resource_holder.inl"


class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};
public:
	explicit  Aircraft(Type type, const TextureHolder& textures);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	Type	   mType;
	sf::Sprite mSprite;
};
#endif // !AIRCRAFT_HPP

