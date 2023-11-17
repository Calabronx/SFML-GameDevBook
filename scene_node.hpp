#pragma once
#ifndef SCENE_NODE_HPP
#define SCENE_NODE_HPP

#include<memory>
#include <vector>


class SceneNode
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode();
	void attachChild(Ptr child);
	Ptr  detachChild(const SceneNode& node);

private:
	std::vector<Ptr> mChildren;
	SceneNode*		 mParent;
};
#endif // !SCENE_NODE_HPP

