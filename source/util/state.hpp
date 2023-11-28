#pragma once
#ifndef STATE_HPP
#define STATE_HPP

#include<SFML/Graphics.hpp>

//#include "state_stack.hpp"
#include "StateIdentifiers.hpp"
#include "resource_holder.hpp"
#include "../model/player.h"

#include <memory>


class StateStack;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context 
	{
		Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player);

		sf::RenderWindow* window;
		TextureHolder* textures;
		FontHolder* fonts;
		Player* player;

		Context();
	};

public:
	State(StateStack& stack, Context context);
	State();
	virtual ~State();

	virtual void draw() = 0;
	virtual bool update(sf::Time dt) = 0;
	virtual bool handleEvent(const sf::Event& event) = 0;

protected:
	void requestStackPush(States::ID stateID);
	void requestStackPop();
	void requestStateClear();

	Context getContext() const;

private:
	StateStack* mStack;
	Context		mContext;
};
#endif // !STATE_HPP

