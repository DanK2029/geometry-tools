#include "HalfEdgeMesh.h"
#include "../Utils/StringUtils.h"

HalfEdgeMesh::HalfEdgeMesh(std::string path) : numVertices(0), numFaces(0), numHalfEdges(0), curHalfEdgeIndex(0)
{
	std::string line;
	std::ifstream fileModel(path);
	while (std::getline(fileModel, line))
	{
		std::vector<std::string> lineVector = tokenizeString(line, ' ');
		char lineType = lineVector[0].c_str()[0];
		switch (lineType)
		{
		case 'v':
			this->numVertices++;
			break;

		case 'f':
			this->numFaces++;
			this->numHalfEdges += lineVector.size() - 1;
			break;
		}
	}

	this->vertices = (Vertex *)malloc(sizeof(struct Vertex) * this->numVertices);
	this->faces = (Face *)malloc(sizeof(struct Face) * this->numFaces);

	this->readFromFile(path);

	std::cout << "half edge set size: " << this->halfEdges.size() << std::endl;

	this->completeHalfEdges();
}

HalfEdgeMesh::~HalfEdgeMesh()
{
	free(this->vertices);
	free(this->faces);
}

void HalfEdgeMesh::readFromFile(std::string path)
{
	unsigned int curVertexIndex = 0;
	unsigned int curFaceIndex = 0;

	std::string line;
	std::ifstream fileModel(path);
	while (std::getline(fileModel, line))
	{
		std::vector<std::string> lineVector = tokenizeString(line, ' ');
		char lineType = lineVector[0].c_str()[0];
		switch (lineType)
		{
		case 'v':
			parseVertexLine(curVertexIndex, lineVector);
			curVertexIndex++;
			break;

		case 'f':
			parseFaceLine(curFaceIndex, lineVector);
			curFaceIndex++;
			break;
		}
	}
};

void HalfEdgeMesh::parseVertexLine(unsigned int index, std::vector<std::string> line)
{
	this->vertices[index] = {
		std::stof(line[1]),
		std::stof(line[2]),
		std::stof(line[3])};
};

void HalfEdgeMesh::parseFaceLine(unsigned int index, std::vector<std::string> line)
{

	line.erase(line.begin());
	for (unsigned int i = 0; i < line.size(); i++)
	{
		std::string curToken = line.at(i);
		std::string nextToken = line.at((i + 1) % line.size());
		std::string prevToken = line.at(i == 0
											? line.size() - 1
											: (i - 1) % line.size());

		unsigned int vertexIndex = std::stoi(curToken);
		HalfEdge edge;
		edge.origin = &this->vertices[vertexIndex];
		edge.face = &this->faces[index];
		edge.nextKey = curToken.append("->").append(nextToken);
		edge.prevKey = curToken.append("->").append(prevToken);
		edge.twinKey = nextToken.append("->").append(curToken);

		std::string key = curToken.append("->").append(nextToken);

		this->halfEdges.insert(std::pair<std::string, HalfEdge>(key, edge));
	}
}

void HalfEdgeMesh::completeHalfEdges()
{
	for (auto keyValue : this->halfEdges)
	{
		std::string key = keyValue.first;
		HalfEdge hafEdge = keyValue.second;
	}
}