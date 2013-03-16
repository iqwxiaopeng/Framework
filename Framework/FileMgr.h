#pragma once

#include <string>
#include <list>

using namespace std;

class FileMgr
{
public:
	static bool			write  (std::string path, std::string text);
	static bool			writeln(std::string path, std::string text) { return write(path, text + "\n"); }
	static int			search (std::string path, std::string text); // Found Text or not and how many (counter not implemented yet)
	static list<string>	getFile(std::string path);
};