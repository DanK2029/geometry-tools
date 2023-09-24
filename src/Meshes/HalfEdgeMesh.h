#ifndef HALFEDGEMESH_H
#define HALFEDGEMESH_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include <unistd.h>

#include "../Utils/StringUtils.h"

class HalfEdgeMesh
{
	struct HalfEdge;

public:
	class Vertex
	{
	public:
		float x, y, z;
		HalfEdge *halfedge;

		Vertex(float x, float y, float z) : x(x), y(y), z(z)
		{
			this->halfedge = nullptr;
		}

		friend std::ostream &operator<<(std::ostream &os, const Vertex &v)
		{
			os << "Vertex {" << v.x << ", " << v.y << ", " << v.z << "}";
			return os;
		}
	};

	class Face
	{
	public:
		std::vector<Vertex *> vertices;
		HalfEdge *halfEdge;

		Face()
		{
			this->halfEdge = nullptr;
		}

		friend std::ostream &operator<<(std::ostream &os, const Face &f)
		{

			os << "Face {" << std::endl;
			os << "	vertices: [" << std::endl;
			for (Vertex *v : f.vertices)
			{
				os << "	" << *v << std::endl;
			}
			os << "	]" << std::endl;

			os << "HalfEdge: " << f.halfEdge << std::endl;
			os << "}" << std::endl;

			return os;
		}
	};

	class HalfEdge
	{
	public:
		HalfEdgeMesh::Vertex *originVertex;
		Vertex *nextVertex;
		Face *face;

		HalfEdge *nextEdge;
		HalfEdge *prevEdge;
		HalfEdge *twinEdge;

		HalfEdge()
		{
			this->originVertex = nullptr;
			this->nextVertex = nullptr;
			this->face = nullptr;
			this->nextEdge = nullptr;
			this->prevEdge = nullptr;
			this->twinEdge = nullptr;
		}

		friend std::ostream &operator<<(std::ostream &os, const HalfEdge &he)
		{
			os << "Origin Vertex: " << he.originVertex << std::endl;
			os << "Next Vertex: " << he.nextVertex << std::endl;
			os << "Face: " << he.face << std::endl;
			os << "Next Edge: " << he.nextEdge << std::endl;
			os << "Prev Edge: " << he.prevEdge << std::endl;
			os << "Twin Edge: " << he.twinEdge << std::endl;

			return os;
		}
	};

public:
	std::vector<Vertex> vertexList;
	std::vector<Face> faceList;
	std::vector<HalfEdge> halfEdgeList;

public:
	HalfEdgeMesh(std::string path);
	~HalfEdgeMesh();

private:
	void readFromFile(std::string path);
	void parseVertexLine(std::vector<std::string> line);
	void parseFaceLine(std::vector<std::string> line);
	void completeHalfEdges();

	void connectEdge(HalfEdge halfEdge);
};

#endif
