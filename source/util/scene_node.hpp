#pragma once
#ifndef SCENE_NODE_HPP
#define SCENE_NODE_HPP

#include "../input/Command.hpp"
#include "../input/command_queue.h"

#include<SFML/Graphics.hpp>
#include<memory>
#include<vector>
#include <set>

struct Command;
class CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;
	typedef std::pair<SceneNode*, SceneNode*> Pair;

public:
	SceneNode();
	SceneNode(Category::Type category);
	void attachChild(Ptr child);
	void update(sf::Time dt, CommandQueue& commands);
	Ptr  detachChild(const SceneNode& node);

	sf::Transform							getWorldTransform() const;
	sf::Vector2f							getWorldPosition()	const;
	float									distance(const SceneNode& lhs, const SceneNode& rhs);

	void									removeWrecks();

	void								onCommand(const Command& command, sf::Time dt);
	virtual unsigned int	getCategory() const;
	void								checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
	void								checkSceneCollision(SceneNode& node, std::set<Pair>& collisionPairs);
	virtual sf::FloatRect getBoundingRect() const;
	virtual bool					isMarkedForRemoval() const;
	virtual bool					isDestroyed() const;


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
	Category::Type   mDefaultCategory;
};
	bool	collision(const SceneNode& lhs, const SceneNode& rhs);
	float	distance(const SceneNode& lhs, const SceneNode& rhs);
#endif // !SCENE_NODE_HPP

