#pragma once

#include <string>
#include <vector>

class FileMgr
{
public:
	static bool clearFile(std::string path);

	static bool	write  (std::string path, std::string line);
	static bool	write  (std::string path, std::vector<std::string> lines);
	static bool	writeln(std::string path, std::string text) { return write(path, text + "\n"); }

	static int	search (std::string path, std::string text); // Found Text or not and how many (counter not implemented yet)

	static std::vector<std::string> getFile(std::string path);
};