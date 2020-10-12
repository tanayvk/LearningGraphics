#include <glad.h>
#include <GLFW/glfw3.h>

#include <Loader.h>

RawModel Loader::loadFromVertices(float vertices[], int length)
{
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	vaoIDs.push_back(vao);

	RawModel model;
	model.vaoID = vao;
	model.vertexCount = length * sizeof(float) / 3;

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, length * sizeof(float), (void*)vertices, GL_STATIC_DRAW);
	vboIDs.push_back(vbo);

	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindVertexArray(0);

	return model;
}