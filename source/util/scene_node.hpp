#pragma once
#ifndef SCENE_NODE_HPP
#define SCENE_NODE_HPP

#include<SFML/Graphics.hpp>

#include<memory>
#include <vector>


class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode();
	void attachChild(Ptr child);
	void update(sf::Time dt);
	Ptr  detachChild(const SceneNode& node);

	sf::Transform	getWorldTransform() const;
	sf::Vector2f	getWorldPosition()	const;

private:
	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void	updateCurrent(sf::Time dt);
	void			updateChildren(sf::Time dt);
	
	void				drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Ptr> mChildren;
	SceneNode*		 mParent;
};
#endif // !SCENE_NODE_HPP

