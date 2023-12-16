#pragma once
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>

namespace sf {
	class Sprite;
	class Text;
}

template<typename T>
std::string toString(const T& value);

void		 centerOrigin(sf::Sprite& sprite);
void		 centerOrigin(sf::Text& text);
float		 toRadian(float degree);
float		 length(sf::Vector2f vector);
sf::Vector2f unitVector(sf::Vector2f vector);

//#include"utility.inl"
#endif // !UTILITY_HPP
