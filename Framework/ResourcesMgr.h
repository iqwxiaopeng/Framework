#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourcesMgr
{
public:
	std::unordered_map<std::string, sf::Texture*> textures;

	void addTexture(std::string name);

	ResourcesMgr();
	~ResourcesMgr();
private:
	sf::Texture* getTexture(std::string filename);
	void addObject(std::unordered_map<std::string, sf::Texture*>& map, std::string name);
};

