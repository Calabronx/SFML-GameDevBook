#include "scene_node.hpp"
#include <cassert>

SceneNode::SceneNode()
{
}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

 SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	 auto found = std::find_if(mChildren.begin(), mChildren.end(),
		 [&](Ptr& p) -> bool { return p.get() == &node; });

	 assert(found != mChildren.end());

	 SceneNode::Ptr result = std::move(*found);
	 result->mParent = nullptr;
	 mChildren.erase(found);
	 return result;
}
