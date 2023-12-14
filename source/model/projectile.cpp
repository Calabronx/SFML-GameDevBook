#include "projectile.hpp"
#include "../util/DataTables.hpp"
#include "../util/utility.hpp"

namespace {
    const std::vector<ProjectileData> Table = initializeProjectileData();
}

Projectile::Projectile(Type type, const TextureHolder& textures)
    : Entity(1)
    , mType(type)
    , mSprite(textures.get(Table[type].texture))
    , mTargetDirection()
{
    centerOrigin(mSprite);
}

void Projectile::guideTowards(sf::Vector2f position)
{
    assert(isGuided());
    mTargetDirection = unitVector(position - getWorldPosition());
}

bool Projectile::isGuided() const
{
    return mType == Missile;
}

unsigned int Projectile::getCategory() const
{
    if (mType == EnemyBullet)
        return Category::EnemyProjectile;
    else
        return Category::AlliedProjectile;
}

sf::FloatRect Projectile::getBoundingRect() const
{
    return sf::FloatRect();
}

float Projectile::getMaxSpeed() const
{
    return 0.0f;
}

int Projectile::getDamage() const
{
    return 0;
}

void Projectile::updateCurrent(sf::Time dt, CommandQueue& commands)
{
}

void Projectile::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}
