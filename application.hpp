#pragma once
#ifndef APPLICATION_HPP
#define APPLICATION_HH

#include<SFML/Graphics.hpp>
#include "source/util/resource_holder.hpp"
#include "source/model/player.h"
#include "state_stack.hpp"
#include "StateIdentifiers.hpp"


class Application
{

public:
	Application();
	void run();
private:
	void processInput();
	void update(sf::Time dt);
	void render();

	void updateStatistics(sf::Time dt);
	void registerStates();

private:
	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow;
	TextureHolder    mTextures;
	FontHolder          mFonts;
	Player				mPlayer;

	StateStack          mStateStack;

	sf::Text			mStatisticsText;
	sf::Time            mStatisticsUpdateTime;
	std::size_t         mStatisticsNumFrames;
};
#endif // !APPLICATION_HPP

