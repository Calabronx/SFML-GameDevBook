#include "state.hpp"

State::State(StateStack& stack, Context context)
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

Context State::getContext() const
{
    return Context();
}

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player)
{
}
