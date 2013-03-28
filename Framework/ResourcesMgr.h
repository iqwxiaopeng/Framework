#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// TODO: <soon> rewrite to handle sounds, etc

class ResourcesMgr
{
	public:
		std::unordered_map<std::string, sf::Texture*> textures;

		void addTexture(std::string name);
		void addTexture(std::string name, std::string filename);

		ResourcesMgr();
		~ResourcesMgr();
	private:
		sf::Texture* getTexture(std::string filename);
		void addObject(std::unordered_map<std::string, sf::Texture*>& map, std::string filename, std::string name);
};

