#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

struct Vertex
{
	float x, y, z;

	void print()
	{
		printf("{ %f, %f, %f}", x, y, z);
	}
};

struct Face;

struct HalfEdge
{
	Vertex *origin;

	HalfEdge *next;
	std::string nextKey;

	HalfEdge *prev;
	std::string prevKey;

	HalfEdge *twin;
	std::string twinKey;

	Face *face;
};

struct Face
{
	HalfEdge *edge;
};

class HalfEdgeMesh
{
private:
	Vertex *vertices;
	unsigned int numVertices;

	Face *faces;
	unsigned int numFaces;

	std::map<std::string, HalfEdge> halfEdges;
	unsigned int numHalfEdges;
	unsigned int curHalfEdgeIndex;

public:
	HalfEdgeMesh(std::string path);
	~HalfEdgeMesh();

private:
	void readFromFile(std::string path);
	void parseVertexLine(unsigned int index, std::vector<std::string> line);
	void parseFaceLine(unsigned int index, std::vector<std::string> line);
	void completeHalfEdges();
};