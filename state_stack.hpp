#pragma once
#ifndef STATESTACK_HPP
#define STATESTACK_HPP

#include<SFML/Graphics.hpp>

#include "state_stack.hpp"
#include "state.hpp"


class StateStack : private sf::NonCopyable
{
public:
	enum Action
	{
		Push,
		Pop,
		Clear
	};

public:
	explicit StateStack(State::Context context);

	template <typename T>
	void registerState(States::ID stateID);

	void update(sf::Time dt);
	void draw();
	void handleEvent(const sf::Event& event);

	void pushState(States::ID stateID);
	void popState();
	void clearStates();

	bool isEmpty() const;

private:
	State::Ptr createState(States::ID stateID);
	void	   applyPendingChanges();

private:
	struct PendingChange
	{
		Action		action;
		States::ID	stateID;
	};
private:
	std::vector<State::Ptr>	mStack;
	std::vector<PendingChange> mPendingList;
	State::Context			 mContext;
	std::map<States::ID, std::binary_function<State::Ptr()>> mFactories;
};
#endif // !STATESTACK_HPP

template<typename T>
inline void StateStack::registerState(States::ID stateID)
{
	mFactories[stateID] = [this]()
	{
		return State::Ptr(new T(*this, mContext));
	};

	//mFactories[stateID] = State::Ptr(new T(*this, mContext)); otra manera de hacerlo me parece, si es que no necesita validar antes de asignar el objeto
	
}
