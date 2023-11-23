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


	mActionBinding[MoveLeft].action = [](SceneNode& node, sf::Time dt) {
		node.move(-playerSpeed * dt.asSeconds(), 0.0f);
	};

	mActionBinding[MoveRight].action = [](SceneNode& node, sf::Time dt)
	{
		node.move(playerSpeed * dt.asSeconds(), 0.0f);
	};

	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

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

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Command moveLeft;
		moveLeft.category = Category::PlayerAircraft;
		moveLeft.action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.0f));
		commands.push(moveLeft);
	}*/
	for (auto pair : mKeyBinding) {
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealTimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	return sf::Keyboard::Key();
}

bool Player::isRealTimeAction(Action action)
{
	return false;
}
