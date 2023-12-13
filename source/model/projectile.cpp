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
{
    centerOrigin(mSprite);
}

void Projectile::guideTowards(sf::Vector2f position)
{
}

bool Projectile::isGuided() const
{
    return false;
}

unsigned int Projectile::getCategory() const
{
    return 0;
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
}
