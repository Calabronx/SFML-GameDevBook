#pragma once
#ifndef SCENE_NODE_HPP
#define SCENE_NODE_HPP

#include "../input/Command.hpp"
#include "../input/command_queue.h"

#include<SFML/Graphics.hpp>
#include<memory>
#include<vector>

struct Command;
class CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode();
	void attachChild(Ptr child);
	void update(sf::Time dt, CommandQueue& commands);
	Ptr  detachChild(const SceneNode& node);

	sf::Transform							getWorldTransform() const;
	sf::Vector2f							getWorldPosition()	const;
	float									distance(const SceneNode& lhs, const SceneNode& rhs);

	void									removeWrecks();
	virtual sf::FloatRect getBoundingRect() const;

	void									onCommand(const Command& command, sf::Time dt);
	virtual bool	isMarkedForRemoval() const;
	virtual bool	isDestroyed() const;
	virtual unsigned int	getCategory() const;


private:
	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void	drawBoundingRect(sf::RenderTarget& target, sf::RenderStates) const;
	virtual void	updateCurrent(sf::Time dt, CommandQueue& commands);
	void			updateChildren(sf::Time dt, CommandQueue& commands);

	void				drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
};
#endif // !SCENE_NODE_HPP

