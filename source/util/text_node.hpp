#pragma once
#ifndef TEXTNODE_HPP
#define TEXTNODE_HPP

#include<SFML/Graphics.hpp>
#include "resource_holder.hpp"
#include "ResourceIdentifiers.hpp"
#include "scene_node.hpp"

class TextNode : public SceneNode
{
public:
	explicit TextNode(const FontHolder& fonts, const std::string& text);
	void	 setString(const std::string& text);

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Text mText;
};
#endif // !TEXTNODE_HPP

