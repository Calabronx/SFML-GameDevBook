#pragma once
#include <queue>

#include "Command.hpp"

#ifndef COMMAND_QUEUE_HPP
#define COMMAND_QUEUE_HPP


class CommandQueue
{
public:
	void		push(const Command& command);
	Command		pop();
	bool		isEmpty() const;

private:
	std::queue<Command> mQueue;

};
#endif // !COMMAND_QUEUE_HPP

