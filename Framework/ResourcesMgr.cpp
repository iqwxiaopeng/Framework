#include "StdAfx.h"
#include "ResourcesMgr.h"

ResourcesMgr::ResourcesMgr()
{
}



ResourcesMgr::~ResourcesMgr()
{
	for(auto texture : textures)
		delete texture.second;
}


sf::Texture* ResourcesMgr::getTexture(std::string filename)
{
	sf::Texture *t = new sf::Texture();
	t->loadFromFile("GFX\\" + filename);
	return t;
}


void ResourcesMgr::addObject(std::unordered_map<std::string, sf::Texture*>& map, std::string name, std::string filename)
{
	map.insert(std::make_pair(name, getTexture(filename)));
}


void ResourcesMgr::addTexture(std::string name)
{
	addObject(this->textures, name, name);
}


void ResourcesMgr::addTexture(std::string name, std::string filename)
{
	addObject(this->textures, name, filename);
}
