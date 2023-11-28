#include "state.hpp"

State::State(StateStack& stack, Context context)
    :mStack(&stack), mContext(context)
{
}

State::State()
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
}

void State::requestStackPop()
{
}

void State::requestStateClear()
{
}

State::Context State::getContext() const
{
    return mContext;
}

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player)
    : window(&window), textures(&textures), fonts(&fonts), player(&player)
{
}

State::Context::Context()
{
}
