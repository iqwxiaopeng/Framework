#pragma once

// Function declarations
#include "Containers.h"
#include "Math.h"
#include "Physics.h"

namespace Utils
{
	int getRandom();

	// Noise.cpp
	float BrownianNoise2(float x, float y, unsigned int i, float Persistence);
	float PerlinNoise2(float x, float y);

	// Utils.cpp
	std::string	getTime();
	sf::Color	lerp(const sf::Color& first, const sf::Color& second, float value);

	template <typename T>
	bool comparePointers(const T * const & a, const T * const & b); // checks if *a < *b
};

template <typename T>
bool Utils::comparePointers(const T * const & a, const T * const & b) // checks if *a < *b
{
	return *a < *b;
}