#include "wall.hpp"

Wall::Wall(Cluster* cluster, glm::vec3 position, glm::vec4 color) : RenderObject({ OGLVertexAttribute(0, 3, GL_FLOAT, GL_FALSE), OGLVertexAttribute(1, 4, GL_FLOAT, GL_FALSE) }) {
	// The algorithm to generate a wall is very simple.
	// 1. Define a big array of 0/1 values and set it all to values of 1
	// [1][1][1][1][1]
	// [1][1][1][1][1]
	// [1][1][1][1][1]
	// [1][1][1][1][1]
	// [1][1][1][1][1]
	// 2. Wherever there is a cube, switch the value from 1 to 0.
	// [1][1][1][1][1]
	// [1][1][0][1][1]
	// [1][0][0][0][1]
	// [1][1][0][0][1]
	// [1][1][1][1][1]
	// 3. Append a cube to the RenderObject for i/j index where the value is 1. You end up with a wall with holes.
	// The wall has an offset and a thickness to make it easier to place it exactly where the cluster should be.
	this->position = position;
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