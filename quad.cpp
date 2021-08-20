#include <glm/ext/matrix_transform.hpp>

#include "quad.hpp"

Quad::Quad(glm::vec2 position, glm::vec2 size, glm::vec2 uva, glm::vec2 uvb) :
	RenderObject({ OGLVertexAttribute(0, 3, GL_FLOAT, GL_FALSE), OGLVertexAttribute(1, 2, GL_FLOAT, GL_FALSE) }) {
	this->position = position;
	std::vector<GLfloat> vertices = {
		size.x / -2.0f, size.y / 2.0f, 0, uva.x, uva.y,
		size.x / 2.0f, size.y / 2.0f, 0, uvb.x, uva.y,
		size.x / -2.0f, size.y / -2.0f, 0, uva.x, uvb.y,
		size.x / 2.0f, size.y / -2.0f, 0, uvb.x, uvb.y,
	};
	std::vector<GLuint> indices = { 0, 1, 2, 1, 3, 2 };
	updateVertices(vertices);
	updateIndices(indices);
}
void Quad::render(ShaderManager* shaderMan, std::string const& programName) {
	shaderMan->setUniform("object", programName, glm::translate(glm::mat4(1.0f), glm::vec3(position, 0.0f)));
	RenderObject::render();
}