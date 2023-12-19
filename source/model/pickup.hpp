#ifndef PICKUP_HPP
#define PICKUP_HPP

#include "entity.hpp"
#include "../util/ResourceIdentifiers.hpp"

#include <SFML/Graphics.hpp>
#include "aircraft.hpp"

class Pickup : public Entity
{
public:
	enum Type
	{
		HealthRefill,
		MissileRefill,
		FireSpread,
		FireRate,
		TypeCount
	};
public:
							Pickup(Type type, const TextureHolder& textures);

	virtual unsigned int	getCategory() const;
	virtual sf::FloatRect	getBoundingRect() const;

	void					apply(Aircraft& player) const;

protected:
	virtual void    drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type			mType;
	sf::Sprite		mSprite;
};
#endif // !PICKUP_HPP