#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// TODO: <soon> rewrite to handle sounds, etc

class ResourcesMgr
{
	public:
		std::unordered_map<std::string, sf::Texture*> textures; // Hashmap (file)name --> texture
		std::unordered_map<std::string, sf::Image*  > images; // Hashmap (file)name --> texture

		ResourcesMgr();
		~ResourcesMgr();

		sf::Texture* getTexture(std::string name);
		sf::Image*   getImage  (std::string name);
		void addTextureAndImage(std::string name);
		/**
		 * Adds texture to textures map
		 * @param name index in hashmap
		 * @param filename path to the object starting in GFX directory. ("GFX\\" + filename)
		 */
		void addTextureAndImage(std::string name, std::string filename);
	private:
		/**
		 * Adds object to the container if specified name wasn't inserted yet.
		 * @param map container hashmap for object
		 * @param name index in hashmap
		 * @param object object to add to the container
		 * @return if object was inserted
		 */
		template<typename mapType, typename objectType>
		bool addObject(mapType& map, std::string name, objectType object);

		/**
		 * Returns an object of type returnType from a map specified by name
		 * @param map container hashmap for object
		 * @param name index in hashmap
		 * @return the object if it exists under specified name. Otherwise nullptr
		 */
		template<typename returnType, typename mapType>
		returnType get(mapType& map, std::string name);
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


template<typename returnType, typename mapType>
returnType ResourcesMgr::get(mapType& map, std::string name)
{
	if(map.find(name) == map.end())
		return nullptr;
	return map.at(name);
}