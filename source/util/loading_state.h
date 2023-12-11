#pragma once
#ifndef LOADINGSTATE_HPP
#define LOADINGSTATE_HPP

#include<SFML/Graphics/RectangleShape.hpp>
#include<SFML/Graphics/Text.hpp>

#include"resource_holder.hpp"
#include"ResourceIdentifiers.hpp"
#include "state.hpp"
#include "parallel_task.h"

class LoadingState : public State
{
public:

	LoadingState(StateStack& stack, Context context);
	
	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);

	void			setCompletion(float percent);

private:
	sf::Text					mLoadingText;
	sf::RectangleShape		mProgressBarBackground;
	sf::RectangleShape		mProgressBar;

	ParallelTask			mLoadingTask;
};
#endif // !LOADINGSTATE_HPP


