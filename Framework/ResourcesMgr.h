#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// TODO: <soon> rewrite to handle sounds, etc

class ResourcesMgr
{
	public:
		std::unordered_map<std::string, sf::Texture*> textures; // Hashmap (file)name --> texture

		ResourcesMgr();
		~ResourcesMgr();

		void addTexture(std::string name);
		/**
		 * Adds texture to textures map
		 * @param name index in hashmap
		 * @param filename path to the object starting in GFX directory. ("GFX\\" + filename)
		 */
		void addTexture(std::string name, std::string filename);
	private:
		sf::Texture* getTexture(std::string filename);
		
		template<typename mapType, typename objectType>

		/**
		 * Adds object to the container if specified name wasn't inserted yet.
		 * @param map container hashmap for object
		 * @param name index in hashmap
		 * @param object object to add to the container
		 * @return if object was inserted
		 */
		bool addObject(mapType& map, std::string name, objectType object);
};


template<typename mapType, typename objectType> 
bool ResourcesMgr::addObject(mapType& map, std::string name, objectType object)
{
	auto found = map.find(name);
	if(found == map.end())
	{
		map.insert(std::make_pair(name, object));
		return true;
	}
	return false;
}
