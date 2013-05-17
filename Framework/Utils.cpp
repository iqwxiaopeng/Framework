#include "stdafx.h"
#include "Utils.h"

#include <ctime>

#include "boost/lexical_cast.hpp"

int Utils::getRandom()
{
	return rand();
}

std::string Utils::getTime()
{
	std::string stime = "";
	time_t timeAsSecs;
	time( &timeAsSecs );
	std::tm tm;
	localtime_s(&tm, &timeAsSecs );

	if (tm.tm_mday < 10)
		stime += "0";
	stime += boost::lexical_cast<std::string, int>(tm.tm_mday);
	stime += tm.tm_mon < 10 ? ".0" : ".";
	stime += boost::lexical_cast<std::string, int>(tm.tm_mon + 1);
	stime += ".";
	stime += boost::lexical_cast<std::string, int>(tm.tm_year + 1900);
	stime += tm.tm_hour < 10 ? " 0" : " ";
	stime += boost::lexical_cast<std::string, int>(tm.tm_hour);
	stime += tm.tm_min < 10 ? ".0" : ":";
	stime += boost::lexical_cast<std::string, int>(tm.tm_min);
	stime += tm.tm_sec < 10 ? ".0" : ":";
	stime += boost::lexical_cast<std::string, int>(tm.tm_sec);

	return stime;
}


sf::Color Utils::lerp(const sf::Color& first, const sf::Color& second, float value)
{
	typedef unsigned __int8 _uint8;
	if(value > 1.f)value = 1.f;
	else if(value < 0.f) value = 0.f;

	return sf::Color((_uint8)(first.r + ((float)(second.r - first.r) * value)),
					 (_uint8)(first.g + ((float)(second.g - first.g) * value)),
					 (_uint8)(first.b + ((float)(second.b - first.b) * value)),
					 (_uint8)(first.a + ((float)(second.a - first.a) * value)));
}


