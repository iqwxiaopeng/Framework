#include "stdafx.h"
#include "Config.h"

#include <fstream>

Config::Config(std::string filePath) : path(filePath), saveFile(false)
{
	std::fstream file(path, std::ios::app);
	if (!file.good())
		std::cout << "Could not open config file";
	file.close();
}

Config::~Config()
{
	//dtor
}


/*
* reload -> Clears all values then load them again from file
*/
bool Config::reload()
{
	// clear all values
	// load all value
	throw "not implemented yet";
}


/*
* save -> Saves all values stored in values variable to file
*/
bool Config::save()
{
	// write new values to file
	// write updated values to file
	std::fstream file(path, std::ios::trunc | std::ios::out);
	if (file.good())
	{
		std::string line;
		for (values_map::iterator it = values.begin(); it != values.end(); ++it)
		{
			line = it->first;
			line += "=" + it->second.as<std::string>();
			file << line + "\n";			
		}
		file.flush();
	}
	else
		std::cout << "Could not save config values to file";

	saveFile = false;
	return true;
}

bool Config::readValues()
{
	std::fstream file;
	file.open(path, std::ios::in);
	std::string key;

	if (file.good())
	{
		std::string key;
		std::string value;
		std::string text;

		getline (file, text);
		if (!file.eof())
			do
			{
				key = ""; value = "";

				if (!(text [0] == '#'))
				{
					unsigned int i = 0;

					for (; text [i] != '='; ++i)
						key += text [i];
					for (++i; i < text.length(); ++i) // First "++i" deletes "="
						value += text [i];
					values [key] = value;
				}
				getline (file, text);
			} while (!file.eof());
	}
	else
		std::cout << path << " not found! Can't read config values";
	
	file.close();
	return true;
}