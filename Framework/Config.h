#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "FileMgr.h"

#include "Node.h"


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
		*get(key) = value;
	}


	// Checks if key is set in config file
	bool isSet(std::string key) {
		return get(key) != nullptr;
	}


	Node& operator[](const std::string key) {
		return *get(key);
	}
};