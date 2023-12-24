#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Window/Window.hpp>
#include "../input/command_queue.h"


class Player
{
public:
	enum Action {
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		ActionCount,
		Fire,
		LaunchMissile

	};

	enum MissionStatus {
		MissionRunning,
		MissionSuccess,
		MissionFailure
	};

public:
								Player();


	void					handleEvent(const sf::Event& event, CommandQueue& commands);
	void					handleRealTimeInput(CommandQueue& commands);

	void					assignKey(Action action, sf::Keyboard::Key key);

	void					setMissionStatus(MissionStatus status);
	MissionStatus			getMissionStatus() const;

	void					initializeActions();
	sf::Keyboard::Key	getAssignedKey(Action action) const;

private:
	static bool			isRealTimeAction(Action action);

private:
	std::map<sf::Keyboard::Key, Action>			mKeyBinding;
	std::map<Action, Command>							mActionBinding;
	MissionStatus												mCurrentMissionStatus;
    static const float playerSpeed;

};
#endif // !PLAYER_HPP

