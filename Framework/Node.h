#pragma once

#include "boost\lexical_cast.hpp"

class Node
{
private:
	typedef std::unordered_map<std::string, Node*> childNodes;

public:
	Node(Node *parent, std::string value) : value(new std::string(value)), parent(parent)
	{}
	Node(Node *parent, std::string *value = nullptr) : value(value), parent(parent)
	{}

	std::string* value;
	Node *parent;
	childNodes nodes;

	~Node()
	{
		for(auto pair : nodes)
			delete pair.second;
		delete value;
	}


	template <typename T>
	T as() {
		return boost::lexical_cast<T>(*value);
	}


	template <typename T>
	Node& operator=(T value) {
		*this->value = boost::lexical_cast<std::string>(value);
		return *this;
	}

};