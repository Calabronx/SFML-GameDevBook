#pragma once
#ifndef TITLESTATE_HPP
#define TITLESTATE_HPP

#include<SFML/Graphics.hpp>

#include "state.hpp"

class TitleState : public State
{
public:
	TitleState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);

private:
	sf::Sprite  mBackgroundSprite;
	sf::Text    mText;

	bool		mShowText;
	sf::Time	mTextEffectTime;
};
#endif // !TITLESTATE_HPP

