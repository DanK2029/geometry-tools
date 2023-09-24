#ifndef CLI_HALFEDGEMESH_H
#define CLI_HALFEDGEMESH_H

#include <deque>
#include <string>
#include <iostream>

#include "HalfEdgeMesh.h"

namespace cli
{
	namespace HEM
	{
		void loadObj(std::deque<std::string> parameters)
		{
			std::string filePath = parameters[0];
			HalfEdgeMesh mesh = HalfEdgeMesh(filePath);
		}

		void parseParameters(std::deque<std::string> parameters)
		{
			if (parameters.size() <= 0)
			{
				throw std::invalid_argument("No HalfEdgeMesh operation called!");
			}

			std::string operationStr = parameters[0];
			parameters.pop_front();

			if (operationStr == "loadObj")
			{
				loadObj(parameters);
			}
			else
			{
				throw std::invalid_argument("Operation " + operationStr + " is not a recognized HalfEdgeMesh operation.");
			}
		}
	}
}

#endif
