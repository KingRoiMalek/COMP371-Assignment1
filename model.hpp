#pragma once

#include <glm/glm.hpp>

#include "render_object.hpp"
#include "shader_manager.hpp"

class Model : RenderObject {
public:
	glm::vec3 position = glm::vec3(0, 0, 0);
	glm::vec2 rotation = glm::vec2(0, 0);
	float scale = 1.0f;
public:
	Model(char const* path, glm::vec4 color = glm::vec4(1.0f), glm::vec3 position = glm::vec3(0, 0, 0), glm::vec2 rotation = glm::vec2(0, 0), float scale = 1.0f);
public:
	void render(ShaderManager* shaderMan, std::string const& programName);
};