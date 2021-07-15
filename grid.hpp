#pragma once

#include <glm/vec3.hpp>

#include "render_object.hpp"

class Grid : RenderObject {
public:
	glm::vec3 position = glm::vec3(0, 0, 0);
public:
	Grid(int width, int height, GLfloat sideLength = 1.0f);
	~Grid();
public:
	void render();
};