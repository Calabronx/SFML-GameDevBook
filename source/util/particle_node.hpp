#pragma once
#ifndef PARTICLENODE_HPP
#define PARTICLENODE_HPP

#include<SFML/Graphics.hpp>

#include "scene_node.hpp"
#include "particle.hpp"
#include "ResourceIdentifiers.hpp"

class ParticleNode : public SceneNode
{
public:
											ParticleNode(Particle::Type type, const TextureHolder& textures);
	
	void							addParticle(sf::Vector2f position);
	Particle::Type				getParticleType() const;
	virtual unsigned int	getCategory() const;

private:
	void					updateCurrent(sf::Time dt, CommandQueue&);
	void					drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void					addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const;
	void					computeVertices() const;


private:
	std::deque<Particle>	mParticles;
	const sf::Texture&		mTexture;
	Particle::Type			mType;

	mutable sf::VertexArray mVertexArray;
	mutable bool			mNeedsVertexUpdate;
};
#endif // !PARTICLENODE_HPP

