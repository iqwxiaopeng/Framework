#include "stdafx.h"
#include "Node.h"

Node::Node(Node *parent, std::string name, std::string value) : parent(parent), name(name), value(value)
{
}


Node::~Node()
{
	for(auto pair : nodes)
		delete pair.second;
}


std::string Node::toString()
{
	return name + ": " + value;
}


Node* Node::get(std::string key)
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


Node& Node::operator[](const std::string& key)
{
	return *get(key);
}