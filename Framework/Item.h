#pragma once
#include <string>

class Item
{
public:

	Item(void)
	{
	}

	~Item(void)
	{
	}

	enum type
	{
		NODE,
		VALUE
	};
	type itemType;

	//virtual const std::string getType();
};