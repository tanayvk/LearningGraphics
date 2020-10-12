#include <vector>
#include <Models.h>

class Loader {
	std::vector<unsigned int> vboIDs;
	std::vector<unsigned int> vaoIDs;

public:
	RawModel loadFromVertices(float vertices[], int vertexCount);
};
