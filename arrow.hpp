#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include "render_object.hpp"

class Arrow : RenderObject {
public:
	glm::vec3 origin = glm::vec3(0, 0, 0);
	glm::vec2 orientation = glm::vec2(0, 0);
public:
	Arrow(GLfloat length, glm::vec2 orientation);
	~Arrow();
public:
	void render();
};