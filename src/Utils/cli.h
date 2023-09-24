#ifndef CLI_UTILS_H
#define CLI_UTILS_H

#include <deque>
#include <string>
#include <iostream>

namespace cli
{
	namespace utils
	{
		void parseParameters(std::deque<std::string> parameters)
		{
			std::cout << "UTILS CLI " << std::endl;
			for (int i = 0; i < parameters.size(); i++)
			{
				std::cout << ", " << parameters[i] << std::endl;
			}
		}
	}
}

#endif
