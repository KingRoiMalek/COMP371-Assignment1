#include <glm/glm.hpp>

#include "arrow.hpp"

Arrow::Arrow(GLfloat length, glm::vec2 orientation) : RenderObject({ OGLVertexAttribute(0, 3, GL_FLOAT, GL_FALSE) }) {
	this->orientation = orientation;
	glm::vec3 offset;
	offset.x = glm::sin(orientation.y) * glm::sin(orientation.x);
	offset.y = glm::cos(orientation.y);
	offset.z = glm::sin(orientation.y) * glm::cos(orientation.x);
	offset *= length;
	glm::vec3 tip = origin + offset;
	std::vector<GLfloat> vertices = {origin.x, origin.y, origin.z, tip.x, tip.y, tip.z};
	std::vector<GLuint> indices = {0, 1};
	updateVertices(vertices);
	updateIndices(indices);
}
Arrow::~Arrow() {
	return;
}
void Arrow::render() {
	RenderObject::render(GL_LINES);
}