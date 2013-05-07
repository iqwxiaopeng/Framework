#include "stdafx.h"
#include "Logger.h"

#include <iostream>
#include "FileMgr.h"
#include "Utils.h"

void Logger::log(std::string text, Logger::levels::logLevels level, std::string fileName)
{
	//			log = y.m.d h:m:s [level] log_text
	std::string log = Utils::getTime();

	switch(level)
	{
	default:
	case Logger::levels::info:		log += " [info] "; break;
	case Logger::levels::warning:	log += " [warning] "; break;
	case Logger::levels::error:		log += " [ERROR] "; break;
	case Logger::levels::critical:	log += " [CRITICAL] "; break;
	case Logger::levels::debug:		log += " [debug] "; break;
	case Logger::levels::trace:		log += " [trace] "; break;
	}
	log += text;

	std::cout << log << '\n';
	FileMgr::writeln(fileName, log);

	if (level == Logger::levels::critical)
	{
		Logger::log("Emergency shutdown");
		exit (42);
	}
}