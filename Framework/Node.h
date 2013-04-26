#pragma once

#include "boost\lexical_cast.hpp"
#include "Utils.h"

#include <string>
#include <unordered_map>

class Node
{
private:
	typedef std::unordered_map<std::string, Node*> childNodes;

public:
	std::string name;
	std::string value;
	Node *parent;
	childNodes nodes;

	Node(Node *parent, std::string name = "", std::string value = "");
	~Node();

	template <typename T>
	T as();

	template <typename T>
	Node& operator=(T value);

	Node* get(std::string key); // returns node specified by key
	Node& operator[](const std::string& key);

	std::string toString();
};


template <typename T>
T Node::as()
{
	return boost::lexical_cast<T>(value);
}


template <typename T>
Node& Node::operator=(T value)
{
	this->value = boost::lexical_cast<std::string>(value);
	return *this;
}