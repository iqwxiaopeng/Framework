#include "StdAfx.h"
#include "ResourcesMgr.h"

ResourcesMgr::ResourcesMgr()
{
}



ResourcesMgr::~ResourcesMgr()
{
	for(auto texture : textures)
		delete texture.second;
	for(auto image : images)
		delete image.second;
}


sf::Texture* ResourcesMgr::getTexture(std::string name)
{
	return get<sf::Texture*>(textures, name);
}


sf::Image* ResourcesMgr::getImage(std::string name)
{
	return get<sf::Image*>(images, name);
}


void ResourcesMgr::addTextureAndImage(std::string name)
{ addTextureAndImage(name, name); }
void ResourcesMgr::addTextureAndImage(std::string name, std::string filename)
{
	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile("GFX\\" + filename);

	sf::Image *image = new sf::Image();
	image->loadFromFile("GFX\\" + filename);

	if(!addObject(textures, name, texture))
		delete texture;
	if(!addObject(images  , name, image))
		delete image;
}
