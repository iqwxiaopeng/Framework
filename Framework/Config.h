#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "FileMgr.h"

#include "Item.h"
#include "Node.h"
#include "Value.h"

class Config
{
	public:
		Config(std::string path);
		~Config();

		std::string path; // path to config file
		//typedef std::unordered_map<std::string, std::string> values_map;
		typedef std::unordered_map<std::string, Value> values_map;
		values_map values;
		bool saveFile; // Is it needed to save config to file

		bool readValues();

		/*
			* checkSet -> Check if <path> is set in config; If no, create it
			*/
		template <typename T>
		bool checkSet (std::string key, T value) {
			if (!isSet(key))
				return set(key, value);
			return true;
		}

		/*
			* set -> Write value to config
			*/
		template <typename T>
		bool set(std::string key, T value) {
			values [key] = value;//return pFM->writeln(path, key + "=" + boost::lexical_cast<std::string>(value));
			saveFile = true;
			return true;
		}

		/*
			* isSet -> Check if <path> is set in config file
			*/
		bool isSet(std::string key) {
			if (FileMgr::search(path, key+"=.*") > 0)
				return true;
			return false;
		}

		/*
			* get -> get value from config
			*/
		Value get(std::string key) {
			//return values[key].as<T>();
			return (*this)[key];
		}
		/*
		template <typename T>
		T get(std::string key) {
			//return values[key].as<T>();
			return (*this)[key].as<T>();
		}
		*/

		/*int& IntList::operator[] (const int nIndex)
		{
			return m_anList[nIndex];
		}*/

		Value& operator[](const std::string key) {
			return values[key];
		}

		bool reload();
		bool save();
	protected:
	private:
		std::vector <Item> nodes;
};