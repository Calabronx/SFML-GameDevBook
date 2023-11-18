#include "aircraft.hpp"


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

Aircraft::Aircraft(Type type, const TextureHolder& textures)
	:mType(type), mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
