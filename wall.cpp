#include "wall.hpp"

Wall::Wall(Cluster* cluster, glm::vec4 color) : RenderObject({ OGLVertexAttribute(0, 3, GL_FLOAT, GL_FALSE), OGLVertexAttribute(1, 4, GL_FLOAT, GL_FALSE) }) {
	int planeField[7][7];
	for (int i = 0; i < 7; i += 1)
		for (int j = 0; j < 7; j += 1)
			planeField[i][j] = 1;

	for (Cube *cube : cluster->cubes) {
		int xIndex = (int) cube->position.x + 3;
		int yIndex = (int) cube->position.y + 3;
		planeField[xIndex][yIndex] = 0;
	}

	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;
	GLuint indexOffset = 0;
	GLfloat const s = 0.5;
	GLfloat zOffset = -2.0f;
	GLfloat thickness = 0.2f;
	for (int i = 0; i < 7; i += 1) {
		for (int j = 0; j < 7; j += 1) {
			if (planeField[i][j] == 0) continue;
			float x = (float)i - 3.0f;
			float y = (float)j - 3.0f;
			GLfloat ii[] = {
				x - s, y - s, zOffset - thickness, color.x, color.y, color.z, color.w,
				x + s, y - s, zOffset - thickness, color.x, color.y, color.z, color.w,
				x + s, y + s, zOffset - thickness, color.x, color.y, color.z, color.w,
				x - s, y + s, zOffset - thickness, color.x, color.y, color.z, color.w,
				x - s, y - s, zOffset, color.x, color.y, color.z, color.w,
				x + s, y - s, zOffset, color.x, color.y, color.z, color.w,
				x + s, y + s, zOffset, color.x, color.y, color.z, color.w,
				x - s, y + s, zOffset, color.x, color.y, color.z, color.w
			};

			vertices.insert(vertices.end(), std::begin(ii), std::end(ii));
			GLuint jj[] = {
				indexOffset + 0, indexOffset + 1, indexOffset + 3,
				indexOffset + 3, indexOffset + 1, indexOffset + 2,
				indexOffset + 1, indexOffset + 5, indexOffset + 2,
				indexOffset + 2, indexOffset + 5, indexOffset + 6,
				indexOffset + 5, indexOffset + 4, indexOffset + 6,
				indexOffset + 6, indexOffset + 4, indexOffset + 7,
				indexOffset + 4, indexOffset + 0, indexOffset + 7,
				indexOffset + 7, indexOffset + 0, indexOffset + 3,
				indexOffset + 3, indexOffset + 2, indexOffset + 7,
				indexOffset + 7, indexOffset + 2, indexOffset + 6,
				indexOffset + 4, indexOffset + 5, indexOffset + 0,
				indexOffset + 0, indexOffset + 5, indexOffset + 1
			};
			
			indices.insert(indices.end(), std::begin(jj), std::end(jj));
			indexOffset += 8;
		}
	}
	updateVertices(vertices);
	updateIndices(indices);
}
Wall::~Wall() {
	return;
}
void Wall::render() {
	RenderObject::render();
}