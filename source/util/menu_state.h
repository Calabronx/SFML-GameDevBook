#pragma once
#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SFML/Graphics.hpp>

#include "state.hpp"

class MenuState : public State
{
public:
											MenuState(StateStack& stack, Context context);

	virtual void				draw();
	virtual bool				update(sf::Time dt);
	virtual bool				handleEvent(const sf::Event& event);

	void							updateOptionText();


private:
	enum OptionNames
	{
		Play,
		Exit,
	};

private:
	sf::Sprite						mBackgroundSprite;

	std::vector<sf::Text> mOptions;
	std::size_t						mOptionIndex;


};
#endif // !MENUSTATE_HPP

