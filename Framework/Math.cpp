#include "stdafx.h"
#include "Math.h"

#include <cmath>

int Utils::round(const float& number)
{
    return (int)(number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5));
}


float Utils::distance(const float& x1, const float& y1, const float& x2, const float& y2)
{
	return sqrtf(distanceSquared(x1, y1, x2, y2));
}


float Utils::distanceSquared(const float& x1, const float& y1, const float& x2, const float& y2)
{
	return powf(x2-x1, 2) + powf(y2-y1, 2);
}


float Utils::distanceSquared(const int& x1, const int& y1, const int& x2, const int& y2)
{
	return (float) ( _Pow_int(x2-x1, 2) + _Pow_int(y2-y1, 2) );
}