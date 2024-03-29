#include "label.hpp"
#include "../util/resource_holder.hpp"
#include "../util/resource_holder.inl"

GUI::Label::Label(const std::string& text, const FontHolder& fonts)
    : mText(text, fonts.get(Fonts::Main), 16)
{
}

bool GUI::Label::isSelectable() const
{
    return false;
}

void GUI::Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mText, states);
}

void GUI::Label::setText(const std::string& text)
{
    mText.setString(text);
}

void GUI::Label::handleEvent(const sf::Event& event)
{
}

