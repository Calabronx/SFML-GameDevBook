#pragma once

#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>

#include "resource_holder.hpp"
#include "scene_node.hpp"
#include "sprite_node.hpp"
#include "../model/aircraft.hpp"
#include "../input/command_queue.h"

#include <array>

namespace sf {
	class RenderWindow;
}

class World : private sf::NonCopyable {
public:
	explicit								World(sf::RenderWindow& window);
	void								update(sf::Time dt);
	void								draw();
	CommandQueue& getCommandQueue();

private:
	void								loadTextures();
	void								buildScene();
	void								adaptPlayerPosition();

private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};

private:
	sf::RenderWindow&					mWindow;
	sf::View							mWorldView;
	TextureHolder						mTextures;

	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;

	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	float								mScrollSpeed;
	Aircraft*							mPlayerAircraft;
	CommandQueue						mCommandQueue;

};

#endif // !WORLD_HPP
