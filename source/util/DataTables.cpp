#include "DataTables.hpp"
#include "../model/aircraft.hpp"
#include "../model/projectile.hpp"

std::vector<AircraftData> initializeAircraftData()
{
	std::vector<AircraftData> data(Aircraft::TypeCount);

	data[Aircraft::Eagle].hitpoints = 100;
	data[Aircraft::Eagle].speed = 200.0f;
	data[Aircraft::Eagle].fireInterval = sf::seconds(1);
	data[Aircraft::Eagle].texture = Textures::Eagle;

	data[Aircraft::Raptor].hitpoints = 20;
	data[Aircraft::Raptor].speed = 80.0f;
	data[Aircraft::Raptor].texture = Textures::Raptor;
	data[Aircraft::Raptor].directions.push_back(Direction(45, 80));
	data[Aircraft::Raptor].directions.push_back(Direction(-45, 160));
	data[Aircraft::Raptor].directions.push_back(Direction(45, 80));
	data[Aircraft::Raptor].fireInterval = sf::Time::Zero;

	data[Aircraft::Avenger].hitpoints = 40;
	data[Aircraft::Avenger].speed = 50.f;
	data[Aircraft::Avenger].texture = Textures::Avenger;
	data[Aircraft::Avenger].directions.push_back(Direction(+45, 50));
	data[Aircraft::Avenger].directions.push_back(Direction(0, 50));
	data[Aircraft::Avenger].directions.push_back(Direction(-45, 100));
	data[Aircraft::Avenger].directions.push_back(Direction(0, 50));
	data[Aircraft::Avenger].directions.push_back(Direction(+45, 50));
	data[Aircraft::Avenger].fireInterval = sf::seconds(2);
	//data[Aircraft::Raptor].directions.push_back

	return data;
}

std::vector<ProjectileData> initializeProjectileData()
{
	std::vector<ProjectileData> data(Projectile::TypeCount);

	data[Projectile::AlliedBullet].damage = 10;
	data[Projectile::AlliedBullet].speed = 300.0f;
	data[Projectile::AlliedBullet].texture = Textures::Bullet;

	data[Projectile::EnemyBullet].damage = 10;
	data[Projectile::EnemyBullet].speed = 300.0f;
	data[Projectile::EnemyBullet].texture = Textures::Bullet;

	data[Projectile::Missile].damage = 200;
	data[Projectile::Missile].speed = 150.f;
	data[Projectile::Missile].texture = Textures::Missile;

	return data;
}

Direction::Direction(float angle, float distance)
{
}
