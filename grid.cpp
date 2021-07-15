#include "grid.hpp"

Grid::Grid(int width, int height, GLfloat sideLength) : RenderObject({ OGLVertexAttribute(0, 3, GL_FLOAT, GL_FALSE) }) {
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;
	GLuint indexOffset = 0;
	for (int i = 0; i < width; i += 1) {
		for (int j = 0; j < height; j += 1) {
			GLfloat x = ((GLfloat)i - (GLfloat)width / 2.0f) * sideLength + position.x;
			GLfloat y = position.y;
			GLfloat z = ((GLfloat)j - (GLfloat)height / 2.0f) * sideLength  + position.z;
			GLfloat ii[] = { x, y, z, x, y, z + 1.0f, x + 1.0f, y, z + 1.0f, x + 1.0f, y, z };
			vertices.insert(vertices.end(), std::begin(ii), std::end(ii));
			GLuint jj[] = { indexOffset, indexOffset + 1, indexOffset + 1, indexOffset + 2, indexOffset + 2, indexOffset + 3, indexOffset + 3, indexOffset};
			indices.insert(indices.end(), std::begin(jj), std::end(jj));
			indexOffset += 4;
		}
	}
	updateVertices(vertices);
	updateIndices(indices);
}
Grid::~Grid() {
	return;
}
void Grid::render() {
	RenderObject::render(GL_LINES);
}