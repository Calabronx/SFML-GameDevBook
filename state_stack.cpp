#include "state_stack.hpp"

#include<cassert>

StateStack::StateStack(State::Context context)
{
}

void StateStack::update(sf::Time dt)
{
}

void StateStack::draw()
{
}

void StateStack::handleEvent(const sf::Event& event)
{
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if (!(*itr)->handleEvent(event))
			return;
	}

	applyPendingChanges();
}

void StateStack::pushState(States::ID stateID)
{
	for (PendingChange change : mPendingList)
	{
		switch (change.action)
		{
			case Push:
				mStack.push_back(createState(change.stateID));
				break;
			case Pop:
				mStack.pop_back();
				break;
			case Clear:
				mStack.clear();
				break;
			default:
				break;
		}
	}

	mPendingList.clear();
}

void StateStack::popState()
{
}

void StateStack::clearStates()
{
}

bool StateStack::isEmpty() const
{
	return mStack.empty();
}

State::Ptr StateStack::createState(States::ID stateID)
{
	auto found = mFactories.find(stateID);
	assert(found != mFactories.end());

	return found->second();
}

void StateStack::applyPendingChanges()
{
}
