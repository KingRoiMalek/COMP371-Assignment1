#pragma once

#include "quad.hpp"

class Number {
public:
	int value;
	Quad** digits;
	glm::vec2 position;
public:
	Number(glm::vec2 position, int value, Quad** digits);
public:
	void render(ShaderManager* shaderMan, std::string const& programName);
	void setValue(int value);
};