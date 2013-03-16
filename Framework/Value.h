#pragma once

#include <string>
#include <boost\lexical_cast.hpp>


class Value
{
public:
	Value() {} // default ctor

	Value(std::string value)
	{
		this->value = value;
	}

	std::string value;

	template <typename T>
	T as() {
		return boost::lexical_cast<T>(value);
	}

	template <typename T>
	std::vector<T> asArrayOf()
	{
		if (value [0] != '[' || value [values.size()-1] != ']')
			return 0;
		std::vector <T> values;
		std::string value = "";

		for (int i = 1; i < value.size()-1; ++i)
		{
			if(value [i] == ',')
			{
				if (value [i+1] == ' ')
					++i;
				values.push_back(value);
			}
		}

		return values; // Czy tablica i unordered_map siê dobrze skopiuj¹?
	}

	template <typename T>
	std::unordered_map<std::string, T> asMapOf()
	{
		std::unordered_map <std::string, T> values; // Mo¿e wskaŸnik i new/delete, a nie lokalny obiekt

		return values; // Czy tablica i unordered_map siê dobrze skopiuj¹?
	}


	template <typename T>
	Value& operator=(T value) {
		this->value = boost::lexical_cast<std::string>(value);;
		return *this;
	}
};