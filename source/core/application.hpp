#pragma once
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

#include "../util/resource_holder.hpp"
#include "../util/ResourceIdentifiers.hpp"
#include "../model/player.h"
#include "../util/state_stack.hpp"
#include "../util/music_player.hpp"

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

	SoundPlayer			mSounds;
	MusicPlayer			mMusic;
	StateStack          mStateStack;

	sf::Text			mStatisticsText;
	sf::Time            mStatisticsUpdateTime;
	std::size_t         mStatisticsNumFrames;
};
#endif // !APPLICATION_HPP

