#include "StringUtils.h"

namespace utils
{
	std::vector<std::string> tokenizeString(std::string str, char splitter)
	{
		std::vector<std::string> tokens;
		std::string current = "";
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == splitter)
			{
				if (current != "")
				{
					tokens.push_back(current);
					current = "";
				}
				continue;
			}
			current += str[i];
		}

		if (current.size() != 0)
		{
			tokens.push_back(current);
		}
		return tokens;
	}
}