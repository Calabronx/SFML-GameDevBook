#pragma once
#ifndef GAME_OVER_STATE_HPP
#define GAME_OVER_STATE_HPP

#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "../view/container.hpp"

class GameOverState : public State
{
public:
								GameOverState(StateStack& stack, Context context);

	virtual void	draw();
	virtual bool	update(sf::Time dt);
	virtual bool	handleEvent(const sf::Event& event);

private:
	sf::Text	mGameOverText;
	sf::Time	mElapsedTime;
};

#endif // !GAME_OVER_STATE_HPP

