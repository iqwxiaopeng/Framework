#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "FileMgr.h"

#include "Node.h"


// TODO: move it to utils
#include <climits>
#include <sstream>
std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems, int limit = INT_MAX)
{
	std::stringstream ss(s);
	std::string item;
	int i = 0;
	while(std::getline(ss, item, delim))
	{
		elems.push_back(item);
		if(++i >= limit)
			break;
	}

	// TODO: maybe a better way? :D
	while(std::getline(ss, item, ' '))
	{
		item = ' ' + item;
		elems[elems.size()-1] += item;
	}
	return elems;
}
std::vector<std::string> split(const std::string& s, char delim, int limit = 0)
{
	std::vector<std::string> elems;
	return split(s, delim, elems, limit);
}




class Config
{
public:
	Config(std::string path);
	~Config();

	std::string path; // path to config file
	Node *root;


	bool reload();
	bool save();
	Node* get(std::string key); // returns node specified by key in config

	// Checks if <path> is set in config; If no, create it
	template <typename T>
	void checkSet (std::string key, T value) {
		if (!isSet(key)) set(key, value);
	}


	// Writes value to config
	template <typename T>
	void set(std::string key, T value) {
		get(key) = value;
	}


	// Checks if key is set in config file
	bool isSet(std::string key) {
		return get(key) != nullptr;
	}


	Node& operator[](const std::string key) {
		return *get(key);
	}
};