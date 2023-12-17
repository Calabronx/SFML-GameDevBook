#include "utility.hpp"

#include <cmath>
#include <cassert>

void centerOrigin(sf::Sprite& sprite)
{
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.0f), std::floor(bounds.top + bounds.height / 2.0f));
}

void centerOrigin(sf::Text& text)
{
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(std::floor(bounds.left + bounds.width / 2.0f), std::floor(bounds.top + bounds.height / 2.0f));
}

float toRadian(float degree)
{
	return 3.141592653589793238462643383f / 180.f * degree;
}

 float length(sf::Vector2f vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

 float toDegree(float radian)
 {
	 return 180.f / 3.141592653589793238462643383f * radian;
 }

 sf::Vector2f unitVector(sf::Vector2f vector)
{
	assert(vector != sf::Vector2f(0.f, 0.f));
	return vector / length(vector);
}

 float distance(const SceneNode& lhs, const SceneNode& rhs)
 {
	 return length(lhs.getWorldPosition() - rhs.getWorldPosition());
 }
