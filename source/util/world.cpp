#include "world.hpp"
#include "resource_holder.hpp"

World::World(sf::RenderWindow& window, FontHolder& fonts)
	: mWindow(window)
	, mWorldView(window.getDefaultView())
	, mFonts(fonts)
	, mTextures()
	, mSceneGraph()
	, mSceneLayers()
	, mWorldBounds(0.0f, 0.0f, mWorldView.getSize().x, 2000.0f)
	, mSpawnPosition(mWorldView.getSize().x / 2.0f, mWorldBounds.height - mWorldView.getSize().y / 2.0f)
	, mScrollSpeed(-50.0f)
	, mPlayerAircraft(nullptr)
{
	loadTextures();
	buildScene();

	// prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	mWorldView.move(0.0f, mScrollSpeed * dt.asSeconds());
	mPlayerAircraft->setVelocity(0.0f, 0.0f);

	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	if (velocity.x != 0.0f && velocity.y != 0.0f)
		mPlayerAircraft->setVelocity(velocity / std::sqrt(2.0f));

	mPlayerAircraft->accelerate(0.0f, mScrollSpeed);

	if (position.x <= mWorldBounds.left + 150 || position.x >= mWorldBounds.left + mWorldBounds.width - 150)
	{
		velocity.x = -velocity.x;
		mPlayerAircraft->setVelocity(velocity);
	}

	// Forward commands to the scene graph
	while (!mCommandQueue.isEmpty())
		mSceneGraph.onCommand(mCommandQueue.pop(), dt);

	// Regular update step
	mSceneGraph.update(dt);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}

void World::loadTextures()
{
	mTextures.load(Textures::Eagle,  "Media/Textures/Eagle.png");
	mTextures.load(Textures::Raptor, "Media/Textures/Raptor.png");
	mTextures.load(Textures::Desert, "Media/Textures/Desert.png");
}

void World::buildScene()
{
	// initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}
	// prepare the tiled background
	sf::Texture& texture = mTextures.get(Textures::Desert);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	// add the background sprite to the scene
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	// add players aircraft
	std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextures, mFonts));
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mPlayerAircraft->setVelocity(40.0f, mScrollSpeed);
	mSceneLayers[Air]->attachChild(std::move(leader));

	// add two escorting aircrafts, placed relatively to the main plane
	std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Raptor, mTextures, mFonts));
	leftEscort->setPosition(-80.0f, 50.0f);
	mPlayerAircraft->attachChild(std::move(leftEscort));

	std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Raptor, mTextures, mFonts));
	rightEscort->setPosition(80.0f, 50.0f);
	mPlayerAircraft->attachChild(std::move(rightEscort));
}

void World::adaptPlayerPosition()
{
	// Keep player´s position inside the screen bounds, at least borderDistance units from the border
	sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.0f, mWorldView.getSize());
	const float borderDistance = 40.0f;

	sf::Vector2f position = mPlayerAircraft->getPosition();
	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
	mPlayerAircraft->setPosition(position);
}

void World::spawnEnemies()
{
}

sf::FloatRect World::getViewBounds() const
{
	return sf::FloatRect();
}

sf::FloatRect World::getBattlefieldBounds() const
{
	return sf::FloatRect();
}
