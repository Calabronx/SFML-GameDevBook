#include "aircraft.hpp"

#include "../util/utility.hpp"
#include "../util/category.hpp"
#include"../util/DataTables.hpp"
#include "../util/StringHelpers.hpp"


namespace
{
	const std::vector<AircraftData> Table = initializeAircraftData();
}

Textures::ID toTextureID(Aircraft::Type type) {
	switch (type)
	{
	case Aircraft::Eagle:
		return Textures::Eagle;
	case Aircraft::Raptor:
		return Textures::Raptor;
	}
	return Textures::Eagle;
}

float Aircraft::getMaxSpeed() const
{
	return Table[mType].speed;
}

Aircraft::Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts)
	:Entity(Table[type].hitpoints), mType(type), mSprite(textures.get(toTextureID(type))), mHealthDisplay(nullptr)
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

	std::unique_ptr<TextNode> healthDisplay(new TextNode(fonts, ""));
	mHealthDisplay = healthDisplay.get();
	attachChild(std::move(healthDisplay));

}


unsigned int Aircraft::getCategory() const
{
	switch (mType)
	{
		case Eagle:
			return Category::PlayerAircraft;
		default:
			return Category::EnemyAircraft;
	}
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

void Aircraft::updateTexts()
{
	mHealthDisplay->setString(toString(getHitpoints()) + " HP");
	mHealthDisplay->setPosition(0.f, 50.f);
	mHealthDisplay->setRotation(-getRotation());
}

void Aircraft::updateMovementPattern(sf::Time dt)
{
	const std::vector<Direction>& directions = Table[mType].directions;
	if (!directions.empty()) {
		float distanceToTravel = directions[mDirectionIndex].distance;
		if (mTravelledDistance > distanceToTravel)
		{
			mDirectionIndex = (mDirectionIndex + 1) % directions.size();
			mTravelledDistance = 0.0f;
		}
		float radians = toRadian(directions[mDirectionIndex].angle + 90.f);
		float vx = getMaxSpeed() * std::cos(radians);
		float vy = getMaxSpeed() * std::sin(radians);
		setVelocity(vx, vy);
		mTravelledDistance += getMaxSpeed() * dt.asSeconds();
	}
}
