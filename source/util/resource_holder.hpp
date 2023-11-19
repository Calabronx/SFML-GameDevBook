#pragma once
#ifndef RESOURCEHOLDER_HPP
#define RESOURCEHOLDER_HPP

#include <SFML/Graphics.hpp>

#include <map>
#include <memory>
#include <string>
#include <cassert>


namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		Eagle,
		Raptor,
		Desert
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void			load(Identifier id, const std::string& filename);

	template <typename Parameter>
	void			load(Identifier id, const std::string& filename, const Parameter& secondParam);
	void			insertResource(Identifier id, std::unique_ptr<Resource> resource);

	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;


private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};
typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif 


