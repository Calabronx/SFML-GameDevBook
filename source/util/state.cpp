#include "state.hpp"
#include "state_stack.hpp"

State::State(StateStack& stack, Context context)
    :mStack(&stack)
    ,mContext(context)

{
}

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player)
    : window(&window), textures(&textures), fonts(&fonts), player(&player)
{
}

State::Context::Context()
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
    mStack->pushState(stateID);
}

void State::requestStackPop()
{
    mStack->popState();
}

void State::requestStateClear()
{
    mStack->clearStates();
}

State::Context State::getContext() const
{
    return mContext;
}

