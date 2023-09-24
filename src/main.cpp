#include <deque>
#include <string>

#include "cli.h"

int main(int argc, char **argv)
{
	std::deque<std::string> commandLineArguments;
	for (int i = 1; i < argc; i++)
	{
		commandLineArguments.push_back(argv[i]);
	}

	cli::parseParameters(commandLineArguments);
}