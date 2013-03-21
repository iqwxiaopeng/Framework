#include "stdafx.h"
#include "Utils.h"

#include <iostream>
#include <ctime>

#include <climits>
#include <sstream>
#include <vector>

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


std::vector<std::string>& Utils::split(const std::string &s, char delim, std::vector<std::string> &elems, int limit = INT_MAX)
{
	std::stringstream ss(s);
	std::string item;
	int i = 0;
	while(std::getline(ss, item, delim))
	{
		elems.push_back(item);
		if(++i >= limit)
			break;
	}

	// TODO: maybe a better way? :D
	while(std::getline(ss, item, ' '))
	{
		item = ' ' + item;
		elems[elems.size()-1] += item;
	}
	return elems;
}


std::vector<std::string> Utils::split(const std::string& s, char delim, int limit = INT_MAX)
{
	std::vector<std::string> elems;
	return split(s, delim, elems, limit);
}