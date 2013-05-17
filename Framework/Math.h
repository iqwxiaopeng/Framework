#pragma once

namespace Utils
{
	int		round(const float& number);
	float	distance(const float& x1, const float& y1, const float& x2, const float& y2);
	float	distanceSquared(const float& x1, const float& y1, const float& x2, const float& y2);
	float	distanceSquared(const int&   x1, const int&   y1, const int&   x2, const int&   y2);
};