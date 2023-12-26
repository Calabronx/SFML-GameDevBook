#pragma once
#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include<SFML/Graphics.hpp>

struct Particle
{
	enum Type
	{
		Propellant,
		Smoke,
		ParticleCount
	};

	sf::Vector2f	position;
	sf::Color		color;
	sf::Time		lifeTime;
};
#endif // !PARTICLE_HPP

