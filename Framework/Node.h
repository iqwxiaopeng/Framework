#include "Item.h"

class Node : public Item
{
public:
	const std::string getType() {
		return "Node";
	}
};