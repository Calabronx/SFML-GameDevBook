#pragma once

#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>

#include "ResourceIdentifiers.hpp"
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
	explicit								World(sf::RenderWindow& window, FontHolder& fonts);
	void								update(sf::Time dt);
	void								draw();
	CommandQueue& getCommandQueue();

private:
	void								loadTextures();
	void								buildScene();
	void								adaptPlayerPosition();
	void								spawnEnemies();
	void								addEnemies();
	void								addEnemy(Aircraft::Type type, float relX, float relY);
	void								adaptPlayerVelocity();
	void								destroyEntitiesOutsideView();
	void								guideMissiles();
	void								handleCollisions();

	bool								hasAlivePlayer() const;
	bool								matchesCategories(SceneNode::Pair& pair, Category::Type type1, Category::Type type2);
	sf::FloatRect				getViewBounds() const;
	sf::FloatRect				getBattlefieldBounds() const;

private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};

	struct SpawnPoint
	{
		SpawnPoint(Aircraft::Type type, float x, float y)
		: type(type)
		, x(x)
		, y(y)
		{
		}

		Aircraft::Type type;
		float		   x;
		float		   y;
	};

private:
	sf::RenderWindow&					mWindow;
	sf::View							mWorldView;
	TextureHolder						mTextures;
	FontHolder&							mFonts;

	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;

	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	float								mScrollSpeed;
	Aircraft*							mPlayerAircraft;
	CommandQueue						mCommandQueue;

	std::vector <SpawnPoint>		mEnemySpawnPoints;
	std::vector <Aircraft*>			mActiveEnemies;

};

#endif // !WORLD_HPP
