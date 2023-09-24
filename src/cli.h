#ifndef CLI_H
#define CLI_H

#include <string>
#include <deque>
#include <vector>
#include <stdexcept>

#include "Utils/cli.h"
#include "Meshes/cli.h"

namespace cli
{
	enum Module
	{
		M,
		UTILS
	};

	void parseParameters(std::deque<std::string> parameters)
	{
		std::string moduleStr = parameters[0];
		parameters.pop_front();

		if (moduleStr == "utils")
		{
			cli::utils::parseParameters(parameters);
		}
		else if (moduleStr == "meshes")
		{
			cli::HEM::parseParameters(parameters);
		}
		else
		{
			throw std::invalid_argument("Invalid Argument: Module " + moduleStr + " is not a recognized module.");
		}
	}
}

#endif
