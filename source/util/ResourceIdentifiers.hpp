#ifndef RESOURCEIDENTIFIERS_HPP
#define RESOURCEIDENTIFIERS_HPP

#include<SFML/Graphics.hpp>


// Forward declaration of SFML classes
namespace sf
{
	class Texture;
	class Font;
}

namespace Textures
{
	enum ID
	{
		Eagle,
		Raptor,
		Desert,
		Avenger,
		TitleScreen,
		ButtonNormal,
		ButtonSelected,
		ButtonPressed,
		Bullet,
		Missile
	};
}

namespace Fonts
{
	enum ID
	{
		Main,
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>	TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>				FontHolder;

#endif // BOOK_RESOURCEIDENTIFIERS_HPP