#pragma once
#ifndef STATE_HPP
#define STATE_HPP

#include<SFML/Graphics.hpp>

#include "StateIdentifiers.hpp"
#include "ResourceIdentifiers.hpp"
#include "../model/player.h"

#include <memory>
#include "music_player.hpp"
#include "sound_player.hpp"

class StateStack;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context 
	{
		Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player, MusicPlayer& music, SoundPlayer& sounds);

		sf::RenderWindow*		window;
		TextureHolder*			textures;
		FontHolder*						fonts;
		Player*							player;
		MusicPlayer*			music;
		SoundPlayer*			sounds;
	};

	public:
						State(StateStack& stack, Context context);
		virtual ~State();

		virtual void		draw() = 0;
		virtual bool		update(sf::Time dt) = 0;
		virtual bool		handleEvent(const sf::Event& event) = 0;

	protected:
		void					requestStackPush(States::ID stateID);
		void					requestStackPop();
		void					requestStateClear();

		Context					getContext() const;

	private:
		StateStack*				mStack;
		Context					mContext;
};

#endif // !STATE_HPP

