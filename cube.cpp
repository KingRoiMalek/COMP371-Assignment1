#include "cube.hpp"

Cube::Cube(glm::vec4 color, glm::vec3 position) : RenderObject({ OGLVertexAttribute(0, 3, GL_FLOAT, GL_FALSE), OGLVertexAttribute(1, 4, GL_FLOAT, GL_FALSE) }) {
	this->position = position;
	GLfloat const s = 0.5;
	std::vector<GLfloat> vertices = {
		-s, -s, -s, color.x, color.y, color.z, color.w,
		s, -s, -s, color.x, color.y, color.z, color.w,
		s, s, -s, color.x, color.y, color.z, color.w,
		-s, s, -s, color.x, color.y, color.z, color.w,
		-s, -s, s, color.x, color.y, color.z, color.w,
		s, -s, s, color.x, color.y, color.z, color.w,
		s, s, s, color.x, color.y, color.z, color.w,
		-s, s, s, color.x, color.y, color.z, color.w
	};
	// Using an index array to not have to re-use vertices over and over again for triangles
	// that may share them. This saves up quite a bit of space (over 50% memory save).
	std::vector<GLuint> indices = {
		0, 1, 3, 
		3, 1, 2,   
		1, 5, 2, 
		2, 5, 6,
		5, 4, 6, 
		6, 4, 7,
		4, 0, 7, 
		7, 0, 3,
		3, 2, 7, 
		7, 2, 6,
		4, 5, 0, 
		0, 5, 1
	};
	updateVertices(vertices);
	updateIndices(indices);
}
Cube::~Cube() {
	return;
}
void Cube::render() {
	RenderObject::render();
}
void Cube::setPosition(glm::vec3 position) {
	this->position = position;
}