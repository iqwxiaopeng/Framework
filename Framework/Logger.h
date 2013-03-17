#pragma once

#include <string>

class Logger
{
public:
	struct levels
	{
		enum logLevels
		{
			info, warning, error, critical, debug, trace
		};
	};

	static void log(std::string Text, int level = levels::info, std::string fileName = "log.txt");

private:
	Logger();
	Logger(const Logger&);
	Logger& operator=(const Logger&);
};