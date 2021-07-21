#include <glm/ext/matrix_transform.hpp>

#include "cluster.hpp"

Cluster::Cluster() {
	generateCluster();
}
Cluster::Cluster(glm::vec3 position, float rotation, float scale) {
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
	generateCluster();
}
Cluster::~Cluster() {
	return;
}
void Cluster::appendCube(glm::vec3 offset) {
	float const R = (float)(rand() % 255) / 255.0f;
	float const G = (float)(rand() % 255) / 255.0f;
	float const B = (float)(rand() % 255) / 255.0f;
	cubes.push_back(new Cube(glm::vec4(R, G, B, 1.0f), offset));
}
void Cluster::generateCluster() {
	glm::vec3 const UP = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 const DOWN = glm::vec3(0.0f, -1.0f, 0.0f);
	glm::vec3 const LEFT = glm::vec3(-1.0f, 0.0f, 0.0f);
	glm::vec3 const RIGHT = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 const FORWARD = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 const BACKWARD = glm::vec3(0.0f, 0.0f, -1.0f);
	float const maxPlaneOffset = 2.0f;

	glm::vec3 const offsets[] = { UP, DOWN, LEFT, RIGHT, FORWARD, BACKWARD };
	std::vector<glm::vec3> coordinates = { glm::vec3(0.0f, 0.0f, 0.0f) };
	appendCube(glm::vec3(0.0f, 0.0f, 0.0f));
	while (coordinates.size() < 9) {
		int const coordinateCount = coordinates.size();
		glm::vec3 randomCoordinate = coordinates[rand() % coordinateCount];
		glm::vec3 newCoordinate = randomCoordinate + offsets[rand() % sizeof offsets / sizeof * offsets];
		if (newCoordinate.x > maxPlaneOffset || newCoordinate.x < -maxPlaneOffset) {
			continue;
		}
		if (newCoordinate.y > maxPlaneOffset || newCoordinate.y < -maxPlaneOffset) {
			continue;
		}
		if (std::find(coordinates.begin(), coordinates.end(), newCoordinate) != coordinates.end()) {
			continue;
		} else {
			coordinates.push_back(newCoordinate);
			appendCube(newCoordinate);
		}
	}
}
void Cluster::render(ShaderManager* shaderMan) {
	for (Cube *cube : cubes) {
		const glm::mat4 i = glm::mat4(1.0f);
		glm::mat4 transform = 
		glm::translate(i, position) * // Step 4: Translate cluster
		glm::rotate(i, rotation, glm::vec3(0, 1.0f, 0)) * // Step 3: Rotate cluster around y-axis
		glm::scale(i, glm::vec3(scale)) * // Step 2: Scale cluster by a constant
		glm::translate(i, cube->position); // Step 1: Translate cube by offset
		shaderMan->setUniform("object", "basic", transform);
		cube->render();
	}
}
void Cluster::setPosition(glm::vec3 position) {
	this->position = position;
}