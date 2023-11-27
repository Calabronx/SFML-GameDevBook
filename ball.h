#pragma once
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(sf::Vector2f position, float radius);
	~Ball();

	void update(float deltaTime);
	void render(sf::RenderWindow& window);

private:
	sf::CircleShape body;
	sf::Vector2f pos;
	float radius;

	float x_speed;
	float y_speed;
};
#endif // !BALL_H

