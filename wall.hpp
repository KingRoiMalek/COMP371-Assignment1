#pragma once

#include <glm/vec4.hpp>

#include "cluster.hpp"
#include "render_object.hpp"

class Wall : RenderObject {
public:
	Wall(Cluster *cluster, glm::vec4 color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	~Wall();
public:
	void render();
};