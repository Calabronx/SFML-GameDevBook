#pragma once
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>
#include "scene_node.hpp"

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
float		 toDegree(float radian);
sf::Vector2f unitVector(sf::Vector2f vector);
float		 distance(const SceneNode& lhs, const SceneNode& rhs);

//#include"utility.inl"
#endif // !UTILITY_HPP
