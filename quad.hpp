#pragma once

#include <glm/vec2.hpp>

#include "render_object.hpp"
#include "shader_manager.hpp"

class Quad : RenderObject {
public:
	glm::vec2 position;
	glm::vec2 size;
public:
	Quad(glm::vec2 position, glm::vec2 size, glm::vec2 uva, glm::vec2 uvb);
public:
	void render(ShaderManager* shaderMan, std::string const& programName);
};