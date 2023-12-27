#include "particle_node.hpp"
#include "DataTables.hpp"

namespace 
{
	const std::vector<ParticleData> Table = initializeParticleData();
}

ParticleNode::ParticleNode(Particle::Type type, const TextureHolder& textures)
	: SceneNode()
	, mParticles()
	, mTexture(textures.get(Textures::Particle))
	, mType(type)
	, mVertexArray(sf::Quads)
	, mNeedsVertexUpdate(true)
{
}

void ParticleNode::updateCurrent(sf::Time dt, CommandQueue&)
{
	while (!mParticles.empty() && mParticles.front().lifeTime <= sf::Time::Zero)
		mParticles.pop_front();

	for (Particle& particle : mParticles)
		particle.lifeTime -= dt;

	mNeedsVertexUpdate = true;
}

void ParticleNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (mNeedsVertexUpdate)
	{
		computeVertices();
		mNeedsVertexUpdate = false;
	}

	states.texture = &mTexture;

	target.draw(mVertexArray, states);
}

void ParticleNode::addParticle(sf::Vector2f position)
{
	Particle particle;
	particle.position = position;
	particle.color = Table[mType].color;
	particle.lifeTime = Table[mType].lifeTime;

	mParticles.push_back(particle);
}

Particle::Type ParticleNode::getParticleType() const
{
	return mType;
}

void ParticleNode::computeVertices() const
{
	sf::Vector2f size(mTexture.getSize());
	sf::Vector2f half = size / 2.f;

	mVertexArray.clear();

	for (const Particle& particle : mParticles)
	{
		sf::Vector2f pos = particle.position;
		sf::Color color = particle.color;

		float ratio = particle.lifeTime.asSeconds() / Table[mType].lifeTime.asSeconds();
		color.a = static_cast<sf::Uint8>(255 * std::max(ratio, 0.f));

		addVertex(pos.x - half.x, pos.y - half.y, 0.f,		0.f,	color);
		addVertex(pos.x + half.x, pos.y - half.y, size.x,	0.f,	color);
		addVertex(pos.x + half.x, pos.y + half.y, size.x,	size.y, color);
		addVertex(pos.x - half.x, pos.y + half.y, 0.f,		size.y, color);
	}
}

void ParticleNode::addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const
{
	sf::Vertex vertex;
	vertex.position = sf::Vector2f(worldX, worldY);
	vertex.texCoords = sf::Vector2f(texCoordX, texCoordY);
	vertex.color = color;

	mVertexArray.append(vertex);
}

unsigned int ParticleNode::getCategory() const
{
	return Category::ParticleSystem;
}
