#pragma once

#include <cstdlib>
#include <iostream>

class Utils
{
public:
	static inline int GetRandom()
	{
		return rand();
	}

	static std::string getTime();
};