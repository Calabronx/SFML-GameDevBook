#pragma once
#ifndef BLOOM_EFFECT_HPP
#define BLOOM_EFFECT_HPP

#include "ResourceIdentifiers.hpp"
#include "resource_holder.hpp"
#include "post_effect.hpp"

#include <SFML/Graphics.hpp>

#include <array>

class BloomEffect : public PostEffect
{
public:
					BloomEffect();
	virtual void apply(const sf::RenderTexture& input, sf::RenderTarget& output);

private:
	typedef std::array<sf::RenderTexture, 2> RenderTextureArray;

private:
	void		prepareTextures(sf::Vector2u size);

	void		filterBright(const sf::RenderTexture& input, sf::RenderTexture& output);
	void		blurMultipass(RenderTextureArray& renderTextures);
	void		blur(const sf::RenderTexture& input, sf::RenderTexture& output, sf::Vector2f offsetFactor);
	void		downSample(const sf::RenderTexture& input, sf::RenderTexture& output);
	void		add(const sf::RenderTexture& source, const sf::RenderTexture& bloom, sf::RenderTarget& output);

private:
	ShaderHolder			mShaders;

	sf::RenderTexture		mBrightnessTexture;
	RenderTextureArray		mFirstPassTextures;
	RenderTextureArray		mSecondPassTextures;
};
#endif // !BLOOM_EFFECT_HPP

