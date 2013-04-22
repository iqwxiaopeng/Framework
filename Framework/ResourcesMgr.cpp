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


sf::Texture* ResourcesMgr::getTexture(std::string name)
{
	if(textures.find(name) == textures.end())
		return nullptr;
	return textures.at(name);
}


sf::Texture* ResourcesMgr::loadTexture(std::string filename)
{
	sf::Texture *t = new sf::Texture();
	t->loadFromFile("GFX\\" + filename);
	return t;
}


void ResourcesMgr::addTexture(std::string name)
{ addTexture(name, name); }
void ResourcesMgr::addTexture(std::string name, std::string filename)
{
	addObject(textures, name, loadTexture(filename));
}
