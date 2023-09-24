class WingedEdgeMesh
{
public:
	class Edge;

	class Vertex
	{
	public:
		float x, y, z;
		Edge *edge;

		Vertex(float x, float y, float z, Edge *edge = nullptr) : x(x), y(y), z(z), edge(edge) {}
	};

	class Face
	{
	public:
		unsigned int id;
		Edge *edge;

		Face(unsigned int id, Edge *edge = nullptr) : id(id), edge(edge) {}
	};

	class Edge
	{
	public:
		Vertex *start;
		Vertex *end;

		Face *right;
		Face *left;

		Edge *rightNext;
		Edge *rightPrev;

		Edge *leftNext;
		Edge *leftPrev;

		Edge(Vertex *start, Vertex *end, Face *right = nullptr, Face *left = nullptr, Edge *rightNext = nullptr, Edge *rightPrev = nullptr, Edge *leftNext = nullptr, Edge *leftPrev = nullptr) : start(start), end(end), right(right), left(left), rightNext(rightNext), rightPrev(rightPrev), leftNext(leftNext), leftPrev(leftPrev){};
	};
};
