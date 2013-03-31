#pragma once

#include <cstdlib>
#include <vector>
#include <iostream>

#include <SFML\Graphics.hpp>

class Utils
{
public:
	static inline int GetRandom()
	{
		return rand();
	}

	// Noise.cpp
	static float BrownianNoise2(float x, float y, unsigned int i, float Persistence);
	static float PerlinNoise2(float x, float y);

	// Utils.cpp
	static std::string getTime();
	static std::vector<std::string> split(const std::string& s, char delim, int limit = INT_MAX);
	static sf::Color lerp(sf::Color first, sf::Color second, float value);
	static float distance(float x1, float y1, float x2, float y2);
	static int round(float number);

private:
	static std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems, int limit = INT_MAX);
};