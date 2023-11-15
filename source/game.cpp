#include "game.hpp"

const float Game::PlayerSpeed = 100.0f;
const sf::Time Game::TimePerFrame = sf::seconds(1.0f / 60.0f);

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application")
	, mPlayer()
{
	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.0f, 100.0f);
	mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
	sf::Clock clock;
	while (mWindow.isOpen()) {
		sf::Time deltaTime = clock.restart();
		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		/*if (event.type == sf::Event::Closed)
			mWindow.close();*/
		switch (event.type) {
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;

	mPlayer.move(movement * elapsedTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}
