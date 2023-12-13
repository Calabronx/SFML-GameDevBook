#ifndef DATATABLES_HPP
#define DATATABLES_HPP

#include <vector>
#include "resource_holder.hpp"
#include "ResourceIdentifiers.hpp"
class Aircraft;

struct Direction {
					Direction(float angle, float distance);
	float			angle;
	float			distance;
};

struct AircraftData
{
	int						hitpoints;
	float					speed;
	Textures::ID			texture;
	sf::Time				fireInterval;
	std::vector<Direction>	directions;
};

struct ProjectileData
{
	int					damage;
	float				speed;
	Textures::ID		texture;
};

std::vector<AircraftData>	initializeAircraftData();
std::vector<ProjectileData> initializeProjectileData();
#endif // !DATATABLES_HPP