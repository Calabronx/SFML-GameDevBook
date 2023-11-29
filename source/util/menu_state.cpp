#include "menu_state.h"

MenuState::MenuState(StateStack& stack, Context context)
	: State(stack, context)
	, mOptions()
	, mOptionIndex(0)
{
	sf::Font& font = context.fonts->get(Fonts::Main);

	sf::Text playOption;
	playOption.setFont(font);
	playOption.setString("Play");
	//centerOrigin(playOption);
	playOption.setPosition(context.window->getView().getSize() / 2.f);
	mOptions.push_back(playOption);

	updateOptionText();
}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);

	for (const sf::Text& text : mOptions)
		window.draw(text);
}

bool MenuState::update(sf::Time dt)
{
	return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
	if (event.key.code == sf::Keyboard::Return)
	{
		if (mOptionIndex == Play)
		{
			requestStackPop();
			requestStackPush(States::Game);
		}
		else if (mOptionIndex == Exit)
		{
			requestStackPop();
		}
	}

	if (event.key.code == sf::Keyboard::Up)
	{
		if (mOptionIndex > 0)
			mOptionIndex--;
		else
			mOptionIndex = mOptions.size() - 1;

		updateOptionText();
	}
	else if (event.key.code == sf::Keyboard::Down)
	{
		if (mOptionIndex < mOptions.size() - 1)
			mOptionIndex++;
		else
			mOptionIndex = 0;

		updateOptionText();
	}

	return true;
}

void MenuState::updateOptionText()
{
	if (mOptions.empty())
		return;

	//white all texts
	for (sf::Text& text : mOptions)
		text.setFillColor(sf::Color::White);

	mOptions[mOptionIndex].setFillColor(sf::Color::Red);
}