#include "player.h"
#include "../util/category.hpp"

#include <iostream>
#include "aircraft.hpp"

const float Player::playerSpeed = 200.0f;

struct AircraftMover
{
	AircraftMover(float vx, float vy)
		: velocity(vx, vy)
	{
	}

	void operator() (Aircraft& aircrft, sf::Time) const
	{
		Aircraft& aircraft = static_cast<Aircraft&>(aircrft);
		aircraft.accelerate(velocity);
	}

	sf::Vector2f velocity;
};

Player::Player()
{
	mKeyBinding[sf::Keyboard::Left]	 = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Up]	 = MoveUp;
	mKeyBinding[sf::Keyboard::Down]  = MoveDown;

	initializeActions();

	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		Command output;
		output.category = Category::PlayerAircraft;
		output.action = [](SceneNode& s, sf::Time)
		{
			std::cout << "X: " << s.getPosition().x << ", Y: " << s.getPosition().y << "\n";
		};
		commands.push(output);
	}
}

void Player::handleRealTimeInput(CommandQueue& commands)
{
	for (auto pair : mKeyBinding) {
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealTimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}

void Player::initializeActions()
{
	const float playerSpeed = 200.0f;

	mActionBinding[MoveLeft].action  = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.0f));
	mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.0f));
	mActionBinding[MoveUp].action    = derivedAction<Aircraft>(AircraftMover(0.0f, -playerSpeed));
	mActionBinding[MoveDown].action  = derivedAction<Aircraft>(AircraftMover(0.0f, +playerSpeed));
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	for (auto pair : mKeyBinding) {
		if (pair.second == action)
			return pair.first;
	}
	return sf::Keyboard::Unknown;
}

bool Player::isRealTimeAction(Action action)
{
	switch (action)
	{
		case MoveLeft:
		case MoveRight:
		case MoveDown:
		case MoveUp:
				return true;

		default:
				return false;
	}
}
