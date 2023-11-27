#include "application.hpp"
#include "title_state.hpp"
#include "menu_state.h"
#include "game_state.hpp"
#include "pause_state.hpp"

Application::Application()
	:mWindow(sf::VideoMode(640, 480), "States", sf::Style::Close)
	, mTextures()
	, mFonts()
	, mPlayer()
	, mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer))
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
{
	mWindow.setKeyRepeatEnabled(false);

	mFonts.load(Fonts::Main, "Media/Sansation.ttf");
	mTextures.load(Textures::TitleScreen, "Media/Textures/TitleScreen.png");

	mStatisticsText.setFont(mFonts.get(Fonts::Main));
	mStatisticsText.setPosition(5.0f, 5.0f);
	mStatisticsText.setCharacterSize(10u);

	registerStates();

	mStateStack.pushState(States::Title);
}

void Application::run()
{

	if (mStateStack.isEmpty())
		mWindow.close();
}

void Application::processInput()
{
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		mStateStack.handleEvent(event);
	}
}

void Application::update(sf::Time dt)
{
	mStateStack.update(dt);
}

void Application::render()
{
	mWindow.clear();

	mStateStack.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);

	mWindow.display();
}

void Application::updateStatistics(sf::Time dt)
{
}

void Application::registerStates()
{
	mStateStack.registerState<TitleState>(States::Title);
	mStateStack.registerState<MenuState>(States::Menu);
	mStateStack.registerState<GameState>(States::Game);
	mStateStack.registerState<PauseState>(States::Pause);
}
