#include "stdafx.h"
#include "Utils.h"

#include <iostream>
#include <ctime>

#include "boost/lexical_cast.hpp"

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