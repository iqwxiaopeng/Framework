#include "stdafx.h"
#include "Config.h"

#include "Logger.h"

#include <fstream>

Config::Config(std::string filePath) : path(filePath)
{
	std::fstream file(path, std::ios::app);
	if (!file.good())
		Logger::log("Could not open config file");
	file.close();
}


Config::~Config()
{
	delete root; // root will delete its child values as well
}


Node* Config::get(std::string key)
{
	// TODO: move split to utils
	std::vector<std::string> nodes = split(key, '.', 0);
		
	Node *node = root;
	for(std::string n : nodes)
		if (node->nodes.find(key) != node->nodes.end())
			node = node->nodes[n];
		else
			return nullptr;
	return node;
}


int getDeep(std::string& line)
{
	int deep = 0;
	for(char c : line)
	{
		if(c != '	') // tab
			break;
		deep++;
	}
	return deep;
}


void fillNode(Node *n, std::string& line, int deep)
{
	line = line.substr(deep); // to remove first tabs

	// split(string, ':', 1); to separate the path and the value
	std::vector<std::string> splitted = split(line, ':', 1);
	if(splitted.size() != 2)
		Logger::log("Error while parsing YAML file in: " + line, Logger::levels::critical);

	std::string key = splitted[0];
	std::string value = splitted[1];
	*n = value;
}


// reload Clears all values then load them again from file
bool Config::reload()
{
	delete root;
	root = new Node(nullptr);

	Node *node = root;
	int deep = 0;
	std::vector<std::string> lines = FileMgr::getFile(path);
	for(std::string line : lines)
	{
		int newDeep = getDeep(line);
		if(newDeep > deep)
			node = new Node(root);
		while(newDeep < deep)
			node = node->parent;

		fillNode(node, line, deep);
	}

	return true;
}


// Saves all values stored in root to file
bool Config::save()
{
	std::fstream file(path, std::ios::trunc | std::ios::out);
	if (file.good())
	{
		std::string line;

		/*
		for (values_map::iterator it = values.begin(); it != values.end(); ++it)
		{
			line = it->first;
			line += "=" + it->second.as<std::string>();
			file << line + "\n";			
		}
		file.flush();
		*/
	}
	else
		std::cout << "Could not save config values to file";

	return true;
}