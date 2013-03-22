#include "stdafx.h"
#include "Config.h"

#include "Logger.h"
#include "Utils.h"

#include <fstream>

Config::Config(std::string filePath) : path(filePath), root(nullptr)
{
	std::fstream file(path, std::ios::app);
	if (!file.good())
		Logger::log("Could not open config file");
	file.close();
	reload();
}


Config::~Config()
{
	delete root; // root will delete its child values as well
}


Node* Config::get(std::string key)
{
	std::vector<std::string> nodes = Utils::split(key, '.');
	
	Node *node = root;
	for(std::string n : nodes)
		if (node->nodes.find(n) != node->nodes.end())
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
		if(c != '\t') // tab
			break;
		deep++;
	}
	return deep;
}


void fillNode(Node *node, std::string& line, int deep)
{
	line = line.substr(deep); // to remove first tabs

	std::vector<std::string> splitted = Utils::split(line, ':', 1); // to separate the path and the value

	if(splitted.size() == 1)
		splitted.push_back("");
	if(splitted.size() != 2)
		Logger::log("Error while parsing YAML file in: " + line, Logger::levels::critical);

	std::string key = splitted[0];
	std::string value = splitted[1];
	if(value != "")
		value = value.substr(1); // to remove first space
	node->name = key;
	node->value = value;
	node->parent->nodes[key] = node;
}


// reload Clears all values then load them again from file
bool Config::reload()
{
	delete root;
	root = new Node(nullptr, "Do not cut");
	root->parent = root;

	Node *node = root;
	int deep = -1;
	std::vector<std::string> lines = FileMgr::getFile(path);
	for(std::string line : lines)
	{
		int newDeep = getDeep(line);

		while(newDeep < deep)
		{
			node = node->parent;
			deep--;
		}
		if(newDeep > deep)
		{
			node = new Node(node);
			deep++;
		}
		else if(newDeep == deep)
			node = new Node(node->parent);

		fillNode(node, line, deep);
	}

	return true;
}


void nodeToString(Node *node, std::vector<std::string>& lines, std::string deep)
{
	lines.push_back(deep + node->toString() + "\n");
	for(auto pair : node->nodes)
		nodeToString(pair.second, lines, deep + "\t");
}


// Saves all values stored in root to file
bool Config::save()
{
	if(!FileMgr::clearFile(path))
		Logger::log("Cannot save config", Logger::levels::error);

	std::vector<std::string> lines;
	for(auto pair : root->nodes)
		nodeToString(pair.second, lines, "");

	return FileMgr::write(path, lines);
}