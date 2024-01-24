#pragma once
#ifndef SOUNDPLAYER_HPP
#define SOUNDPLAYER_HPP

#include <list>

#include "resource_holder.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>


class SoundPlayer : private sf::NonCopyable
{
public:
							SoundPlayer();
			void			play(SoundEffect::ID effect);
			void			play(SoundEffect::ID effect, sf::Vector2f position);

			void			removeStoppedSounds();
			void			setListenerPosition(sf::Vector2f position);
			sf::Vector2f	getListenerPosition() const;
private:
	SoundBufferHolder			mSoundBuffers;
	std::list<sf::Sound>		mSounds; 
};
#endif // !SOUNDPLAYER_HPP

