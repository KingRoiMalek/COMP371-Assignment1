#include "cluster.hpp"

Cluster::Cluster() {
	return;
}
Cluster::Cluster(glm::vec3 position, float rotation, float scale) {
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}
Cluster::~Cluster() {
	return;
}
void Cluster::setPosition(glm::vec3 position) {
	this->position = position;
}