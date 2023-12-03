#include "loading_state.h"

LoadingState::LoadingState(StateStack& stack, Context context)
{
}

void LoadingState::draw()
{
}

bool LoadingState::update(sf::Time dt)
{
    return false;
}

bool LoadingState::handleEvent(const sf::Event& event)
{
    return false;
}

void LoadingState::setCompletion(float percent)
{
}
