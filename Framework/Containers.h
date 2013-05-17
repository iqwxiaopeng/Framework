#pragma once

#include <vector>

namespace Utils
{
	template<typename CONTAINER, typename WHAT>
	bool contains(WHAT what, CONTAINER container);

	std::vector<std::string> split(const std::string& s, char delim, int limit = INT_MAX); // Splits the string into a substrings into the vector.
	std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems, int limit = INT_MAX);
};


template<typename CONTAINER, typename WHAT>
bool Utils::contains(WHAT what, CONTAINER container)
{
	for(auto item : container)
		if(item == what)
			return true;
	return false;
}