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
	static int		round(const float& number);
	static bool		collision(const sf::IntRect &, const sf::IntRect &);
	static float	distance(const float& x1, const float& y1, const float& x2, const float& y2);
	static float	distanceSquared(const float& x1, const float& y1, const float& x2, const float& y2);
	static float	distanceSquared(const int&   x1, const int&   y1, const int&   x2, const int&   y2);
	static std::string	getTime();
	static sf::Color	lerp(const sf::Color& first, const sf::Color& second, float value);
	static std::vector<std::string> split(const std::string& s, char delim, int limit = INT_MAX); // Splits the string into a substrings into the vector.

	template <typename T>
	static bool comparePointers(const T * const & a, const T * const & b); // checks if *a < *b
	
	template<typename CONTAINER, typename WHAT>
	static bool contains(WHAT what, CONTAINER container);

private:
	static std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems, int limit = INT_MAX);
};

template <typename T>
bool Utils::comparePointers(const T * const & a, const T * const & b) // checks if *a < *b
{
	return *a < *b;
}

template<typename CONTAINER, typename WHAT>
static bool Utils::contains(WHAT what, CONTAINER container)
{
	for(auto item : container)
		if(item == what)
			return true;
	return false;
}