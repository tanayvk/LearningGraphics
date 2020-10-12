#include <Renderer.h>
#include <glad.h>
#include <GLFW/glfw3.h>

void Renderer::drawRawModel(RawModel model)
{
	glBindVertexArray(model.vaoID);
	glDrawArrays(GL_TRIANGLES, 0, model.vertexCount);
}
