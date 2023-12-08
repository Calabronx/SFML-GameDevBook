#pragma once
#ifndef SETTINGSSTATE_HPP
#define SETTINGSSTATE_HPP

#include <SFML/Graphics.hpp>
#include <array>
#include "state.hpp"
#include "../model/player.h"
#include "../view/container.hpp"
#include "../view/button.hpp"
#include "../view/label.hpp"

class SettingsState : public State 
{
public:
	SettingsState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);

private:
	void updateLabels();
	void addButtonLabel(Player::Action action, float y, const std::string& text, Context context);

private:
	sf::Sprite	mBackgroundSprite;
	GUI::Container	mGUIContainer;
	std::array<GUI::Button::Ptr, Player::ActionCount>  mBindingButtons;
	std::array<GUI::Label::Ptr, Player::ActionCount> mBindingLabels;
};

#endif // !SETTINGSSTATE_HPP

