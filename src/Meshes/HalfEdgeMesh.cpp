#include "HalfEdgeMesh.h"
#include <filesystem>

HalfEdgeMesh::HalfEdgeMesh(std::string path)
{
	this->readFromFile(path);
	this->completeHalfEdges();
}

HalfEdgeMesh::~HalfEdgeMesh()
{
}

void HalfEdgeMesh::readFromFile(std::string path)
{
	std::string line;
	std::ifstream fileModel(path);

	while (std::getline(fileModel, line))
	{
		std::vector<std::string> lineVector = utils::tokenizeString(line, ' ');
		char lineType = lineVector[0].c_str()[0];
		lineVector.erase(lineVector.begin());

		switch (lineType)
		{
		case 'v':
			parseVertexLine(lineVector);
			break;

		case 'f':
			parseFaceLine(lineVector);
			break;
		}
	}

	fileModel.close();
};

void HalfEdgeMesh::parseVertexLine(std::vector<std::string> line)
{
	this->vertexList.push_back(Vertex(
		std::stof(line[0]),
		std::stof(line[1]),
		std::stof(line[2])));
};

void HalfEdgeMesh::parseFaceLine(std::vector<std::string> line)
{
	Face face = Face();
	for (std::string lineToken : line)
	{
		unsigned int vertexIndex = std::stoi(lineToken) - 1;
		face.vertices.push_back(&this->vertexList.at(vertexIndex));
	}

	this->faceList.push_back(face);
}

void HalfEdgeMesh::completeHalfEdges()
{
	for (Face face : this->faceList)
	{
		for (unsigned int i = 0; i < face.vertices.size(); i++)
		{
			Vertex *curVertex = face.vertices.at(i);
			Vertex *nextVertex = face.vertices.at((i + 1) % face.vertices.size());

			HalfEdge halfEdge;
			halfEdge.originVertex = curVertex;
			halfEdge.nextVertex = nextVertex;
			halfEdge.face = &face;

			this->halfEdgeList.push_back(halfEdge);
		}
	}

	for (HalfEdge halfEdge : this->halfEdgeList)
	{
		this->connectEdge(halfEdge);
	}
}

void HalfEdgeMesh::connectEdge(HalfEdge halfEdge)
{
	for (HalfEdge otherHalfEdge : this->halfEdgeList)
	{
		if (halfEdge.face == otherHalfEdge.face)
		{

			if (halfEdge.nextVertex == otherHalfEdge.originVertex)
			{
				halfEdge.nextEdge = &otherHalfEdge;
			}

			if (otherHalfEdge.nextVertex == halfEdge.originVertex)
			{
				halfEdge.prevEdge = &otherHalfEdge;
			}
		}

		if (halfEdge.originVertex == otherHalfEdge.nextVertex && halfEdge.nextVertex == otherHalfEdge.originVertex)
		{
			halfEdge.twinEdge = &otherHalfEdge;
		}
	}
}