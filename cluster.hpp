#pragma once

#include <glm/vec3.hpp>

class Cluster {
public:
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	float rotation = 0.0f;
	float scale = 1.0f;
public:
	Cluster();
	Cluster(glm::vec3 position, float rotation, float scale);
	~Cluster();
public:
	void setPosition(glm::vec3 position);
};