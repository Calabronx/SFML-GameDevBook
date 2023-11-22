#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Window/Window.hpp>
#include "../input/command_queue.h"


class Player
{
public:
	void	handleEvent(const sf::Event& event, CommandQueue& commands);
	void	handleRealTimeInput(CommandQueue& commands);
};
#endif // !PLAYER_HPP

