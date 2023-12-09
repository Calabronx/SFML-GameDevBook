#include "button.hpp"
#include "../util/utility.hpp"



GUI::Button::Button(const FontHolder& fonts, const TextureHolder& textures)
    :mCallback()
    , mNormalTexture(textures.get(Textures::ButtonNormal))
    , mSelectedTexture(textures.get(Textures::ButtonSelected))
    , mPressedTexture(textures.get(Textures::ButtonPressed))
    , mSprite()
    , mText("", fonts.get(Fonts::Main), 16)
    , mIsToggle(false)
{
    mSprite.setTexture(mNormalTexture);

    sf::FloatRect bounds = mSprite.getLocalBounds();
    mText.setPosition(bounds.width / 2.0f, bounds.height / 2.0f);
}

bool GUI::Button::isSelectable() const
{
    return true;
}

void GUI::Button::setCallback(Callback callback)
{
    mCallback = std::move(callback);
}

void GUI::Button::setText(const std::string& text)
{
    mText.setString(text);
    centerOrigin(mText);
}

void GUI::Button::setToggle(bool flag)
{
    mIsToggle = flag;
}


void GUI::Button::select()
{
    Component::select();
    mSprite.setTexture(mSelectedTexture);
}

void GUI::Button::deselect()
{
    Component::deselect();
    mSprite.setTexture(mNormalTexture);
}

void GUI::Button::activate()
{
    Component::activate();

    if (mIsToggle)
        mSprite.setTexture(mPressedTexture);

    if (mCallback)
        mCallback();

    if (!mIsToggle)
        deactivate();
}

void GUI::Button::deactivate()
{
    Component::deactivate();
    if (mIsToggle)
    {
        // reset texture to right one depending on if we are selected or not
        if (isSelected())
            mSprite.setTexture(mSelectedTexture);
        else
            mSprite.setTexture(mNormalTexture);
    }
}

void GUI::Button::handleEvent(const sf::Event& event)
{
}

void GUI::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mSprite, states);
    target.draw(mText, states);
}
