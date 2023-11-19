#pragma once
#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>

#include "../util/StringHelpers.hpp"
#include "../util/world.hpp"

class Game : private sf::NonCopyable
{
public:
											Game();
	void								run();

private:
	void								processEvents();
	void								update(sf::Time elapsedTime);
	void								render();

	void								updateStatistics(sf::Time elapsedTime);
	void								handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
private:
	static const float					PlayerSpeed;
	static const sf::Time				TimePerFrame;

	sf::RenderWindow					mWindow;
	World								mWorld;

	sf::Texture							mTexture;
	sf::Sprite							mPlayer;
	sf::Font							mFont;
	sf::Text							mStatisticsText;
	sf::Time							mStatisticsUpdateTime;

	std::size_t							mStatisticsNumFrames;
	bool							    mIsMovingUp;
	bool								mIsMovingDown;
	bool								mIsMovingRight;
	bool							    mIsMovingLeft;

};
#endif // !GAME_H



