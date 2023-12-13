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
	:Entity(Table[type].hitpoints)
	, mType(type)
	, mSprite(textures.get(Table[type].texture))
	, mFireCommand()
	, mMissileCommand()
	, mFireCountdown(sf::Time::Zero)
	, mIsFiring(false)
	, mIsLaunchingMissile(false)
	//, mIsMarkedForRemoval(false)
	, mFireRateLevel(1)
	/*, mSpreadLevel(1)
	, mMissileAmmo(2)
	, mDropPickupCommand()*/
	, mTravelledDistance(0.f)
	, mDirectionIndex(0)
	, mHealthDisplay(nullptr)
	/*, mMissileDisplay(nullptr)*/
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

	std::unique_ptr<TextNode> healthDisplay(new TextNode(fonts, ""));
	mHealthDisplay = healthDisplay.get();
	attachChild(std::move(healthDisplay));

	mFireCommand.category = Category::SceneAirLayer;
	mFireCommand.action = [this, &textures](SceneNode& node, sf::Time)
	{
		createBullets(node, textures);
	};

	mMissileCommand.category = Category::SceneAirLayer;
	mMissileCommand.action = [this, &textures](SceneNode& node, sf::Time)
	{
		createProjectile(node, Projectile::Missile, 0.f, 0.5f, textures);
	};

}

void Aircraft::fire()
{
}

void Aircraft::launchMissile()
{
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

void Aircraft::checkProjectileLaunch(sf::Time dt, CommandQueue& commands)
{
	// Check for automatic gunfire, allow only in intervals
	if (mIsFiring && mFireCountdown <= sf::Time::Zero)
	{
		// Interval expired: we can fire a new bullet
		commands.push(mFireCommand);
		mFireCountdown += Table[mType].fireInterval / (mFireRateLevel + 1.f);
		mIsFiring = false;
	}
	else if (mFireCountdown > sf::Time::Zero)
	{
		// interval not expired: Decrease it further
		mFireCountdown -= dt;
		mIsFiring = false;
	}

	// Check for missile launch
	if (mIsLaunchingMissile)
	{
		commands.push(mMissileCommand);
		mIsLaunchingMissile = false;
	}
}

void Aircraft::createBullets(SceneNode& node, const TextureHolder& textures) const
{
}

void Aircraft::createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const
{
}
