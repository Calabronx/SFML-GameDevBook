#include "button.hpp"
#include "../util/utility.hpp"
#include "../util/resource_holder.hpp"
#include "../util/resource_holder.inl"

GUI::Button::Button(State::Context context)
    :mCallback()
    , mSprite(context.textures->get(Textures::Buttons))
    , mText("", context.fonts->get(Fonts::Main), 16)
    , mSounds(*context.sounds)
    , mIsToggle(false)
{
    //mSprite.setTexture(mNormalTexture);
    changeTexture(Normal);

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
    //mSprite.setTexture(mSelectedTexture);
    changeTexture(Selected);
}

void GUI::Button::deselect()
{
    Component::deselect();
    //mSprite.setTexture(mNormalTexture);
    changeTexture(Normal);
}

void GUI::Button::activate()
{
    Component::activate();

    if (mIsToggle)
        //mSprite.setTexture(mPressedTexture);
        changeTexture(Pressed);

    if (mCallback)
        mCallback();

    if (!mIsToggle)
        deactivate();

    mSounds.play(SoundEffect::Button);
}

void GUI::Button::deactivate()
{
    Component::deactivate();

    if (mIsToggle)
    {
        // reset texture to right one depending on if we are selected or not
        if (isSelected())
            //mSprite.setTexture(mSelectedTexture);
            changeTexture(Selected);
        else
            //mSprite.setTexture(mNormalTexture);
            changeTexture(Normal);
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

void GUI::Button::changeTexture(Type buttonType)
{
    sf::IntRect textureRect(0, 50 * buttonType, 200, 50);
    mSprite.setTextureRect(textureRect);
}
