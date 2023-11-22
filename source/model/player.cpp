#include "player.h"
#include "../util/category.hpp"

#include <iostream>
#include "aircraft.hpp"

struct AircraftMover
{
	AircraftMover(float vx, float vy)
		: velocity(vx, vy)
	{
	}

	void operator() (Aircraft& aircraft, sf::Time) const
	{
		Aircraft& aircraft = static_cast<Aircraft&>(aircraft);
		//aircraft.accelerate(velocity);
	}

	sf::Vector2f velocity;
};

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
	{
		Command output;
		output.category = Category::PlayerAircraft;
		output.action = [](SceneNode& s, sf::Time)
		{
			std::cout << s.getPosition().x << "," << s.getPosition().y << "\n";
		};
		commands.push(output);
	}
}

void Player::handleRealTimeInput(CommandQueue& commands)
{
	const float playerSpeed = 30.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Command moveLeft;
		moveLeft.category = Category::PlayerAircraft;
		moveLeft.action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.0f));
		commands.push(moveLeft);
	}
}
