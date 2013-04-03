#pragma once

#include "boost\lexical_cast.hpp"
#include "Utils.h"

class Node
{
private:
	typedef std::unordered_map<std::string, Node*> childNodes;

public:
	Node(Node *parent, std::string name = "", std::string value = "") : parent(parent), name(name), value(value)
	{}

	std::string name;
	std::string value;
	Node *parent;
	childNodes nodes;

	~Node()
	{
		for(auto pair : nodes)
			delete pair.second;
	}


	template <typename T>
	T as() {
		return boost::lexical_cast<T>(value);
	}


	template <typename T>
	Node& operator=(T value) {
		this->value = boost::lexical_cast<std::string>(value);
		return *this;
	}


	std::string toString()
	{
		return name + ": " + value;
	}


	Node* get(std::string key) // returns node specified by key
	{
		std::vector<std::string> nodes = Utils::split(key, '.');
	
		Node *node = this;
		for(std::string n : nodes)
			if (node->nodes.find(n) != node->nodes.end())
				node = node->nodes[n];
			else
				return nullptr;
		return node;
	}

	Node& operator[](const std::string& key) {
		return *get(key);
	}
};