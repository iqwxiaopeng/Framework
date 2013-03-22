#pragma once

#include <cstdlib>
#include <vector>
#include <iostream>

class Utils
{
public:
	static inline int GetRandom()
	{
		return rand();
	}

	static std::string getTime();
	static std::vector<std::string> split(const std::string& s, char delim, int limit = INT_MAX);

private:
	static std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems, int limit = INT_MAX);
};